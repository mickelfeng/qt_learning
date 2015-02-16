#include "exitmessagebox.h"

ExitMessageBox::ExitMessageBox(QWidget *parent) :
    QMessageBox(parent)
{
    int buttonMsg = QMessageBox::question(this, "确认退出", "你确定退出VMS?",
                                          QMessageBox::Ok|QMessageBox::Cancel,
                                          QMessageBox::Ok);
    if(QMessageBox::Ok == buttonMsg)
    {
        exit(0);
    }
}
