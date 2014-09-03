#-------------------------------------------------
#
#
#
# Project Vault 1.0.0
# Project created by QtCreator 2014-07-21T12:52:35
# Developed by Denson Ngumo
# Property of Deenze
#
#
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Vault
TEMPLATE = app

RC_FILE=Vault.rc

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
    groups.cpp \
    about.cpp


HEADERS  += homescreen.h \
    database.h \
    masterpasswordform.h \
    databasesettingsform.h \
    opendatabaseform.h \
    password.h \
    serial.h \
    newentryform.h \
    changemasterkeyform.h \
    groups.h \
    about.h


FORMS    += homescreen.ui \
    masterpasswordform.ui \
    databasesettingsform.ui \
    opendatabaseform.ui \
    newentryform.ui \
    changemasterkeyform.ui \
    groups.ui \
    about.ui


RESOURCES += \
    MyResources.qrc
