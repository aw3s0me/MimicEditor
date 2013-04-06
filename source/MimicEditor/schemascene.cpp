#include "schemascene.h"

SchemaScene::SchemaScene(){

}

SchemaScene::SchemaScene(QMenu *itemMenu, QObject *parent):QGraphicsScene(parent){
    myItemMenu=itemMenu;
    myMode = MoveItem;
    myItemType = SchemaItem::Filter;
    line=0;
    textItem=0;
    ItemPressed = false;
    setMode(MoveItem);
}

void SchemaScene::setMode(Mode mode){
    myMode=mode;
}

void SchemaScene::setItemType(SchemaItem::ItemType type){
    myItemType=type;
}

/*void SchemaScene::itemInserted(SchemaItem *item)
{

} */

void SchemaScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent){
    QGraphicsScene::mousePressEvent(mouseEvent);
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
            if(ItemPressed) break;
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
    qDebug()<<("oollo");
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
    ItemPressed = false;
}
