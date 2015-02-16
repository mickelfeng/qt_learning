#ifndef CRALWER_H
#define CRALWER_H

#include <QMainWindow>

namespace Ui {
class Cralwer;
}

class Cralwer : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Cralwer(QWidget *parent = 0);
    ~Cralwer();
    
private:
    Ui::Cralwer *ui;
};

#endif // CRALWER_H
