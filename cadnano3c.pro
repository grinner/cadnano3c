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
    customqgraphicsview.cpp \
    styles.cpp \
    model/document.cpp \
    cnobject.cpp \
    model/vhelix/vhelix.cpp

HEADERS  += mainwindow.h \
    customqgraphicsview.h \
    styles.h \
    document.h \
    cnobject.h \
    common.h \
    strandset.h \
    model/vhelix/vhelix.h \
    model/part/part.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
