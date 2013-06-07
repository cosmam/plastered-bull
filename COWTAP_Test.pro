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

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_LDFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

CFLAGS += --coverage
LDFLAGS += --coverage

TEMPLATE = app

INCLUDEPATH += src/Unit_Tests \
               src/Data/Criteria/Unit_Tests \
               src/Data/Goal/Unit_Tests \
               src/Data/Goal/Widgets/Unit_Tests

SOURCES += main.cpp \
    src/Data/Goal/Unit_Tests/customgoaltest.cpp \
    src/Data/Goal/Unit_Tests/goalmock.cpp \
    src/Data/Goal/Unit_Tests/yeargoaltest.cpp \
    src/Data/Goal/Unit_Tests/weekgoaltest.cpp \
    src/Data/Goal/Unit_Tests/monthgoaltest.cpp \
    src/Data/Goal/Unit_Tests/goaltest.cpp \
    src/Data/Goal/Unit_Tests/daygoaltest.cpp \
    src/Data/Goal/Widgets/Unit_Tests/customgoalwidgettest.cpp \
    src/Data/Goal/Widgets/Unit_Tests/yeargoalwidgettest.cpp \
    src/Data/Goal/Widgets/Unit_Tests/weekgoalwidgettest.cpp \
    src/Data/Goal/Widgets/Unit_Tests/monthgoalwidgettest.cpp \
    src/Data/Goal/Widgets/Unit_Tests/daygoalwidgettest.cpp \
    src/Unit_Tests/testchasis.cpp \
    src/Data/Criteria/Unit_Tests/wordscriteriatest.cpp \
    src/Data/Criteria/Unit_Tests/criteriatest.cpp \
    src/Data/Criteria/Unit_Tests/criteriamock.cpp \
    src/Data/Criteria/Unit_Tests/pagescriteriatest.cpp

include(COWTAP.pri)

HEADERS += \
    src/Data/Goal/Unit_Tests/customgoaltest.h \
    src/Data/Goal/Unit_Tests/goalmock.h \
    src/Data/Goal/Unit_Tests/yeargoaltest.h \
    src/Data/Goal/Unit_Tests/weekgoaltest.h \
    src/Data/Goal/Unit_Tests/monthgoaltest.h \
    src/Data/Goal/Unit_Tests/goaltest.h \
    src/Data/Goal/Unit_Tests/daygoaltest.h \
    src/Data/Goal/Widgets/Unit_Tests/customgoalwidgettest.h \
    src/Data/Goal/Widgets/Unit_Tests/yeargoalwidgettest.h \
    src/Data/Goal/Widgets/Unit_Tests/weekgoalwidgettest.h \
    src/Data/Goal/Widgets/Unit_Tests/monthgoalwidgettest.h \
    src/Data/Goal/Widgets/Unit_Tests/daygoalwidgettest.h \
    src/Unit_Tests/testchasis.h \
    src/Data/Criteria/Unit_Tests/wordscriteriatest.h \
    src/Data/Criteria/Unit_Tests/criteriatest.h \
    src/Data/Criteria/Unit_Tests/criteriamock.h \
    src/Data/Criteria/Unit_Tests/pagescriteriatest.h
