#ifndef CATEGORIE_H
#define CATEGORIE_H
#include <QString>
#include <QSqlQueryModel>

class Categorie
{
    int id;
    QString nom;
    QString type;

    QString description;

    public:
    Categorie();
       Categorie(int,QString,QString,QString);
       ~Categorie();

       int getId();
       void setId(int);
       QString getnom();
       void setnom(QString);
       QString gettype();
       void settype(QString);

       QString getdescription();
       void setdescription(QString);


       bool ajouter();
       bool supprimer(int);
       bool modifier(int,QString,QString,QString);
       QSqlQueryModel* afficher();
       QSqlQueryModel* recherche_nom(QString);
      Categorie recherche_mail(QString);
       bool verifierExnoms(QString);

       QSqlQueryModel* trier();
       QSqlQueryModel* trier1();

       QSqlQueryModel * chercher_Categorie_par_nom(QString m);


       QSqlQueryModel * chercher_Categorie_par_id(QString idd);

};

#endif // CATEGORIE_H
