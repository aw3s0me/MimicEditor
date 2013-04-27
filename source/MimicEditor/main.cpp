#include <QApplication>
#include "mainwindow.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    //Q_INIT_RESOURCE(MimicEditor);
   QTextCodec *codec = QTextCodec::codecForName("windows-1251");
   QTextCodec *codecForTr = QTextCodec::codecForName("utf-8");
   //QTextCodec *codec = QTextCodec::codecForName("KOI8-R");
   QTextCodec::setCodecForTr(codecForTr);
   QTextCodec::setCodecForCStrings(codec);
   QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
