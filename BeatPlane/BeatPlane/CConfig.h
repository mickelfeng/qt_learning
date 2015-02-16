#ifndef CCONFIG_H
#define CCONFIG_H

#include <QSettings>

class CConfig
{
public:
    CConfig(const QString&app,const QString& ini_file_name);
    ~CConfig();
    void write(const QString &key, const QVariant &var);
    void write(const char *key, const QVariant &var);
    QVariant read(const QString& key);
    QVariant read(const char* key);
    void setNode(const QString& node);
    void setNode(const char* node);
    void Clear();
private:
    QSettings *m_s;
    QString m_current_node;
};

#endif // CCONFIG_H
