#include "agents.h"
#include "profil.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QMainWindow>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include "QAbstractItemView"
agents::agents()
{

}
agents::agents(QString CIN,QString nom,QString prenom,QDate date_naissance,QString email,QString tel,QString nom_nom_profil)
 {
     this->CIN=CIN;
     this->nom=nom;
     this->prenom=prenom;
     this->date_naissance=date_naissance;
     this->email=email;
     this->tel=tel;

 }
QString agents::get_nom(){return nom;}
QString agents::get_prenom(){return prenom;}
QString agents::get_CIN(){return CIN;}
QString agents::get_tel(){return tel;}
QString agents::get_email(){return email;}
QDate agents::get_date(){return date_naissance;}
QString agents::get_nom_profil(){return nom_profil;}
void agents::getData(int ID)
{

    QSqlQuery query;
    query.prepare("SELECT * FROM agents WHERE ID=:ID");
    query.bindValue(":ID",ID);

    if (query.exec()){
        query.first();
        setData(query);

    }
    else
    {
        qDebug()<<"FALSE";
    }

}
void agents::setData(QSqlQuery query)
{

    int IDNo = query.record().indexOf("CIN");
    int nomNo = query.record().indexOf("nom");
    int prenomNo = query.record().indexOf("prenom");
    int ecoleNo = query.record().indexOf("date naissance");
    int diplomeNo = query.record().indexOf("email");
    int anneeNo = query.record().indexOf("tel");


    this->CIN = query.value(IDNo).toInt();
    this->nom = query.value(nomNo).toString();
    this->prenom = query.value(prenomNo).toString();
    this->date_naissance =query.value(ecoleNo).toDate();
    this->email = query.value(diplomeNo).toString();
    this->tel = query.value(anneeNo).toInt();
}
bool agents::ajouter(QString CIN, QString nom, QString prenom, QDate date_naissance, QString email, QString tel,QString nom_profil)//--------------ajouter------//
{
    QSqlQuery query;
    query.prepare("INSERT INTO agents (CIN, NOM, PRENOM,Date_naissance,email,tel,nom_profil) "
                        "VALUES (:CIN,:nom,:prenom,:Date_naissance,:email,:tel,:nom_profil)");
    query.bindValue(":CIN",CIN);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":Date_naissance",date_naissance);
    query.bindValue(":email",email);
    query.bindValue(":tel",tel);
    query.bindValue(":nom_profil",nom_profil);
    query.exec();
    query.prepare("UPDATE profil set NB_AGENTS=NB_AGENTS +1 where nom_profil='"+nom_profil+"'") ;
    return    query.exec();
}
void agents::afficher1(Ui::MainWindow *ui)//--------------afficher------//
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from agents");
    q.exec();
    modal->setQuery(q);
    ui->tab_agents->setModel(modal);
}
/*QSqlQueryModel * agents::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * "
                "from agents");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("tel"));
return model;
}*/
/*agents agents::Rechercheragents(QString nom1)
{
agents agentsAConsulter;
QSqlQuery query;
query.prepare("Select * from agents where nom=:nom1");
query.bindValue(":nom",nom1);
if (query.exec())
{
    while (query.next()){

        agentsAConsulter.CIN=(query.value(0).toString());
        agentsAConsulter.nom=(query.value(1).toString());
        agentsAConsulter.prenom=(query.value(2).toString());
        agentsAConsulter.date_naissance=(query.value(3).toString());
        agentsAConsulter.email=(query.value(4).toString());
    }
}
return agentsAConsulter;
}




QSqlQueryModel *agents::ConsulterPointageParticulier(QString nom1, int *RowCount){
    QSqlQueryModel * model= new QSqlQueryModel ();




    model->setQuery("select * from agents where nom Like '%"+nom1+"%' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date naissance"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("tel"));
    *RowCount=model->rowCount();
    return model;

}*/

bool agents::supprimer(Ui::MainWindow *ui)
{

    QString ref=ui->tab_agents->model()->data(ui->tab_agents->model()->index(ui->tab_agents->selectionModel()->currentIndex().row(),0)).toString();

    QSqlQuery query;
    query.prepare("select * FROM agents WHERE machine ='"+ref+"'");
    query.exec();
    int total=0;
    while(query.next()){
        total++;
    }
    if(total==1){
        QSqlQuery q;
        q.prepare("DELETE FROM agents WHERE machine ='"+ref+"'");
        return q.exec();

        profil P;
        P.afficher_P(ui);
        agents A;
        A.afficher1(ui);
    }
    else{
        return false;
    }

}
bool agents::supprimer1(Ui::MainWindow *ui)
{

    QSqlQuery q;
    QString ref=ui->tab_agents->model()->data(ui->tab_agents->model()->index(ui->tab_agents->selectionModel()->currentIndex().row(),1)).toString();
     QString nom_profil=ui->tab_agents->model()->data(ui->tab_agents->model()->index(ui->tab_agents->selectionModel()->currentIndex().row(),6)).toString();
    q.prepare("DELETE FROM agents WHERE nom ='"+ref+"'");
    if(q.exec())
    {
            q.prepare("UPDATE profil set NB_AGENTS=NB_AGENTS -1 where nom_profil='"+nom_profil+"'") ;
        return q.exec();

    } else return false;




}
bool agents::modifier1(Ui::MainWindow *ui)
{
    QMessageBox msgBox ;

   QString CIN = ui->CIN_m->text();
   QString nom= ui->nom_m->text();
   QString prenom= ui->prenom_m->text();
QDate Date_naissance=ui->date_m->date();
   QString email =ui->email_m->text();
    QString tel =ui->tel_m->text();
    QString nom_profil=ui->comboBox_2->currentText();
   agents A(CIN, nom, prenom,Date_naissance,email,tel,nom_profil);
   QSqlQuery query;
   query.prepare ("update agents set cin ='"+CIN+"', nom ='"+nom+"',prenom ='"+prenom+"',email ='"+email+"', tel ='"+tel+"',nom_profil='"+nom_profil+"' where cin ='"+CIN+"'");
   return  (query.exec());

}
QSqlQueryModel *agents::getModelSpecial(QString inputValue,QString filterChecked){
    QSqlQueryModel * model= new QSqlQueryModel ();
    QSqlQuery query;
    query.prepare("SELECT *FROM agents WHERE "+filterChecked+" LIKE '%' || :inputValue || '%' ");
    query.bindValue(":inputValue",inputValue);
    query.exec();
    model->setQuery(query);
    return model;
}
QSqlQueryModel * agents::afficher_choix1(QString choix)//trier
{
    QSqlQueryModel * model =new QSqlQueryModel();

    if (choix=="CIN")
    {
     model->setQuery("SELECT * FROM agents  ORDER BY CIN;");
    }
    else if(choix=="nom")
    {
        model->setQuery("SELECT * FROM agents  ORDER BY nom ASC ;");
    }
    else if(choix=="prenom")
    {
        model->setQuery("SELECT * FROM agents  ORDER BY prenom ASC;");
    }
    else if (choix=="tel")
    {
        model->setQuery("SELECT * FROM agents ORDER BY tel ");
    }
    else if (choix=="trier par")
    {
        model->setQuery("SELECT * FROM agents");
    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("NOM_PROFIL"));

    return model;
}
int agents::calculercatego(QString catego){
   QSqlQuery query;
   query.prepare("select * from agents where nom_profil='"+catego+"'");
   query.bindValue(":nom_profil",catego);
   query.exec();
   int total=0;
   while(query.next()){
       total++;
   }
   return total;
}

void agents::departentss(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select nom_profil from profil");
    q.exec();
    modal->setQuery(q);
    ui->comboBox->setModel(modal);
    ui->comboBox_2->setModel(modal);

}

//--------Verifacation-----//
bool agents::verifCIN(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->CIN_1->text().isEmpty() || ui->CIN_1->text().length()!=8 || ui->CIN_1->text().contains(QRegExp("[^0-9]")))
    {
        ui->a1->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->a1->setPixmap(PixTrueIcon);
        return true;

    }
}

bool agents::verifnom(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->nom_1->text().isEmpty()||ui->nom_1->text().contains(QRegExp("[^a-zA-Z]+$")))
    {
        ui->a2->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->a2->setPixmap(PixTrueIcon);
        return true;

    }
}

bool agents::verifprenom(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->prenom_0->text().isEmpty()||ui->prenom_0->text().contains(QRegExp("[^a-zA-Z]+$")))
    {
        ui->a3->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->a3->setPixmap(PixTrueIcon);
        return true;

    }
}
bool agents::VerifMail(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");
    if (ui->email_0->text().isEmpty() || (ui->email_0->text().lastIndexOf("@",-1)>ui->email_0->text().lastIndexOf(".",-1)) || ui->email_0->text().lastIndexOf("@",-1)==-1 || ui->email_0->text().lastIndexOf("@",-1)==-1)
    {
        ui->a4->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->a4->setPixmap(PixTrueIcon);
        return true;


    }
}
bool agents::verifTel(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->tel_0->text().isEmpty() || ui->tel_0->text().length()!=8 || ui->tel_0->text().contains(QRegExp("[^0-9]")))
    {
        ui->a5->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->a5->setPixmap(PixTrueIcon);
        return true;

    }
}

bool agents::verifdate(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->date_0->date()==QDate::fromString("01/01/1800","dd/MM/yyyy"))
    {
        ui->a6->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->a6->setPixmap(PixTrueIcon);
        return true;

    }
}

//---------verfication del modification--------//

bool agents::verifCIN_m(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->CIN_m->text().isEmpty() || ui->CIN_m->text().length()!=8 || ui->CIN_m->text().contains(QRegExp("[^0-9]")))
    {
        ui->m1->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->m1->setPixmap(PixTrueIcon);
        return true;

    }
}

bool agents::verifnom_m(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->nom_m->text().isEmpty()||ui->nom_m->text().contains(QRegExp("[^a-zA-Z]+$")))
    {
        ui->m2->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->m2->setPixmap(PixTrueIcon);
        return true;

    }
}

bool agents::verifprenom_m(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->prenom_m->text().isEmpty()||ui->prenom_m->text().contains(QRegExp("[^a-zA-Z]+$")))
    {
        ui->m3->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->m3->setPixmap(PixTrueIcon);
        return true;

    }
}
bool agents::VerifMail_m(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");
    if (ui->email_m->text().isEmpty() || (ui->email_m->text().lastIndexOf("@",-1)>ui->email_m->text().lastIndexOf(".",-1)) || ui->email_m->text().lastIndexOf("@",-1)==-1 || ui->email_m->text().lastIndexOf("@",-1)==-1)
    {
        ui->m5->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->m5->setPixmap(PixTrueIcon);


    }
}
bool agents::verifTel_m(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->tel_m->text().isEmpty() || ui->tel_m->text().length()!=8 || ui->tel_m->text().contains(QRegExp("[^0-9]")))
    {
        ui->m6->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->m6->setPixmap(PixTrueIcon);
        return true;

    }
}

bool agents::verifdate_m(Ui::MainWindow *ui){
    QPixmap PixTrueIcon=QPixmap(":/16x16/icons/16x16/cil-check-circle.png");
   QPixmap PixFalseIcon=QPixmap(":/16x16/icons/16x16/cil-x-circle.png");

    if (ui->date_m->date()==QDate::fromString("01/01/1800","dd/MM/yyyy"))
    {
        ui->m4->setPixmap(PixFalseIcon);
        return false;

    }
    else
    {
        ui->m4->setPixmap(PixTrueIcon);
        return true;

    }
}
//-----------selection text---//
void agents::InitIndication(Ui::MainWindow *ui)
{
ui->nom_1->setToolTip("Le nom de l'employé doit non-vide et seulement composé par des lettres alphabétique !");
ui->nom_m->setToolTip("Le nom de l'employé doit non-vide et seulement composé par des lettres alphabétique !");
ui->prenom_0->setToolTip("Le nom de l'employé doit non-vide et seulement composé par des lettres alphabétique !");
ui->prenom_m->setToolTip("Le nom de l'employé doit non-vide et seulement composé par des lettres alphabétique !");
ui->email_0->setToolTip("Le mail doit être non-vide, comporte le caractére '@' et '.' et le @ doit être positionné avant le '.'");
ui->email_m->setToolTip("Le mail doit être non-vide, comporte le caractére '@' et '.' et le @ doit être positionné avant le '.'");
ui->CIN_1->setToolTip("Le numéro de carte d'identité (CIN) doit être non-vide et seulement composé par  des chifrres, Exactment huit chiffres !");
ui->CIN_m->setToolTip("Le numéro de carte d'identité (CIN) doit être non-vide et seulement composé par  des chifrres, Exactment huit chiffres !");
ui->tel_0->setToolTip("Le numéro de téléphone (Tel) doit être non-vide et seulement composé par  des chifrres, Exactment huit chiffres !");
ui->tel_m->setToolTip("Le numéro de téléphone (Tel) doit être non-vide et seulement composé par  des chifrres, Exactment huit chiffres !");
ui->date_0->setToolTip("La date de naissance doit être changé !");
ui->date_m->setToolTip("La date de naissance doit être changé !");
ui->comboBox->setToolTip("Un profil doit être choisi !");
ui->comboBox_2->setToolTip("Un profil doit être choisi !");
ui->home->setToolTip("Aller au menu");
ui->ajouter_2->setToolTip("Ajouter un Agent ou un Profil");
ui->afficher_2->setToolTip("Afficher un Agent ou un Profil");
}
bool agents::supprimer3(Ui::MainWindow *ui)
{
    QString ref=ui->tab_agents->model()->data(ui->tab_agents->model()->index(ui->tab_agents->selectionModel()->currentIndex().row(),0)).toString();

    QSqlQuery query;
    query.prepare("select * FROM agents WHERE CIN ='"+ref+"'");
    query.exec();
    int total=0;
    while(query.next()){
        total++;
    }
    if(total==1){
        QSqlQuery q;
        q.prepare("DELETE FROM agents WHERE CIN ='"+ref+"'");
        return q.exec();
    }
    else{
        return false;
    }
}
//--------------------------//
