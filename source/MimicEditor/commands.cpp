#include "commands.h"
#include <QMetaEnum>

MoveCommand::MoveCommand(SchemaItem *item, const QPointF &oldPos, QUndoCommand *parent)
:QUndoCommand(parent)
{
    myItem=item;
    newPos=myItem->pos();
    myOldPos=oldPos;
}

void MoveCommand::undo()
{
    myItem->setPos(myOldPos);
    myItem->scene()->update();
    setText(QObject::tr("Move %1").arg(createCommandString(myItem,newPos)));
}

void MoveCommand::redo()
{
    myItem->setPos(newPos);
    setText(QObject::tr("Move %1").arg(createCommandString(myItem, newPos)));
}


bool MoveCommand::mergeWith(const QUndoCommand *command)
{
    const MoveCommand *moveCommand=static_cast<const MoveCommand*>(command);
    SchemaItem *item=moveCommand->myItem;

    if(myItem!=item){
        return false;
    }

    newPos=item->pos();
    setText(QObject::tr("Move %1").arg(createCommandString(myItem,newPos)));

    return true;
}


DeleteCommand::DeleteCommand(SchemaScene *scene, QUndoCommand *parent)
:QUndoCommand(parent)
{
    myScene=scene;
    QList<QGraphicsItem *> list = myScene->selectedItems();
    list.first()->setSelected(false);
    myItem=static_cast<SchemaItem *>(list.first());
    setText(QObject::tr("Delete %1").arg(createCommandString(myItem,myItem->pos())));
}

void DeleteCommand::undo()
{
    myScene->addItem(myItem);
    myScene->update();
}

void DeleteCommand::redo()
{
    myScene->removeItem(myItem);
}

AddCommand::AddCommand(SchemaItem::ItemType addItemType, SchemaScene *scene, QMenu *contextMenu ,QUndoCommand *parent)
    :QUndoCommand(parent)
{
    static int itemCount = 0;

    myScene=scene;
    myItem=new SchemaItem(addItemType,contextMenu);
    initialPos=QPointF((itemCount * 15)%int(scene->width()),(itemCount * 15)%int(scene->height()));

    scene->update();
    ++itemCount;
    setText(QObject::tr("Add %1").arg(createCommandString(myItem,initialPos)));
}

AddCommand::~AddCommand()
{
    if (!myItem->scene())
        delete myItem;
}

void AddCommand::undo()
{
    myScene->removeItem(myItem);
    myScene->update();
}

void AddCommand::redo()
{
    myScene->addItem(myItem);
    myItem->setPos(initialPos);
    myScene->clearSelection();
    myScene->update();
}

QString createCommandString(SchemaItem *item, const QPointF &pos){
    return QObject::tr("%1 at (%2, %3)")
            .arg(item->myTypeToString())
            .arg(pos.x()).arg(pos.y());
}
