#ifndef TESTADJUST_H
#define TESTADJUST_H

#include <QWidget>

namespace Ui {
class TestAdjust;
}

class TestAdjust : public QWidget
{
    Q_OBJECT

public:
    explicit TestAdjust(QWidget *parent = 0);
    ~TestAdjust();

private:
    Ui::TestAdjust *ui;
};

#endif // TESTADJUST_H
