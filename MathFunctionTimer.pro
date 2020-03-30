QT       = core
# QT += network
CONFIG   += console
CONFIG   -= app_bundle

target.path = /sbin
INSTALLS += target

TEMPLATE = app
SOURCES += main.cpp \
    calculate.cpp

HEADERS += \
    calculate.hpp



