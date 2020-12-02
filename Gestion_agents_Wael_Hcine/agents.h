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
     QDate date_naissance;
     QString nom_profil;

     int id;
public:
    agents();
    agents(QString CIN,QString nom,QString prenom,QDate date_naissance,QString email,QString tel,QString nom_profil);
     QString get_CIN();
     QString get_nom();
     QString get_prenom();
     QDate get_date();
     QString get_email();
     QString get_tel();
      QString get_nom_profil();
     void set_CIN(QString CIN1){CIN=CIN1;};
     void set_nom(QString nom1 ){nom=nom1;}
     void set_prenom(QString prenom1){prenom=prenom1;}
     void set_email(QString email1){email=email1;}
     void set_date(QDate date_naissance1){date_naissance=date_naissance1;}
     void set_tel(QString Tel1){tel=Tel1;}
     void set_nom_profil(QString nom_profil1){nom_profil=nom_profil1;}
     bool ajouter(QString CIN,QString nom,QString prenom,QDate date_naissance,QString email,QString tel,QString nom_profil);
     QSqlQueryModel * afficher();
    agents Rechercheragents(QString nom1);
    QSqlQueryModel *ConsulterPointageParticulier(QString nom1, int *RowCount);
   bool supprimer(Ui::MainWindow *ui);
    bool supprimer1(Ui::MainWindow *ui);
    bool modifier(QString CIN,QString nom,QString prenom,QDate Date_naissance,QString email,QString tel,QString nom_profil);
void afficher1(Ui::MainWindow *ui);
bool modifier1(Ui::MainWindow *ui);
QSqlQueryModel *getModelSpecial(QString inputValue,QString filterChecked);
QSqlQueryModel *afficher_choix1(QString choix);
int calculercatego(QString catego);
void departentss(Ui::MainWindow *ui);
bool verifCIN(Ui::MainWindow *ui);
bool verifnom(Ui::MainWindow *ui);
bool verifprenom(Ui::MainWindow *ui);
bool VerifMail(Ui::MainWindow *ui);
bool verifTel(Ui::MainWindow *ui);
bool verifdate(Ui::MainWindow *ui);
bool verifCIN_m(Ui::MainWindow *ui);
bool verifnom_m(Ui::MainWindow *ui);
bool verifprenom_m(Ui::MainWindow *ui);
bool VerifMail_m(Ui::MainWindow *ui);
bool verifTel_m(Ui::MainWindow *ui);
bool verifdate_m(Ui::MainWindow *ui);
void InitIndication(Ui::MainWindow *ui);


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
