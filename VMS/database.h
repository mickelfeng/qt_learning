#ifndef DATABASE1_H
#define DATABASE1_H
#include <QSqlDatabase>
#include <QSqlQuery>
class DataBase
{
public:
    DataBase();
    bool openDataBase(const QString &name, const QString &type,
                      const QString &connectionName = "defaultConnection");

    virtual void createTable();
    void closeDataBase();

private:
    QSqlDatabase db;
};

#endif // DATABASE1_H
