#ifndef DEVIS_H
#define DEVIS_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDate>
#include "ui_mainwindow.h"

class devis
{
    int CODE_DEV;
    QString DATE_DEV;
    int MONTNET_DEV;
    QString DESC_DEV;
public:
    devis();
    devis(int CODE_DEV,int MONTNET_DEV,QString DESC_DEV,QString DATE_DEV);

    //getters
    int getCODE_DEV(){return CODE_DEV;}
    int getMONTNET_DEV(){return MONTNET_DEV;}
    QString getDESC_DEV(){return DESC_DEV;}
    QString getDATE_DEV(){return DATE_DEV;}

    //Setters
    void setCODE_DEV(int x){CODE_DEV = x ;}
    void setMONTNET_DEV(int x){MONTNET_DEV = x ;}
    void setDESC_DEV(QString x){DATE_DEV = x ;}
    void setDATE_DEV(QString x){DATE_DEV = x ;}
    int revenus_total();
    void tri_montant_a(Ui::MainWindow *ui);
    void tri_montant_d(Ui::MainWindow *ui);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * recherche(int CODE_DEVIS);
    bool modifier(Ui::MainWindow *ui);
    QSqlQueryModel * afficher_choix1(QString choix);
    bool imprimer();

};



#endif // DEVIS_H
