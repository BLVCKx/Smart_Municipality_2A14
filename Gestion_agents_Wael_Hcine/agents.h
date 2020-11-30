#ifndef AGENTS_H
#define AGENTS_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
class agents
{protected:
     QString nom,prenom,email;
     QString CIN,tel;
     QString date_naissance;

     int id;
public:
    agents();
    agents(QString CIN,QString nom,QString prenom,QString date_naissance,QString email,QString tel);
     QString get_CIN();
     QString get_nom();
     QString get_prenom();
     QString get_date();
      QString get_email();
     QString get_tel();
     void set_CIN(QString CIN1){CIN=CIN1;};
     void set_nom(QString nom1 ){nom=nom1;}
     void set_prenom(QString prenom1){prenom=prenom1;}
     void set_email(QString email1){email=email1;}
     void set_date(QString date_naissance1){date_naissance=date_naissance1;}
     void set_tel(QString Tel1){tel=Tel1;}
     bool ajouter(QString CIN,QString nom,QString prenom,QString date_naissance,QString email,QString tel);
     QSqlQueryModel * afficher();
    agents Rechercheragents(QString nom1);
    QSqlQueryModel *ConsulterPointageParticulier(QString nom1, int *RowCount);
   bool supprimer(Ui::MainWindow *ui);
    bool supprimer1(Ui::MainWindow *ui);
    bool modifier(QString CIN,QString nom,QString prenom,QString Date_naissance,QString email,QString tel);
void afficher1(Ui::MainWindow *ui);
bool modifier1(Ui::MainWindow *ui);
QSqlQueryModel *getModelSpecial(QString inputValue,QString filterChecked);
QSqlQueryModel *afficher_choix1(QString choix);
    void setIDtoDisplay(int id){
        this->id=id;
    }
    int getIDtoDisplay(){
        return id;
    }
    void getData(int ID);
void setData(QSqlQuery query);

};

#endif // AGENTS_H
