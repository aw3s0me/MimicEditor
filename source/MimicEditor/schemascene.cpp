#include "schemascene.h"

SchemaScene::SchemaScene(){

}

SchemaScene::SchemaScene(QMenu *itemMenu, QObject *parent):QGraphicsScene(parent){
    myItemMenu=itemMenu;
    movingItem=0;
    myMode = MoveItem;
    myItemType = SchemaItem::Filter;
    line=0;
    textItem=0;
    setMode(MoveItem);
}

void SchemaScene::setMode(Mode mode){
    myMode=mode;
}

void SchemaScene::setItemType(SchemaItem::ItemType type){
    myItemType=type;
}

void SchemaScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent){
    QGraphicsScene::mousePressEvent(mouseEvent);

    //QPointF mousePos(mouseEvent->buttonDownScenePos(Qt::LeftButton).x(),
     //                mouseEvent->buttonDownScenePos(Qt::LeftButton).y());
    //movingItem=itemAt(mousePos);
    qDebug()<<"moving item = " << movingItem;

    //if(ItemPressed) {
    //    qDebug()<<"itempressed=true";

    if (movingItem!=0 && mouseEvent->button()==Qt::LeftButton) {
        qDebug() << "Click on item";
        oldPos=movingItem->pos();
        return;
    }
        //clearSelection();
    //}

    //QGraphicsScene::mousePressEvent(mouseEvent);
    if(mouseEvent->button()==Qt::LeftButton)
    {
        qDebug()<<"You Clicked Left Mouse Button on scene";
    }
    else {
        return;
    }
    SchemaItem *newItem;
    switch(getMode()){
        case InsertItem: {
            /*if(ItemPressed) {
                QPointF mousePos(mouseEvent->buttonDownScenePos(Qt::LeftButton).x(),
                                 mouseEvent->buttonDownScenePos(Qt::LeftButton).y());
                movingItem=itemAt(mousePos);
                if (movingItem!=0 && mouseEvent->button()==Qt::LeftButton) {
                    oldPos=movingItem->pos();
                }
                clearSelection();
                QGraphicsScene::mousePressEvent(mouseEvent);
                break;
            } */
            newItem=new SchemaItem(myItemType, myItemMenu);
            addItem(newItem);
            //newItem->setPos(mouseEvent->scenePos());
            newItem->setPos(mouseEvent->scenePos().x()-(newItem->boundingRect().width()/2),mouseEvent->scenePos().y()-(newItem->boundingRect().height()/2));
            emit itemInserted(newItem);
            break;
        }
        case InsertLine:
            //line=new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),mouseEvent->scenePos()));
            //addItem(line);
            break;
        case InsertText:
            //textItem=new DiagramTextItem();
            //emit textInserted(textItem);
        default:
            ;
    }
    qDebug()<<("added");
}

void SchemaScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent){
    QGraphicsScene::mouseMoveEvent(mouseEvent);

    if (myMode==InsertLine && line!=0){
        QLineF newLine(line->line().p1(),mouseEvent->scenePos());
        line->setLine(newLine);
    }
    else if (getMode()==MoveItem){
        //QGraphicsScene::mouseMoveEvent(mouseEvent);
    }
}

void SchemaScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
    if (movingItem!=0 && mouseEvent->button() == Qt::LeftButton){
        //if (oldPos!=movingItem->pos()) {
            qDebug()<<"moving has emitted";
            emit itemMoved(qgraphicsitem_cast<SchemaItem *>(movingItem), oldPos);
        //}
        //movingItem=0;
    }
    movingItem=0;
    //ItemPressed = false;
}
