#include "abonnement.h"
#include "QString"

abonnement::abonnement()
{

}
abonnement::abonnement(int id,QString nom,QString prenom,int ref_moy,QString payement)
{
    this->id=id ;
    this->nom=nom;
    this->prenom=prenom ;
    this->ref_moy=ref_moy;
    this->payement=payement;
}

int  abonnement::get_id(){return id ;}
QString abonnement::get_nom(){return nom ;}
QString abonnement::get_prenom(){return prenom ;}
int abonnement::get_ref_moy(){return ref_moy;}
QString abonnement::get_payement(){return payement;}
void abonnement::set_id(int a){id=a;}
void abonnement::set_nom(QString a){nom=a;}
void abonnement::set_prenom(QString a){prenom=a;}
void abonnement::set_ref_moy(int a){ref_moy=a;}
void abonnement::set_payement(QString a){payement=a;}


bool  abonnement::ajouter()
{

    QSqlQuery query;
  QString id_string= QString::number(id);
  QString ref_moy_string= QString::number(ref_moy);

         query.prepare("INSERT INTO abonnement (id,nom,prenom,ref_moy,payement) "
                       "VALUES (:id,:nom,:prenom,:ref_moy,:payement)");
         query.bindValue(":id",id);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":ref_moy", ref_moy);
         query.bindValue(":payement", payement);

        return query.exec();

}
bool abonnement::supprimer(int id)
{
    QSqlQuery query;
         query.prepare("DELETE from abonnement where id= :id");
         query.bindValue(":id", id);
        return query.exec();


}

QSqlQueryModel* abonnement::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM abonnement");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("ref_moy"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("payement"));

  return  model;
}


bool abonnement::modifier()
{

 QSqlQuery query ;
 QString id_string= QString::number(id);
 QString ref_moy_string= QString::number(ref_moy);
 query.prepare("update abonnement set nom=:nom,prenom=:prenom,ref_moy=:ref_moy,payement=:payement where id=:id ");

 query.bindValue(":id",id);
 query.bindValue(":nom", nom);
 query.bindValue(":prenom", prenom);
 query.bindValue(":ref_moy",ref_moy);
 query.bindValue(":payement", payement);

 return query.exec();

}

void abonnement::chercher(int rm,QString n, QString p)
{

    QSqlQuery query1;
    query1.prepare("select * from abonnement where ref_moy=:rm and nom=:n and prenom=:p");
    query1.bindValue(":rm",rm);
    query1.bindValue(":n",n);
    query1.bindValue(":p",p);
    query1.exec();
    while(query1.next())
    {
        id=query1.value(0).toInt();
        nom= query1.value(1).toString();
        prenom = query1.value(2).toString();
        ref_moy = query1.value(3).toInt();
       payement=query1.value(4).toString();
    }

}
void abonnement::chercher_id(int idd)
{
    QSqlQuery query1;
    query1.prepare("select * from abonnement where id=:idd ");
    query1.bindValue(":idd",idd);
    query1.exec();
    while(query1.next())
    {
        id=query1.value(0).toInt();
        nom= query1.value(1).toString();
        prenom = query1.value(2).toString();
        ref_moy = query1.value(3).toInt();
       payement=query1.value(4).toString();
    }


}

void abonnement::chercher_nom_prenom(QString n, QString p)

{
    QSqlQuery query1;
    query1.prepare("select * from abonnement where nom=:n and prenom=:p");
    query1.bindValue(":n",n);
    query1.bindValue(":p",p);
    query1.exec();
    while(query1.next())
    {
        id=query1.value(0).toInt();
        nom= query1.value(1).toString();
        prenom = query1.value(2).toString();
        ref_moy = query1.value(3).toInt();
       payement=query1.value(4).toString();
    }


}

QSqlQueryModel* abonnement::afficher_unabonnement()
{
  QSqlQueryModel* model=new QSqlQueryModel();


  QString ref_moy_string= QString::number(ref_moy);


   model->setQuery("SELECT* FROM  abonnement where ref_moy='"+ref_moy_string+"' and nom='"+nom+"'and  prenom='"+prenom+"'");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("ref_moy"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("payement"));


   return  model;
}
QSqlQueryModel* abonnement::afficher_unabonnement_id()
{
  QSqlQueryModel* model=new QSqlQueryModel();


  QString id_string= QString::number(id);


   model->setQuery("SELECT* FROM abonnement where id='"+id_string+"'");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("ref_moy"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("payement"));


   return  model;
}
QSqlQueryModel* abonnement::afficher_unabonnement_nom_prenom()
{
  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM abonnement where nom='"+nom+"'and  prenom='"+prenom+"' ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("ref_moy"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("payement"));


   return  model;
}
