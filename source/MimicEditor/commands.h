#ifndef COMMANDS_H
#define COMMANDS_H

#include <QUndoCommand>
#include <QList>
#include <QGraphicsItem>

#include "schemaitem.h"
#include "schemascene.h"

/*Три типа комманд - передвижение, добавление, удаление,
 *комманду наследуем от QUndoCommand, для того, чтобы иметь взаимодействие
 *с классом QUndoStack. Перегружаем методы undo, redo.
 */

/*MoveCommand команда имеет указатель на итем, чтобы иметь доступ к Item'y
 *А также старую и новую позицию
 */
class MoveCommand:public QUndoCommand
{
public:
    enum {Id = 1234 }; //инумератор попомщник для id()
    MoveCommand(SchemaItem *item, const QPointF &oldPos, QUndoCommand *parent=0);
    void undo();
    void redo();
    //Если две команды имеют ТОТ же id, то программа попытается только объединить их, не удалить
    bool mergeWith(const QUndoCommand *command);
    int id() const {return Id;}
private:
    SchemaItem *myItem;
    QPointF myOldPos;
    QPointF newPos;
};

//указатель на item, и указатель на сцену, чтобы взаимодействовать со сценой
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
    AddCommand(SchemaItem *item, SchemaScene *scene, QUndoCommand *parent=0);
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
