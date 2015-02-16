SOURCES += \
    mainwindow.cpp \
    main.cpp \
    loginerrormessagebox.cpp \
    logindialog.cpp \
    exitmessagebox.cpp \
    combodelegate.cpp \
    purchasemsgdialog.cpp \
    aboutdialog.cpp \
    amendpwdialog.cpp \
    regdialog.cpp \
    database.cpp

FORMS += \
    mainwindow.ui \
    logindialog.ui \
    purchasemsgdialog.ui \
    aboutdialog.ui \
    amendpwdialog.ui \
    regdialog.ui

OTHER_FILES += \
    VMS.pro.user

HEADERS += \
    mainwindow.h \
    loginerrormessagebox.h \
    logindialog.h \
    exitmessagebox.h \
    combodelegate.h \
    purchasemsgdialog.h \
    aboutdialog.h \
    amendpwdialog.h \
    regdialog.h \
    database.h
QT      += \
    sql \
    widgets
