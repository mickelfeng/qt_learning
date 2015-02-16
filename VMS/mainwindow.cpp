#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    login = new LoginDialog();
    login->exec();
    if(login->loginstatus)
    {
        db = new DataBase;
        if(!db->openDataBase("vegetable.db", "QSQLITE"))
        {
            QMessageBox::critical(this, "错误", "数据库打开失败！！！", QMessageBox::Ok);
            exit(0);
        }

        //构建界面  初始化界面
        ui->setupUi(this);
        ui->stackedWidget->setCurrentIndex(0);
        ui->farmerStackedWidget->setCurrentIndex(0);

        createAction();

          //设置为默认输入时间
        msgStatusLable = new QLabel("欢迎使用VMS管理系统");
        msgStatusLable->setMinimumSize(600,25);

        currentTimeShowTimer();     //创建定时器，用来控制当前时间状态栏显示

        ui->statusBar->addWidget(msgStatusLable);
        ui->statusBar->addWidget(currentTimeLable);

        //构建功能通用布局
        purchaseInterface();    //purchase界面
        farmerInterFace();      //farmer界面
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete login;
    db->closeDataBase();
}

//重写closEvent函数，添加关闭提示
void MainWindow::closeEvent(QCloseEvent *event)
{
    int buttonMsg = QMessageBox::question(this, "确认退出", "你确定退出VMS?",
                                          QMessageBox::Ok|QMessageBox::Cancel,
                                          QMessageBox::Ok);
    if(QMessageBox::Ok == buttonMsg)
    {
        event->accept();
        exit(0);
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::createAction()     //创建action
{
    purchaseAction = new QAction("收购", this);
    purchaseAction->setStatusTip("收购");
    ui->mainToolBar->addAction(purchaseAction);
    connect(purchaseAction, SIGNAL(triggered()), this, SLOT(purchaseAction_activated()));

    farmerAction = new QAction("农户", this);
    farmerAction->setStatusTip("农户信息");
    ui->mainToolBar->addAction(farmerAction);
    connect(farmerAction, SIGNAL(triggered()), this, SLOT(farmerAction_activated()));

}

//文件 下拉选项 农户资料 Action
void MainWindow::on_farmerDataAction_triggered()
{
     ui->stackedWidget->setCurrentIndex(1);
}
//文件 下拉选项 收购资料 Action
void MainWindow::on_purchaseDataAction_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
}
//文件 下拉选项 退出 Action
void MainWindow::on_exitaction_triggered()
{
    close();
}
//关于
void MainWindow::on_aboutAction_triggered()
{
    about = new AboutDialog;
    about->exec();
}

//双击purchase槽函数
void MainWindow::on_purchaseTableView_doubleClicked(const QModelIndex &index)
{
    purchaseMSGDialog purchaseMSG;
    purchaseMSG.purchaseSet(index,purchaseModel);
    purchaseMSG.exec();
}
//堆栈窗口切换  主功能窗口切换
void MainWindow::purchaseAction_activated()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::farmerAction_activated()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//当前时间状态栏显示
void MainWindow::currentTimeShowTimer()     //定时器
{
    QDateTime datetime = QDateTime::currentDateTime();  //获取当前系统时间
    currentTimeLable = new QLabel(datetime.toString("yyyy年MM月dd日  hh:mm:ss  ddd    "));
    currentTimeLable->setMinimumSize(200,25);
    currentTimeLable->setAlignment(Qt::AlignRight);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(currentTimeShow()));
    timer->start(1000);
}

void MainWindow::currentTimeShow()      //显示
{
    QDateTime datetime = QDateTime::currentDateTime();  //获取当前系统时间
    currentTimeLable->setText(datetime.toString("yyyy年MM月dd日  hh:mm:ss  ddd    "));
}
//purchase

//purchase通用布局
void MainWindow::purchaseInterface()
{
    QDateTime datetime = QDateTime::currentDateTime();  //获取当前系统时间
    ui->purchaseTimeDateEdit->setDateTime(datetime);  //设置当前时间为默认输入时间

    ui->purchaseKindcomBox->addItem("黄瓜");
    ui->purchaseKindcomBox->addItem("西红柿");


    purchaseModel = new QSqlTableModel;
    purchaseModel->setTable("purchase");
    purchaseModel->setEditStrategy(QSqlTableModel::OnManualSubmit);  //手动提交
    purchaseModel->select();

    ui->purchaseTableView->setModel(purchaseModel);
    setPurchaseModelHeader();
    ui->purchaseTableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);  //内容居左
    ui->purchaseTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //只读不能修改表
    ui->purchaseTableView->setSelectionBehavior(QAbstractItemView::SelectRows);  //选中一行
}

void MainWindow::setPurchaseModelHeader()
{
    purchaseModel->setHeaderData(0,Qt::Horizontal,"收购ID");
    purchaseModel->setHeaderData(1,Qt::Horizontal,"农户ID");
    purchaseModel->setHeaderData(2,Qt::Horizontal,"蔬菜品种");
    purchaseModel->setHeaderData(3,Qt::Horizontal,"净重");
    purchaseModel->setHeaderData(4,Qt::Horizontal,"价格");
    purchaseModel->setHeaderData(5,Qt::Horizontal,"收购时间");
}
//purchase 添加按钮
void MainWindow::on_purchaseAddButton_clicked()
{
    int rowCount = purchaseModel->rowCount();
//    purchaseModel->insertRow(rowCount);
    QDateTime datetime = QDateTime::currentDateTime();  //获取当前系统时间
    QString pid = datetime.toString("yyyyMMddhhmmss");
    if(fidexists(ui->purchaseIDLineEdit->text())) //检查fid是否存在
    {
        purchaseModel->insertRow(rowCount);
        purchaseModel->setData(purchaseModel->index(rowCount, 0),pid);
        purchaseModel->setData(purchaseModel->index(rowCount, 1),ui->purchaseIDLineEdit->text().toInt());
        purchaseModel->setData(purchaseModel->index(rowCount, 2),ui->purchaseKindcomBox->currentText());
        purchaseModel->setData(purchaseModel->index(rowCount, 3),ui->purchaseWeightSpinBox->text().toInt());
        purchaseModel->setData(purchaseModel->index(rowCount, 4),ui->purchasePriceDoubleSpinBox->text().toDouble());
        purchaseModel->setData(purchaseModel->index(rowCount, 5),ui->purchaseTimeDateEdit->text());
    }
    else
    {
//        int tempRowCount = purchaseModel->rowCount()-1;     //获取新增行的行号
//        purchaseModel->revertRow(tempRowCount);             //撤消新增行当操作
        if(QMessageBox::Ok == QMessageBox::warning(this, "错误", "用户ID不存在，是否添加该农户资料？",
                             QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok))
        {
            ui->stackedWidget->setCurrentIndex(1);
        }
    }
    ui->purchaseIDLineEdit->clear();
    ui->purchaseKindcomBox->clearEditText();
    ui->purchaseWeightSpinBox->clear();
    ui->purchasePriceDoubleSpinBox->clear();
}
//purchase 撤销
void MainWindow::on_purchaseCancelButton_clicked()
{
    purchaseModel->revertAll();
}
//pruchase 刷新
void MainWindow::on_purchaseRefreshButton_clicked()
{
    purchaseModel->setTable("purchase");
    purchaseModel->select();
    setPurchaseModelHeader();
}
//purchase 提交数据
void MainWindow::on_purchaseCommitButton_clicked()
{
    if(QMessageBox::Ok == QMessageBox::question(this, "提交确认", "确定提交当前数据到数据库？",
                                                QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Cancel))
    {
        purchaseModel->database().transaction();
        if(purchaseModel->submitAll())
        {
            purchaseModel->database().commit();
        }
        else
        {
            purchaseModel->database().rollback();
            QMessageBox::warning(this,"purchase error", ("数据库错误:" + (purchaseModel->lastError().text())));
        }
    }
}

//farmer
void MainWindow::setFarmerModelHeader()
{
    farmerModel->setHeaderData(0,Qt::Horizontal, "姓名");
    farmerModel->setHeaderData(1,Qt::Horizontal, "编号");
    farmerModel->setHeaderData(2,Qt::Horizontal, "性别");
    farmerModel->setHeaderData(3,Qt::Horizontal, "电话");
    farmerModel->setHeaderData(4,Qt::Horizontal, "住址");
}

//加载farmerModel
void MainWindow::loadFarmerModel(QTableView *tv)
{
    farmerModel->setTable("farmer");
    farmerModel->setEditStrategy(QSqlTableModel::OnManualSubmit);  //手动提交
    farmerModel->select();
    tv->setModel(farmerModel);
    setFarmerModelHeader();
    tv->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);  //内容居左
    tv->resizeColumnToContents(4);
//    tv->setAlternatingRowColors(true);
    tv->setStyleSheet("QTableView{background-color: rgb(250, 250, 115);"
             "alternate-background-color: rgb(141, 163, 215);}");
}


//farmer通用布局
void MainWindow::farmerInterFace()
{
    ui->farmerStatusLabel->setText("等待功能选择");
    ui->farmerSexCBox->addItem("男");
    ui->farmerSexCBox->addItem("女");
    farmerModel = new QSqlTableModel;
    loadFarmerModel(ui->farmerTableView);
    ui->farmerTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //只读不能修改表
    loadFarmerModel(ui->farmerSelectTableView);


}

//farmer slots
void MainWindow::on_farmerAddButton_clicked()  //farmer 录入按钮触发
{
    ui->farmerStackedWidget->setCurrentIndex(0);
    ui->farmerStatusLabel->setText("录入状态");
    farmerStatus = farmerAdd;
    farmerModel->setTable("farmer");
    farmerModel->select();
    setFarmerModelHeader();
}
void MainWindow::on_farmerSelectButton_clicked() //farmer 查找按钮触发
{
    ui->farmerStackedWidget->setCurrentIndex(1);
    ui->farmerStatusLabel->setText("查找状态");
    ui->farmerNameCheckBox->setChecked(true);   //默认只按name查找
    farmerStatus = farmerSelect;
    farmerModel->setTable("farmer");
    farmerModel->select();
    setFarmerModelHeader();
    ui->farmerSelectTableView->setSelectionBehavior(QAbstractItemView::SelectRows);  //选中一行
    ui->farmerSelectTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //只读不能修改表
}
void MainWindow::on_farmerAmendButton_clicked()     //farmer 修改按钮
{
    ui->farmerStackedWidget->setCurrentIndex(1);
    ui->farmerStatusLabel->setText("修改状态");
    ui->farmerNameCheckBox->setChecked(true);   //默认只按name查找
    farmerStatus = farmerAmend;
    farmerModel->setTable("farmer");
    farmerModel->select();
    setFarmerModelHeader();
    ui->farmerSelectTableView->setItemDelegateForColumn(2,&combodegate);
    ui->farmerSelectTableView->setSelectionBehavior(QAbstractItemView::SelectItems);  //选中一项
    ui->farmerSelectTableView->setEditTriggers(QAbstractItemView::DoubleClicked); //双击修改表
}
void MainWindow::on_farmerDeleteButton_clicked()        //farmer 删除按钮
{
    ui->farmerStackedWidget->setCurrentIndex(1);
    ui->farmerStatusLabel->setText("删除状态");
    ui->farmerNameCheckBox->setChecked(true);
    farmerStatus = farmerDelete;
    farmerModel->setTable("farmer");
    farmerModel->select();
    setFarmerModelHeader();
    ui->farmerSelectTableView->setSelectionBehavior(QAbstractItemView::SelectRows);  //选中一行
    ui->farmerSelectTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //只读不能修改表
}

//获取输入的资料
void MainWindow::getInputFarmer()
{
    fname = ui->farmerNameLineEdit->text();
    ui->farmerNameLineEdit->clear();
    fid = ui->farmerIDLineEdit->text();
    ui->farmerIDLineEdit->clear();
    fsex = ui->farmerSexCBox->currentText();
    ftele = ui->farmerTelLineEdit->text();
    ui->farmerTelLineEdit->clear();
    faddress = ui->farmerAddRLineEdit->text();
    ui->farmerAddRLineEdit->clear();
}
//清空farmer资料暂存字符串
void MainWindow::clearInputFarmer()
{
    fname.clear();
    fid.clear();
    fsex.clear();
    ftele.clear();
    faddress.clear();
}

//fid存在判断
bool MainWindow::fidexists(QString id)
{
    QSqlQuery query;
    QString sql = QString("SELECT fid FROM farmer WHERE fid = %1").arg(id);
    query.exec(sql);
    query.first();
    if(0 == query.value(0).toString().compare(""))
    {
        return false;
    }
    else
    {
        return true;
    }
}

//farmer确定按钮的槽函数定义
void MainWindow::on_farmerOkButton_clicked()
{
    int rowCount = farmerModel->rowCount();
    int selectRowCount = 0; 

    switch(farmerStatus)
    {
    case farmerAdd:
        getInputFarmer();
        if(fidexists(fid))
        {
            QMessageBox::critical(this, "错误", "用户编号已存在！！！", QMessageBox::Ok);
        }
        else
        {
            farmerModel->insertRow(rowCount);
            farmerModel->setData(farmerModel->index(rowCount, 0),fname);
            farmerModel->setData(farmerModel->index(rowCount, 1),fid);
            farmerModel->setData(farmerModel->index(rowCount, 2),fsex);
            farmerModel->setData(farmerModel->index(rowCount, 3),ftele);
            farmerModel->setData(farmerModel->index(rowCount, 4),faddress);
        }
        clearInputFarmer();
        break;

    case farmerSelect:
        getInputFarmer();
        farmerModel->setFilter("fsex = '男'");
        farmerModel->select();
        farmerModel->setFilter("faddress LIKE '%%'");
        farmerModel->select();
        if(!(ui->farmerNameCheckBox->isChecked()))
        {
            fname.clear();
            fname = "%%";
        }
        if(!(ui->farmerIDCheckBox->isChecked()))
        {
            fid.clear();
            fid = "%%";
        }
        if(!(ui->farmerSexCheckBox->isChecked()))
        {
            fsex.clear();
            fsex = "%%";
        }
        if(!(ui->farmerAddrCheckBox->isChecked()))
        {
            faddress.clear();
            faddress = "%%";
        }

        selectSql = QString("fname LIKE '%1' AND "
                            "fid LIKE '%2' "
                            "AND fsex LIKE '%3' "
                            "AND faddress LIKE '%4'").arg(fname).arg(fid).arg(fsex).arg(faddress);
        farmerModel->setFilter(selectSql);
        farmerModel->select();
        clearInputFarmer();
        break;

    case farmerAmend:
        break;

    case farmerDelete:
        selectRowCount = ui->farmerSelectTableView->currentIndex().row();
        farmerModel->removeRow(selectRowCount);
        break;

    default:
        break;

    }
}
//farmer 提交确认
void MainWindow::on_farmerCommitButton_clicked()
{
    if(QMessageBox::Ok == QMessageBox::question(this, "提交确认", "确定提交当前数据到数据库？",
                                                QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Cancel))
    {
        farmerModel->database().transaction();
        if(farmerModel->submitAll())
        {
            farmerModel->database().commit();
        }
        else
        {
            farmerModel->database().rollback();
            QMessageBox::warning(this,"farmer error", ("数据库错误:" + (farmerModel->lastError().text())));
        }
    }
}
//farmer 撤销
void MainWindow::on_farmerCancelButton_clicked()
{
    farmerModel->revertAll();
}
//farmer 刷新
void MainWindow::on_farmerRefreshButton_clicked()
{
    farmerModel->setTable("farmer");
    farmerModel->select();
    setFarmerModelHeader();
}
//用户注册
void MainWindow::on_regAction_triggered()
{
    reg = new RegDialog;
    reg->exec();
}
//密码修改
void MainWindow::on_amendAction_triggered()
{
    amendPW = new AmendPWDialog;
    amendPW->exec();
}

void MainWindow::on_currrentUserAction_triggered()
{
    QMessageBox::information(this, "当前用户", QString("当前用户是：%1").arg(login->currentUser), QMessageBox::Ok);
}
