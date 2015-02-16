#ifndef PAINTERDIALOG_H
#define PAINTERDIALOG_H

#include <QDialog>

namespace Ui {
class PainterDialog;
}

class PainterDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PainterDialog(QWidget *parent = 0);
    ~PainterDialog();

protected:
   virtual void paintEvent(QPaintEvent *);
    
private:
    Ui::PainterDialog *ui;
};

#endif // PAINTERDIALOG_H
