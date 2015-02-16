#include "cralwer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cralwer w;
    w.show();
    
    return a.exec();
}
