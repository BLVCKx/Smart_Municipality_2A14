#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include <QThread>
#include <QWidget>
#include <QDialog>
#include <QSqlQuery>
#include<QSqlQueryModel>

class abonnement
{
    int id,ref_moy;
    QString nom,prenom,payement;
public:
    abonnement();

    abonnement(int id,QString nom,QString prenom,int ref_moy,QString payement);
    int get_id();
    QString get_nom();
    QString get_prenom();
    int get_ref_moy();
    QString get_payement();
    void set_id(int);
    void set_nom(QString);
    void set_prenom(QString);
    void set_ref_moy(int);
    void set_payement(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    void chercher(int rm,QString n, QString p);
    void chercher_id(int idd);
    void chercher_nom_prenom(QString n, QString p);

    QSqlQueryModel* afficher_unabonnement();
    QSqlQueryModel* afficher_unabonnement_id();
    QSqlQueryModel* afficher_unabonnement_nom_prenom();

};

#endif // ABONNEMENT_H
