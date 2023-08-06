QT       += core gui sql
QT +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Frage.cpp \
    GameSession.cpp \
    lifelines.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    test.cpp \
    testcommit.cpp

HEADERS += \
    Frage.h \
    GameSession.h \
    lifelines.h \
    mainwindow.h \
    player.h \
    test.h \
    testcommit.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/'../../../../../../Program Files/MySQL/MySQL Connector C 6.1/lib/' -llibmysql

INCLUDEPATH += $$PWD/'../../../../../../Program Files/MySQL/MySQL Connector C 6.1/include'
DEPENDPATH += $$PWD/'../../../../../../Program Files/MySQL/MySQL Connector C 6.1/include'
