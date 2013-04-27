#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsItem>
#include <QList>
#include <QPainter>
#include <QFileDialog>
#include <QDebug>
#include <QMetaEnum>
#include <QMenu>
#include <QtGui>
#include <QtCore>

//
class SchemaScene;

QT_BEGIN_NAMESPACE
class QImage;
class QGraphicsItem;
class QGraphicsScene;
class QTextEdit;
class QGraphicsSceneMouseEvent;
class QMenu;
class QGraphicsSceneContextMenuEvent;
class QStyleOptionGraphicsItem;
class QWidget;
QT_END_NAMESPACE

class SchemaArrowItem;

class SchemaItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    enum { Type = UserType + 15 };

    enum ItemType { Filter, Transformator, Amplifier, Fourth };

    Q_ENUMS(ItemType)

   // SchemaItem();

    //SchemaItem(const QPixmap & pixmap);

    SchemaItem(ItemType itemtype, QMenu *contextMenu, QGraphicsItem *parent=0 /*, QGraphicsScene *scene = 0*/);

    void addArrow(SchemaArrowItem *arrow);
    void removeArrow(SchemaArrowItem *arrow);
    void removeArrows();


    ItemType itemType() const{
        return myItemType;
    }



    int type() const{
        return Type;
    }

    //QImage image() const;

    QRectF boundingRect() const;
    QString myTypeToString();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRect BoundingBox;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
private:
    ItemType myItemType;
    QMenu *myContextMenu;
    QList<SchemaArrowItem*> arrows;
};

#endif // ITEM_H
