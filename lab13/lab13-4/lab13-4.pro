include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

SOURCES += \
        bankaccount.cpp \
        main.cpp        

HEADERS += \
    bankaccount.h
