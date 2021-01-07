#ifndef RESERVATION_H
#define RESERVATION_H
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
#include<QtCore>
#include<QtGui>

class Equipement
{
private :
QString id;
QString nom;
QString nombre;
QString adresse;
QString prix;
QString marque;
public:
    Equipement(QString,QString,QString,QString,QString,QString);
    Equipement();

      void setId(QString n){id=n;}
      void setNom(QString n){nom=n;}
      void setNombre(QString n){nombre=n;}
      void setAdresse(QString n){adresse=n;}
      void setPrix(QString n){prix=n;}
      void setMarque(QString n){marque=n;}

      QString getId(){return id;}
      QString getNom(){return nom;}
      QString getNombre(){return nombre;}
      QString getAdresse(){return adresse;}
      QString getPrix(){return prix;}
      QString getMarque(){return marque;}

      bool ajouterequipement();
      void afficherequipement(Ui::MainWindow *ui);
      void selectionnerequipement(Ui::MainWindow *ui,const QModelIndex &index);
      bool modifierequipement();
      bool supprimerequipement(Ui::MainWindow *ui);
      void creationpdf();
bool verif_id(QString ch_id);
      ~Equipement(){};

};

#endif // RESERVATION_H
