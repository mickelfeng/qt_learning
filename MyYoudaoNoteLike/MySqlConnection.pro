#-------------------------------------------------
#
# Project created by QtCreator 2015-02-03T14:42:29
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = MySqlConnection
TEMPLATE = app

DEFINES += QCUSTOMPLOT_USE_LIBRARY

# Link with debug version of qcustomplot if compiling in debug mode, else with release library:
CONFIG(debug, release|debug) {
  win32:QCPLIB = qcustomplotd1
  else: QCPLIB = qcustomplotd
} else {
  win32:QCPLIB = qcustomplot1
  else: QCPLIB = qcustomplot
}
LIBS += -L./3rdpart/qcp/lib -l$$QCPLIB


INCLUDEPATH+="3rdpart/qcp/include"

SOURCES += main.cpp\
        mainwindow.cpp \
    tabitem.cpp \
    myrealtimeplot.cpp \
    mycolormapplot.cpp \
    treeviewtest.cpp \
    collapseview.cpp \
    collpsetestform.cpp \
    testadjust.cpp \
    collapseviewitem.cpp \
    slidewindow.cpp \
    litteriem.cpp

HEADERS  += mainwindow.h \
    tabitem.h \
    myrealtimeplot.h \
    mycolormapplot.h \
    treeviewtest.h \
    collapseview.h \
    collpsetestform.h \
    testadjust.h \
    collapseviewitem.h \
    slidewindow.h \
    litteriem.h

FORMS    += mainwindow.ui \
    tabitem.ui \
    treeviewtest.ui \
    collapseview.ui \
    collpsetestform.ui \
    testadjust.ui \
    collapseviewitem.ui \
    slidewindow.ui \
    litteriem.ui

RESOURCES += \
    rs/rs.qrc
