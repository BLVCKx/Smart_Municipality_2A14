#include "logement.h"
#include "individus.h"
#include<QString>
#include "mainwindow.h"
#include "QSqlQuery"
#include<QMessageBox>
#include <QObject>
#include"QSqlQueryModel"
logement::logement()
{
    id=0;
    nomf="";
    secteur="";
    price=0;
}
logement::logement(int id,QString nomf,QString secteur,int price)
{


    this->id=id;
    this->nomf=nomf;
    this->secteur=secteur;

    this->price=price;
    }

int logement::get_id()
{
    return id;
}

QString logement::get_nomf()
{
    return nomf;
}
QString logement::get_secteur()
{
    return secteur;
}

int logement::get_price()
{
    return price;
}

bool logement::ajouter()
{
    QSqlQuery qry;
   QString  res=QString::number(id);
    qry.prepare("INSERT INTO LOGEMENT(ID,NOMF,SECTEUR,PRICE)""VALUES(:id,:nomf,:secteur,:price)");
    qry.bindValue(":id",id);
    qry.bindValue(":nomf",nomf);
    qry.bindValue(":secteur",secteur);
    qry.bindValue(":price",price);

    return qry.exec();

}

//************************
QSqlQueryModel * logement::Afficher_logement()
{
QSqlQueryModel* model= new QSqlQueryModel();
model->setQuery("select * from LOGEMENT");
model->setHeaderData(0,Qt::Vertical,QObject::tr("id"));
model->setHeaderData(1,Qt::Vertical,QObject::tr("nomf"));
model->setHeaderData(2,Qt::Vertical,QObject::tr("secteur"));
model->setHeaderData(3,Qt::Vertical,QObject::tr("price"));
return model;
}
//*************************
bool logement::Supprimer_logement(int log)
{
    QSqlQuery qry;
    QString res=QString::number(log);
    qry.prepare("delete from LOGEMENT where ID = :id");
    qry.bindValue(":id",res);
    return qry.exec();
}
//************************
bool logement::Modifier_logement(int id, QString nomf, QString secteur, int price)
{
    QSqlQuery qry;

    qry.prepare("update LOGEMENT set ID=:id,NOMF=:nomf,SECTEUR=:secteur,PRICE=:price where ID=:id");
    qry.bindValue(":id",id);
    qry.bindValue(":nomf",nomf);
    qry.bindValue(":secteur",secteur);
    qry.bindValue(":price",price);
    return qry.exec();
}
//****************************
QSqlQueryModel * logement::CHERCHER_logement(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from LOGEMENT where ((id ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("id"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nomf"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("secteur"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("price"));
    return model;
}
//*************************
QSqlQueryModel * logement::TRIER_logement()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from LOGEMENT order by id desc");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("id"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nomf"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("secteur"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("price")); return model ;

}
QSqlQueryModel * logement::TRIER2_logement()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from LOGEMENT order by price desc");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("id"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nomf"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("secteur"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("price"));
    return model ;

}
