QT       +=core gui sql
QT       +=core gui printsupport
QT       +=multimedia
QT       +=charts
QT       +=widgets
QT       +=serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Blocc.cpp \
    abonnement.cpp \
    agents.cpp \
    arduin.cpp \
    arduinoo.cpp \
    categorie.cpp \
    conn.cpp \
    devis.cpp \
    equipement.cpp \
    fournisseur.cpp \
    gestionmoyen.cpp \
    individus.cpp \
    logement.cpp \
    main.cpp \
    mainwindow.cpp \
    profil.cpp \
    projet.cpp \
    stati.cpp \
    statistiques.cpp

HEADERS += \
    Blocc.h \
    abonnement.h \
    agents.h \
    arduin.h \
    arduinoo.h \
    categorie.h \
    conn.h \
    devis.h \
    equipement.h \
    fournisseur.h \
    gestionmoyen.h \
    individus.h \
    logement.h \
    login.h \
    mainwindow.h \
    profil.h \
    projet.h \
    stati.h \
    statistiques.h

FORMS += \
    arduinoo.ui \
    mainwindow.ui \
    stati.ui \
    statistiques.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    files.qrc

DISTFILES += \
    arabic.qm \
    elissa-aa-baly-habibi_uCClgMns.mp3
