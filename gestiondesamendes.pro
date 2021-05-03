QT       += core gui sql
QT       += core gui printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    amende.cpp \
    calculator.cpp \
    connection.cpp \
    excel.cpp \
    main.cpp \
    gestionamende.cpp \
    policier.cpp

HEADERS += \
    amende.h \
    calculator.h \
    connection.h \
    excel.h \
    gestionamende.h \
    policier.h

FORMS += \
    calculator.ui \
    gestionamende.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
