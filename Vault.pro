#-------------------------------------------------
#
# Project created by QtCreator 2014-07-21T12:52:35
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Vault
TEMPLATE = app


SOURCES += main.cpp\
        homescreen.cpp \
    database.cpp \
    masterpasswordform.cpp \
    databasesettingsform.cpp \
    opendatabaseform.cpp \
    password.cpp \
    serial.cpp \
    newentryform.cpp \
    changemasterkeyform.cpp \
    groups.cpp


HEADERS  += homescreen.h \
    database.h \
    masterpasswordform.h \
    databasesettingsform.h \
    opendatabaseform.h \
    password.h \
    serial.h \
    newentryform.h \
    changemasterkeyform.h \
    groups.h


FORMS    += homescreen.ui \
    masterpasswordform.ui \
    databasesettingsform.ui \
    opendatabaseform.ui \
    newentryform.ui \
    changemasterkeyform.ui \
    groups.ui


RESOURCES += \
    MyResources.qrc
