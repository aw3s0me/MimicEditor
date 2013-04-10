#include "schemaitem.h"
#include "schemascene.h"

//SchemaItem::SchemaItem(const QPixmap & pixmap): QGraphicsPixmapItem(pixmap) {}

SchemaItem::SchemaItem(ItemType itemtype, QMenu *contextMenu, QGraphicsItem *parent /*, QGraphicsScene *scene*/)
    :QGraphicsSvgItem(parent)
{

    myItemType=itemtype;
    myContextMenu=contextMenu;

    switch (myItemType){
        case Filter:

            break;
    case Transformator: {
            QString filename=":/Images/temp.svg";
            renderer()->load(filename);
            setFlag(ItemIsMovable);
            break;
        }
        case Third:
            break;
        case Fourth:
            break;
        default:
            break;
    }


}


SchemaItem::SchemaItem() : QGraphicsSvgItem(){

}



QRectF SchemaItem::boundingRect() const
{
    return QRectF(0,0,100,100);
    //return QRectF(0,0,50,50);
}

QString SchemaItem::myTypeToString()
{
    int index = metaObject()->indexOfEnumerator("ItemType");
    QMetaEnum metaEnum = metaObject()->enumerator(index);
    return metaEnum.valueToKey(itemType());
}

void SchemaItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsSvgItem::paint(painter, option, widget);
}

void SchemaItem::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
   // qDebug() << "Click on item";
        //dynamic_cast<SchemaScene*>(this->scene())->ItemPressed = true;
        dynamic_cast<SchemaScene*>(this->scene())->movingItem = this;
}
