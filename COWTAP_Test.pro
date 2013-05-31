#-------------------------------------------------
#
# Project created by QtCreator 2013-05-30T19:15:39
#
#-------------------------------------------------

QT       += gui core testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COWTAP_Test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += src/Data/Goal/Unit_Tests

SOURCES += main.cpp \
    src/Data/Goal/Unit_Tests/customgoaltest.cpp \
    src/Data/Goal/Unit_Tests/goalmock.cpp \
    src/Data/Goal/Unit_Tests/yeargoaltest.cpp \
    src/Data/Goal/Unit_Tests/weekgoaltest.cpp \
    src/Data/Goal/Unit_Tests/monthgoaltest.cpp \
    src/Data/Goal/Unit_Tests/goaltest.cpp \
    src/Data/Goal/Unit_Tests/daygoaltest.cpp \
    src/Data/Goal/Widgets/Unit_Tests/customgoalwidgettest.cpp

include(COWTAP.pri)

HEADERS += \
    src/Data/Goal/Unit_Tests/customgoaltest.h \
    src/Data/Goal/Unit_Tests/goalmock.h \
    src/Data/Goal/Unit_Tests/yeargoaltest.h \
    src/Data/Goal/Unit_Tests/weekgoaltest.h \
    src/Data/Goal/Unit_Tests/monthgoaltest.h \
    src/Data/Goal/Unit_Tests/goaltest.h \
    src/Data/Goal/Unit_Tests/daygoaltest.h \
    src/Data/Goal/Widgets/Unit_Tests/customgoalwidgettest.h
