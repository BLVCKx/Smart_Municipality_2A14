#include "devis.h"
#include <QDate>
#include <QString>
#include <QDebug>
devis::devis()
{
    this->CODE_DEV=0;
    this->DATE_DEV="";
    this->MONTNET_DEV=0;
    this->DESC_DEV="";
}
devis::devis(int CODE_DEV,int MONTNET_DEV ,QString DESC_DEV,QString DATE_DEV)
{
    this->CODE_DEV=CODE_DEV;
    this->MONTNET_DEV=MONTNET_DEV;
    this->DESC_DEV=DESC_DEV;
    this->DATE_DEV=DATE_DEV;
}
bool devis::ajouter() //works
{
QSqlQuery query;
query.prepare("INSERT INTO DEVIS(CODE_DEV,MONTNET_DEV,DATE_DEV,DESC_DEV)"
              " VALUES(:CODE_DEV,:MONTNET_DEV,:DATE_DEV,:DESC_DEV)");

query.bindValue(":CODE_DEV",getCODE_DEV());
query.bindValue(":MONTNET_DEV",getMONTNET_DEV());
query.bindValue(":DESC_DEV",getDESC_DEV());
query.bindValue(":DATE_DEV",getDATE_DEV());
return query.exec();
}
QSqlQueryModel * devis::afficher() //Works
    {
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from devis");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CODE_DEV")); //horizontal
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("MONTNET_DEV")); //horizontal
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DESC_DEV")); //horizontal
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_DEV")); //horizontal
    return model;
    }

bool devis::supprimer(int CODE_DEV) //works
{
    QSqlQuery query;
    QString res = QString::number(CODE_DEV);
    query.prepare("DELETE FROM DEVIS WHERE CODE_DEV = :CODE_DEV");
    query.bindValue(":CODE_DEV",res);
    return query.exec();
    }
QSqlQueryModel *devis::recherche(int CODE_DEV) //Works
{
    QString query1="SELECT * FROM DEVIS WHERE CODE_DEV=";
    QString idtxt= QString::number(CODE_DEV);
    QString queryfull=query1 + idtxt;
  // qDebug() << "query  :" << queryfull;

    QSqlQueryModel * model = new QSqlQueryModel();
      model->setQuery(queryfull);
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("CODE_DEV")); //horizontal
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("MONTNET_DEV")); //horizontal
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("DESC_DEV")); //horizontal
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_DEV")); //horizontal
    return model;
}

bool devis::modifier(Ui::MainWindow *ui)
{
    QSqlQuery query;
       int a = ui->lineEdit_19->text().toInt();
       int b = ui->lineEdit_20->text().toInt();
       QString c = ui->lineEdit_21->text();
     QString f  = ui->lineEdit_22->text();
      QString teta= QString::number(a);
      QString alpha= QString::number(b);


       query.prepare ("update DEVIS set CODE_DEV ='"+teta+"', MONTNET_DEV='"+alpha+"', DATE_DEV='"+c+"',DESC_DEV ='"+f+"' WHERE CODE_DEV ='"+teta+"'");
      return query.exec();
}
QSqlQueryModel * devis::afficher_choix1(QString choix)//trier
{
    QSqlQueryModel * model =new QSqlQueryModel();

    if (choix=="DATE_DEV")
    {
     model->setQuery("SELECT * FROM DEVIS  ORDER BY DATE_DEV;");
    }
    else if(choix=="MONTNET_DEV")
    {
        model->setQuery("SELECT * FROM DEVIS  ORDER BY MONTNET_DEV  ASC ;");
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_DEV"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_DEV"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTNET_DEV"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESC_DEV"));

    return model;
}

void devis::tri_montant_d(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from devis order by MONTNET_DEV DESC");
    q.exec();
    modal->setQuery(q);
    ui->tableView_8->setModel(modal);

}


void devis::tri_montant_a(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modalx=new QSqlQueryModel();
    q.prepare("select * from devis order by MONTNET_DEV ASC");
    q.exec();
    modalx->setQuery(q);
    ui->tableView_8->setModel(modalx);

}

int devis::revenus_total()
{
    int revenus_tot=0;
    QSqlQuery query;
    query.prepare("select MONTNET_DEV from DEVIS where CODE_DEV>0");
    query.exec();
    while(query.next()){
        revenus_tot+=query.value(0).toInt();
    }
    return revenus_tot;
}
