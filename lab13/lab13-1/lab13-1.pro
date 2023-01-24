include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

SOURCES += \
        functions.cpp \
        functionsTest.cpp \
        main.cpp         \
        number.cpp \
        numberTests.cpp

HEADERS += \
    functions.h \
    number.h
