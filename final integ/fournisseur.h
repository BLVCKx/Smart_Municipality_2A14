#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDate>
#include "ui_mainwindow.h"

class fournisseur
{
    int ID_FOUR;
    QString NOM_FOUR;
    QString ADRESSE_FOUR;
    int TEL_FOUR;
    QString EMAIL_FOUR;
public:
    fournisseur();
    fournisseur(int ID_FOUR,int Tel,QString nom,QString ADRESSE_FOUR,QString email);

    //getters
    int getID_FOUR(){return ID_FOUR;}
    int getTEL_FOUR(){return TEL_FOUR;}
    QString getNOM_FOUR(){return NOM_FOUR;}
    QString getADRESSE_FOUR(){return ADRESSE_FOUR;}
    QString getEMAIL_FOUR(){return EMAIL_FOUR;}
 QSqlQueryModel * tri_nom();
  QSqlQueryModel * tri_id();
    //Setters
    void setID_FOUR(int x){ID_FOUR = x ;}
    void setTEL_FOUR(int x){TEL_FOUR = x ;}
    void setNOM_FOUR(QString x){NOM_FOUR = x ;}
    void setADRESSE_FOUR(QString x){ADRESSE_FOUR = x ;}
    void setEMAIL_FOUR(QString x) {EMAIL_FOUR= x;}


    bool ajouter(int a, QString b,QString c,QString d,int e);
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel *recherche(int ID_FOUR);
    QSqlQueryModel * afficher_choix1(QString choix);
    bool modifier(Ui::MainWindow *ui);
};



#endif // FOURNISSEUR_H
