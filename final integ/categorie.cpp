#include "categorie.h"
#include <QSqlQuery>
Categorie::Categorie()
{
    id=0;
    nom="";
    type="";

    description="";

}
Categorie::Categorie(int id,QString nom,QString type,QString  description)
{
    this->id=id;
    this->nom=nom;
     this->type=type;
    this->description=description;
}
Categorie::~Categorie()
{

}


QString Categorie::getnom(){
    return nom;
}
void Categorie::setnom(QString nom){
    this->nom=nom;
}

int Categorie::getId(){
    return id;
}
void Categorie::setId(int id){
    this->id=id;
}
QString Categorie::gettype(){
    return type;
}
void Categorie::settype(QString type){
    this->type=type;
}

QString Categorie::getdescription(){
    return description;
}
void Categorie::setdescription(QString description){
    this->description=description;
}




bool Categorie::ajouter(){
    QSqlQuery query;
    query.prepare("insert into Categorie (id,nom,type,description) values (:id,:nom,:type,:description)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);

       query.bindValue(":description",description);

    return query.exec();
}

bool Categorie::supprimer(int id){
    QSqlQuery q;
    q.prepare("select * from Categorie where id=:id");
    q.bindValue(":id",id);
    q.exec();
    int total=0; //mch mawjoud mayfasakhch
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("delete from Categorie where id=:id");
        query.bindValue(":id",id);

        return query.exec();
    }
    else{
        return false;
    }


}

bool Categorie::modifier(int idc ,QString nom,QString type,QString  description){
    QSqlQuery query;
    query.prepare("update Categorie set nom=:nom,type=:type,description=:description where id=:idc");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":description",description);

    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel * Categorie::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Categorie");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));


    return model;
}


QSqlQueryModel * Categorie::chercher_Categorie_par_nom(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Categorie WHERE NOM like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));

        return model ;
    }

 }

QSqlQueryModel *Categorie::chercher_Categorie_par_id(QString idd)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Categorie WHERE ID like '"+idd+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
        return model ;
    }
}

QSqlQueryModel* Categorie:: trier()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Categorie order by nom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));

    return model;
}

QSqlQueryModel* Categorie:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Categorie order by id desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));

    return model;
}

QSqlQueryModel* Categorie::recherche_nom(QString nom){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Categorie WHERE NOM like '"+nom+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    return model ;
}


 bool Categorie::verifierExnoms(QString nom){
 int i=0;

 QSqlQuery query;
 query.prepare("select * from Categorie where NOM= ? ");
query.addBindValue(nom);
 if(query.exec())
 {while(query.next())
     {i++;}}

 if(i!=0)
     return true ;
 else
     return false;}


