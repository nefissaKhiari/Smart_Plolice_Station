QT       += core gui sql charts network multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    affaire.cpp \
    connection.cpp \
    intervenant.cpp \
    main.cpp \
    affairesjuridiques.cpp \
    messengerclient.cpp \
    messengerconnection.cpp

HEADERS += \
    affaire.h \
    affairesjuridiques.h \
    connection.h \
    intervenant.h \
    messengerclient.h \
    messengerconnection.h

FORMS += \
    affairesjuridiques.ui \
    messengerclient.ui \
    messengerconnection.ui

QMAKE_CXXFLAGS += -std=gnu++11
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recources.qrc
