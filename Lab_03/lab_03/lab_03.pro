TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    mtx_generation.cpp \
    mtx_multiplication.cpp \
    test.cpp

HEADERS += \
    mtx_generation.h \
    mtx_multiplication.h \
    test.h
