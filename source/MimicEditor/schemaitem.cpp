#include "schemaitem.h"
#include "schemascene.h"

SchemaItem::SchemaItem(ItemType itemtype, QMenu *contextMenu, QGraphicsItem *parent /*, QGraphicsScene *scene*/)
    :QGraphicsItem(parent)
{
    myItemType=itemtype;
    myContextMenu=contextMenu;
    setFlag(ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    switch (myItemType){
        case Filter:
            BoundingBox=QRect(0,0,50,50);
            break;
        case Transformator: {
            BoundingBox=QRect(0,0,50,80);
            break;
        }
        case Amplifier:
            BoundingBox=QRect(0,0,75,40);
            break;
        case Fourth:
            BoundingBox=QRect(0,0,100,100);
            break;
        default:
            BoundingBox=QRect(0,0,100,100);
            break;
    }
}

QRectF SchemaItem::boundingRect() const
{
    //return QGraphicsItem::boundingRect();
    return BoundingBox;
}

QString SchemaItem::myTypeToString()
{
    int index = this->metaObject()->indexOfEnumerator("ItemType");
    QMetaEnum metaEnum = metaObject()->enumerator(index);
    return metaEnum.valueToKey(itemType());
}

void SchemaItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::NoBrush);
    painter->setPen(Qt::darkBlue);
    switch (myItemType){
        case Filter:
            painter->drawLine(QPointF(25,0),QPointF(0,50));
            painter->drawLine(QPointF(0,50),QPointF(50,50));
            painter->drawLine(QPointF(25,0),QPointF(50,50));
            break;
        case Transformator: {
            painter->drawRect(0,0,50,75);
            painter->drawRect(10,12.5,30,40);
            break;
        }
        case Amplifier:
            painter->drawRect(0,10,10,10);
            painter->drawRect(10,0,50,30);
            painter->drawRect(60,10,10,10);
            break;
        case Fourth:
            break;
        default:
            break;
    }
    //painter->set
    //painter->drawRect(BoundingBox);
}

void SchemaItem::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    Q_CHECK_PTR(myContextMenu);
    //myContextMenu->popup(mouseEvent->screenPos());
    if (mouseEvent->button()==Qt::LeftButton){
        dynamic_cast<SchemaScene*>(this->scene())->movingItem = this;
        //setSelected(true);
    }
   /* else if (mouseEvent->button()==Qt::RightButton){
        scene()->clearSelection();
        setSelected(true);
        const QPoint point(mouseEvent->pos().x(),mouseEvent->pos().y());
        myContextMenu->exec(point);
    } */
}

void SchemaItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    scene()->clearSelection();
    //setSelected(true);
    if (this->myContextMenu)
        myContextMenu->exec(event->screenPos());
}
