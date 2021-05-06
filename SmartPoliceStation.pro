QT       += core gui sql charts network multimedia multimediawidgets axcontainer serialport printsupport widgets concurrent



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  quickwidgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    QrCode.cpp \
    affaire.cpp \
    affectation.cpp \
    affectations.cpp \
    amende.cpp \
    calc.cpp \
    cam.cpp \
    citoyen.cpp \
    connection.cpp \
    detenu.cpp \
    equipement.cpp \
    excel.cpp \
    exceli.cpp \
    infraction.cpp \
    intervenant.cpp \
    login.cpp \
    main.cpp \
    maintenance.cpp \
    messengerclient.cpp \
    messengerconnection.cpp \
    missions.cpp \
    notification.cpp \
    policestation.cpp \
    policier.cpp \
    service.cpp \
    smtp.cpp \
    vehicule.cpp

HEADERS += \
    QrCode.hpp \
    affaire.h \
    affectation.h \
    affectations.h \
    amende.h \
    calc.h \
    cam.h \
    citoyen.h \
    connection.h \
    detenu.h \
    equipement.h \
    excel.h \
    exceli.h \
    infraction.h \
    intervenant.h \
    login.h \
    maintenance.h \
    messengerclient.h \
    messengerconnection.h \
    missions.h \
    notification.h \
    policestation.h \
    policier.h \
    service.h \
    smtp.h \
    vehicule.h

FORMS += \
    Calc.ui \
    cam.ui \
    messengerclient.ui \
    messengerconnection.ui \
    policestation.ui


QMAKE_CXXFLAGS += -std=gnu++11
QMAKE_CXXFLAGS += -std=gnu++14
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc \
    translation.qrc
