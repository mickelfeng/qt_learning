#include <QtGui>

class MyDialog : public QWidget
{
    Q_OBJECT
public:
    MyDialog(QWidget *parent = 0);
public slots:
    void makeDrag();
protected:
    void dropEvent(QDropEvent *de);
    void dragMoveEvent(QDragMoveEvent *de);
    void dragEnterEvent(QDragEnterEvent *event);
};

class MyGroupBox : public QGroupBox
{
public:
    MyGroupBox(QWidget *parent = 0) : QGroupBox("GroupBox", parent) {};
protected:
    void dropEvent(QDropEvent *de);
    void dragMoveEvent(QDragMoveEvent *de);
    void dragEnterEvent(QDragEnterEvent *event);
};


MyDialog::MyDialog(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    QPushButton *pushButton = new QPushButton("Click Me", this);
    layout->addWidget(pushButton);
    connect(pushButton, SIGNAL(pressed()), this, SLOT(makeDrag()));
    MyGroupBox *box = new MyGroupBox(this);
    layout->addWidget(box);
    // Allow media to be dropped on the widget
    setAcceptDrops(true);
    box->setAcceptDrops(true);
}

void MyDialog::makeDrag()
{
    QDrag *dr = new QDrag(this);
    // The data to be transferred by the drag and drop operation is contained in a QMimeData object
    QMimeData *data = new QMimeData;
    data->setText("This is a test");
    // Assign ownership of the QMimeData object to the QDrag object.
    dr->setMimeData(data);
    // Start the drag and drop operation
    dr->start();
}

void MyDialog::dragMoveEvent(QDragMoveEvent *de)
{
    // The event needs to be accepted here
    de->accept();
}

void MyDialog::dragEnterEvent(QDragEnterEvent *event)
{
    // Set the drop action to be the proposed action.
    event->acceptProposedAction();
}

void MyDialog::dropEvent(QDropEvent *de)
{
    // Unpack dropped data and handle it the way you want
    qDebug("Contents: %s", de->mimeData()->text().toLatin1().data());
}

void MyGroupBox::dropEvent(QDropEvent *de)
{
    // Unpack dropped data and handle it the way you want
    qDebug("Contents: %s", de->mimeData()->text().toLatin1().data());
}

void MyGroupBox::dragMoveEvent(QDragMoveEvent *de)
{
    // The event needs to be accepted here
    de->accept();
}

void MyGroupBox::dragEnterEvent(QDragEnterEvent *event)
{
    // Set the drop action to be the proposed action.
    event->acceptProposedAction();
}

#include "main.moc"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MyDialog d;
    d.show();
    return a.exec();
}
