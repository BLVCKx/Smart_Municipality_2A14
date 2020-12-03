#include "gestionprojet.h"
#include "ui_gestionprojet.h"
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
gestionprojet::gestionprojet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionprojet)
{
    ui->setupUi(this);
}

gestionprojet::~gestionprojet()
{
    delete ui;
}

void gestionprojet::on_pushButton_clicked()
{
    int id=ui->id_p->text().toInt();
    QString nom= ui->nom_p->text();
    QString emplacement= ui->emplacement_p->text();
    QString lieu= ui->lieu_p->text();
    QString email= ui->email_p->text();
    QString contenue= ui->contenue_p->text();
    QString description= ui->desc_p->text();


  Projet p(id,nom,emplacement,lieu,email,contenue,description);
  bool test=p.ajouter();
  if(test)
{ui->tabp->setModel(tmpp.afficher()); //refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Projet"),
                  QObject::tr("Projet ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Projet"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionprojet::on_btn_modifier_p_clicked()
{
    int id=ui->id_p_modif->text().toInt();
    QString nom= ui->nv_nom_p->text();
    QString emplacement= ui->nv_emplacement_p->text();
    QString lieu= ui->nv_lieu_p->text();
    QString email= ui->nv_email_p->text();
    QString contenue= ui->nv_contenue_p->text();
    QString description= ui->nv_desc_p->text();



      Projet p(id,nom,emplacement,lieu,email,contenue,description);
      bool test=p.modifier(id,nom,emplacement,lieu,email,contenue,description);
      if(test)
    {
          ui->tabp->setModel(tmpp.afficher());
    QMessageBox::information(nullptr, QObject::tr("Modifier un Projet"),
                      QObject::tr("Projet modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un Projet"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionprojet::on_btn_supprimer_p_clicked()
{
    QSqlQuery query;

        int id = ui->id_a_supprimer_p->text().toInt();

        query.prepare("delete from projet where id=:id");
        query.bindValue(":id", id);
        bool v =query.exec();
        if(v)
        {ui->tabp->setModel(tmpp.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer un Projet"),
                        QObject::tr("Projet supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un Projet"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionprojet::on_btn_refreshp_clicked()
{
    ui->tabp->setModel(tmpp.afficher());
}

void gestionprojet::on_btn_rechercher_p_clicked()
{
    QString nom = ui->lineEdit->text();
        if(tmpp.verifierExnoms(nom)==false)
        {QMessageBox::warning(this,"ERREUR","Projet n'existe pas");}
        else
        ui->tabp->setModel(tmpp.recherche_nom(nom));
}

void gestionprojet::on_btn_pdf_p_clicked()
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
              double xscale = double(ui->tabp->width() / 65);
              double yscale = double(ui->tabp->height() / 65);
              painter.scale(xscale, yscale);
              ui->tabp->render(&painter);
              painter.end();
          }
          else
          {
              qWarning("failed to open file");
             QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
          }
       }
}

void gestionprojet::on_btn_tri_nom_p_clicked()
{
      ui->tabp->setModel(tmpp.trier());
}

void gestionprojet::on_btn_tri_id_p_clicked()
{
      ui->tabp->setModel(tmpp.trier1());
}
