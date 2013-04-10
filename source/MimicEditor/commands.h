#ifndef COMMANDS_H
#define COMMANDS_H

#include <QUndoCommand>
#include <QList>
#include <QGraphicsItem>

#include "schemaitem.h"
#include "schemascene.h"

class MoveCommand:public QUndoCommand
{
public:
    enum {Id = 1234 };
    MoveCommand(SchemaItem *item, const QPointF &oldPos, QUndoCommand *parent=0);
    void undo();
    void redo();
    bool mergeWith(const QUndoCommand *command);
    int id() const {return Id;}
private:
    SchemaItem *myItem;
    QPointF myOldPos;
    QPointF newPos;
};

class DeleteCommand : public QUndoCommand
{
public:
    DeleteCommand(SchemaScene *scene, QUndoCommand *parent=0);
    void undo();
    void redo();
private:
    SchemaItem *myItem;
    SchemaScene *myScene;
};

class AddCommand : public QUndoCommand
{
public:
    AddCommand(SchemaItem::ItemType addItemType, SchemaScene *scene, QMenu *contextMenu, QUndoCommand *parent=0);
    ~AddCommand();

    void undo();
    void redo();

private:
    SchemaItem *myItem;
    SchemaScene *myScene;
    QPointF initialPos;

};

QString createCommandString(SchemaItem *item, const QPointF &pos);

#endif // COMMANDS_H
