QT       += core gui sql
QT       += multimedia
QT       += printsupport
QT       += serialport
QT       += network
QT       += core gui sql charts
QT       += core gui axcontainer
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    affectations.cpp \
    connection.cpp \
    excel.cpp \
    main.cpp \
    missions.cpp \
    notification.cpp \
    qr_code.cpp \
    vehicule.cpp \
    vehiculemission.cpp

HEADERS += \
    affectations.h \
    connection.h \
    excel.h \
    missions.h \
    notification.h \
    qr_code.h \
    vehicule.h \
    vehiculemission.h

FORMS += \
    vehiculemission.ui
TARGET =sound

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Sound.qrc \
    resources.qrc
