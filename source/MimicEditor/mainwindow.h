#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QDebug>


#include "schemaitem.h"
#include "schemascene.h"
#include "schemaview.h"

QT_BEGIN_NAMESPACE
class QToolButton;
class QButtonGroup;
class QAction;
QT_END_NAMESPACE


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void activateTab(int);
    void closingTab(int);
    void itemInserted(SchemaItem *item);
    //void deleteItem();
    void ButtonItemGroupClicked(int id);
    void ButtonPointerTypeGroupClicked(int id);
    //void ButtonItemGroupReleased(int id);
    void on_actionCreate_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionExit_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();


private:
    /////////METHODS///////////////
    ///для инициализации
    void createItemToolBar();
    void createPointerToolBar();
    void InitializeTabWidget();
    void InitializeCommandPanel();
    void InitializeMenuBar();

    void createActions();
    ///для инициализации виджета
    QAbstractButton *createWidget(const QString &text, SchemaItem::ItemType type);
    QButtonGroup *initializeButtonGroup();
    QButtonGroup *initializeButtonPointerTypeGroup();
    ////////MENUS//////////////////
    QMenu *itemMenu;
    ///////////////////////////////
    Ui::MainWindow *ui;
    int i;
    ////////////////////////////////
    QButtonGroup *buttonItemGroup; //группа наших кнопок
    QButtonGroup *buttonPointerTypeGroup;
    ////////////////////////////////
    QAction *addAction;
    QAction *deleteAction;
    QAction *toFrontAction;
    QAction *sendBackAction;
    QAction *aboutAction;
    //Панель команд
    QAction *CreateAction;
    QAction *OpenAction;
    QAction *SaveAction;
    QAction *SaveAsAction;
    QAction *ExitAction;
    QAction *UndoAction;
    QAction *RedoAction;

    ///////////////SCENE AND VIEW, INIT FROM TABS/////////////////
    SchemaScene *cur_scene;
    SchemaScene::Mode cur_mode;
    SchemaItem::ItemType cur_item;
    QGraphicsView *cur_view;

};

#endif // MAINWINDOW_H
