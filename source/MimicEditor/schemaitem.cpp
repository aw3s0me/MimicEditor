#include "schemaitem.h"

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
}

void SchemaItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsSvgItem::paint(painter, option, widget);
}
