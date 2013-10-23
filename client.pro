#-------------------------------------------------
#
# Project created by QtCreator 2013-10-22T12:42:08
#
#-------------------------------------------------

QT       += core gui

TARGET = client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpclient.cpp \
    porting_os.cpp \
    thread.cpp

HEADERS  += mainwindow.h \
    tcpclient.h \
    porting_os.h \
    thread.h

FORMS    += mainwindow.ui

OTHER_FILES +=
