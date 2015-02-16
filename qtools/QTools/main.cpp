#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec.h>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gbk"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("gbk"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gbk"));


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
