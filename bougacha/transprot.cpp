#include "transprot.h"
#include "ui_transprot.h"
#include <QMessageBox>
#include <QString>
#include <QThread>
#include <QDebug>

transprot::transprot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transprot)
{
    ui->setupUi(this);
    ui->tableView->setModel(g.afficher());

}

transprot::~transprot()
{
    delete ui;
}

void transprot::on_ajouter_clicked()
{
    int ref=ui->lineEdit_ref->text().toInt();
    QString modele=ui->comboBox->currentText();
    QString confort=ui->lineEdi_confort->text();
    int nombre_de_place=ui->spinBox_np->text().toInt();
    QString climatisation=ui->lineEdit_cli->text();

    gestionmoyen g(ref,modele,confort,nombre_de_place,climatisation);
    bool test=g.ajouter();
    QMessageBox msgBox;

    if(test)
      {  msgBox.setText("Ajout avec succes.");
        ui->tableView->setModel(g.afficher());
    }
    else
        msgBox.setText("Echec d'ajout");
        msgBox.exec();

}

void transprot::on_pushButton_mod_clicked()
{
    int ref=ui->lineEdit_ref_2->text().toInt();
    QString modele=ui->comboBox_2->currentText();
    QString confort=ui->lineEdi_confort_2->text();
    int nombre_de_place=ui->spinBox_np_2->text().toInt();
    QString climatisation=ui->lineEdit_cli_2->text();

     gestionmoyen g(ref,modele,confort,nombre_de_place,climatisation);
     bool test=g.modifier();
     QMessageBox msgBox;

     if(test)
       {  msgBox.setText("Modifier avec succes.");
         ui->tableView->setModel(g.afficher());
     }
     else
         msgBox.setText("echec modification");
         msgBox.exec();
}

void transprot::on_pushButton_supp_clicked()
{
    int y=ui->lineEdit_ref_2->text().toInt();
    bool test=g.supprimer(y);
    QMessageBox msgBox;

    if(test)
       {
    msgBox.setText("Suppression avec succes.");
    ui->tableView->setModel(g.afficher());//refreche

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}

void transprot::on_tableView_activated(const QModelIndex &index)
{   QMessageBox msgBox;

   gestionmoyen g;
        QString val = ui->tableView->model()->data(index).toString();
        QString ref_string= QString::number(g.get_ref());
        QString nombre_de_place_string= QString::number(g.get_nombre_de_place());

        QSqlQuery query;
         query.prepare("select * from transport where ref=:val or modele=:val  or confort=:val  or nombre_de_place=:val  or climatisation=:val ");
         query.bindValue(":val", val);

        if (query.exec())
        {
            while (query.next())
            {
                ui->lineEdit_ref_2->setText(query.value(0).toString());
                ui->comboBox_2->setCurrentText(query.value(1).toString());
                ui->lineEdi_confort_2->setText(query.value(2).toString());
                ui->spinBox_np_2->setValue(query.value(3).toString().toInt());
                ui->lineEdit_cli_2->setText(query.value(4).toString());
            }
        }
        else
        {
                            msgBox.setText("Erreur");
        }

}
void transprot::on_Refreche_clicked()
{
    gestionmoyen g;
    ui->tableView->setModel(g.afficher());
}

void transprot::on_comboBox_trier_activated(const QString &arg1)
{
   gestionmoyen g;
   QSqlQueryModel * modal = new QSqlQueryModel();
   QSqlQuery * qry = new QSqlQuery();
   if (arg1=="ref")
   {
    qry->prepare("Select * from employe order by ref ");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }
  else if (arg1=="modele")
   {
    qry->prepare("Select * from employe order by modele desc");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }

   else if (arg1=="nombre de place")
   {
    qry->prepare("Select * from employe order by modele et nombre_de_place  ");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }
}
void transprot::on_comboBox_rechercher_activated(const QString &arg1)
{
     gestionmoyen g;
    if(arg1=="modele et nombre_de_place et confort")
    {
    g.chercher(ui->comboBox_2->currentText(),ui->spinBox_np_2->text().toInt(),ui->lineEdi_confort_2->text());
    ui->tableView->setModel(g.afficher_untransport());
    }
    else if (arg1=="ref")
    {
        g.chercher_ref(ui->lineEdit_ref_2->text().toInt());
        ui->tableView->setModel(g.afficher_untransport_ref());

    }
    else if (arg1=="modele et confort")
    {
        g.chercher_modele_confort(ui->comboBox_2->currentText(),ui->lineEdi_confort_2->text());
        ui->tableView->setModel(g.afficher_untransport_modele_confort());

    }
}







