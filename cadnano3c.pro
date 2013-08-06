#-------------------------------------------------
#
# Project created by QtCreator 2013-08-06T14:23:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cadnano3c
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    customqgraphicsview.cpp

HEADERS  += mainwindow.h \
    customqgraphicsview.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
