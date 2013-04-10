#include <QApplication>
#include "mainwindow.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
   QTextCodec *utfcodec = QTextCodec::codecForName("Unicode");
   QTextCodec::setCodecForTr(utfcodec);
   QTextCodec::setCodecForCStrings(utfcodec);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
