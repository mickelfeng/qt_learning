/*************************************************
Author:Micooz
Date:2013-10-23
Description:ini配置读写实现
**************************************************/
#include "CConfig.h"

CConfig::CConfig(const QString &app, const QString &ini_file_name)
{
    setNode(app);
    m_s = new QSettings(ini_file_name,QSettings::IniFormat);
}

void CConfig::write(const QString& key,const QVariant& var)
{
    m_s->setValue(m_current_node + "/" + key ,var);
}
void CConfig::write(const char* key,const QVariant& var)
{
    m_s->setValue(QString(m_current_node) + "/" + key ,var);
}

QVariant CConfig::read(const QString& key)
{
    return m_s->value(m_current_node + "/" + key,0);
}
QVariant CConfig::read(const char* key)
{
    return m_s->value(QString(m_current_node) + "/" + key,0);
}

void CConfig::setNode(const QString& node)
{
    m_current_node = node;
}

void CConfig::setNode(const char* node)
{
    m_current_node = QString(node);
}

void CConfig::Clear()
{
    m_s->clear();
}

CConfig::~CConfig()
{
    delete m_s;
}
