#include "mainwindow.h"
#include <QApplication>


#include "slidewindow.h"

#include <QtSql>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SlideWindow m;

    m.show();
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("localhost");
//    db.setDatabaseName("test");
//    db.setUserName("root");
//    db.setPassword("qaz");
//    db.open();


    return a.exec();

}
