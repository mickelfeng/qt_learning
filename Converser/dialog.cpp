#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    binary=new QLabel(QObject::trUtf8("二进制:"));
    dex = new QLabel(QObject::trUtf8("十进制:"));
    hex = new QLabel(QObject::trUtf8("十六进制:"));
    exit = new QPushButton(QObject::trUtf8("退出"));
    ebinary = new QLineEdit();
    QRegExp regx("[0-1]{0,30}");
    QValidator *validator = new QRegExpValidator(regx,ebinary);
    ebinary->setValidator( validator );

    edex = new QLineEdit();
    QRegExp regx1("[0-9]{0,9}");
    QValidator *validator1 = new QRegExpValidator(regx1,edex);
    edex->setValidator(validator1);
    ehex = new QLineEdit();
    QRegExp regx2("[0-9a-fA-F]{0,7}");
    QValidator *validator2 = new QRegExpValidator(regx2,ehex);
    ehex->setValidator(validator2);

    hbinary = new QHBoxLayout();
    hdex = new QHBoxLayout();
    hhex = new QHBoxLayout();

    QObject::connect(ebinary,SIGNAL(textEdited(QString)),this,SLOT(changeB()));
    QObject::connect(edex,SIGNAL(textEdited(QString)),this,SLOT(changeD()));
    QObject::connect(ehex,SIGNAL(textEdited(QString)),this,SLOT(changeH()));
    QObject::connect(exit,SIGNAL(clicked()),this,SLOT(close()));


    hbinary->addWidget(binary);
    hbinary->addWidget(ebinary);

    hdex->addWidget(dex);
    hdex->addWidget(edex);

    hhex->addWidget(hex);
    hhex->addWidget(ehex);

    total = new QVBoxLayout();

    total->addLayout(hbinary);
    total->addLayout(hdex);
    total->addLayout(hhex);
    total->addWidget(exit);
    setLayout(total);

}
void Dialog::changeB(){
    edex->clear();
    ehex->clear();
    bool ok;
  /*/  long int n = ebinary->text().toLong();
   // long int k = BitoEdx(n);
   // edex->setText(QString::number(k));
   // ehex->setText(ba.setNum((qlonglong)k,16));*/
    int he = ebinary->text().toInt(&ok,2);
    edex->setText(QString::number(he));
    ehex->setText(ba.setNum(he,16));
}
void Dialog::changeD(){
    ebinary->clear();
    ehex->clear();
    int n = edex->text().toInt();
    ebinary->setText(ba.setNum(n,2));
    ehex->setText(ba.setNum(n,16));
}
void Dialog::changeH(){
    ebinary->clear();
    edex->clear();
    bool ok;
    int he = ehex->text().toInt(&ok,16);
    ebinary->setText(ba.setNum(he,2));
    edex->setText(QString::number(he));
}
/*long Dialog::BitoEdx(long n){
    long k = n;
    int number = 0; //计数多少位
    long sum=0;      //结果值
    while(k = k/10)
        number+=1;
    k = n;

    for(int i=0; i<=number;i++){
        sum+=(pow(2,i) * (k%10));
        k = k/10.0;
    }
    return sum;
}
*/
Dialog::~Dialog()
{
    delete binary;
    delete dex;
    delete hex;
    delete ebinary;
    delete edex;
    delete ehex;

    delete hbinary;
    delete hdex;
    delete hhex;
    delete total;
    
}
