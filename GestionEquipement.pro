QT       += core gui sql charts multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    equipement.cpp \
    main.cpp \
    gestionequipement.cpp \
    maintenance.cpp \
    notification.cpp

HEADERS += \
    connection.h \
    equipement.h \
    gestionequipement.h \
    maintenance.h \
    notification.h

FORMS += \
    gestionequipement.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressource.qrc
