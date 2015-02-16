#ifndef MYREALTIMEPLOT_H
#define MYREALTIMEPLOT_H

#include <QObject>
#include "qcustomplot.h"

class MyRealTimePlot :public QCustomPlot
{
    Q_OBJECT
public:
    explicit MyRealTimePlot(QCustomPlot *parent = 0);

signals:

public slots:
    void realtimeDataSlot();
private:
    QTimer dataTimer;
};

#endif // MYREALTIMEPLOT_H
