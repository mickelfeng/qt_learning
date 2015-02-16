#ifndef LITTERIEM_H
#define LITTERIEM_H

#include <QWidget>

namespace Ui {
class LitterIem;
}

class LitterIem : public QWidget
{
    Q_OBJECT

public:
    explicit LitterIem(QWidget *parent = 0);
    ~LitterIem();

private:
    Ui::LitterIem *ui;
};

#endif // LITTERIEM_H
