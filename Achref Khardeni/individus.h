#ifndef INDIVIDUS_H
#define INDIVIDUS_H

#include<QDate>
#include<QString>
#include"QSqlQueryModel"
#include"QSqlQuery"
class individus
{ public:
    individus();
       individus(int,QString,QString,QDate,int);
       int get_cin();
          QString get_nom();
          QString get_prenom();
          QDate get_datedenaissance();
          int get_idl();

          bool ajouter();
       bool Supprimer_individus(int);
          bool Modifier_individus(int cin,QString nom,QString prenom,QDate datedenaissance,int idl);
          QSqlQueryModel * Afficher_individus();

   private :
          int idl,cin;
          QString nom,prenom;
          QDate datedenaissance ;

};
#endif // INDIVIDUS_H
