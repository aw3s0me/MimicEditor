#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

#include "schemaitem.h"

class SchemaScene;

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
    void InitializeTabWidget();

private slots:
    void activateTab(int);
    void itemInserted(SchemaItem *item);
    //void deleteItem();
    void ButtonItemGroupClicked(int id);
    void ButtonPointerTypeGroupClicked(int id);

    void on_actionCreate_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSaveAs_triggered();

    void on_actionExit_triggered();

    void on_UndoAction_triggered();

    void on_RedoAction_triggered();

    void on_action_triggered();

    void on_actionAddFilter_triggered();

    void on_actionAddTransformator_triggered();

private:
    /////////METHODS///////////////
    ///для инициализации
    void createItemToolBar();
    void createPointerToolBar();

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
    QAction *addFilter;
    QAction *addTransformator;
    ///////////////SCENE AND VIEW, INIT FROM TABS/////////////////
    SchemaScene *cur_scene;
    QGraphicsView *cur_view;

};

#endif // MAINWINDOW_H
