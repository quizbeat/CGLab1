#-------------------------------------------------
#
# Project created by QtCreator 2014-09-23T00:05:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FirstQtWidgetApp
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    nmmatrix.cpp \
    nmvector.cpp

HEADERS  += widget.h \
    nmmatrix.h \
    nmvector.h

FORMS    += widget.ui
