/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 6. Apr 18:40:00 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCreateItemToolbar;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menuBar;
    QMenu *FileMenu;
    QMenu *EditMenu;
    QMenu *ViewMenu;
    QMenu *menu;
    QMenu *HelpMenu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(650, 413);
        actionCreateItemToolbar = new QAction(MainWindow);
        actionCreateItemToolbar->setObjectName(QString::fromUtf8("actionCreateItemToolbar"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget->addTab(tab, QString());

        horizontalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 650, 26));
        FileMenu = new QMenu(menuBar);
        FileMenu->setObjectName(QString::fromUtf8("FileMenu"));
        EditMenu = new QMenu(menuBar);
        EditMenu->setObjectName(QString::fromUtf8("EditMenu"));
        ViewMenu = new QMenu(menuBar);
        ViewMenu->setObjectName(QString::fromUtf8("ViewMenu"));
        menu = new QMenu(ViewMenu);
        menu->setObjectName(QString::fromUtf8("menu"));
        HelpMenu = new QMenu(menuBar);
        HelpMenu->setObjectName(QString::fromUtf8("HelpMenu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(FileMenu->menuAction());
        menuBar->addAction(EditMenu->menuAction());
        menuBar->addAction(ViewMenu->menuAction());
        menuBar->addAction(HelpMenu->menuAction());
        ViewMenu->addAction(menu->menuAction());
        menu->addAction(actionCreateItemToolbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionCreateItemToolbar->setText(QApplication::translate("MainWindow", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\237\321\200\320\270\320\261\320\276\321\200\320\276\320\262", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCreateItemToolbar->setToolTip(QApplication::translate("MainWindow", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\237\321\200\320\270\320\261\320\276\321\200\320\276\320\262", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0, QApplication::UnicodeUTF8));
        FileMenu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        EditMenu->setTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        ViewMenu->setTitle(QApplication::translate("MainWindow", "\320\222\320\270\320\264", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\230\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\321\213", 0, QApplication::UnicodeUTF8));
        HelpMenu->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
