#ifndef GESTIONMOYEN_H
#define GESTIONMOYEN_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>

class gestionmoyen
{
public:
    gestionmoyen();
    gestionmoyen(int,QString,QString,int,QString);
    int get_ref();
    QString get_modele();
    QString get_confort();
    int get_nombre_de_place();
    QString get_climatisation();
    void set_ref(int);
    void set_modele(QString);
    void set_confort(QString);
    void set_nombre_de_place(int);
    void set_climatisation(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    void chercher(QString m,int np, QString c);
    void chercher_ref(int r);
    void chercher_modele_confort(QString m, QString c);

    QSqlQueryModel* afficher_untransport();
    QSqlQueryModel* afficher_untransport_ref();
    QSqlQueryModel* afficher_untransport_modele_confort();
private:

    int ref,nombre_de_place ;
    QString modele,confort,climatisation;
};

#endif // GESTIONMOYEN_H




