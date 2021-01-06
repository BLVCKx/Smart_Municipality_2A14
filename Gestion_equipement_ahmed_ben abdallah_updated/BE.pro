QT       += core gui sql printsupport multimedia serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Blocc.cpp \
    accueil.cpp \
    arduinoo.cpp \
    connexion.cpp \
    equipement.cpp \
    main.cpp \
    dialog.cpp \
    stati.cpp

HEADERS += \
    Blocc.h \
    accueil.h \
    arduinoo.h \
    connexion.h \
    dialog.h \
    equipement.h \
    stati.h

FORMS += \
    accueil.ui \
    arduinoo.ui \
    dialog.ui \
    stati.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc
