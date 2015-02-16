#ifndef H_IO_H
#define H_IO_H
#include <QTextStream>


namespace IO{
    static QTextStream cout(stdout, QIODevice::WriteOnly);
    static QTextStream cin(stdin,QIODevice::ReadOnly);

    void getString(QString* _out_str);
}




#endif // H_IO_H
