#ifndef CLIENT_H
#define CLIENT_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<QFileInfo>
#include<QMessageBox>
#include<QSqlQueryModel>
#include<QDebug>
#include<QFileDialog>
#include<QDialog>


class Blocc
{
private :
    QString id_bloc;
    QString nom_bloc;
    QString equipement;
    QString type_equipement;
    QString numero_four;
    QString date ;
    QString situation ;
public:
    Blocc(QString,QString,QString,QString,QString,QString,QString);
    Blocc();

    void setId(QString n){id_bloc=n;}
        void setNom(QString n){nom_bloc=n;}
        void setEquipement(QString n){equipement=n;}
        void setTypeEquipement(QString n){type_equipement=n;}
        void setNumero(QString n){numero_four=n;}
        void setDate(QString n){date=n;}
        void setSituation(QString n){situation=n;}

        QString getId(){return id_bloc;}
        QString getNom(){return nom_bloc;}
        QString getEquipement(){return equipement;}
        QString getTypeEquipement(){return type_equipement;}
        QString getNumero(){return numero_four;}
        QString getDate(){return date;}
        QString getSituation(){return situation;}

        bool ajouterbloc();
        QSqlQueryModel *afficherbloc();
        bool modifierbloc ();
        bool supprimer(Ui::MainWindow *ui);
        void recherche(Ui::MainWindow *ui);
        void TRI1(Ui::MainWindow *ui);
        void TRI2(Ui::MainWindow *ui);
        bool verif_numero(QString numero);
        bool verif_date(QString date_d);
        bool verif_nom(QString ch_nom);
        bool verif_id(QString ch_id);








    ~Blocc(){};


};

#endif // CLIENT_H
