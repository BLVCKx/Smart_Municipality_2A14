#include "dialog.h"
#include "ui_dialog.h"
#include<QMessageBox>
#include<QSqlQueryModel>
#include<QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include<QPrinter>
#include<QPrintDialog>
#include<QFileDialog>
#include"Blocc.h"
#include"equipement.h"
#include<QDateTime>
#include<QTimer>
#include<statistique.h>




Dialog::Dialog(QWidget *parent) :
   QMainWindow(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
   QTimer *timer=new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
Blocc c;
    ui->tableView->setModel(c.afficherbloc());

    player = new QMediaPlayer(this);
    animation = new QPropertyAnimation(ui->label_17,"geometry");
        animation->setDuration(90000);
        animation->setStartValue(ui->label_17->geometry());
        animation->setEndValue(QRect(8000,80,20,0));
        animation->start();





}



Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QSqlQuery qry;


    QString id_bloc;
        QString nom_bloc;
        QString equipement;
        QString type_equipement;
        QString numero_four;
        QString date ;
        QString situation ;
   id_bloc=ui->lineEdit_id->text();
    nom_bloc=ui->lineEdit_nom->text();
    equipement=ui->lineEdit_equipement->text();
    type_equipement=ui->lineEdit_type->text();
    numero_four=ui->lineEdit_num->text();
    date=ui->lineEdit_date->text();
   situation=ui->comboBox_situation->currentText();
   Blocc c(id_bloc,nom_bloc,equipement,type_equipement,numero_four,date,situation);
   if(c.verif_id(id_bloc)==false){

          QMessageBox::critical(nullptr,QObject::tr("Ajouter un Bloc"),
                                           QObject::tr("ID Doit contenir 6 chifres.\n"
                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
               }else if((nom_bloc=="") ||(c.verif_nom(nom_bloc)==false )){
          QMessageBox::critical(nullptr,QObject::tr("Ajouter un Bloc"),
                                           QObject::tr("Veuillez remplir tous les cases.\n"
                                                       "Click Cancel to exit ."),QMessageBox::Cancel);

               }else if((equipement=="")) {
          QMessageBox::critical(nullptr,QObject::tr("Ajouter un Bloc"),
                                           QObject::tr("Veuillez remplir tous les cases.\n"
                                                       "Click Cancel to exit ."),QMessageBox::Cancel);

              }else if((type_equipement=="")) {
          QMessageBox::critical(nullptr,QObject::tr("Ajouter un Bloc"),
                                           QObject::tr("Veuillez saisir correctement le numero.\n"
                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
               }
            else if((numero_four=="") || (c.verif_numero(numero_four)==false) ){
          QMessageBox::critical(nullptr,QObject::tr("Ajouter un Bloc"),
                                           QObject::tr("Veuillez remplir tous les cases.\n"
                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
                  }
          else if((date=="") ||(c.verif_date(date)==false ))
      {
          QMessageBox::critical(nullptr,QObject::tr("Ajouter un Bloc"),
                                           QObject::tr("Veuillez saisir la date sous forme jj/mm/aaaa.\n"
                                                       "Click Cancel to exit ."),QMessageBox::Cancel);
                  }
      else if((situation=="") )
   {
      QMessageBox::critical(nullptr,QObject::tr("Ajouter un Bloc"),
                                       QObject::tr("Veuillez saisir la categorie.\n"
                                                   "Click Cancel to exit ."),QMessageBox::Cancel);
              }


else{
   bool test=c.ajouterbloc();
if (test)
    {
    ui->tableView->setModel(c.afficherbloc());
    QMessageBox::information(nullptr,QObject::tr("Ajouter un Bloc"),
                                     QObject::tr("Client ajouté .\n"
                                                 "Click Cancel to exit ."),QMessageBox::Cancel);
     }
else
{
    QMessageBox::critical(nullptr,QObject::tr("Ajouter un Bloc"),
                                     QObject::tr("Erreur.\n"
                                                 "Click Cancel to exit ."),QMessageBox::Cancel);
}

  }
}


void Dialog::on_tabWidget_2_currentChanged(int index)
{

    QSqlQueryModel * modal=new QSqlQueryModel();


    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("select * from BLOC");
    qry->exec();

    modal->setQuery(*qry);
    ui->tableView->setModel(modal);


    qDebug() <<(modal->rowCount());
    index=0;
    index++;

}



void Dialog::on_pushButton_delete_clicked()
{
    QSqlQuery qry;
    Blocc c;


    bool test =c.supprimer(ui);
    if(test)
       {
        QMessageBox::information(nullptr,QObject::tr("Supprimer un Client"),
                                         QObject::tr("Client sumprié .\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);

       }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Supprimer un Client"),
                                         QObject::tr("Erreur.\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);
       }



}

void Dialog::on_pushButton_edit_clicked()
{  QSqlQuery qry ;


       QString id_bloc;
        QString nom_bloc;
        QString equipement;
        QString type_equipement;
        QString numero_four;
        QString date ;
        QString situation ;
        id_bloc=ui->lineEdit_id->text();
    nom_bloc=ui->lineEdit_nom->text();
    equipement=ui->lineEdit_equipement->text();
    type_equipement=ui->lineEdit_type->text();
    numero_four=ui->lineEdit_num->text();
    date=ui->lineEdit_date->text();
   situation=ui->comboBox_situation->currentText();
   Blocc c(id_bloc,nom_bloc,equipement,type_equipement,numero_four,date,situation);
         bool test=c.modifierbloc();
         if (test)
         {
             QMessageBox::information(nullptr,QObject::tr("Modifier un Bloc"),
                                              QObject::tr("Client Modifié .\n"
                                                          "Click Cancel to exit ."),QMessageBox::Cancel);

          }
     else
     {
             QMessageBox::critical(nullptr,QObject::tr("Modifier un BLoc"),
                                              QObject::tr("Erreur.\n"
                                                          "Click Cancel to exit ."),QMessageBox::Cancel);
        }


}





void Dialog::on_pushButton_recherche_clicked()
{  Blocc c;
    c.recherche(ui);
}

void Dialog::on_tableView_activated(const QModelIndex &index)
{
    QSqlQuery* query=new QSqlQuery();
QString val=ui->tableView->model()->data(index).toString() ;
           query->prepare("SELECT * FROM BLOC  where ID='"+val+"' or NOM_BLOC='"+val+"' or EQUIPEMENT='"+val+"' or TYPE_EQUIPEMENT='"+val+"' or DATE_A='"+val+"'  ");
    if(query->exec())
{ while (query->next())
        {            ui->lineEdit_id->setText(query->value(0).toString());
            ui->lineEdit_nom->setText(query->value(1).toString());
            ui->lineEdit_equipement->setText(query->value(2).toString());
            ui->lineEdit_type->setText(query->value(3).toString());
            ui->lineEdit_num->setText(query->value(4).toString());
            ui->lineEdit_date->setText(query->value(5).toString());





        }

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Sélectionner un Client"),
                                         QObject::tr("Erreur .\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);
       }


}



void Dialog::on_radioButton_clicked()
{
    Blocc c ;
    c.TRI1(ui);
}



void Dialog::on_radioButton_2_clicked()
{
    Blocc c;
    c.TRI2(ui);
}

void Dialog::on_pushButton_actualiser_clicked()
{
    QSqlQueryModel * modal=new QSqlQueryModel();


    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("select * from BLOC");
    qry->exec();

    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

     // ui->tableView->setModel(c.afficher());
     // qDebug()<<ui->tabclient->model()->rowCount();




}

void Dialog::on_pushButton_sauvgarderreservatio_clicked()
{   QSqlQuery qry ;
    QString id,nom,nombre,adresse,prix,marque ;
       id=ui->lineEdit_id_equipement->text();
           nom=ui->lineEdit_nom_equipement->text();
           nombre=ui->lineEdit_nombre_equipement->text();
        adresse=ui->lineEdit_adresse_equipement->text();
        prix=ui->lineEdit_prix_equipement->text();
        marque=ui->lineEdit_marque_equipement->text();

  Equipement R(id,nom,nombre,adresse,prix,marque);
  if(R.verif_id(id)==false){

        QMessageBox::critical(nullptr,QObject::tr("Ajouter Equipement"),
                                         QObject::tr("ID Doit contenir 6 chifres.\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);
             }else if((nom=="")){
        QMessageBox::critical(nullptr,QObject::tr("Ajouter Equipement"),
                                         QObject::tr("Veuillez remplir tous les cases.\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);

             }
    else if((nombre=="") )
  {
    QMessageBox::critical(nullptr,QObject::tr("Ajouter Equipement"),
                                     QObject::tr("Veuillez remplir tous les cases.\n"
                                                 "Click Cancel to exit ."),QMessageBox::Cancel);
            }else if(( adresse=="") ){
        QMessageBox::critical(nullptr,QObject::tr("Ajouter Equipement"),
                                         QObject::tr("Veuillez remplir tous les cases.\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);

            }else if((prix=="") ){
        QMessageBox::critical(nullptr,QObject::tr("Ajouter Equipement"),
                                         QObject::tr("Veuillez remplir tous les cases.\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);
             }
          else if(marque==""){
        QMessageBox::critical(nullptr,QObject::tr("Ajouter Equipement"),
                                         QObject::tr("Veuillez remplir tous les cases.\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);
                }


  else {
bool test=R.ajouterequipement();
if(test)
{
    QMessageBox::information(nullptr,QObject::tr("Ajouter Equipement"),
                                         QObject::tr("Equipement ajoutée .\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);
         }
    else
    {
    QMessageBox::critical(nullptr,QObject::tr("Ajouter Equipement"),
                                     QObject::tr("ERooR .\n"
                                                 "Click Cancel to exit ."),QMessageBox::Cancel);
    }
}


}










void Dialog::on_tabWidget_3_currentChanged(int index)
{
    Equipement r;
    r.afficherequipement(ui);
}

void Dialog::on_tableView_2_activated(const QModelIndex &index)
{
   Equipement r ;
  r.selectionnerequipement(ui,index);
}

void Dialog::on_pushButton_modifierreservation_clicked()
{
    QSqlQuery qry ;

    QString id,nom,nombre,adresse,prix,marque ;
       id=ui->lineEdit_id_equipement->text();
           nom=ui->lineEdit_nom_equipement->text();
           nombre=ui->lineEdit_nombre_equipement->text();
        adresse=ui->lineEdit_adresse_equipement->text();
        prix=ui->lineEdit_prix_equipement->text();
        marque=ui->lineEdit_marque_equipement->text();
 Equipement r(id,nom,nombre,adresse,prix,marque);
 bool test=r.modifierequipement();
         if (test)
             {
         QMessageBox::information(nullptr,QObject::tr("Modifier Equipement"),
                                          QObject::tr("Equipement Modifié .\n"
                                                      "Click Cancel to exit ."),QMessageBox::Cancel);

              }
         else
         {
         QMessageBox::critical(nullptr,QObject::tr("Modifier Equipement"),
                                          QObject::tr("ereur .\n"
                                                      "Click Cancel to exit ."),QMessageBox::Cancel);
            }


}

void Dialog::on_pushButton_3_clicked()
{
    QSqlQuery qry;
   Equipement r;


    bool test =r.supprimerequipement(ui);
    if(test)
       {
        QMessageBox::information(nullptr,QObject::tr("Supprimer Equipement"),
                                         QObject::tr("Equipement supprimé .\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);

       }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("Supprimer Equipement"),
                                         QObject::tr("Erreur .\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);
       }

}

void Dialog::on_pushButton_4_clicked()
{
    Equipement r ;
    r.afficherequipement(ui);

}

void Dialog::on_pushButton_5_clicked()
{
    const QString format("<td>%1</td>");
           QString html;
           QAbstractItemModel *md = ui->tableView_2->model();
           html = "<html><body><table border=\"0\">";

           html += "<td></td>";
           for(int column = 0; column < md->columnCount();
               column++) {
               QString data = md->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
               html += format.arg(data);
           }
           for(int row = 0; row < md->rowCount() ; row++) {
               html += "<tr>";
               QString data = md->headerData(row, Qt::Vertical, Qt::DisplayRole).toString();
               html += format.arg(data);
               for(int column = 0; column < md->columnCount();
                   column++) {
                   QString data = md->index(row, column).data(Qt::DisplayRole).toString();
                   html += format.arg(data);
               }
               html += "</tr>";
           }
           html += "</table></body></html>";

           QPrinter printer;
           QPrintDialog *dialog = new QPrintDialog(&printer);
           if(dialog->exec() == QDialog::Accepted) {
               QTextDocument document;
               document.setHtml(html);
               document.print(&printer);
           }
    }


void Dialog::on_slider_progress_sliderMoved(int position)
{
player->setPosition(position);}

void Dialog::on_slider_volume_sliderMoved(int position)
{
 player->setVolume(position);
}

void Dialog::on_pushButton_6_clicked()
{
// import file
    player->setMedia(QUrl("qrc:/song/ressources/musique-relaxan.mp3")) ;
       player->play();
       qDebug() << player->errorString();
}

void Dialog::on_pushButton_7_clicked()
{
player->stop();
}

void Dialog::on_pushButton_2_clicked()
{

    QString str;
           str.append("<html><head></head><body><center>"+QString("GESTION EQUIPEMENT"));
           str.append("<table border=1><tr>") ;
           str.append("<td>"+QString("ID_E")+"</td>") ;
           str.append("<td>"+QString("NOM")+"</td>") ;
           str.append("<td>"+QString("NOMBRE")+"</td>") ;
           str.append("<td>"+QString("ADRESSE")+"</td>") ;
           str.append("<td>"+QString("PRIX")+"</td>") ;
           str.append("<td>"+QString("MARQUE")+"</td>") ;



           QSqlQuery* query=new QSqlQuery();
           query->exec("SELECT ID_E,NOM,NOMBRE,ADRESSE,PRIX,MARQUE FROM EQUIPEMENT");

           while(query->next())
           {
           str.append("<tr><td>");
           str.append(query->value(0).toString()) ;
           str.append("</td><td>") ;
           str.append(query->value(1).toString());
           str.append("</td><td>") ;
           str.append(query->value(2).toString());
           str.append("</td><td>") ;
           str.append(query->value(3).toString());
           str.append("</td><td>") ;
           str.append(query->value(4).toString());
           str.append("</td><td>") ;
           str.append(query->value(5).toString());
           str.append("</td></td>");
           str.append(query->value(6).toString());
           str.append("</td></tr>");


           }
        str.append("</table></center></body></html>") ;

        QPrinter printer ;
        printer.setOrientation(QPrinter::Portrait);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4) ;

        QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","..","PDF(*.pdf)");

        if (path.isEmpty()) return ;
        printer.setOutputFileName(path) ;

        QTextDocument doc;
        doc.setHtml(str) ;
        doc.print(&printer);



}









