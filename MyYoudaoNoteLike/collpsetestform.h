#ifndef COLLPSETESTFORM_H
#define COLLPSETESTFORM_H

#include <QWidget>

namespace Ui {
class CollpseTestForm;
}

class CollpseTestForm : public QWidget
{
    Q_OBJECT

public:
    explicit CollpseTestForm(QWidget *parent = 0);
    ~CollpseTestForm();

private:
    Ui::CollpseTestForm *ui;
};

#endif // COLLPSETESTFORM_H
