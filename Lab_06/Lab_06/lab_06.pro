TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ant.cpp \
        findBestParams.cpp \
        generator.cpp \
        main.cpp \
        map.cpp \
        path.cpp \
        simulation.cpp

HEADERS += \
    ant.h \
    bestPath.h \
    findBestParams.h \
    generator.h \
    map.h \
    path.h \
    simulation.h
