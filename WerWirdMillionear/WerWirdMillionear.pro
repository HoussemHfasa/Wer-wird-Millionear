QT       += core gui widgets
QT +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += multimedia

LIBS += -lVLCQtCore -lVLCQtWidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AudioPlayer.cpp \
    Frage.cpp \
    GameSession.cpp \
    anmeldenseite.cpp \
    bestenlisteseite.cpp \
    lifelines.cpp \
    lose.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    settings.cpp \
    win.cpp

HEADERS += \
    AudioPlayer.h \
    Frage.h \
    GameSession.h \
    anmeldenseite.h \
    bestenlisteseite.h \
    lifelines.h \
    lose.h \
    mainwindow.h \
    player.h \
    settings.h \
    win.h

FORMS += \
    lose.ui \
    mainwindow.ui \
    settings.ui \
    win.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc \
    resource.qrc \
    resource.qrc

DISTFILES +=

SUBDIRS += \
    ../Wer_wird_millionear1/Wer_wird_millionear.pro \
    Wer_wird_millionear.pro

win32: LIBS += -L$$PWD/'../../../../../../Program Files/MySQL/MySQL Connector C 6.1/lib/' -llibmysql

INCLUDEPATH += $$PWD/'../../../../../../Program Files/MySQL/MySQL Connector C 6.1/include'
DEPENDPATH += $$PWD/'../../../../../../Program Files/MySQL/MySQL Connector C 6.1/include'

win32: LIBS += -L$$PWD/../VLC-Qt_1.1.0_win64_msvc2015/lib/ -lVLCQtWidgets

INCLUDEPATH += $$PWD/../VLC-Qt_1.1.0_win64_msvc2015/include
DEPENDPATH += $$PWD/../VLC-Qt_1.1.0_win64_msvc2015/include

win32: LIBS += -L$$PWD/../VLC-Qt_1.1.0_win64_msvc2015/lib/ -lVLCQtCore

INCLUDEPATH += $$PWD/../VLC-Qt_1.1.0_win64_msvc2015/include
DEPENDPATH += $$PWD/../VLC-Qt_1.1.0_win64_msvc2015/include

win32: LIBS += -L$$PWD/../VLC-Qt_1.1.0_win64_msvc2015/lib/ -lVLCQtQml

INCLUDEPATH += $$PWD/../VLC-Qt_1.1.0_win64_msvc2015/include
DEPENDPATH += $$PWD/../VLC-Qt_1.1.0_win64_msvc2015/include
