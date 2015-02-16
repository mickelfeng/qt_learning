/***************MyThread.h******************/

#include <QtCore/QThread>
#include <QtGui/QPushButton>

class MyThread : public QThread
{
    Q_OBJECT
    public:
        MyThread(QPushButton *pb);
        ~MyThread();
        QPushButton *pb;
    protected:
        void run();
};
