#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QGraphicsView>

class QGraphicsScene;
class QWheelEvent;

namespace Ui {
class ImageView;
}

class ImageView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ImageView(QWidget *parent = 0);
    ~ImageView();
protected:
    void wheelEvent(QWheelEvent *e);
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *e);
private slots:
    void  scaleView(qreal scaleFactor);
    void zoomIn();
    void zoomOut();
private:
    Ui::ImageView *ui;
    void init();
    QGraphicsScene*scence;
};

#endif // IMAGEVIEW_H
