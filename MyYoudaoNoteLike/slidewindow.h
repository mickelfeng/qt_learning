#ifndef SLIDEWINDOW_H
#define SLIDEWINDOW_H

#include <QMainWindow>

namespace Ui {
class SlideWindow;
}

class SlideWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SlideWindow(QWidget *parent = 0);
    ~SlideWindow();

private:
    Ui::SlideWindow *ui;
};

#endif // SLIDEWINDOW_H
