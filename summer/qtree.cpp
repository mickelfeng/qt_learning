#include "qtree.h"
#include "mainwindow.h"

extern QString selectedFile;
extern QString destFold;

QTree::QTree(QWidget *parent) : QTreeView(parent)
{
    setAcceptDrops(true);
}

void QTree::mousePressEvent(QMouseEvent *event)
{
    if(event->button()== Qt::LeftButton)
        startPos = event->pos();

    QTreeView::mousePressEvent(event);
}

//void QTree::mouseMoveEvent(QMouseEvent *event)
//{
//    if (event->buttons() & Qt::LeftButton) {
//        int distance = (event->pos() - startPos).manhattanLength();
//        if (distance >= QApplication::startDragDistance())
//            performDrag();
//    }
//    QTreeView::mouseMoveEvent(event);
//}

void QTree::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<"dragEnterEvent"<<event->pos();
    QTree *source =
            qobject_cast<QTree *>(event->source());
    if (source && source != this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void QTree::dropEvent(QDropEvent *event)
{
    qDebug()<<"dropEvent"<<event->pos();
    QTree *source =
            qobject_cast<QTree *>(event->source());
    if (source && source != this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();

        QFileInfo info(selectedFile);
        qDebug()<<selectedFile;
        qDebug()<<destFold+"/"+info.fileName();
        QFile::copy(selectedFile,destFold+"/"+info.fileName());
    }
}

void QTree::dragMoveEvent(QDragMoveEvent *event)
{
    qDebug()<<"dragMoveEvent"<<event->pos();
    QTree *source =
            qobject_cast<QTree *>(event->source());
    if (source && source != this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}
