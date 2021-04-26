QT       += core gui sql charts network multimedia multimediawidgets axcontainer serialport printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    affaire.cpp \
    affectations.cpp \
    connection.cpp \
    excel.cpp \
    intervenant.cpp \
    main.cpp \
    messengerclient.cpp \
    messengerconnection.cpp \
    missions.cpp \
    notification.cpp \
    policestation.cpp \
    vehicule.cpp

HEADERS += \
    affaire.h \
    affectations.h \
    connection.h \
    excel.h \
    intervenant.h \
    messengerclient.h \
    messengerconnection.h \
    missions.h \
    notification.h \
    policestation.h \
    vehicule.h

FORMS += \
    messengerclient.ui \
    messengerconnection.ui \
    policestation.ui


QMAKE_CXXFLAGS += -std=gnu++11
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
