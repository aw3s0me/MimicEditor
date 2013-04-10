#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "schemascene.h"
#include "schemaitem.h"
#include "commands.h"
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
        undoStack = new QUndoStack(this);
        createUndoView();
        this->setWindowTitle(tr("Редактор мнемосхем"));
        InitializeTabWidget();
        buttonItemGroup=initializeButtonGroup();
        //connect(buttonItemGroup,SIGNAL(buttonClicked(int)),this, SLOT(ButtonItemGroupClicked(int)));
        connect(buttonItemGroup,SIGNAL(buttonPressed(int)),this, SLOT(ButtonItemGroupPressed(int)));
        connect(buttonItemGroup,SIGNAL(buttonClicked(int)),this, SLOT(ButtonItemGroupClicked(int)));
        //connect(buttonItemGroup,SIGNAL(buttonReleased(int)),this,SLOT(ButtonItemGroupReleased(int)));
        buttonPointerTypeGroup=initializeButtonPointerTypeGroup();
        connect(buttonPointerTypeGroup,SIGNAL(buttonClicked(int)),this,SLOT(ButtonPointerTypeGroupClicked(int)));
        createActions();
        InitializeCommandPanel();
        InitializeMenuBar();
        createItemToolBar();
        createPointerToolBar();
        connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(activateTab(int)));
        connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(closingTab(int)));
        UncheckAll = false;
    }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::itemMoved(SchemaItem *movedItem, const QPointF &StartPosition)
{
    undoStack->push(new MoveCommand(movedItem, StartPosition));
}

void MainWindow::InitializeTabWidget(){
    itemMenu=menuBar()->addMenu(tr("&Item"));
    SchemaScene *s = new SchemaScene(itemMenu, this);
    cur_scene=s;
    s->setSceneRect(0,0,1000,500);
    connect(s,SIGNAL(itemInserted(SchemaItem*)),this,SLOT(itemInserted(SchemaItem*)));
    connect(s, SIGNAL(itemMoved(SchemaItem*,QPointF)), this, SLOT(itemMoved(SchemaItem*,QPointF)));
    SchemaView *maingrview=new SchemaView;
    maingrview->scrollBarWidgets(Qt::AlignRight|Qt::AlignBottom);
    //connect(maingrview,SIGNAL())
    cur_view=maingrview;
    cur_mode=s->getMode();
    maingrview->setScene(s);
    ui->tabWidget->setMovable(true);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->setTabsClosable(true);
    ui->tabWidget->addTab(maingrview,"Схема "+QString::number(ui->tabWidget->count()+1));
    ui->tabWidget->show();
}

void MainWindow::InitializeCommandPanel()
{
    //создаем тулбар
        QToolBar *CommandPanel=new QToolBar("Панель команд",this);

        CommandPanel->activateWindow();
        CommandPanel->setFloatable(true);
        CommandPanel->show();
        //добавляем тулбар в свободную часть
        this->addToolBar(Qt::TopToolBarArea, CommandPanel);
        CommandPanel->addAction(CreateAction);
        CommandPanel->addAction(OpenAction);
        CommandPanel->addAction(SaveAction);
        CommandPanel->addAction(SaveAsAction);
        CommandPanel->addAction(ExitAction);
        CommandPanel->addSeparator();
        CommandPanel->addAction(UndoAction);
        CommandPanel->addAction(RedoAction);

}

void MainWindow::InitializeMenuBar()
{
    ui->FileMenu->addAction(CreateAction);
    ui->FileMenu->addAction(OpenAction);
    ui->FileMenu->addAction(SaveAction);
    ui->FileMenu->addAction(SaveAsAction);
    ui->FileMenu->addAction(ExitAction);
    ui->EditMenu->addAction(UndoAction);
    ui->EditMenu->addAction(RedoAction);
}

void MainWindow::activateTab(int index)
{
    qDebug()<<"Selected Tab Index is: "+QString::number(index);

    if (!(cur_view=qobject_cast<QGraphicsView *>(ui->tabWidget->widget(index)))){
        return;
    }
    else {
        if(!(cur_scene=qobject_cast<SchemaScene *>(cur_view->scene()))){
            return;
        }
        else {
            cur_scene->setMode(cur_mode);
            cur_scene->setItemType(cur_item);
            qDebug("set to cur_mode");
        }
    }

}

void MainWindow::itemInserted(SchemaItem *item)
{
    if(cur_scene){
        buttonPointerTypeGroup->button(int(SchemaScene::MoveItem))->setChecked(true);
        //cur_scene->setMode(SchemaScene::Mode(buttonPointerTypeGroup->checkedId()));
        buttonItemGroup->button(int(item->itemType()))->setChecked(false);
    }
    else {
        qDebug("ItemInsError");
        return;
    }
}

void MainWindow::ButtonItemGroupPressed(int id)
{

    qDebug()<<"You Clicked Button with "+QString::number(id)+" "+QString::number(int(SchemaItem::ItemType(id)));
    qDebug()<<"Pressed Button with "+QString::number(buttonItemGroup->checkedId())+" "+QString::number(int(SchemaItem::ItemType(id)));

    QAbstractButton *checkedById=buttonItemGroup->button(id);
    QAbstractButton *checkedByMethod=buttonItemGroup->checkedButton();


    if(checkedById==checkedByMethod/*&&cur_scene->getMode()!=SchemaScene::MoveItem*/){
        UncheckAll = true;
        //checkedById->setChecked(false);
        //buttonItemGroup->setId(-1);
        //buttonItemGroup->setExclusive(false);
        //checkedById->setChecked(false);
        //buttonItemGroup->blockSignals(true);
        //checkedByMethod->setChecked(true);
        //buttonItemGroup->setExclusive(true);
        cur_scene->setMode(SchemaScene::MoveItem);
        cur_mode=SchemaScene::MoveItem;
        qDebug("Unchecked");
        return;
    }
//    checkedById->setChecked(true);
//    checkedByMethod->setChecked(false);

    qDebug()<<"You Clicked Button with "+QString::number(id)+" "+QString::number(int(SchemaItem::ItemType(id)));
    /*if (id==InsertTextButton){

    }
    else { */
    if (ui->tabWidget->currentIndex()==-1){

        return;
    }
    else{
        if(cur_scene){
            cur_scene->setMode(SchemaScene::InsertItem);
            cur_mode=SchemaScene::InsertItem;
            cur_scene->setItemType(SchemaItem::ItemType(id));
            cur_item=SchemaItem::ItemType(id);
        }
        else {
            qDebug("butt_clickERROR");
            return;
        }
    }
}

void MainWindow::ButtonItemGroupClicked(int id)
{
    if (UncheckAll)
    {
        buttonItemGroup->setExclusive(false);
        QAbstractButton *checkedById=buttonItemGroup->button(id);
        checkedById->setChecked(false);
        buttonItemGroup->setExclusive(true);
        UncheckAll = false;
    }
}

void MainWindow::ButtonPointerTypeGroupClicked(int id)
{
    qDebug()<<"You Clicked Button with "+QString::number(id);
    if (ui->tabWidget->currentIndex()==-1){
        return;
    }
    else{
        if(cur_scene){
            cur_scene->setMode(SchemaScene::Mode(buttonPointerTypeGroup->checkedId()));
        }
        else {
            qDebug("point_clickERROR");
            return;
        }
    }
}
/*
void MainWindow::ButtonItemGroupReleased(int id)
{
    QAbstractButton *releasedButton=buttonItemGroup->button(id);
}
*/
void MainWindow::on_actionCreate_triggered()
{
    SchemaScene *newScene = new SchemaScene(itemMenu, this);
    connect(newScene, SIGNAL(itemMoved(SchemaItem*,QPointF)), this, SLOT(itemMoved(SchemaItem*,QPointF)));
    newScene->setSceneRect(0,0,1000,500);
    newScene->setMode(cur_mode);
    newScene->setItemType(cur_item);
    SchemaView *newGrView=new SchemaView(this);
    newGrView->scrollBarWidgets(Qt::AlignRight|Qt::AlignBottom);
    newGrView->setScene(newScene);
    ui->tabWidget->addTab(newGrView,"New Tab");
    ui->tabWidget->show();

}

void MainWindow::closingTab(int index)
{
    qDebug() << "Closing tab ?" << QString(index);
    ui->tabWidget->removeTab(index);
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

void MainWindow::on_actionUndo_triggered()
{
}

void MainWindow::on_actionRedo_triggered()
{
}

void MainWindow::createItemToolBar()
{
//создаем тулбар
    QToolBar *newItemToolBar=new QToolBar("Item Toolbar",this);
    //добавление кнопок на тулбар с помощью группы кнопок
    QList<QAbstractButton *> buttons=buttonItemGroup->buttons();
    foreach (QAbstractButton *button, buttons){
        button->setCheckable(true);
        newItemToolBar->addWidget(button);
    }
    newItemToolBar->addSeparator();
    newItemToolBar->activateWindow();
    newItemToolBar->setFloatable(true);
    newItemToolBar->show();
    //добавляем тулбар в свободную часть
    this->addToolBar(Qt::TopToolBarArea, newItemToolBar);

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

void MainWindow::createUndoView()
{
    undoView = new QUndoView(undoStack);
    undoView->setWindowTitle(tr("Command List"));
    undoView->show();
    undoView->setAttribute(Qt::WA_QuitOnClose, false);
}

void MainWindow::createActions()
{
    //Инициализируем Action'ы и коннектим к слотам
    CreateAction=new QAction(tr("Создать"), this);
    OpenAction=new QAction("Открыть", this);
    SaveAction=new QAction("Сохранить", this);
    SaveAsAction=new QAction("Сохранить как", this);
    ExitAction=new QAction("Выйти", this);
    //UndoAction=new QAction("Отменить", this);
    UndoAction = undoStack->createUndoAction(this, tr("&Undo"));
    RedoAction = undoStack->createRedoAction(this, tr("&Redo"));
    UndoAction->setShortcuts(QKeySequence::Undo);
    RedoAction->setShortcuts(QKeySequence::Redo);
    //RedoAction=new QAction("Вернуть", this);
    CreateAction->setStatusTip(tr("Создать"));
    OpenAction->setStatusTip("Открыть");
    SaveAction->setStatusTip("Сохранить");
    SaveAsAction->setStatusTip("Сохранить как");
    ExitAction->setStatusTip("Выйти");
    UndoAction->setStatusTip("Отменить");
    RedoAction->setStatusTip("Вернуть");
    connect(CreateAction,SIGNAL(triggered()),this,SLOT(on_actionCreate_triggered()));
    connect(OpenAction,SIGNAL(triggered()),this,SLOT(on_actionOpen_triggered()));
    connect(SaveAction,SIGNAL(triggered()),this,SLOT(on_actionSave_triggered()));
    connect(SaveAsAction,SIGNAL(triggered()),this,SLOT(on_actionSaveAs_triggered()));
    connect(ExitAction,SIGNAL(triggered()),this,SLOT(on_actionExit_triggered()));
    connect(UndoAction,SIGNAL(triggered()),this,SLOT(on_actionUndo_triggered()));
    connect(RedoAction,SIGNAL(triggered()),this,SLOT(on_actionRedo_triggered()));
    CreateAction->setIcon(QIcon(":/Images/Icons/new_file.ico"));
    OpenAction->setIcon(QIcon(":/Images/Icons/document_open.ico"));
    SaveAction->setIcon(QIcon(":/Images/Icons/document_save.ico"));
    SaveAsAction->setIcon(QIcon(":/Images/Icons/document_save_as.ico"));
    ExitAction->setIcon(QIcon(":/Images/Icons/exit.ico"));
    UndoAction->setIcon(QIcon(":/Images/Icons/edit_undo.ico"));
    RedoAction->setIcon(QIcon(":/Images/Icons/edit_redo.ico"));

    //QAction *addAction;
    //QAction *deleteAction;
    //QAction *toFrontAction;
    //QAction *sendBackAction;
    //QAction *aboutAction;
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
    newButtonGroup->setExclusive(true);
    //newButtonGroup->

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


