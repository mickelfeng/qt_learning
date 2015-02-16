#QT禁用最大化按钮 和 禁止调节窗口大小 在ui->setupUi(this); 后加

    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);  
    setFixedSize(this->width(), this->height());  