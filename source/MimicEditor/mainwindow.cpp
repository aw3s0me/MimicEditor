#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "schemascene.h"
#include "schemaitem.h"
#include <QtCore>
#include <QtGui>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QSvgRenderer>
#include <QList>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        InitializeTabWidget();
        buttonItemGroup=initializeButtonGroup();
        connect(buttonItemGroup,SIGNAL(buttonClicked(int)),this, SLOT(ButtonItemGroupClicked(int)));
        buttonPointerTypeGroup=initializeButtonPointerTypeGroup();
        connect(buttonPointerTypeGroup,SIGNAL(buttonClicked(int)),this,SLOT(ButtonPointerTypeGroupClicked(int)));
        createActions();
        createItemToolBar();
        createPointerToolBar();
        connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(activateTab(int)));
        //connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
        //connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
        //SchemaItem *item = new SchemaItem(QBitmap("pic.png"));
        //s->addItem(item);
        //ui->toolBar->resize(ui->toolBar->minimumWidth(),ui->toolBar->sizeHint().height());
        //QGraphicsSvgItem *svgitem=new QGraphicsSvgItem("D:/bubbles.svg");
        //svgitem->setFlag(QGraphicsItem::ItemIsMovable, true);
        //s->addItem(svgitem);

    }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitializeTabWidget(){
    itemMenu=menuBar()->addMenu(tr("&Item"));
    SchemaScene *s = new SchemaScene(itemMenu, this);
    cur_scene=s;
    connect(s,SIGNAL(itemInserted(SchemaItem*)),this,SLOT(itemInserted(SchemaItem*)));
    QGraphicsView *maingrview=new QGraphicsView();
    cur_view=maingrview;
    maingrview->setScene(s);
    ui->tabWidget->setMovable(true);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(maingrview,"Schema "+QString::number(ui->tabWidget->count()+1));
    ui->tabWidget->show();
}

void MainWindow::activateTab(int index)
{
    /* ПРОВЕРКА
    QMessageBox* msgBox;
    msgBox = new QMessageBox(this);
    msgBox->setWindowTitle("Hello");
    msgBox->setText("Selected Tab Index is: "+QString::number(index));
    msgBox->show();
    */

    if (!(cur_view=qobject_cast<QGraphicsView *>(ui->tabWidget->widget(index)))){
        return;
    }
    else {
        if(!(cur_scene=qobject_cast<SchemaScene *>(cur_view->scene()))){
            return;
        }
    }

}

void MainWindow::itemInserted(SchemaItem *item)
{
    //if (cur_view){
        if(cur_scene){
            buttonPointerTypeGroup->button(int(SchemaScene::MoveItem))->setChecked(true);
            cur_scene->setMode(SchemaScene::Mode(buttonPointerTypeGroup->checkedId()));

            buttonItemGroup->button(int(item->itemType()))->setChecked(false);
        }
        else {
            qDebug("ItemInsError");
            return;
        }
   // }
   // else {
     //   qDebug("ItemInsError");
     //   return;
    //}
}

void MainWindow::ButtonItemGroupClicked(int id)
{
    QList<QAbstractButton *> buttons = buttonItemGroup->buttons();
    foreach(QAbstractButton *button, buttons){
        button->setChecked(false);
    }
    QMessageBox* msgBox;
    msgBox = new QMessageBox();
    msgBox->setWindowTitle("Hello");
    msgBox->setText("You Clicked Button with "+QString::number(id)+" "+QString::number(int(SchemaItem::ItemType(id))));
    msgBox->show();
    /*if (id==InsertTextButton){

    }
    else { */
    if (ui->tabWidget->currentIndex()==-1){

        return;
    }
    else{
        /*QWidget *currentTab=ui->tabWidget->currentWidget();
        QGraphicsView *temp_view;
        SchemaScene *temp_scene; */
        /*QMessageBox* msgBox;
        msgBox = new QMessageBox();
        msgBox->setWindowTitle("Hello");
        msgBox->setText(currentTab->metaObject()->className());
        msgBox->show(); */
        //if (cur_view){
            if(cur_scene){
                    cur_scene->setMode(SchemaScene::InsertItem);
                    cur_scene->setItemType(SchemaItem::ItemType(id));
            }
            else {
                qDebug("butt_clickERROR");
                return;
            }
        //}
        //else {
          //  qDebug("butt_clickERROR");
          //  return;
        //}
    }
}

void MainWindow::ButtonPointerTypeGroupClicked(int id)
{
    QMessageBox* msgBox;
    msgBox = new QMessageBox();
    msgBox->setWindowTitle("Hello");
    msgBox->setText("You Clicked Button with "+QString::number(id));
    msgBox->show();
    if (ui->tabWidget->currentIndex()==-1){
        return;
    }
    else{
        /*QWidget *currentTab=ui->tabWidget->currentWidget();
        QGraphicsView *temp_view;
        SchemaScene *temp_scene; */
        /*QMessageBox* msgBox;
        msgBox = new QMessageBox();
        msgBox->setWindowTitle("Hello");
        msgBox->setText(currentTab->metaObject()->className());
        msgBox->show(); */
        //if (temp_view=qobject_cast<QGraphicsView *>(currentTab)){
            //if(temp_scene=qobject_cast<SchemaScene *>(temp_view->scene())){
        //if (cur_view){
            if(cur_scene){
                cur_scene->setMode(SchemaScene::Mode(buttonPointerTypeGroup->checkedId()));
            }
            else {
                qDebug("point_clickERROR");
                return;
            }
        //}
        //else {
         //   qDebug("point_clickERROR");
         //  return;
        //}
    }
}

void MainWindow::on_actionCreate_triggered()
{
    SchemaScene *newScene = new SchemaScene(itemMenu, this);
    QGraphicsView *newGrView=new QGraphicsView(this);
    //SchemaItem *item = new SchemaItem(QBitmap("pic.png"));
    //newGrView->scrollBarWidgets()
    //newScene->addItem(item);
    //newScene->addRect(QRectF(0, 0, 100, 200), QPen(Qt::black), QBrush(Qt::green));
    newGrView->setScene(newScene);
    ui->tabWidget->addTab(newGrView,"New Tab");
    ui->tabWidget->show();
}

void MainWindow::on_actionOpen_triggered()
{

}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionSaveAs_triggered()
{

}

void MainWindow::on_actionExit_triggered()
{
    qApp->exit();
}

void MainWindow::on_UndoAction_triggered()
{

}

void MainWindow::on_RedoAction_triggered()
{

}

void MainWindow::on_action_triggered()
{

}

void MainWindow::on_actionAddFilter_triggered()
{
    QMessageBox* msgBox;
    msgBox = new QMessageBox();
    msgBox->setWindowTitle("Hello");
    msgBox->setText("You Clicked Add Filter");
    msgBox->show();

}

void MainWindow::on_actionAddTransformator_triggered()
{
    QMessageBox* msgBox;
    msgBox = new QMessageBox();
    msgBox->setWindowTitle("Hello");
    msgBox->setText("You Clicked Add Transformator");
    msgBox->show();
}



void MainWindow::createItemToolBar()
{
//создаем тулбар
    QToolBar *newItemToolBar=new QToolBar("Item Toolbar",this);
    //добавление кнопок на тулбар с помощью группы кнопок
    QList<QAbstractButton *> buttons=buttonItemGroup->buttons();
    foreach (QAbstractButton *button, buttons){
        newItemToolBar->addWidget(button);
    }

    //newItemToolBar->addWidget(buttonItemGroup);
    //создем и добавляем кнопочки
    //newItemToolBar->addWidget(createWidget(tr("Filter"),SchemaItem::Filter));
    //newItemToolBar->addWidget(createWidget(tr("Transformator"),SchemaItem::Transformator));
    //newItemToolBar->addSeparator();
    //newItemToolBar->addWidget(createWidget(tr("Third"),SchemaItem::Third));
    //newItemToolBar->addSeparator();
    //newItemToolBar->addWidget(createWidget("Fourth",SchemaItem::Fourth));
    newItemToolBar->addSeparator();
    newItemToolBar->activateWindow();
    newItemToolBar->setFloatable(true);
    newItemToolBar->show();
    //добавляем тулбар в свободную часть
    this->addToolBar(Qt::TopToolBarArea, newItemToolBar);

    //делаем хрень
    newItemToolBar->addAction(QBitmap(":/Images/iconexmpl.png"),"Add Filter", this, SLOT(on_actionAddFilter_triggered()));
    newItemToolBar->addAction(QBitmap(":/Images/iconexmpl.png"),"Add Transformator", this, SLOT(on_actionAddTransformator_triggered()));
}

void MainWindow::createPointerToolBar()
{
    QToolBar *newPointerToolBar=new QToolBar("Pointer Toolbar",this);
    QList<QAbstractButton *> pButtons=buttonPointerTypeGroup->buttons();
    foreach (QAbstractButton *pButton, pButtons){
        newPointerToolBar->addWidget(pButton);
    }

    this->addToolBar(Qt::TopToolBarArea, newPointerToolBar);
}

void MainWindow::createActions()
{
    //Инициализируем Action'ы и коннектим к слотам
    //QAction *addAction;
    //QAction *deleteAction;
    //QAction *toFrontAction;
    //QAction *sendBackAction;
    //QAction *aboutAction;
    addFilter=new QAction("Add Filter", this);
    addTransformator=new QAction("Add Transformator",this);
    addTransformator->setStatusTip("Add Transformator");
    addFilter->setStatusTip("Add Filter");
    //коннектим к слотам экшны
    connect(addFilter,SIGNAL(triggered()),this,SLOT(on_actionAddFilter_triggered()));
    connect(addTransformator,SIGNAL(triggered()),this,SLOT(on_actionAddTransformator_triggered()));

}

QAbstractButton *MainWindow::createWidget(const QString &text, SchemaItem::ItemType type)
{

    //SchemaItem item(type, itemMenu); //можно добавить если скимаitem будет хранить иконку, помолимся господа
    QToolButton *button=new QToolButton();
    QIcon icon(QBitmap(":/Images/iconexmpl.png"));
    button->setIcon(icon);
    //button->setGeometry(0,0,10,10);
    button->setText(text);
    button->setToolTip(text);
    button->setCheckable(true);

    return button;
}

QButtonGroup *MainWindow::initializeButtonGroup()
{
    QButtonGroup *newButtonGroup=new QButtonGroup(this);
    newButtonGroup->addButton(createWidget(tr("Filter"),SchemaItem::Filter),int(SchemaItem::Filter));
    newButtonGroup->addButton(createWidget(tr("Transformator"),SchemaItem::Transformator),int(SchemaItem::Transformator));
    newButtonGroup->addButton(createWidget(tr("Third"),SchemaItem::Third),int(SchemaItem::Third));
    newButtonGroup->addButton(createWidget("Fourth",SchemaItem::Fourth),int(SchemaItem::Fourth));

    return newButtonGroup;
}

QButtonGroup *MainWindow::initializeButtonPointerTypeGroup()
{
    QButtonGroup *newButtonPointerGroup=new QButtonGroup(this);
    QToolButton *pointerButton = new QToolButton;
    pointerButton->setCheckable(true);
    pointerButton->setChecked(true);
    pointerButton->setIcon(QBitmap(":/Images/pointer.png"));
    newButtonPointerGroup->addButton(pointerButton,int(SchemaScene::MoveItem));
    QToolButton *linePointerButton=new QToolButton;
    linePointerButton->setCheckable(true);
    linePointerButton->setIcon(QBitmap(":/Images/linepointer.png"));
    newButtonPointerGroup->addButton(linePointerButton,SchemaScene::InsertLine);
    return newButtonPointerGroup;
}
