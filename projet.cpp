#include "projet.h"
#include <QSqlQuery>
Projet::Projet()
{
    id=0;
    nom="";
    emplacement="";
    lieu="";
    email="";
    contenue="";
    description="";

}
Projet::Projet(int id,QString nom,QString emplacement,QString lieu,QString email,QString contenue,QString  description)
{
    this->id=id;
    this->nom=nom;
     this->emplacement=emplacement;
    this->lieu=lieu;
    this->email=email;
    this->contenue=contenue;
    this->description=description;
}
Projet::~Projet()
{

}


QString Projet::getnom(){
    return nom;
}
void Projet::setnom(QString nom){
    this->nom=nom;
}

int Projet::getId(){
    return id;
}
void Projet::setId(int id){
    this->id=id;
}
QString Projet::getemplacement(){
    return emplacement;
}
void Projet::setemplacement(QString emplacement){
    this->emplacement=emplacement;
}
QString Projet::getlieu(){
    return lieu;
}
void Projet::setlieu(QString lieu){
    this->lieu=lieu;
}
QString Projet::getcontenue(){
    return contenue;
}
void Projet::setcontenue(QString contenue){
    this->contenue=contenue;
}
QString Projet::getdescription(){
    return description;
}
void Projet::setdescription(QString description){
    this->description=description;
}
QString Projet::getemail(){
    return email;
}
void Projet::setemail(QString email){
    this->email=email;
}



bool Projet::ajouter(){
    QSqlQuery query;
    query.prepare("insert into Projet (id,nom,emplacement,lieu,email,contenue,description) values (:id,:nom,:emplacement,:lieu,:email,:contenue,:description)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":emplacement",emplacement);
    query.bindValue(":lieu",lieu);
     query.bindValue(":email",email);
      query.bindValue(":contenue",contenue);
       query.bindValue(":description",description);

    return query.exec();
}

bool Projet::supprimer(int id){
    QSqlQuery q;
    q.prepare("select * from Projet where id=:id");
    q.bindValue(":id",id);
    q.exec();
    int total=0; //mch mawjoud mayfasakhch
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("delete from Projet where id=:id");
        query.bindValue(":id",id);

        return query.exec();
    }
    else{
        return false;
    }


}

bool Projet::modifier(int idc ,QString nom,QString emplacement,QString lieu,QString email,QString contenue,QString  description){
    QSqlQuery query;
    query.prepare("update Projet set nom=:nom,emplacement=:emplacement,lieu=:lieu,email=:email,contenue=:contenue,description=:description where id=:idc");
    query.bindValue(":id",id);

    query.bindValue(":nom",nom);
    query.bindValue(":emplacement",emplacement);
    query.bindValue(":lieu",lieu);
     query.bindValue(":email",email);
      query.bindValue(":contenue",contenue);
       query.bindValue(":description",description);

    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel * Projet::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Projet");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONTENUE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DESCRIPTION"));


    return model;
}


QSqlQueryModel * Projet::chercher_Projet_par_nom(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Projet WHERE NOM like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIEU"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONTENUE"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("DESCRIPTION"));

        return model ;
    }

 }

QSqlQueryModel *Projet::chercher_Projet_par_id(QString idd)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Projet WHERE ID like '"+idd+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIEU"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONTENUE"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("DESCRIPTION"));
        return model ;
    }
}

QSqlQueryModel* Projet:: trier()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Projet order by nom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONTENUE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DESCRIPTION"));

    return model;
}

QSqlQueryModel* Projet:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Projet order by id desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONTENUE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DESCRIPTION"));

    return model;
}

QSqlQueryModel* Projet::recherche_nom(QString nom){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Projet WHERE NOM like '"+nom+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONTENUE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    return model ;
}


 bool Projet::verifierExnoms(QString nom){
 int i=0;

 QSqlQuery query;
 query.prepare("select * from Projet where NOM= ? ");
query.addBindValue(nom);
 if(query.exec())
 {while(query.next())
     {i++;}}

 if(i!=0)
     return true ;
 else
     return false;}


