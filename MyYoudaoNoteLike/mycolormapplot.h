#ifndef MYCOLORMAPPLOT_H
#define MYCOLORMAPPLOT_H

#include "qcustomplot.h"

#include <QObject>

class MyColorMapPlot : public QCustomPlot
{
    Q_OBJECT
public:
    explicit MyColorMapPlot(QCustomPlot *parent = 0);

signals:

public slots:

};

#endif // MYCOLORMAPPLOT_H
