#include "profil.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "QAbstractItemView"
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


//----------verifaction-----//
bool profil::verifID(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->ID_0->text().isEmpty() || ui->ID_0->text().length()!=6 || ui->ID_0->text().contains(QRegExp("[^0-9]")))
    {
        ui->p1->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->p1->setPixmap(PixTrueIcon);
        return true;

    }
}
bool profil::verifnom_profil(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->nom_profil_0->text().isEmpty()||ui->nom_profil_0->text().contains(QRegExp("[^a-zA-Z]+$")))
    {
        ui->p2->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->p2->setPixmap(PixTrueIcon);
        return true;

    }
}
bool profil::verifsalaire(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->salaire_0->text().isEmpty()|| ui->salaire_0->text().contains(QRegExp("[^0-9]")))
    {
        ui->p3->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->p3->setPixmap(PixTrueIcon);
        return true;

    }
}
bool profil::verifdescription(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->description_0->text().isEmpty()||ui->description_0->text().contains(QRegExp("[^a-zA-Z]+$")))
    {
        ui->p4->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->p4->setPixmap(PixTrueIcon);
        return true;

    }
}
bool profil::verifnb_agents(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->nb_0->text().isEmpty() || ui->nb_0->text().contains(QRegExp("[^0-9]")))
    {
        ui->p5->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->p5->setPixmap(PixTrueIcon);
        return true;

    }
}


bool profil::verifIDm(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->IDp_m->text().isEmpty() || ui->IDp_m->text().length()!=6 || ui->IDp_m->text().contains(QRegExp("[^0-9]")))
    {
        ui->mp1->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->mp1->setPixmap(PixTrueIcon);
        return true;

    }
}
bool profil::verifnom_profilm(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->nomp_m->text().isEmpty()||ui->nomp_m->text().contains(QRegExp("[^a-zA-Z]+$")))
    {
        ui->mp2->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->mp2->setPixmap(PixTrueIcon);
        return true;

    }
}
bool profil::verifsalairem(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->salairep_m->text().isEmpty()|| ui->salairep_m->text().contains(QRegExp("[^0-9]")))
    {
        ui->mp3->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->mp3->setPixmap(PixTrueIcon);
        return true;

    }
}
bool profil::verifdescriptionm(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->descriptionp_m->text().isEmpty()||ui->descriptionp_m->text().contains(QRegExp("[^a-zA-Z0-9]+$")))
    {
        ui->mp4->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->mp4->setPixmap(PixTrueIcon);
        return true;

    }
}
bool profil::verifnb_agentsm(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->nbagentsp_m->text().isEmpty()|| ui->nbagentsp_m->text().contains(QRegExp("[^0-9]")))
    {
        ui->mp5->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->mp5->setPixmap(PixTrueIcon);
        return true;

    }
}
//-----------selection text---//
void profil::InitIndication(Ui::MainWindow *ui){
ui->description_0->setToolTip("La description doit non-vide !");
ui->descriptionp_m->setToolTip("La description doit non-vide !");
ui->nom_profil_0->setToolTip("Le nom de profil doit non-vide et seulement composé par des lettres alphabétique !");
ui->nomp_m->setToolTip("Le nom de profil doit non-vide et seulement composé par des lettres alphabétique !");
ui->salaire_0->setToolTip("Le salaire (TND) doit être non-vide et seulement composé par  des chifrres!");
ui->salairep_m->setToolTip("Le salaire (TND) doit être non-vide et seulement composé par  des chifrres !");
ui->nb_0->setToolTip("Le nombre des agents doit être non-vide et seulement composé par  des chifrres !");
ui->nbagentsp_m->setToolTip("Le nombre des agents doit être non-vide et seulement composé par  des chifrres !");
ui->ID_0->setToolTip("Le numéro d'identification (ID) doit être non-vide et seulement composé des chifrres, Exactment six chiffres !");
ui->IDp_m->setToolTip("Le numéro d'identification (ID) doit être non-vide et seulement composé des chifrres, Exactment six chiffres !");
}
bool profil::supprimer33(Ui::MainWindow *ui)
{
    QString ref=ui->tab_profil->model()->data(ui->tab_profil->model()->index(ui->tab_profil->selectionModel()->currentIndex().row(),0)).toString();

    QSqlQuery query;
    query.prepare("select * FROM profil WHERE ID ='"+ref+"'");
    query.exec();
    int total=0;
    while(query.next()){
        total++;
    }
    if(total==1){
        QSqlQuery q;
        q.prepare("DELETE FROM profil WHERE ID ='"+ref+"'");
        return q.exec();
    }
    else{
        return false;
    }


}
