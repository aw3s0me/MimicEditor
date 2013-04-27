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
    setText(QObject::tr("Перемещение на %1").arg(createCommandString(myItem,newPos)));
}

void MoveCommand::redo()
{
    myItem->setPos(newPos);
    setText(QObject::tr("Перемещение на %1").arg(createCommandString(myItem, newPos)));
}


bool MoveCommand::mergeWith(const QUndoCommand *command)
{
    //безопасное приведение
    const MoveCommand *moveCommand=static_cast<const MoveCommand*>(command);
    SchemaItem *item=moveCommand->myItem;//получаем итем новой команды

    if(myItem!=item){ //если итем старой команды не равен итему новой команды в параметре
        return false;
    }

    newPos=item->pos(); //меняем позицию
    setText(QObject::tr("Перемещение на %1").arg(createCommandString(myItem,newPos)));

    return true;
}


DeleteCommand::DeleteCommand(SchemaScene *scene, QUndoCommand *parent)
:QUndoCommand(parent)
{
    myScene=scene;
    QList<QGraphicsItem *> list = myScene->selectedItems();
    list.first()->setSelected(false); //инициализируем delete команду левым элементом
    myItem=static_cast<SchemaItem *>(list.first());
    setText(QObject::tr("Удаление %1").arg(createCommandString(myItem,myItem->pos())));
}

void DeleteCommand::undo()
{
    myScene->addItem(myItem); //Добавляем обратно и обновляем
    myScene->update();
}

void DeleteCommand::redo()
{
    myScene->removeItem(myItem); //удаляем со сцены
}

AddCommand::AddCommand(SchemaItem *item, SchemaScene *scene, QUndoCommand *parent)
{
    myScene=scene;
    myItem=item;
    initialPos=item->pos();
    setText(QObject::tr("Добавление на %1").arg(createCommandString(myItem,initialPos)));
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
