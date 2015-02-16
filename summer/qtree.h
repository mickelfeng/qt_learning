#ifndef QTREE_H
#define QTREE_H

#include <QtGui>
#include <QtCore>
#include <Qt>
#include <QTreeView>
#include <QApplication>
#include <QFileSystemModel>
#include <QList>
#include <QDirModel>

class QTree:public QTreeView
{
    Q_OBJECT
public:
    QTree(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);

private:
    QPoint startPos;
};

#endif // QTREE_H
