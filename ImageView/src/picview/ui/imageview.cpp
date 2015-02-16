#include "imageview.h"
#include "ui_imageview.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QWheelEvent>
#include <QDebug>

ImageView::ImageView(QWidget *parent) :
    QGraphicsView(parent),
    ui(new Ui::ImageView)
{
    ui->setupUi(this);

    init();

    QPixmap map("E://m2.png");

    for (int i = 0; i < 10; ++i) {

        QGraphicsPixmapItem*item=new QGraphicsPixmapItem(map);

        item->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
        item->setZValue(-1);
        //允许选择、发送状态改变事件、能够移动
        item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges | QGraphicsItem::ItemIsMovable);

        scence->addItem(item);
    }

}

ImageView::~ImageView()
{
    delete ui;
}

void ImageView::wheelEvent(QWheelEvent *e)
{

    if (e->modifiers() & Qt::ControlModifier) {
        if (e->delta() > 0){
            zoomIn();
        }
        else{
            zoomOut();
        }
        e->accept();
    } else {
        QGraphicsView::wheelEvent(e);
    }

}

void ImageView::enterEvent(QEvent *e)
{
    qDebug()<<"in";

    QGraphicsView::enterEvent(e);
}

void ImageView::leaveEvent(QEvent *e)
{
    qDebug()<<"out";
    QGraphicsView::enterEvent(e);
}

void ImageView::mousePressEvent(QMouseEvent *e)
{
    qDebug()<<"press";

    QGraphicsView::mousePressEvent(e);
    if(e->button()==Qt::LeftButton){
        zoomIn();
    }else{
        zoomOut();
    }
}

void ImageView::scaleView(qreal scaleFactor)
{

    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);

}

void ImageView::zoomIn()
{
    scaleView(qreal(1.2));
}

void ImageView::zoomOut()
{
    scaleView(1 / qreal(1.2));
}

void ImageView::init()
{
    //缓存背景模式，提高绘制效率，防止闪屏
    setCacheMode(CacheBackground);

    setViewportUpdateMode(BoundingRectViewportUpdate);

    //设置抗锯齿，平滑图像或字体边缘
    setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing|QPainter::SmoothPixmapTransform);

    //允许节点位置动态调整
    setTransformationAnchor(AnchorUnderMouse);

    //允许上下文菜单
    setContextMenuPolicy(Qt::ActionsContextMenu);

    //允许拖拽滚屏
    setDragMode( QGraphicsView::RubberBandDrag);



    scence=new QGraphicsScene(this);

    scence->setBackgroundBrush(QBrush(Qt::black));

    // scence->setItemIndexMethod(QGraphicsScene::NoIndex);

    this->setStyleSheet("border:1px solid red");


}
