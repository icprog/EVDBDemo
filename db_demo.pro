#-------------------------------------------------
#
# Project created by QtCreator 2014-07-07T17:25:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = db_demo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialthread.cpp \
    serial/qextserialbase.cpp \
    serial/qextserialenumerator.cpp \
    serial/qextserialport.cpp \
    serial/win_qextserialport.cpp \
    config.c \
    yocdialog.cpp

HEADERS  += mainwindow.h \
    serialthread.h \
    serial/qextserialbase.h \
    serial/qextserialenumerator.h \
    serial/qextserialport.h \
    serial/win_qextserialport.h \
    config.h \
    yocdialog.h

FORMS    += mainwindow.ui
