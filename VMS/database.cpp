#include "database.h"

DataBase::DataBase()
{
}
bool DataBase::openDataBase(const QString &name, const QString &type, const QString &connectionName)
{
    db = QSqlDatabase::addDatabase(type,connectionName);
    db.setDatabaseName(name);
    if(!db.open())
    {
        return false;
    }
    else
    {
        return true;
    }
}
void DataBase::createTable()
{
    //无数据库文件，创建默认数据的数据库文件
    QSqlQuery query; //if not exists
    query.exec("CREATE TABLE IF NOT EXISTS account(user char(10) UNIQUE NOT NULL, password char(16) NOT NULL)");
    query.exec("INSERT INTO account VALUES('root', '1234567890')"); //bad 创建有问题
    query.exec("CREATE TABLE IF NOT EXISTS farmer(fname VARCHAR(10) NOT NULL, fid INTERGER PRIMARY KEY, fsex VARCHAR(1), ftel CHAR(15), faddress VARCHAR)"); //farmer Table
    query.exec("CREATE TABLE IF NOT EXISTS purchase(pid CHAR(20) PRIMARY KEY, pfid INTERGER, pkind VARCHAR, pprice DOUBLE, pweight INTEGER, ptime DATETIME)");
}

void DataBase::closeDataBase()
{
    db.close();
}
