#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include "schemaitem.h"
#include "schematextitem.h"
#include <QMessageBox>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class SchemaItem;

QT_BEGIN_NAMESPACE
//class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
QT_END_NAMESPACE

class SchemaScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum Mode { InsertItem, InsertLine, InsertText, MoveItem };
    SchemaScene(QMenu *itemMenu, QObject *parent = 0);
    SchemaScene();
    Mode getMode(){
        return myMode;
    }
    //bool ItemPressed;
    QGraphicsItem *movingItem;

    //SchemaScene(QObject *parent=0);
    
public slots:
    void setMode(Mode mode);
    void setItemType(SchemaItem::ItemType type);

    //void editorLostFocus(SchemaTextItem *item);

signals:
    void itemInserted(SchemaItem *item);
    void textInserted(QGraphicsTextItem *item);
    void itemSelected(QGraphicsItem *item);
    void itemMoved(SchemaItem *movedItem, const QPointF &movedFromPosition);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
    bool isItemChange(int type);
    SchemaItem::ItemType myItemType;
    QMenu *myItemMenu;

    Mode myMode;
    bool leftButtonDown;
    QPointF startPoint;
    QPointF oldPos;
    QGraphicsLineItem *line;
    QFont myFont;
    SchemaTextItem *textItem;
    
};

#endif // SCENE_H
