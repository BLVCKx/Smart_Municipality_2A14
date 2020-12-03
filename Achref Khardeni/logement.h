#ifndef LOGEMENT_H
#define LOGEMENT_H


#include<QDate>
#include<QString>
#include"QSqlQueryModel"
#include"QSqlQuery"
class logement
{ public:
    logement();
       logement(int,QString,QString,int);
       int get_id();
          QString get_nomf();
          QString get_secteur();
          int get_price();

          bool ajouter();
       bool Supprimer_logement(int);
          bool Modifier_logement(int id,QString nomf,QString secteur,int price);
          QSqlQueryModel * Afficher_logement();
          QSqlQueryModel * CHERCHER_logement(const QString &aux);
          QSqlQueryModel *TRIER2_logement();

          QSqlQueryModel *TRIER_logement();

   private :
          int id,price;
          QString nomf,secteur;
};


#endif // LOGEMENT_H
