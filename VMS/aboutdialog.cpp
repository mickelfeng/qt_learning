#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->iconLabel->setPixmap(QPixmap(QApplication::applicationDirPath() + "/images/Hacker.jpg"));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
