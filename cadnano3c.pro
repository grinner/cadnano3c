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
    model/document/document.cpp \
    model/cnobject.cpp \
    model/vhelix/vhelix.cpp \
    model/vhelix/removevhelixcommand.cpp \
    model/part/part.cpp \
    model/part/createxovercommand.cpp \
    model/oligo/oligo.cpp \
    model/strand/strand.cpp \
    model/document/addpartcommand.cpp

HEADERS  += mainwindow.h \
    customqgraphicsview.h \
    styles.h \
    model/document/document.h \
    model/cnobject.h \
    common.h \
    strandset.h \
    model/vhelix/vhelix.h \
    model/part/part.h \
    model/vhelix/removevhelixcommand.h \
    model/part/renumbervhelicescommand.h \
    model/part/createxovercommand.h \
    model/oligo/oligo.h \
    model/strand/strand.h \
    model/document/addpartcommand.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
