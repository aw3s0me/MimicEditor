#ifndef SCHEMAARROWITEM_H
#define SCHEMAARROWITEM_H

#include <QGraphicsLineItem>
#include "schemaitem.h"

QT_BEGIN_NAMESPACE
class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;
QT_END_NAMESPACE


class SchemaArrowItem : public QGraphicsLineItem {
public:
    SchemaArrowItem();
    void updatePosition();

protected:
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

private:
    SchemaItem *myStartItem;
    SchemaItem *myEndItem;
    QPolygonF arrowHead;
};

#endif // SCHEMAARROWITEM_H
