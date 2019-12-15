TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    levenstein_mtx.cpp \
    damerau_levenshtein_mtr.cpp \
    damerau_levenshtein.cpp \
    usermtxlevenshtein.cpp \
    timetest.cpp \
    test.cpp \
    func_testing.cpp \
    user_mode.cpp \
    time_testing.cpp

HEADERS += \
    base_counter.h \
    levenstein_mtx.h \
    damerau_levenshtein_mtr.h \
    damerau_levenshtein.h \
    usermtxlevenshtein.h \
    timetest.h \
    test.h \
    user_mode.h \
    func_testing.h \
    time_testing.h
