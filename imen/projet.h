#ifndef PROJET_H
#define PROJET_H
#include <QString>
#include <QSqlQueryModel>

class Projet
{
    int id;
    QString nom;
    QString emplacement;
    QString lieu;
    QString email;
    QString contenue;
    QString description;

    public:
    Projet();
       Projet(int,QString,QString,QString,QString,QString,QString);
       ~Projet();

       int getId();
       void setId(int);
       QString getnom();
       void setnom(QString);
       QString getemplacement();
       void setemplacement(QString);
       QString getlieu();
       void setlieu(QString);
       QString getemail();
       void setemail(QString);
       QString getcontenue();
       void setcontenue(QString);
       QString getdescription();
       void setdescription(QString);


       bool ajouter();
       bool supprimer(int);
       bool modifier(int,QString,QString,QString,QString,QString,QString);
       QSqlQueryModel* afficher();
       QSqlQueryModel* recherche_nom(QString);
       Projet recherche_mail(QString);
       bool verifierExnoms(QString);

       QSqlQueryModel* trier();
       QSqlQueryModel* trier1();

       QSqlQueryModel * chercher_Projet_par_nom(QString m);


       QSqlQueryModel * chercher_Projet_par_id(QString idd);


};

#endif // PROJET_H
