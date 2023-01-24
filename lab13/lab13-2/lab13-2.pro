include(gtest_dependency.pri)
INCLUDEPATH(googletest)
INCLUDEPATH(googlemock)
INCLUDEPATH(googletest/include)
INCLUDEPATH(googlemock/include)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

SOURCES += \
        main.cpp         \
        numberTest.cpp

HEADERS += \
    number.h
