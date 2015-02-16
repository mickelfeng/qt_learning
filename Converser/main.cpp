#include <QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setWindowTitle(QObject::trUtf8("转换器"));
    w.show();
    
    return a.exec();
}
