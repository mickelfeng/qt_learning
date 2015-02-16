#include "mainwindow.h"
#include "ui_mainwindow.h"

QString selectedFile="";
QString curCloudFold="";
QString curLocalFold="";
QString curFold="";
QString destFold="";
QStringList foundFiles;//for search
QStringList waitList;
QStringList doneList;
QStringList runList;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadSettings();
    ui->textEdit->append("Load Settings successfully");
    ui->textEdit->append("Do you work with drag and drop");

    pause=0;

    ui->filesTable->hide(); //Hide and Show
    ui->filesFoundLabel->hide();
    connect(ui->lineEdit,SIGNAL(returnPressed()),ui->pushButton,SIGNAL(clicked()));//search

    setTree();

    ui->LocalTree->setContextMenuPolicy(Qt::CustomContextMenu);// 实现右键菜单
    ui->CloudTree->setContextMenuPolicy(Qt::CustomContextMenu);// 实现右键菜单

    //初始化托盘
    trayicon = new QSystemTrayIcon(this);
    trayiconMenu = new QMenu(this);
    //为托盘菜单添加菜单项
    trayiconMenu->addAction(ui->actionQuit);
    //为托盘菜单添加分隔符
    trayiconMenu->addSeparator();

    //将创建的QIcon对象作为系统托盘图标
    trayicon->setIcon(QIcon(":/images/Cat-Black-icon.png"));
    //显示托盘图标
    trayicon->show();
    //设置系统托盘提示
    trayicon->setToolTip(tr("托盘测试"));
    //将创建菜单作为系统托盘菜单
    trayicon->setContextMenu(trayiconMenu);

    //在系统托盘显示气泡消息提示
    trayicon->showMessage(tr("主人主人"), tr("我在这里"), QSystemTrayIcon::Information, 5000);
    //为系统托盘绑定单击信号的槽 即图标激活时
    connect(trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason)));

    cloudmodel = new QFileSystemModel(this);
    cloudmodel->setReadOnly(false);
    cloudmodel->setFilter(QDir::AllDirs | QDir::Files | QDir::Drives | QDir::NoDot);
    QModelIndex cloud = cloudmodel->setRootPath(curCloudFold);
    ui->CloudTree->setModel(cloudmodel);
    ui->CloudTree->setRootIndex(cloud);

    localmodel = new QFileSystemModel(this);
    localmodel->setReadOnly(false);
    localmodel->setFilter(QDir::Drives | QDir::AllDirs | QDir::Files | QDir::NoDot);
    ui->LocalTree->setModel(localmodel);
    QModelIndex local=localmodel->setRootPath(curLocalFold);
    ui->LocalTree->setRootIndex(local);
    ui->textEdit->append("Initiallizd. Now you Can do whatever you like ");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    trayicon->hide();
    this->close();
}

void MainWindow::on_CloudTree_pressed(const QModelIndex &index)
{
    selectedFile = cloudmodel->fileInfo(index).absoluteFilePath();
    destFold=curLocalFold;
}

void MainWindow::on_LocalTree_pressed(const QModelIndex &index)
{
    selectedFile = localmodel->fileInfo(index).absoluteFilePath();
    destFold=curCloudFold;
}

void MainWindow::on_LocalTree_doubleClicked(const QModelIndex &index)
{
    QFileInfo info(localmodel->fileInfo(index).absoluteFilePath());
    if(!info.isDir())
        QDesktopServices::openUrl(QUrl::fromLocalFile(info.absoluteFilePath()));
    else
    {
        curLocalFold = info.absoluteFilePath();
        curFold=curLocalFold;

        localmodel = new QFileSystemModel(this);
        localmodel->setReadOnly(false);
        localmodel->setFilter(QDir::AllDirs | QDir::Files | QDir::Drives | QDir::NoDot);
        ui->LocalTree->setModel(localmodel);
        QModelIndex local=localmodel->setRootPath(curLocalFold);
        ui->LocalTree->setRootIndex(local);
    }
}

void MainWindow::on_CloudTree_doubleClicked(const QModelIndex &index)
{
    QString file = cloudmodel->fileInfo(index).absoluteFilePath();
    if(!QFileInfo(file).isDir())
        QDesktopServices::openUrl(QUrl::fromLocalFile(file));
    else
    {
        curCloudFold = file;
        curFold = file;
        cloudmodel = new QFileSystemModel(this);
        cloudmodel->setReadOnly(false);
        cloudmodel->setFilter(QDir::AllDirs | QDir::Files | QDir::Drives | QDir::NoDot);
        QModelIndex cloud = cloudmodel->setRootPath(curCloudFold);
        ui->CloudTree->setModel(cloudmodel);
        ui->CloudTree->setRootIndex(cloud);
    }
}

void MainWindow::on_actionGithub_triggered()
{
    if(waitList.empty())
    {
        ui->textEdit->append("happy!! All Local Job Done");
        system("D:/git/pull.bat");
    }

    int i =system("D:/git/push.bat");
    while(i!=0)
    {
        Sleep(2000);
        i=system("D:/git/pull.bat");
    }

    QString first = firstFile();

    if(first== NULL)
    {
        ui->textEdit->append("happy!! All CLoud Job Done");
    }

    setTree();
}

void MainWindow::callOpendss(const QString &fileName)
{

}

void MainWindow::callGridlabd()
{
    if(!runList.isEmpty())
    {
        foreach(QString filename,runList)
        {

            if(pause==1)
            {
                pause=0;
                return;
            }
            ui->textEdit->append("Now Run "+filename);
            QFileInfo info("D:/git/Case/"+filename);
            if(info.suffix()=="glm")
            {
                QTime time;
                time.start();
                QString cmd = "gridlabd D:\\git\\Case\\" + filename + "\\"+filename;
                QThread::sleep(2);
                timeElapse=time.elapsed();
                qDebug()<<timeElapse;

                QString log = filename + ".log";
                QString dst = "> D:\\git\\Case\\" +filename+"\\" + log;
                system(cmd.toLatin1()+ dst.toLatin1() );

                QFile file("D:/git/Case/tag/"+filename+".tag");
                if(!file.open(QIODevice::ReadOnly)){
                    std::cerr <<"open error" << qPrintable(file.errorString())<<std::endl;
                    return;
                }

                QTextStream stream(&file);//read
                QStringList list;
                QString line;
                do {
                    line=stream.readLine();
                    list.append(line);
                } while (!line.isNull());

                list.replace(0,"2");
                list.replace(1,QString::number(timeElapse,10));
                file.close();

                QFile file2("D:/git/Case/tag/"+filename +".tag");
                if(!file2.open(QIODevice::ReadWrite)){
                    std::cerr <<"open error" << qPrintable(file.errorString())<<std::endl;
                    return;
                }
                QTextStream stream2(&file2);

                foreach(QString name , list)
                {
                    stream2 << name << "\r\n";
                    stream2.flush();
                }
                file2.close();
                system("D:/git/push.bat");
                setTree();
            }
        }
    }
    else
    {
        ui->textEdit->append("All Local Job Done!!!");
    }
}

void MainWindow::delFile()
{ 
    if(curFold == curLocalFold)
    {
        QModelIndex index = ui->LocalTree->currentIndex();
        if(!index.isValid()) return;
        deleteDirectory(localmodel->fileInfo(index));
    }
    else
    {
        QModelIndex index = ui->CloudTree->currentIndex();
        if(!index.isValid()) return;
        deleteDirectory(cloudmodel->fileInfo(index));
    }
}

void MainWindow::deleteDirectory(QFileInfo fileList){

    if(fileList.isDir()){
        int childCount =0;
        QString dir = fileList.filePath();
        QDir thisDir(dir);
        childCount = thisDir.entryInfoList().count();
        QFileInfoList newFileList = thisDir.entryInfoList();
        if(childCount>2){
            for(int i=0;i<childCount;i++){
                if(newFileList.at(i).fileName().operator ==(".")|newFileList.at(i).fileName().operator ==("..")){
                    continue;
                }
                deleteDirectory(newFileList.at(i));
            }
        }
        fileList.absoluteDir().rmpath(fileList.fileName());
    }else if(fileList.isFile()){
        fileList.absoluteDir().remove(fileList.fileName());
    }
}

void MainWindow::setList()
{
    QStringList list = QDir("D:/git/Case/tag").entryList(QDir::Files);
    foreach(QString file , list)
    {
        QFile filename("D:/git/Case/tag/"+file);
        if(!filename.open(QIODevice::ReadOnly)){
            std::cerr <<"open error" << qPrintable(filename.errorString())<<std::endl;
            return;
        }
        QTextStream stream(&filename);
        QString line;
        line = stream.readLine();
        if(line=="0")
            waitList.append(QFileInfo(file).completeBaseName());
        if(line=="1")
            runList.append(QFileInfo(file).completeBaseName());
        if(line=="2")
            doneList.append(QFileInfo(file).completeBaseName());
    }
}

QString MainWindow::firstFile()
{
    if(!waitList.empty())
    {
        QString filename=waitList.at(0);
        QFile file("D:/git/Case/tag/"+filename+".tag");

        if(!file.open(QIODevice::ReadOnly)){
            std::cerr <<"open error" << qPrintable(file.errorString())<<std::endl;
            return NULL;
        }

        QTextStream stream(&file);
        QString line;
        line = stream.readAll();
        line=line.replace(0,1,"1");//running!
        file.close();

        QFile file2("D:/git/Case/tag/"+filename +".tag");
        if(!file2.open(QIODevice::ReadWrite)){
            std::cerr <<"open error" << qPrintable(file.errorString())<<std::endl;
            return NULL;
        }
        QTextStream stream2(&file2);
        stream2 << line;
        stream2.flush();
        file2.close();
        return filename;
    }
    else
        return NULL;
}

void MainWindow::newFold()
{
    if(curFold == curLocalFold)
    {
        QModelIndex index=ui->LocalTree->currentIndex();
        if(!index.isValid()) return;
        QString name = QInputDialog::getText(this,"Name","Enter a name");
        if(name.isEmpty()) return;
        QDir dir;
        dir.mkdir(curFold+"/"+name);
    }
    else
    {
        QModelIndex index=ui->CloudTree->currentIndex();
        if(!index.isValid()) return;
        QString name = QInputDialog::getText(this,"Name","Enter a name");
        if(name.isEmpty()) return;
        QDir dir;
        dir.mkdir(curFold+"/"+name);
    }
}

void MainWindow::newFile()
{
    if(curFold == curLocalFold)
    {
        QModelIndex index=ui->LocalTree->currentIndex();
        if(!index.isValid()) return;

        QString name = QInputDialog::getText(this,"Name","Enter a name");
        if(name.isEmpty()) return;

        QFile file(curFold+"/"+name);
        file.open(QIODevice::WriteOnly);
        file.close();
    }
    else
    {
        QModelIndex index=ui->CloudTree->currentIndex();
        if(!index.isValid()) return;

        QString name = QInputDialog::getText(this,"Name","Enter a name");
        if(name.isEmpty()) return;

        QFile file(curFold+"/"+name);
        file.open(QIODevice::WriteOnly);
        file.close();
    }
}
void MainWindow::rename()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Rename"),
                                         tr("Name"), QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty())
    {
        QFileInfo info(localmodel->fileInfo(ui->LocalTree->currentIndex()));
        QString oldName = info.absoluteFilePath();
        QString newName = info.absoluteDir().absolutePath().append("/").append(text);
        QFile::rename(oldName,newName);
    }

}

void MainWindow::on_LocalTree_customContextMenuRequested(const QPoint &pos)
{
    curFold = curLocalFold;
    QModelIndex index = ui->LocalTree->indexAt(pos);
    QString file = localmodel->filePath(index);

    QMenu *menu=new QMenu;

    if(file.isEmpty())
    {
        menu->addAction(QString(tr("New folder")),this,SLOT(newFold()));
        menu->addAction(QString(tr("New File")),this,SLOT(newFile()));
    }

    if(QFileInfo(file).isDir() | QFileInfo(file).isFile())
    {
        menu->addAction(QString(tr("Delete")),this,SLOT(delFile()));
        menu->addAction(QString(tr("Rename")),this,SLOT(rename()));
    }
    menu->exec(QCursor::pos());
}

void MainWindow::on_CloudTree_customContextMenuRequested(const QPoint &pos)
{
    curFold = curCloudFold;
    QModelIndex index = ui->CloudTree->indexAt(pos);
    QString file = cloudmodel->filePath(index);

    QMenu *menu=new QMenu;

    if(file.isEmpty())
    {
        menu->addAction(QString(tr("New folder")),this,SLOT(newFold()));
        menu->addAction(QString(tr("New File")),this,SLOT(newFile()));
    }

    if(QFileInfo(file).isDir() | QFileInfo(file).isFile())
    {
        menu->addAction(QString(tr("Delete")),this,SLOT(delFile()));
        menu->addAction(QString(tr("Rename")),this,SLOT(rename()));
    }
    menu->exec(QCursor::pos());
}

void MainWindow::onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    //单击
    case QSystemTrayIcon::Trigger:
        //双击
    case QSystemTrayIcon::DoubleClick:
        //恢复窗口显示
        this->setWindowState(Qt::WindowActive);
        this->show();
        break;
    default:
        break;
    }
}

void MainWindow::closeEvent(QCloseEvent *event)

{
    if(trayicon->isVisible())
    {
        event->ignore();
        this->hide();
    }
    else
    {
        writeSettings();
        event->accept();
    }
}


void MainWindow::on_actionGo_triggered()
{
    callGridlabd();
}

void MainWindow::on_actionPause_triggered()
{
    pause=1;
}

void MainWindow::on_actionInfo_triggered()
{
    QMessageBox message(QMessageBox::NoIcon, "^^", "点我干嘛");
    QPixmap image0(":/images/Cat-Black-icon.png");
    message.setIconPixmap(image0);
    message.exec();
}


void MainWindow::writeSettings()
{
    QSettings settings("THU","hgl10");
    settings.setValue("geometry",saveGeometry());
    settings.setValue("curLocalFold",curLocalFold);
    settings.setValue("curCloudFold",curCloudFold);
    settings.setValue("hidecloud",ui->actionCloudTree->isChecked());
    settings.setValue("hidelocal",ui->actionLocalTree->isChecked());
    settings.setValue("debuginfo",ui->actionDebugInfo->isChecked());
}

void MainWindow::loadSettings()
{
    QSettings settings("THU","hgl10");
    restoreGeometry(settings.value("geometry").toByteArray());
    curLocalFold = settings.value("curLocalFold").toString();
    curCloudFold = settings.value("curCloudFold").toString();
    if(settings.value("debuginfo").toBool())
    {
        ui->textEdit->hide();
        ui->actionDebugInfo->setChecked(true);
    }
    else
        ui->textEdit->show();
    if(settings.value("hidecloud").toBool())
    {
        ui->CloudTree->hide();
        ui->lineEdit->hide();
        ui->pushButton->hide();
        ui->actionCloudTree->setChecked(true);
    }
    else
        ui->CloudTree->show();
    if(settings.value("hidelocal").toBool())
    {
        ui->LocalTree->hide();
        ui->actionLocalTree->setChecked(true);
    }
    else
        ui->LocalTree->show();
}

void MainWindow::on_pushButton_clicked()
{
    ui->CloudTree->hide();
    ui->filesTable->show();
    ui->filesFoundLabel->show();
    ui->filesTable->setColumnCount(2);
    ui->filesTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    QStringList labels;
    labels << tr("File Name") << tr("Size");
    ui->filesTable->setHorizontalHeaderLabels(labels);
    ui->filesTable->verticalHeader()->hide();
    ui->filesTable->setShowGrid(false);

    foundFiles.clear();

    QDir dir(curCloudFold);
    QStringList fileList;
    foreach (QString file, dir.entryList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot)) {
        fileList.append(dir.absolutePath()+"/"+file);
    }

    findFiles(fileList,ui->lineEdit->text());
    showFiles(foundFiles);
    connect(ui->filesTable, SIGNAL(cellActivated(int,int)),
            this, SLOT(openFileOfItem(int,int)));
}

void MainWindow::openFileOfItem(int row, int)
{
    QTableWidgetItem *item = ui->filesTable->item(row, 0);
    QDesktopServices::openUrl(QUrl::fromLocalFile(QDir(curCloudFold).absoluteFilePath(item->text())));
}

void MainWindow::findFiles(const QStringList &filelist, const QString &text)
{
    foreach(QString file, filelist)
    {
        if(QFileInfo(file).isDir())
        {
            QDir dir(file);
            QStringList fileList;
            foreach (QString file, dir.entryList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot)) {
                fileList.append(dir.absolutePath()+"/"+file);
            }

            findFiles(fileList,text);
        }
        if(QFileInfo(file).isDir() | QFileInfo(file).suffix() == "txt" | QFileInfo(file).suffix()== "tag" | QFileInfo(file).suffix() == "dss" | QFileInfo(file).suffix() == "glm" )
        {
            QFile filename(file);
            if (filename.open(QIODevice::ReadOnly)) {
                QString line;
                QTextStream in(&filename);
                while (!in.atEnd()) {
                    line = in.readLine();
                    if (line.contains(text)) {
                        foundFiles << file;
                        break;
                    }
                }
            }
        }
    }
}

void MainWindow::showFiles(const QStringList &files)
{
    ui->filesTable->clear();
    int row = ui->filesTable->rowCount();
    for(int i =0 ; i< row; i++)
        ui->filesTable->removeRow(i);
    row = 0;
    for (int i = 0; i < files.size(); ++i) {
        QFile file(QDir(curCloudFold).absoluteFilePath(files[i]));
        qint64 size = QFileInfo(file).size();

        QTableWidgetItem *fileNameItem = new QTableWidgetItem(files[i]);
        fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *sizeItem = new QTableWidgetItem(tr("%1 KB").arg(int((size + 1023) / 1024)));
        sizeItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        sizeItem->setFlags(sizeItem->flags() ^ Qt::ItemIsEditable);

        ui->filesTable->insertRow(row);
        ui->filesTable->setItem(row, 0, fileNameItem);
        ui->filesTable->setItem(row, 1, sizeItem);
        row++;
    }
    ui->filesFoundLabel->setText(tr("%1 file(s) found").arg(files.size()) +
                                 (" (Double click on a file to open it)"));
}

void MainWindow::on_lineEdit_textEdited(const QString &)
{
    if(ui->lineEdit->text().isEmpty())
    {
        ui->CloudTree->show();
        ui->filesTable->hide();
        ui->filesFoundLabel->hide();
    }
}

void MainWindow::on_actionDebugInfo_triggered()
{
    if(ui->actionDebugInfo->isChecked())
        ui->textEdit->hide();
    else
        ui->textEdit->show();
}

void MainWindow::on_actionLocalTree_triggered()
{
    if(ui->actionLocalTree->isChecked())
        ui->LocalTree->hide();
    else
        ui->LocalTree->show();
}

void MainWindow::on_actionCloudTree_triggered()
{
    if(ui->actionCloudTree->isChecked())
    {
        ui->CloudTree->hide();
        ui->lineEdit->hide();
        ui->pushButton->hide();
    }
    else
    {
        ui->CloudTree->show();
        ui->lineEdit->show();
        ui->pushButton->show();
    }
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox message(QMessageBox::NoIcon, "^^", "点我干嘛");
    QPixmap image0(":/images/Cat-Black-icon.png");
    message.setIconPixmap(image0);
    message.exec();
}

void MainWindow::on_actionRefresh_triggered()
{
    setTree();
}

void MainWindow::setTree()
{
    ui->treeWidget->clear();

    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderLabel(tr("Case")); //设置头的标题

    waitList.clear();
    runList.clear();
    doneList.clear();

    setList();

    imageItemWait = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("Waiting")));
    imageItemWait->setIcon(0,QIcon(":/images/Cat-Black-icon.png"));

    foreach(QString name , waitList)
    {
        imageItemWait->addChild(new QTreeWidgetItem(imageItemWait,QStringList(QString(name)))); //子节点1
    }

    imageItemRun = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("Running")));
    imageItemRun->setIcon(0,QIcon(":/images/recycle.png"));

    foreach(QString name , runList)
    {
        imageItemRun->addChild(new QTreeWidgetItem(imageItemRun,QStringList(QString(name)))); //子节点1
    }

    imageItemDone = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("Done")));
    imageItemDone->setIcon(0,QIcon(":/images/check.png"));

    foreach(QString name , doneList)
    {
        imageItemDone->addChild(new QTreeWidgetItem(imageItemDone,QStringList(QString(name)))); //子节点1
    }

    ui->treeWidget->expandAll(); //结点全部展开
}
