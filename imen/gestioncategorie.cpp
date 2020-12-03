#include "gestioncategorie.h"
#include "ui_gestioncategorie.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QPrintDialog>
#include <QPainter>

#include <QMessageBox>
#include <QColor>
#include <QPalette>
#include <QSqlQuery>
#include <QPrinter>
#include <QTableWidget>
#include <QPixmap>
gestioncategorie::gestioncategorie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestioncategorie)
{
    ui->setupUi(this);
}

gestioncategorie::~gestioncategorie()
{
    delete ui;
}

void gestioncategorie::on_btn_ajouter_clicked()
{
    int id=ui->id->text().toInt();
    QString nom= ui->nom->text();
    QString type= ui->type->text();
    QString description= ui->description->text();



  Categorie p(id,nom,type,description);
  bool test=p.ajouter();
  if(test)
{ui->tab_cat->setModel(tmpc.afficher()); //refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une Categorie"),
                  QObject::tr("Categorie ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une Categorie"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestioncategorie::on_btn_modifier_c_clicked()
{
    int id=ui->id_a_modifier->text().toInt();
    QString nom= ui->nv_nom->text();
    QString type= ui->nv_type->text();
    QString description= ui->nv_desc->text();



  Categorie p(id,nom,type,description);
      bool test=p.modifier(id,nom,type,description);
      if(test)
    {
          ui->tab_cat->setModel(tmpc.afficher());
    QMessageBox::information(nullptr, QObject::tr("Modifier une Categorie"),
                      QObject::tr("Categorie modifiée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier une Categorie"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestioncategorie::on_btn_supprimer_c_clicked()
{
    QSqlQuery query;

        int id = ui->id_a_supprimer->text().toInt();

        query.prepare("delete from categorie where id=:id");
        query.bindValue(":id", id);
        bool v =query.exec();
        if(v)
        {ui->tab_cat->setModel(tmpc.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer une Categorie"),
                        QObject::tr("Categorie supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une Categorie"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestioncategorie::on_btn_rechercher_c_clicked()
{
    QString nom = ui->nom_a_chercher->text();
        if(tmpc.verifierExnoms(nom)==false)
        {QMessageBox::warning(this,"ERREUR","Categorie n'existe pas");}
        else
        ui->tab_cat->setModel(tmpc.recherche_nom(nom));
}

void gestioncategorie::on_btn_refresh_clicked()
{
      ui->tab_cat->setModel(tmpc.afficher());
}

void gestioncategorie::on_btn_pdf_clicked()
{

    QPrinter *printer = new QPrinter(QPrinter::HighResolution);
           printer->setOutputFormat(QPrinter::NativeFormat);
           printer->setPageSize(QPrinter::A4);
           printer->setOrientation(QPrinter::Portrait);
           printer->setFullPage(true);


       QPrintDialog *printDialog = new QPrintDialog(printer,this);
       printDialog->setWindowTitle("Impression PDF");
       if(printDialog->exec())
       {
          QPainter painter;
          if(painter.begin(printer))
          {
              double xscale = double(ui->tab_cat->width() / 65);
              double yscale = double(ui->tab_cat->height() / 65);
              painter.scale(xscale, yscale);
              ui->tab_cat->render(&painter);
              painter.end();
          }
          else
          {
              qWarning("failed to open file");
             QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
          }
       }
}

void gestioncategorie::on_tri_id_clicked()
{
    ui->tab_cat->setModel(tmpc.trier1());
}

void gestioncategorie::on_tri_nom_clicked()
{
    ui->tab_cat->setModel(tmpc.trier());
}
