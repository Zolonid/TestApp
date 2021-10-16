QT       += core gui network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
#TEMPLATE=vcapp
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connectiondialog.cpp \
    connectionmanager.cpp \
    consolewidget.cpp \
    main.cpp \
    mainwindow.cpp \
    testwidget.cpp \
    util.cpp

HEADERS += \
    connectiondialog.h \
    connectionmanager.h \
    consolewidget.h \
    mainwindow.h \
    testwidget.h \
    util.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
