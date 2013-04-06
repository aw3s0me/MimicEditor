 #ifndef ITEM_H
#define ITEM_H

#include <QGraphicsSvgItem>
#include <QList>
#include <QPainter>
#include <QFileDialog>
#include <QSvgRenderer>
#include <QDebug>

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
class QPolygonF;
QT_END_NAMESPACE

class SchemaArrowItem;

class SchemaItem : public QGraphicsSvgItem
{
public:

    enum { Type = UserType + 15 };

    enum ItemType { Filter, Transformator, Third, Fourth };

    SchemaItem();

    //SchemaItem(const QPixmap & pixmap);

    SchemaItem(ItemType itemtype, QMenu *contextMenu, QGraphicsItem *parent=0 /*, QGraphicsScene *scene = 0*/);

    void addArrow(SchemaArrowItem *arrow);
    void removeArrow(SchemaArrowItem *arrow);
    void removeArrows();

    ItemType itemType() const{
        return myItemType;
    }

    QPolygonF polygon() const{
        return myPolygon;
    }

    int type() const{
        return Type;
    }

    //QImage image() const;

    QRectF boundingRect() const;

    //QSvgRenderer mySvgRenderer;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
    ItemType myItemType;
    QPolygonF myPolygon;
    QMenu *myContextMenu;
    QList<SchemaArrowItem*> arrows;
};

#endif // ITEM_H
