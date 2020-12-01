#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QMessageBox>
#include <QApplication>
#include "agents.h"
#include <QSqlRecord>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QSqlTableModel>
#include "tableprinter.h"
#include <QMessageBox>
#include  <QDebug>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include <QMessageBox>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include"profil.h"
#include "statistiques.h"
#include "ui_statistiques.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    agents A;
     A.afficher1(ui);
     A.departentss(ui);
     ui->modifier->hide();
     ui->Statistque->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    agents A;
     A.afficher1(ui);
     A.departentss(ui);
     profil P;
     P.afficher_P(ui);//----------afficher-----//
     ui->modifier->hide();
     ui->Statistque->hide(); 
}

void MainWindow::on_ajouter_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->modifier->hide();
    ui->Statistque->hide();
    agents A;
     A.afficher1(ui);
     A.departentss(ui);
     profil P;
     P.afficher_P(ui);
   }

void MainWindow::on_afficher_2_clicked()
{

    ui->stackedWidget->setCurrentIndex(2);
    agents A;
     A.afficher1(ui);
     A.departentss(ui);
     profil P;
     P.afficher_P(ui);//----------afficher-----//
     ui->modifier->hide();
     ui->Statistque->hide();
}

void MainWindow::on_modifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_Statistque_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
//----------ajouter-----//
void MainWindow::on_ajouter_0_clicked()
{

    QString CIN = ui->CIN_1->text();
    QString nom= ui->nom_1->text();
    QString prenom= ui->prenom_0->text();
    QDate Date_naissance=ui->date_0->date();
    QString email =ui->email_0->text();
    QString tel =ui->tel_0->text();
    QString nom_profil=ui->comboBox->currentText();
  agents A(QString CIN,QString nom,QString prenom,QDate Date_naissance,QString email,QString tel,QString nom_profil);
  agents A1;
   bool test=A1.ajouter(CIN,nom,prenom,Date_naissance,email,tel,nom_profil);
  if(test)
{
QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("employe ajouté.\n"
                              "Click Cancel to exit."),QMessageBox::Cancel);
agents A;
 A.afficher1(ui);
 A.departentss(ui);
 profil P;
 P.afficher_P(ui);

}

  else
{
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employé"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."),QMessageBox::Cancel);

}
 ui->CIN_1->clear();
 ui->nom_1->clear();
 ui->prenom_0->clear();
 ui->date_0->clear();
 ui->email_0->clear();
 ui->tel_0->clear();

}


//----------chercher-----//
void MainWindow::on_chercher_agents_cursorPositionChanged(int arg1, int arg2)
{
    agents A;
        QString inputValue,filterChecked;
        inputValue=ui->chercher_agents->text();
        filterChecked="nom";

        if (ui->check_CIN->isChecked()){
            filterChecked="CIN";

        }
        if (ui->check_email->isChecked()){
            filterChecked="email";

        }
        if (ui->check_prenom->isChecked()){
            filterChecked="prenom";

        }
        ui->tab_agents->setModel(A.getModelSpecial(inputValue,filterChecked));


}
//----------supprimer-----//
void MainWindow::on_pushButton_13_clicked()
{

    agents e;

        if(e.supprimer1(ui))
        {
            QMessageBox ::information(this,"","Employe Supprimé")  ;


            e.afficher1(ui);
             e.departentss(ui);
             profil P;
             P.afficher_P(ui);

        }
        else {
            QMessageBox ::information(this,"","erreur")  ;
        }

}

//----------modifier-----//
void MainWindow::on_tab_agents_activated(const QModelIndex &index)
{
    QString val=ui->tab_agents->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from agents where nom Like '%"+val+"%' or prenom Like'%"+val+"%' or date_naissance Like '%"+val+"%'  ");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->CIN_m->setText(qry.value(0).toString());
            ui->nom_m->setText(qry.value(1).toString());
            ui->prenom_m->setText(qry.value(2).toString());
            ui->date_m->setDate(qry.value(3).toDate());
            ui->email_m->setText(qry.value(4).toString());
            ui->tel_m->setText(qry.value(5).toString());
            ui->comboBox_2->setEditText(qry.value(6).toString());
        }
    }
    ui->stackedWidget->setCurrentIndex(3);
    ui->modifier->show();


}

void MainWindow::on_pushButton_12_clicked()
{
    agents e;

        if(e.modifier1(ui))
        {
            QMessageBox ::information(this,"","Employe modifiee")  ;

             e.afficher1(ui);
             e.departentss(ui);
             profil P;
             P.afficher_P(ui);

        }
         ui->stackedWidget->setCurrentIndex(2);//retour afficher
          ui->modifier->hide();
}
//----------actualiser-----//
void MainWindow::on_pushButton_15_clicked()
{
    agents A;
     A.afficher1(ui);
     A.departentss(ui);
     profil P;
     P.afficher_P(ui);
}
//----------imprimer-------//
void MainWindow::on_pushButton_10_clicked()
{

    //imprimer

    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()==QDialog::Rejected)

        return;
}
//----------pdf---------//
void MainWindow::on_pushButton_14_clicked()
{

    QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = ui->tab_agents->model()->rowCount();
                 const int columnCount = ui->tab_agents->model()->columnCount();

                 out <<  "<html>\n"
                     "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg("strTitle")
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                     "<center> <H1>Liste des agents </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                 // headers
                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                 for (int column = 0; column < columnCount; column++)
                     if (!ui->tab_agents->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tab_agents->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->tab_agents->isColumnHidden(column)) {
                             QString data = ui->tab_agents->model()->data(ui->tab_agents->model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table> </center>\n"
                     "</body>\n"
                     "</html>\n";

           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
             if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

            QPrinter printer (QPrinter::PrinterResolution);
             printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

            QTextDocument doc;
             doc.setHtml(strStream);
             doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
             doc.print(&printer);

    }







//----------trier par---------//
void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
    agents A;
    QString choix=ui->comboBox_3->currentText();
    ui->tab_agents->setModel(A.afficher_choix1(choix));
}
//-------------------------------------------------profil----------------------------------------------------------------//
//----------ajouter profil-----//
void MainWindow::on_ajouter_profil_clicked()
{
    QString ID = ui->ID_0->text();
    QString nom_profil= ui->nom_profil_0->text();
   QString salaire= ui->salaire_0->text();
    QString description=ui->description_0->text();
    QString nb_agents =ui->nb_0->text();
profil P(QString ID,QString nom_profil,QString salaire,QString description ,QString nb_agents);
profil p1;
bool test=p1.ajouter_p(ID,nom_profil,salaire,description,nb_agents);
if(test)
{
QMessageBox::information(nullptr, QObject::tr("Ajouter profil"),
                QObject::tr("profil ajouté.\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);

agents A;
 A.afficher1(ui);
 A.departentss(ui);
 profil P;
 P.afficher_P(ui);
}

else
{
    QMessageBox::critical(nullptr, QObject::tr("Ajouter profil"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);

}
ui->ID_0->clear();
ui->nom_profil_0->clear();
ui->salaire_0->clear();
ui->description_0->clear();
ui->nb_0->clear();
}
//------chercher profil------//



void MainWindow::on_chercher_profil_cursorPositionChanged(int arg1, int arg2)
{
    profil P;
        QString inputValue,filterChecked;
        inputValue=ui->chercher_profil->text();
        filterChecked="NOM_PROFIL";

        if (ui->check_ID->isChecked()){
            filterChecked="ID";

        }
        if (ui->check_salaire->isChecked()){
            filterChecked="salaire";

        }
        ui->tab_profil->setModel(P.getModelSpecial(inputValue,filterChecked));

}
//------trier par profil-----//
void MainWindow::on_comboBox_4_activated(const QString &arg1)
{
    profil P;
    QString choix=ui->comboBox_4->currentText();
    ui->tab_profil->setModel(P.afficher_choix_p(choix));
}
//------imprimer profil-----//
void MainWindow::on_imprimer_clicked()
{
    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()==QDialog::Rejected);
}
//------pdf profil-----//
void MainWindow::on_pdf_clicked()
{
    QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = ui->tab_profil->model()->rowCount();
                 const int columnCount = ui->tab_profil->model()->columnCount();

                 out <<  "<html>\n"
                     "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg("strTitle")
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                     "<center> <H1>Liste des profils </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                 // headers
                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                 for (int column = 0; column < columnCount; column++)
                     if (!ui->tab_profil->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tab_profil->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->tab_profil->isColumnHidden(column)) {
                             QString data = ui->tab_profil->model()->data(ui->tab_profil->model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table> </center>\n"
                     "</body>\n"
                     "</html>\n";

           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
             if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

            QPrinter printer (QPrinter::PrinterResolution);
             printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

            QTextDocument doc;
             doc.setHtml(strStream);
             doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
             doc.print(&printer);
}
//------actualiser profil-----//
void MainWindow::on_actualiser_clicked()
{

    agents A;
     A.afficher1(ui);
     A.departentss(ui);
     profil P;
     P.afficher_P(ui);
}
//------modifier profil-----//
void MainWindow::on_tab_profil_activated(const QModelIndex &index)
{
    QString val=ui->tab_profil->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from profil where nom_profil Like '%"+val+"%' or salaire Like'%"+val+"%' or description Like '%"+val+"%'  ");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->IDp_m->setText(qry.value(0).toString());
            ui->nomp_m->setText(qry.value(1).toString());
            ui->salairep_m->setText(qry.value(2).toString());
            ui->descriptionp_m->setText(qry.value(3).toString());
            ui->nbagentsp_m->setText(qry.value(4).toString());

        }
    }
    ui->stackedWidget->setCurrentIndex(3);
     ui->modifier->show();
}

void MainWindow::on_modifier_profil_clicked()
{
    profil P;

        if(P.modifier_p(ui))
        {
            QMessageBox ::information(this,"","Profil modifiee")  ;

            P.afficher_P(ui);


        }
 ui->stackedWidget->setCurrentIndex(2);
 ui->modifier->hide();
}
//------supprimer profil-----//
void MainWindow::on_pushButton_21_clicked()
{
    profil P;

        if(P.supprimer_p(ui))
        {
            QMessageBox ::information(this,"","Employe Supprimé")  ;

            P.afficher_P(ui);

        }
        else {
            QMessageBox ::information(this,"","erreur")  ;
        }
}

void MainWindow::on_pushButton_20_clicked()
{
    statistiques *s=new statistiques();
    s->show();
}
