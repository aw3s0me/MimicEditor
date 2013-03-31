#include "schemascene.h"

SchemaScene::SchemaScene(){

}


SchemaScene::SchemaScene(QMenu *itemMenu, QObject *parent):QGraphicsScene(parent){
    myItemMenu=itemMenu;
    myMode = MoveItem;
    myItemType = SchemaItem::Filter;
    line=0;
    textItem=0;
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
    QMessageBox* msgBox;

    if(mouseEvent->button()==Qt::LeftButton)
    {
            msgBox = new QMessageBox();
            msgBox->setWindowTitle("Hello");
            msgBox->setText("You Clicked Left Mouse Button");
            //msgBox->show();
    }
    else {
        return;
    }
    SchemaItem *newItem;
    switch(myMode){
        case InsertItem:
            newItem=new SchemaItem(myItemType, myItemMenu);
            addItem(newItem);
            newItem->setPos(mouseEvent->scenePos());
            emit itemInserted(newItem);
            msgBox->show();
            break;
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
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void SchemaScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent){
    if (myMode==InsertLine && line!=0){
        QLineF newLine(line->line().p1(),mouseEvent->scenePos());
        line->setLine(newLine);
    }
    else if (myMode==MoveItem){
        QGraphicsScene::mouseMoveEvent(mouseEvent);
    }
}
