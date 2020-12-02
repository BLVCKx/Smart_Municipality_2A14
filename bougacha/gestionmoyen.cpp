#include "gestionmoyen.h"

gestionmoyen::gestionmoyen()
{

}
gestionmoyen::gestionmoyen(int ref,QString modele,QString confort,int nombre_de_place,QString climatisation)
{
    this->ref=ref ;
    this->modele=modele;
    this->confort=confort ;
    this->nombre_de_place=nombre_de_place;
    this->climatisation=climatisation;
}

int  gestionmoyen::get_ref(){return ref ;}
QString gestionmoyen::get_modele(){return modele ;}
QString gestionmoyen::get_confort(){return confort ;}
int gestionmoyen::get_nombre_de_place(){return nombre_de_place;}
QString gestionmoyen::get_climatisation(){return climatisation;}
void gestionmoyen::set_ref(int){this->ref=ref;}
void gestionmoyen::set_modele(QString){this->modele=modele;}
void gestionmoyen::set_confort(QString){this->confort=confort;}
void gestionmoyen::set_nombre_de_place(int){this->nombre_de_place=nombre_de_place;}
void gestionmoyen::set_climatisation(QString){this->climatisation=climatisation;}


bool  gestionmoyen::ajouter()
{

    QSqlQuery query;
  QString ref_string= QString::number(ref);
  QString nombre_de_place_string= QString::number(nombre_de_place);

         query.prepare("INSERT INTO transport ( ref,modele,confort,nombre_de_place,climatisation) "
                       "VALUES (:ref,:modele,:confort,:nombre_de_place,:climatisation)");
         query.bindValue(":ref",ref);
         query.bindValue(":modele", modele);
         query.bindValue(":confort", confort);
         query.bindValue(":nombre_de_place", nombre_de_place);
         query.bindValue(":climatisation", climatisation);

        return query.exec();

}
bool gestionmoyen::supprimer(int reff)
{
    QSqlQuery query;
         query.prepare("DELETE from transport where ref= :ref");
         query.bindValue(":ref", reff);
        return query.exec();


}

QSqlQueryModel* gestionmoyen::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM transport");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("modele"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("confort"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_de_place"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("climatisation"));

  return  model;
}


bool gestionmoyen::modifier()
{

 QSqlQuery query ;
 QString ref_string= QString::number(ref);
 QString nombre_de_place_string= QString::number(nombre_de_place);
 query.prepare("update  transport set  ref=:ref,modele=:modele,confort=:confort,nombre_de_place=:nombre_de_place,climatisation=:climatisation where ref=:ref ");

 query.bindValue(":ref",ref);
 query.bindValue(":modele", modele);
 query.bindValue(":confort", confort);
 query.bindValue(":nombre_de_place",nombre_de_place);
 query.bindValue(":climatisation", climatisation);

 return query.exec();

}

void gestionmoyen::chercher(QString m,int np, QString c)
{

    QSqlQuery query1;
    query1.prepare("select * from transport where modele=:m and nombre_de_place=:np and  confort=:c");
    query1.bindValue(":m",m);
    query1.bindValue(":np",np);
    query1.bindValue(":c",c);
    query1.exec();
    while(query1.next())
    {
    ref=query1.value(0).toInt();
    modele= query1.value(1).toString();
    confort = query1.value(2).toString();
    nombre_de_place = query1.value(3).toInt();
    climatisation=query1.value(4).toString();
    }

}
void gestionmoyen::chercher_ref(int r)
{
    QSqlQuery query1;
    query1.prepare("select * from transport where ref=:r ");
    query1.bindValue(":r",r);
    query1.exec();
    while(query1.next())
    {
        ref=query1.value(0).toInt();
        modele= query1.value(1).toString();
        confort = query1.value(2).toString();
        nombre_de_place = query1.value(3).toInt();
       climatisation=query1.value(4).toString();
    }


}
void gestionmoyen::chercher_modele_confort(QString m, QString c)

{
    QSqlQuery query1;
    query1.prepare("select * from transport where modele=:m and confort=:c ");
    query1.bindValue(":m",m);
    query1.bindValue(":c",c);
    query1.exec();
    while(query1.next())
    {
        ref=query1.value(0).toInt();
        modele= query1.value(1).toString();
        confort = query1.value(2).toString();
        nombre_de_place = query1.value(3).toInt();
       climatisation=query1.value(4).toString();
    }


}

QSqlQueryModel* gestionmoyen::afficher_untransport()
{
  QSqlQueryModel* model=new QSqlQueryModel();


    QString reff;
  reff= QString::number(ref);

   model->setQuery("SELECT* FROM transport where ref='"+reff+"' and modele='"+modele+"'and  confort='"+confort+"'");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("modele"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("confort"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_de_place"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("climatisation"));


   return  model;
}
QSqlQueryModel* gestionmoyen::afficher_untransport_ref()
{
  QSqlQueryModel* model=new QSqlQueryModel();


    QString reff;
  reff= QString::number(ref);

   model->setQuery("SELECT* FROM transport where ref='"+reff+"'  ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("modele"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("confort"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_de_place"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("climatisation"));


   return  model;
}
QSqlQueryModel* gestionmoyen::afficher_untransport_modele_confort()
{
  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM transport  where modele='"+modele+"'and  confort='"+confort+"' ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("modele"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("confort"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_de_place"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("climatisation"));


   return  model;
}

