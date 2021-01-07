#include "fournisseur.h"
#include <QDate>
#include <QString>
#include <QDebug>
fournisseur::fournisseur()
{
    this->ID_FOUR=0;
    this->NOM_FOUR="";
    this->ADRESSE_FOUR="";
    this->TEL_FOUR=0;
    this->EMAIL_FOUR="";
}
fournisseur::fournisseur(int ID_FOUR,int TEL_FOUR,QString NOM_FOUR,QString ADRESSE_FOUR,QString EMAIL_FOUR)
{
    this->ID_FOUR=ID_FOUR;
    this->TEL_FOUR=TEL_FOUR;
    this->NOM_FOUR=NOM_FOUR;
    this->ADRESSE_FOUR=ADRESSE_FOUR;
    this->EMAIL_FOUR=EMAIL_FOUR;
}
bool fournisseur::ajouter(int a, QString b,QString c,QString d,int e) //works
{
QSqlQuery query;
query.prepare("INSERT INTO FOURNISSEUR (ID_FOUR,NOM_FOUR,ADRESSE_FOUR,EMAIL_FOUR,TEL_FOUR) "
              "VALUES(:ID_FOUR,:NOM_FOUR,:ADRESSE_FOUR,:EMAIL_FOUR,:TEL_FOUR)");

query.bindValue(":ID_FOUR",a);
query.bindValue(":NOM_FOUR",b);
query.bindValue(":ADRESSE_FOUR",c);
query.bindValue(":EMAIL_FOUR",d);
query.bindValue(":TEL_FOUR",e);
return query.exec();
}
QSqlQueryModel * fournisseur::afficher() //Works
    {
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_FOUR")); //horizontal
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_FOUR")); //horizontal
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE_FOUR")); //horizontal
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("EMAIL_FOUR")); //horizontal
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TEL_FOUR")); //horizontal
    return model;
    }

bool fournisseur::supprimer(int ID_FOUR) //works
{
    QSqlQuery query;
    QString res = QString::number(ID_FOUR);
    query.prepare("DELETE FROM FOURNISSEUR WHERE ID_FOUR = :ID_FOUR");
    query.bindValue(":ID_FOUR",res);
    return query.exec();
    }
QSqlQueryModel *fournisseur::recherche(int ID_FOUR) //Works
{
    QString query1="SELECT * FROM FOURNISSEUR WHERE ID_FOUR=";
    QString idtxt= QString::number(ID_FOUR);
    QString queryfull=query1 + idtxt;
  // qDebug() << "query  :" << queryfull;

    QSqlQueryModel * model = new QSqlQueryModel();
      model->setQuery(queryfull);
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_FOUR")); //horizontal
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_FOUR")); //horizontal
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("TEL_FOUR")); //horizontal
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE")); //horizontal
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("EMAIL_FOUR")); //horizontal
    return model;
}
QSqlQueryModel * fournisseur::afficher_choix1(QString choix)//trier
{
    QSqlQueryModel * model =new QSqlQueryModel();

    if (choix=="")
    {
     model->setQuery("SELECT * FROM fournisseur  ORDER BY NOM;");
    }
    else if(choix=="Tel")
    {
        model->setQuery("SELECT * FROM fournisseur  ORDER BY tel  ASC ;");
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_FOUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE_FOUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL_FOUR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL_FOUR"));

    return model;
}

bool fournisseur:: modifier(Ui::MainWindow *ui)
{
    QSqlQuery query;
       int a = ui->lineEdit_14->text().toInt();
       QString b = ui->lineEdit_15->text();
       QString c = ui->lineEdit_16->text();
       QString d = ui->lineEdit_17->text();

       int  f  = ui->lineEdit_18->text().toInt();
      QString teta= QString::number(a);
      QString alpha= QString::number(f);

       query.prepare ("update FOURNISSEUR set ID_FOUR ='"+teta+"', NOM_FOUR='"+b+"', ADRESSE_FOUR='"+c+"',EMAIL_FOUR ='"+d+"',TEL_FOUR ='"+alpha+"' WHERE ID_FOUR ='"+teta+"'");
      return query.exec();


  }
 QSqlQueryModel * fournisseur::tri_id()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model ->setQuery("select * from fournisseur order by ID_FOUR ASC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("telephone"));
     return model;
 }

 QSqlQueryModel * fournisseur::tri_nom()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model ->setQuery("select * from fournisseur order by NOM_FOUR ASC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("telephone"));
     return model;
 }
