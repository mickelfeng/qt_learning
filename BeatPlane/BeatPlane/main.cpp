#include <QApplication>
#include <QTextCodec>
#include <QMessageBox>
#include "MainRender.h"

MainRender *myRender;

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    myRender = new MainRender;

    myRender->show();

    return a.exec();
}
