#include "profil.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
profil::profil()
{

}
profil::profil(QString ID,QString nom_profil,QString salaire,QString description ,QString nb_agents)
 {
     this->ID=ID;
     this->nom_profil=nom_profil;
     this->salaire=salaire;
     this->description=description;
     this->nb_agents=nb_agents;

 }
QString profil::get_ID(){return ID;}
QString profil::get_nom_profil(){return nom_profil;}
QString profil::get_salaire(){return salaire;}
QString profil::get_description(){return description;}
QString profil::get_nb_agents(){return nb_agents;}

bool profil::ajouter_p(QString ID, QString nom_profil, QString salaire, QString description,QString nb_agents)//--------------ajouter------//
{
    QSqlQuery query;
    query.prepare("INSERT INTO profil (ID, nom_profil, salaire,description,nb_agents) "
                        "VALUES (:ID,:nom_profil,:salaire,:description,:nb_agents)");
    query.bindValue(":ID",ID);
    query.bindValue(":nom_profil",nom_profil);
    query.bindValue(":salaire",salaire);
    query.bindValue(":description",description);
    query.bindValue(":nb_agents",nb_agents);
    return    query.exec();
}
void profil::afficher_P(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from profil");
    q.exec();
    modal->setQuery(q);
    ui->tab_profil->setModel(modal);
}
QSqlQueryModel *profil::getModelSpecial(QString inputValue,QString filterChecked)
{
    QSqlQueryModel * model= new QSqlQueryModel ();
    QSqlQuery query;
    query.prepare("SELECT *FROM profil WHERE "+filterChecked+" LIKE '%' || :inputValue || '%' ");
    query.bindValue(":inputValue",inputValue);
    query.exec();
    model->setQuery(query);
    return model;
}
QSqlQueryModel * profil::afficher_choix_p(QString choix)//trier
{
    QSqlQueryModel * model =new QSqlQueryModel();

    if (choix=="ID")
    {
     model->setQuery("SELECT * FROM profil  ORDER BY ID;");
    }
    else if(choix=="nom profil")
    {
        model->setQuery("SELECT * FROM profil  ORDER BY NOM_PROFIL;");
    }
    else if(choix=="salaire")
    {
        model->setQuery("SELECT * FROM profil  ORDER BY salaire;");
    }
    else if (choix=="nombre des agents")
    {
        model->setQuery("SELECT * FROM profil ORDER BY nb_agents ");
    }
    else if (choix=="trier par")
    {
        model->setQuery("SELECT * FROM profil");
    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PROFIL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SALAIRE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NB_AGNETS"));
    return model;
}
bool profil::modifier_p(Ui::MainWindow *ui)
{
    QMessageBox msgBox ;

   QString ID = ui->IDp_m->text();
   QString nom_profil= ui->nomp_m->text();
   QString salaire= ui->salairep_m->text();
   QString description=ui->descriptionp_m->text();
   QString nb_agents =ui->nbagentsp_m->text();
   profil P(ID, nom_profil, salaire,description,nb_agents);
   QSqlQuery query;
   query.prepare ("update profil set ID ='"+ID+"', nom_profil ='"+nom_profil+"',salaire ='"+salaire+"', description ='"+description+"',nb_agents ='"+nb_agents+"'where ID='"+ID+"'");
   return  (query.exec());

}
bool profil::supprimer_p(Ui::MainWindow *ui)
{

    QSqlQuery q;
    QString ref=ui->tab_profil->model()->data(ui->tab_profil->model()->index(ui->tab_profil->selectionModel()->currentIndex().row(),0)).toString();
    q.prepare("DELETE FROM profil WHERE ID ='"+ref+"'");
    return (q.exec());



}
