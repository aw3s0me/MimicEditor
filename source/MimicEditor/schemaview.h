#ifndef SCHEMAVIEW_H
#define SCHEMAVIEW_H

#include <QGraphicsView>
#include <QtGui>
#include <QWheelEvent>

class SchemaView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SchemaView(QWidget *parent = 0);
protected:
    void scaleView(qreal scaleFactor);
    void wheelEvent(QWheelEvent *event);
signals:
    
public slots:
    
};

#endif // SCHEMAVIEW_H
