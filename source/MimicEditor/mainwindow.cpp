#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scene.h"
#include "item.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        //connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
        //connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
        Scene *s = new Scene();
        ui->graphicsView->setScene(s);

        Item *item = new Item(QBitmap("pic.png"));
        s->addItem(item);

    }

MainWindow::~MainWindow()
{
    delete ui;
}
