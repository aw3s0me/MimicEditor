#include "schemaview.h"
#include <qmath.h>

SchemaView::SchemaView(QWidget *parent) :
    QGraphicsView(parent)
{
    setMinimumSize(500,250);
    //scale(qreal(0.8),qreal(0.8));
}

void SchemaView::scaleView(qreal scaleFactor)
{
    //qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0,0,1,1)).width();
    //if (factor <0.07 || factor >100)
        //return;
    scale(scaleFactor,scaleFactor);
}

void SchemaView::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2,-event->delta()/240.0));
}
