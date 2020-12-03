#include "individus.h"
#include<QString>
#include "mainwindow.h"
#include "QSqlQuery"
#include<QMessageBox>
#include <QObject>
#include"QSqlQueryModel"
individus::individus()
{
    cin=0;
    nom="";
    prenom="";
    idl=0;
}
individus::individus(int cin,QString nom,QString prenom,QDate datedenaissance,int idl)
{


    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->datedenaissance=datedenaissance;
    this->idl=idl;
    }

int individus::get_cin()
{
    return cin;
}

QString individus::get_nom()
{
    return nom;
}
QString individus::get_prenom()
{
    return prenom;
}
QDate individus::get_datedenaissance()
{
    return datedenaissance;
}

int individus::get_idl()
{
    return idl;
}

bool individus::ajouter()
{
    QSqlQuery qry;
   QString  res=QString::number(cin);
    qry.prepare("INSERT INTO INDIVIDUS(CIN,NOM,PRENOM,DATE_DE_NAISSANCE,ID_LOGEMENT)""VALUES(:cin,:nom,:prenom,:datedenaissance,:idl)");
    qry.bindValue(":cin",cin);
    qry.bindValue(":nom",nom);
    qry.bindValue(":prenom",prenom);
    qry.bindValue(":datedenaissance",datedenaissance);
    qry.bindValue(":idl",idl);

    return qry.exec();

}

//************************
QSqlQueryModel * individus::Afficher_individus()
{
QSqlQueryModel* model= new QSqlQueryModel();
model->setQuery("select * from INDIVIDUS");
model->setHeaderData(0,Qt::Vertical,QObject::tr("cin"));
model->setHeaderData(1,Qt::Vertical,QObject::tr("nom"));
model->setHeaderData(2,Qt::Vertical,QObject::tr("prenom"));
model->setHeaderData(3,Qt::Vertical,QObject::tr("date de naissance"));
model->setHeaderData(4,Qt::Vertical,QObject::tr("idl"));
return model;
}
//*************************
bool individus::Supprimer_individus(int ind)
{
    QSqlQuery qry;
    QString res=QString::number(ind);
    qry.prepare("delete from INDIVIDUS where CIN = :cin");
    qry.bindValue(":cin",res);
    return qry.exec();
}
//************************
bool individus::Modifier_individus(int cin, QString nom, QString prenom, QDate datedenaissance, int idl)
{
    QSqlQuery qry;

    qry.prepare("update INDIVIDUS set CIN=:cin,NOM=:nom,PRENOM=:prenom,DATE_DE_NAISSANCE=:datedenaissance,ID_LOGEMENT=:idl where CIN=:cin");

    qry.bindValue(":cin",cin);
    qry.bindValue(":nom",nom);
    qry.bindValue(":prenom",prenom);
    qry.bindValue(":datedenaissance",datedenaissance);

    qry.bindValue(":idl",idl);
    return qry.exec();
}
