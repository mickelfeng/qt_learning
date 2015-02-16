#include "config.h"

Config::Config(QObject *parent) :
    QObject(parent)
{
    set=new QSettings("config.ini", QSettings::IniFormat);
}
/**
 * @brief 获取配置
 * @param key 配置名
 * @param group 配置分组 默认connect
 * @return
 */
QString Config::getValue(QString key,QString group)
{
    QString temp=group+"/"+key;
    QString result;
    result=set->value(temp).toString();
    return result;
}

void Config::setValue(QString key, QString value, QString group)
{
    set->beginGroup(group);
    set->setValue(key,value);
    set->endGroup();
}
