QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    func_dlya_clienta.cpp \
    main.cpp \
    mainwindow.cpp \
    registr_i_auth.cpp

HEADERS += \
    client.h \
    func_dlya_clienta.h \
    mainwindow.h \
    registr_i_auth.h

FORMS += \
    mainwindow.ui \
    registr_i_auth.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
