#ifndef TREEVIEWTEST_H
#define TREEVIEWTEST_H

#include <QWidget>

namespace Ui {
class TreeViewtest;
}

class TreeViewtest : public QWidget
{
    Q_OBJECT

public:
    explicit TreeViewtest(QWidget *parent = 0);
    ~TreeViewtest();
private slots:
    void onItemChange();
private:
    Ui::TreeViewtest *ui;
    QWidget floatWidget;
};

#endif // TREEVIEWTEST_H
