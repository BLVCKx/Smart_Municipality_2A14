   #include "agents.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
agents::agents()
{

}
agents::agents(QString CIN,QString nom,QString prenom,QString date_naissance,QString email,QString tel,QString profil)
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
QString agents::get_date(){return date_naissance;}
QString agents::get_profil(){return profil;}


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
    this->date_naissance =query.value(ecoleNo).toString();
    this->email = query.value(diplomeNo).toString();
    this->tel = query.value(anneeNo).toInt();
}
bool agents::ajouter(QString CIN, QString nom, QString prenom, QString date_naissance, QString email, QString tel,QString profil)//--------------ajouter------//
{
    QSqlQuery query;
    query.prepare("INSERT INTO agents (CIN, NOM, PRENOM,Date_naissance,email,tel,profil) "
                        "VALUES (:CIN,:nom,:prenom,:Date_naissance,:email,:tel,:profil)");
    query.bindValue(":CIN",CIN);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":Date_naissance",date_naissance);
    query.bindValue(":email",email);
    query.bindValue(":tel",tel);
    query.bindValue(":profil",profil);

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
/*agents agents::Rechercheragents(QString nom1)//--------------ajouter------//
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
    }
    else{
        return false;
    }

}
bool agents::supprimer1(Ui::MainWindow *ui)
{

    QSqlQuery q;
    QString ref=ui->tab_agents->model()->data(ui->tab_agents->model()->index(ui->tab_agents->selectionModel()->currentIndex().row(),1)).toString();
    q.prepare("DELETE FROM agents WHERE nom ='"+ref+"'");
    return (q.exec());



}
bool agents::modifier1(Ui::MainWindow *ui)
{
    QMessageBox msgBox ;

   QString CIN = ui->CIN_m->text();
   QString nom= ui->nom_m->text();
   QString prenom= ui->prenom_m->text();
   QString Date_naissance=ui->date_m->text();
   QString email =ui->email_m->text();
    QString tel =ui->tel_m->text();
    QString profil=ui->comboBox->currentText();
   agents A(CIN, nom, prenom,Date_naissance,email,tel,profil);
   QSqlQuery query;
   query.prepare ("update agents set cin ='"+CIN+"', nom ='"+nom+"',prenom ='"+prenom+"', date_naissance ='"+Date_naissance+"',email ='"+email+"', tel ='"+tel+"',profil='"+profil+"' where cin ='"+CIN+"'");
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
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PROFIL"));

    return model;
}
int agents::calculercatego(QString catego){
   QSqlQuery query;
   query.prepare("select * from agents where profil='"+catego+"'");
   query.bindValue(":profil",catego);
   query.exec();
   int total=0;
   while(query.next()){
       total++;
   }


   return total;
}
