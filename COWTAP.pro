#-------------------------------------------------
#
# Project created by QtCreator 2013-05-11T20:49:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COWTAP
TEMPLATE = app

SOURCES += src/main.cpp\
    src/mainwindow.cpp

HEADERS  += src/mainwindow.h

FORMS    += src/mainwindow.ui \

include(COWTAP.pri)
