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
#include <QDebug>
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
#include<QMediaPlayer>
#include <QMainWindow>
#include<QPropertyAnimation>
#include<QtMultimedia/QMediaPlayer>
#include<QDebug>
#include"Blocc.h"
#include"equipement.h"
#include"stati.h"
#include"arduinoo.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include<QString>
#include<QDebug>
#include<QMessageBox>
#include<QListWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "arduin.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Blocc c;
        ui->tableView_4->setModel(c.afficherbloc());

    gestionmoyen g;
    ui->tableView->setModel(g.afficher());
    abonnement a;
     ui->tableView_2->setModel(a.afficher());
    agents A;
     A.afficher1(ui);
     A.departentss(ui);
     ui->ajouter_2->hide();
     ui->afficher_2->hide();
     ui->modifier->hide();
     ui->Statistque->setStyleSheet("QPushButton{background: transparent;}");
     QPropertyAnimation * animation = new QPropertyAnimation(ui->label, "geometry");
                animation->setDuration(10000);
                animation->setLoopCount(-1);
                animation->setStartValue(QRect(-30, 250, 553,71));
                animation->setEndValue(QRect(1050, 250, 553,71));
                animation->start();
                ui->tabindiv->setModel(tmpindiv.Afficher_individus());
                ui->tablog->setModel(tmplog.Afficher_logement());

                //----------------------------------//

                int ret=A1.connect_arduino(); // lancer la connexion à arduino
                              switch(ret){
                              case(0):qDebug()<< "arduino is available and connected to : "<< A1.getarduino_port_name();
                                  break;
                              case(1):qDebug() << "arduino is available but not connected to :" <<A1.getarduino_port_name();
                                 break;
                              case(-1):qDebug() << "arduino is not available";
                              }

                                  QObject::connect(A1.getserial(), SIGNAL(readyRead()),this,SLOT(readserial()));
                //---------------------------------------//



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_home_clicked()
{
    ui->ajouter_2->hide();
    ui->afficher_2->hide();
    ui->modifier->hide();
    ui->Statistque->setStyleSheet("QPushButton{background: transparent;}");
    ui->stackedWidget->setCurrentIndex(1);
    agents A;
     A.afficher1(ui);
     A.departentss(ui);
     A.InitIndication(ui);
     profil P;
     P.afficher_P(ui);//----------afficher-----//
     P.InitIndication(ui);
     QMediaPlayer * bulletsound = new QMediaPlayer();
     bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
    if (bulletsound->state() == QMediaPlayer::PlayingState){
         bulletsound->setPosition(0);
     }
     else if (bulletsound->state() == QMediaPlayer::StoppedState){
         bulletsound->play();


     }
}

void MainWindow::on_ajouter_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->modifier->hide();
    ui->Statistque->setStyleSheet("QPushButton{background: transparent;}");
    agents A;
     A.afficher1(ui);
     A.departentss(ui);
     profil P;
     P.afficher_P(ui);
     P.InitIndication(ui);
     A.InitIndication(ui);
     QMediaPlayer * bulletsound = new QMediaPlayer();
     bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
    if (bulletsound->state() == QMediaPlayer::PlayingState){
         bulletsound->setPosition(0);
     }
     else if (bulletsound->state() == QMediaPlayer::StoppedState){
         bulletsound->play();
     }
   }

void MainWindow::on_afficher_2_clicked()
{

    ui->stackedWidget->setCurrentIndex(3);
    agents A;
     A.afficher1(ui);
     A.departentss(ui);
     profil P;
     P.afficher_P(ui);//----------afficher-----//
     P.InitIndication(ui);
     A.InitIndication(ui);
     ui->modifier->hide();
     ui->Statistque->setStyleSheet("QPushButton{background: transparent;}");
     QMediaPlayer * bulletsound = new QMediaPlayer();
     bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
    if (bulletsound->state() == QMediaPlayer::PlayingState){
         bulletsound->setPosition(0);
     }
     else if (bulletsound->state() == QMediaPlayer::StoppedState){
         bulletsound->play();
     }
}

void MainWindow::on_modifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
}




//----------ajouter-----//
void MainWindow::on_ajouter_0_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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
  if(test && A1.verifCIN(ui) && A1.verifnom(ui)&&A1.verifprenom(ui)&& A1.VerifMail(ui)&&A1.verifTel(ui))
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
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    agents e;

        if(e.supprimer3(ui))
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
      ui->stackedWidget->setCurrentIndex(4);
     ui->tabWidget_3->setCurrentIndex(0);
    ui->modifier->show();


}

void MainWindow::on_pushButton_12_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    agents e;
       e.modifier1(ui);
        if(e.modifier1(ui))
        {
            QMessageBox ::information(this,"","Employe modifiee")  ;

             e.afficher1(ui);
             e.departentss(ui);
             profil P;
             P.afficher_P(ui); 
         }
        ui->stackedWidget->setCurrentIndex(3);//retour afficher
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
     QMediaPlayer * bulletsound = new QMediaPlayer();
     bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
    if (bulletsound->state() == QMediaPlayer::PlayingState){
         bulletsound->setPosition(0);
     }
     else if (bulletsound->state() == QMediaPlayer::StoppedState){
         bulletsound->play();
     }
}
//----------imprimer-------//
void MainWindow::on_pushButton_10_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QString ID = ui->ID_0->text();
    QString nom_profil= ui->nom_profil_0->text();
   QString salaire= ui->salaire_0->text();
    QString description=ui->description_0->text();
    QString nb_agents =ui->nb_0->text();
profil P(QString ID,QString nom_profil,QString salaire,QString description ,QString nb_agents);
profil p1;
bool test=p1.ajouter_p(ID,nom_profil,salaire,description,nb_agents);
if(test && p1.verifID(ui)&& p1.verifnom_profil(ui)&& p1.verifsalaire(ui)&& p1.verifdescription(ui)&& p1.verifnb_agents(ui))
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
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()==QDialog::Rejected);

}
//------pdf profil-----//
void MainWindow::on_pdf_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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
     ui->stackedWidget->setCurrentIndex(4);
     ui->tabWidget_3->setCurrentIndex(1);
     ui->modifier->show();
}

void MainWindow::on_modifier_profil_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    profil P;

        if(P.modifier_p(ui)&& P.verifIDm(ui)&& P.verifnom_profilm(ui)&& P.verifsalairem(ui)&& P.verifdescriptionm(ui)&& P.verifnb_agentsm(ui))
        {
            QMessageBox ::information(this,"","Profil modifiee")  ;

            P.afficher_P(ui);


        }
 ui->stackedWidget->setCurrentIndex(3);

 ui->modifier->hide();
}
//------supprimer profil-----//
void MainWindow::on_pushButton_21_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    profil P;

        if(P.supprimer33(ui))
        {
            QMessageBox ::information(this,"","Employe Supprimé")  ;

            P.afficher_P(ui);

        }
        else {
            QMessageBox ::information(this,"","erreur");
        }
}

void MainWindow::on_pushButton_20_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    statistiques *s=new statistiques();
    s->show();
}
//--------verfifaction line agnets--------//
void MainWindow::on_CIN_1_cursorPositionChanged(int arg1, int arg2)
{agents A;
    A.verifCIN(ui);
}

void MainWindow::on_nom_1_cursorPositionChanged(int arg1, int arg2)
{agents A;
    A.verifnom(ui);

}

void MainWindow::on_prenom_0_cursorPositionChanged(int arg1, int arg2)
{
    agents A;
        A.verifprenom(ui);
}

void MainWindow::on_email_0_cursorPositionChanged(int arg1, int arg2)
{
    agents A;
        A.VerifMail(ui);
}

void MainWindow::on_tel_0_cursorPositionChanged(int arg1, int arg2)
{
    agents A;
        A.verifTel(ui);
}

void MainWindow::on_date_0_dateChanged(const QDate &date)
{
    agents A;
        A.verifdate(ui);
}

void MainWindow::on_CIN_m_cursorPositionChanged(int arg1, int arg2)
{
    agents A;
        A.verifCIN_m(ui);
}

void MainWindow::on_nom_m_cursorPositionChanged(int arg1, int arg2)
{
    agents A;
        A.verifnom_m(ui);
}

void MainWindow::on_prenom_m_cursorPositionChanged(int arg1, int arg2)
{
    agents A;
        A.verifprenom_m(ui);
}

void MainWindow::on_date_m_dateChanged(const QDate &date)
{
    agents A;
        A.verifdate_m(ui);
}

void MainWindow::on_email_m_cursorPositionChanged(int arg1, int arg2)
{
    agents A;
        A.VerifMail_m(ui);
}

void MainWindow::on_tel_m_cursorPositionChanged(int arg1, int arg2)
{
    agents A;
        A.verifTel_m(ui);
}
//--------verfifaction line profil--------//

void MainWindow::on_ID_0_cursorPositionChanged(int arg1, int arg2)
{
    profil p;
        p.verifID(ui);
}

void MainWindow::on_nom_profil_0_cursorPositionChanged(int arg1, int arg2)
{
    profil p;
        p.verifnom_profil(ui);
}

void MainWindow::on_salaire_0_cursorPositionChanged(int arg1, int arg2)
{
    profil p;
        p.verifsalaire(ui);
}

void MainWindow::on_description_0_cursorPositionChanged(int arg1, int arg2)
{
    profil p;
        p.verifdescription(ui);
}

void MainWindow::on_nb_0_cursorPositionChanged(int arg1, int arg2)
{
    profil p;
        p.verifnb_agents(ui);
}

void MainWindow::on_IDp_m_cursorPositionChanged(int arg1, int arg2)
{
    profil p;
        p.verifIDm(ui);
}

void MainWindow::on_nomp_m_cursorPositionChanged(int arg1, int arg2)
{
    profil p;
        p.verifnom_profilm(ui);
}

void MainWindow::on_salairep_m_cursorPositionChanged(int arg1, int arg2)
{
    profil p;
        p.verifsalairem(ui);
}

void MainWindow::on_descriptionp_m_cursorPositionChanged(int arg1, int arg2)
{
    profil p;
        p.verifdescriptionm(ui);
}

void MainWindow::on_nbagentsp_m_cursorPositionChanged(int arg1, int arg2)
{
    profil p;
        p.verifnb_agentsm(ui);
}

void MainWindow::on_pushButton_16_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
   ui->tabWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
   ui->tabWidget_2->setCurrentIndex(1);
}
//*******bougacha********//
void MainWindow::on_ajouter_3_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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

void MainWindow::on_pushButton_mod_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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

void MainWindow::on_pushButton_supp_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    gestionmoyen g;
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

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QMessageBox msgBox;

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
void MainWindow::on_Refreche_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    gestionmoyen g;
    ui->tableView->setModel(g.afficher());
}

void MainWindow::on_comboBox_trier_activated(const QString &arg1)
{
   gestionmoyen g;
   QSqlQueryModel * modal = new QSqlQueryModel();
   QSqlQuery * qry = new QSqlQuery();
   if (arg1=="ref")
   {
    qry->prepare("Select * from transport order by ref ");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }
  else if (arg1=="modele")
   {
    qry->prepare("Select * from transport order by modele desc");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }

   else if (arg1=="nombre de place")
   {
    qry->prepare("Select * from transport order by modele,nombre_de_place  ");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }
}
void MainWindow::on_comboBox_rechercher_activated(const QString &arg1)
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


void MainWindow::on_pushButton_AJOUTER_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    int id=ui->lineEdit->text().toInt();
    QString nom=ui->lineEdit_2->text();
    QString prenom=ui->lineEdit_3->text();
    int ref_moy=ui->lineEdit_4->text().toInt();
    QString payment=ui->lineEdit_5->text();

    abonnement a(id,nom,prenom,ref_moy,payment);
    bool test=a.ajouter();
    QMessageBox msgBox;

    if(test)
      {  msgBox.setText("Ajout avec succes.");
        ui->tableView_2->setModel(a.afficher());
    }
    else
       msgBox.setText("Echec d'ajout");
   msgBox.exec();

}

void MainWindow::on_pushButton_mod_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    int id=ui->lineEdit_id->text().toInt();
    QString nom=ui->lineEdit_nom_3->text();
    QString prenom=ui->lineEdi_prenom3->text();
    int ref_moy=ui->lineEdit_ref_4->text().toInt();
    QString payment=ui->lineEdit_payment->text();

    abonnement a(id,nom,prenom,ref_moy,payment);
    bool test=a.modifier();
    QMessageBox msgBox;

    if(test)
      {  msgBox.setText("Modification avec succes.");
        ui->tableView_2->setModel(a.afficher());
    }
    else
        msgBox.setText("Echec de Modification");
   msgBox.exec();
}

void MainWindow::on_pushButton_supp_2_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    int y=ui->lineEdit_id->text().toInt();
    bool test=a.supprimer(y);
    QMessageBox msgBox;

    if(test)
       {
    msgBox.setText("Suppression avec succes.");
    ui->tableView_2->setModel(a.afficher());//refreche

    }
    else
        msgBox.setText("Echec de suppression");
   msgBox.exec();
}

void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QMessageBox msgBox;

      abonnement a;
           QString val = ui->tableView_2->model()->data(index).toString();
           QString id_string= QString::number(a.get_id());
           QString ref_moy_string= QString::number(a.get_ref_moy());

           QSqlQuery query;
            query.prepare("select * from abonnement where id=:val or nom=:val or prenom=:val  or ref_moy=:val or payement=:val ");
            query.bindValue(":val", val);

           if (query.exec())
           {
               while (query.next())
               {
                   ui->lineEdit_id->setText(query.value(0).toString());
                   ui->lineEdit_nom_3->setText(query.value(1).toString());
                   ui->lineEdi_prenom3->setText(query.value(2).toString());
                   ui->lineEdit_ref_4->setText(query.value(3).toString());
                   ui->lineEdit_payment->setText(query.value(4).toString());
               }
           }
           else
           {
                               msgBox.setText("Erreur");
           }
}

void MainWindow::on_Refreche_2_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    abonnement a;
    ui->tableView_2->setModel(a.afficher());

}

void MainWindow::on_comboBox_rechercher_2_activated(const QString &arg1)
{
    abonnement a;
   if(arg1=="ref_moy et nom et prenom")
   {
   a.chercher(ui->lineEdit_ref_4->text().toInt(),ui->lineEdit_nom_3->text(),ui->lineEdi_prenom3->text());
   ui->tableView_2->setModel(a.afficher_unabonnement());
   }
   else if (arg1=="id")
   {
      a.chercher_id(ui->lineEdit_id->text().toInt());
       ui->tableView_2->setModel(a.afficher_unabonnement_id());

   }
   else if (arg1=="nom et prenom ")
   {
       a.chercher_nom_prenom(ui->lineEdit_nom_3->text(),ui->lineEdi_prenom3->text());
       ui->tableView_2->setModel(a.afficher_unabonnement_nom_prenom());

   }

}

void MainWindow::on_comboBox_trier_2_activated(const QString &arg1)
{
    abonnement a ;
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery();
    if (arg1=="id")
    {
     qry->prepare("Select * from abonnement order by id ");
     qry->exec();
     modal->setQuery(*qry);
     ui->tableView_2->setModel(modal);
     ui->tableView_2->show();
    }
   else if (arg1=="nom et prenom")
    {
     qry->prepare("Select * from abonnement order by nom,prenom");
     qry->exec();
     modal->setQuery(*qry);
     ui->tableView_2->setModel(modal);
     ui->tableView_2->show();
    }

    else if (arg1=="ref_moy et nom et prenom")
    {
     qry->prepare("Select * from abonnement order by ref_moy,nom,prenom ");
     qry->exec();
     modal->setQuery(*qry);
     ui->tableView_2->setModel(modal);
     ui->tableView_2->show();
    }
}

void MainWindow::on_pushButton_PDF_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QString strStream;
    QTextStream out(&strStream);

     const int rowCount = ui->tableView->model()->rowCount();
     const int columnCount = ui->tableView->model()->columnCount();
    out <<  "<html>\n"
    "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg("strTitle")
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                     "<center> <H1>liste d'Abonnement </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                 // headers
                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                 for (int column = 0; column < columnCount; column++)
                     if (!ui->tableView->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->tableView->isColumnHidden(column)) {
                             QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_imprimer_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;
}

void MainWindow::on_pushButton_PDF_2_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QString strStream;
    QTextStream out(&strStream);

     const int rowCount = ui->tableView_2->model()->rowCount();
     const int columnCount = ui->tableView_2->model()->columnCount();
    out <<  "<html>\n"
    "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg("strTitle")
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                     "<center> <H1>liste d'Abonnement </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                 // headers
                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                 for (int column = 0; column < columnCount; column++)
                     if (!ui->tableView_2->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->tableView_2->isColumnHidden(column)) {
                             QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_imprimer_2_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;
}
//******imen********//
void MainWindow::on_btn_ajouter_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    int id=ui->id_2->text().toInt();
    QString nom= ui->nom_7->text();
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

void MainWindow::on_btn_modifier_c_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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

void MainWindow::on_btn_supprimer_c_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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

void MainWindow::on_btn_rechercher_c_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QString nom = ui->nom_a_chercher->text();
        if(tmpc.verifierExnoms(nom)==false)
        {QMessageBox::warning(this,"ERREUR","Categorie n'existe pas");}
        else
        ui->tab_cat->setModel(tmpc.recherche_nom(nom));
}

void MainWindow::on_btn_refresh_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
      ui->tab_cat->setModel(tmpc.afficher());
}

void MainWindow::on_btn_pdf_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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

void MainWindow::on_tri_id_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->tab_cat->setModel(tmpc.trier1());
}

void MainWindow::on_tri_nom_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->tab_cat->setModel(tmpc.trier());
}

void MainWindow::on_pushButton_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }

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

void MainWindow::on_btn_modifier_p_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }

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

void MainWindow::on_btn_supprimer_p_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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

void MainWindow::on_btn_refreshp_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->tabp->setModel(tmpp.afficher());
}

void MainWindow::on_btn_rechercher_p_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QString nom = ui->lineEdit_6->text();
        if(tmpp.verifierExnoms(nom)==false)
        {QMessageBox::warning(this,"ERREUR","Projet n'existe pas");}
        else
        ui->tabp->setModel(tmpp.recherche_nom(nom));
}

void MainWindow::on_btn_pdf_p_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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

void MainWindow::on_btn_tri_nom_p_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
      ui->tabp->setModel(tmpp.trier());
}

void MainWindow::on_btn_tri_id_p_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
      ui->tabp->setModel(tmpp.trier1());
}





void MainWindow::on_pushButton_8_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_11_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
      ui->stackedWidget->setCurrentIndex(6);
}
void MainWindow::on_pushButton_9_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_ajouter_9_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
     ui->stackedWidget->setCurrentIndex(2);
     ui->ajouter_2->show();
     ui->afficher_2->show();
     ui->modifier->hide();
     ui->Statistque->setStyleSheet("QPushButton{background: transparent;}");
}

void MainWindow::on_ajouter_12_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_ajouter_13_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_btn_categorie_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
     ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_btn_projets_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
     ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_ajouter_14_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_ajouter_10_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
     ui->stackedWidget->setCurrentIndex(9);
}
//*********ben abdhallah*****//
void MainWindow::on_pushButton_6_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QSqlQuery qry;


    QString id_bloc;
        QString nom_bloc;
        QString equipement;
        QString type_equipement;
        QString numero_four;
        QString date ;
        QString situation ;
   id_bloc=ui->lineEdit_id_2->text();
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
    ui->tableView_4->setModel(c.afficherbloc());
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


void MainWindow::on_tabWidget_2_currentChanged(int index)
{

    QSqlQueryModel * modal=new QSqlQueryModel();


    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("select * from BLOC");
    qry->exec();

    modal->setQuery(*qry);
    ui->tableView_4->setModel(modal);


    qDebug() <<(modal->rowCount());
    index=0;
    index++;

}



void MainWindow::on_pushButton_delete_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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

void MainWindow::on_pushButton_edit_clicked()
{   QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QSqlQuery qry ;


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





void MainWindow::on_pushButton_recherche_clicked()
{   QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    Blocc c;
    c.recherche(ui);
}

void MainWindow::on_tableView_4_activated(const QModelIndex &index)
{
    QSqlQuery* query=new QSqlQuery();
QString val=ui->tableView_4->model()->data(index).toString() ;
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



void MainWindow::on_radioButton_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    Blocc c ;
    c.TRI1(ui);
}



void MainWindow::on_radioButton_2_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    Blocc c;
    c.TRI2(ui);
}

void MainWindow::on_pushButton_actualiser_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QSqlQueryModel * modal=new QSqlQueryModel();


    QSqlQuery* qry=new QSqlQuery();

    qry->prepare("select * from BLOC");
    qry->exec();

    modal->setQuery(*qry);
    ui->tableView_4->setModel(modal);

     // ui->tableView->setModel(c.afficher());
     // qDebug()<<ui->tabclient->model()->rowCount();




}

void MainWindow::on_pushButton_sauvgarderreservatio_clicked()
{    QMediaPlayer * bulletsound = new QMediaPlayer();
     bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
    if (bulletsound->state() == QMediaPlayer::PlayingState){
         bulletsound->setPosition(0);
     }
     else if (bulletsound->state() == QMediaPlayer::StoppedState){
         bulletsound->play();
     }
    QSqlQuery qry ;
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










void MainWindow::on_tabWidget_3_currentChanged(int index)
{
    Equipement r;
    r.afficherequipement(ui);
}

void MainWindow::on_tableView_3_activated(const QModelIndex &index)
{
   Equipement r ;
  r.selectionnerequipement(ui,index);
}

void MainWindow::on_pushButton_modifierreservation_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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

void MainWindow::on_pushButton_3_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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

void MainWindow::on_pushButton_4_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    Equipement r ;
    r.afficherequipement(ui);

}

void MainWindow::on_pushButton_5_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    const QString format("<td>%1</td>");
           QString html;
           QAbstractItemModel *md = ui->tableView_3->model();
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

void MainWindow::on_pushButton_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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

//*******bouteraa*******//
void MainWindow::on_pushButton_26_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    int CODE_DEV=ui->lineEdit_19->text().toInt();
    QString DESC_DEV=ui->lineEdit_22->text();
    int MONTNET_DEV=ui->lineEdit_21->text().toInt();
    QString DATE_DEV = ui->lineEdit_20->text();

    devis d(CODE_DEV,MONTNET_DEV,DATE_DEV,DESC_DEV);


    bool test=d.ajouter();
       qDebug() << "test :" << test;
    if (test)
    {
        ui->tableView_6->setModel(dtemp.afficher());
        QMessageBox::information(nullptr,QObject::tr("")
                                 ,QObject::tr("Ajout effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
    }
else
    {
        QMessageBox::critical(nullptr,QObject::tr("erreur")
                                 ,QObject::tr("Ajout non effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
    }

}


void MainWindow::on_pushButton_22_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
 fournisseur f;
 bool test ;
 test=f.modifier(ui);
 ui->tableView_8->setModel(f.afficher());
}

void MainWindow::on_pushButton_19_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QItemSelectionModel *select = ui->tableView_8->selectionModel();

            int id =select->selectedRows(0).value(0).data().toInt();

           if(ftemp.supprimer(id))
            {
                ui->tableView_8->setModel(ftemp.afficher());

             }
}

void MainWindow::on_pushButton_23_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->tableView_8->setModel(ftemp.afficher(  ));


}


void MainWindow::on_pushButton_18_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    int ID_FOUR=ui->lineEdit_8->text().toInt();
    QString NOM_FOUR=ui->lineEdit_7->text();
    QString ADRESSE_FOUR=ui->lineEdit_10->text();
    QString EMAIL_FOUR = ui->lineEdit_11->text();
    int TEL_FOUR=ui->lineEdit_9->text().toInt();

    fournisseur f;



    bool test=f.ajouter(ID_FOUR,NOM_FOUR,ADRESSE_FOUR,EMAIL_FOUR,TEL_FOUR);
       qDebug() << "test :" << test;
    if (test)
    {
        ui->tableView_8->setModel(ftemp.afficher());
        QMessageBox::information(nullptr,QObject::tr("")
                                 ,QObject::tr("Ajout effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
    }
else
    {
        QMessageBox::critical(nullptr,QObject::tr("erreur")
                                 ,QObject::tr("Ajout non effectué\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_29_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->tableView_6->setModel(dtemp.afficher(  ));

}

void MainWindow::on_pushButton_28_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QItemSelectionModel *select = ui->tableView_6->selectionModel();

            int CODE_DEV =select->selectedRows(0).value(0).data().toInt();

           if(dtemp.supprimer(CODE_DEV))
            {
                ui->tableView_6->setModel(dtemp.afficher());

             }
}

void MainWindow::on_pushButton_27_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    devis d;
    bool test ;
    test=d.modifier(ui);
    ui->tableView_6->setModel(d.afficher());


}

void MainWindow::on_pushButton_31_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    {
        ui->tableView_6->setModel(dtemp.afficher(  ));
       int ID_FOUR= ui->lineEdit_13->text().toInt();
       ui->tableView_6->setModel(dtemp.recherche(ID_FOUR));

    }
}

void MainWindow::on_pushButton_30_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()==QDialog::Rejected)

            return;
}


void MainWindow::on_pushButton_25_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->tableView_8->setModel(dtemp.afficher());
}





void MainWindow::on_tableView_8_clicked(const QModelIndex &index)
{
        ui->lineEdit_14->setText( ui->tableView_8->model()->data(ui->tableView_8->model()->index(ui->tableView_8->selectionModel()->currentIndex().row(),0)).toString() );
        ui->lineEdit_15->setText( ui->tableView_8->model()->data(ui->tableView_8->model()->index(ui->tableView_8->selectionModel()->currentIndex().row(),1)).toString() );
        ui->lineEdit_16->setText( ui->tableView_8->model()->data(ui->tableView_8->model()->index(ui->tableView_8->selectionModel()->currentIndex().row(),2)).toString() );
        ui->lineEdit_17->setText( ui->tableView_8->model()->data(ui->tableView_8->model()->index(ui->tableView_8->selectionModel()->currentIndex().row(),0)).toString() );
        ui->lineEdit_18->setText( ui->tableView_8->model()->data(ui->tableView_8->model()->index(ui->tableView_8->selectionModel()->currentIndex().row(),1)).toString() );
}

void MainWindow::on_tableView_6_clicked(const QModelIndex &index)
{
    ui->lineEdit_19->setText( ui->tableView_6->model()->data(ui->tableView_6->model()->index(ui->tableView_6->selectionModel()->currentIndex().row(),0)).toString() );
    ui->lineEdit_20->setText( ui->tableView_6->model()->data(ui->tableView_6->model()->index(ui->tableView_6->selectionModel()->currentIndex().row(),1)).toString() );
    ui->lineEdit_21->setText( ui->tableView_6->model()->data(ui->tableView_6->model()->index(ui->tableView_6->selectionModel()->currentIndex().row(),2)).toString() );
    ui->lineEdit_22->setText( ui->tableView_6->model()->data(ui->tableView_6->model()->index(ui->tableView_6->selectionModel()->currentIndex().row(),0)).toString() );

}

//***********achref*******//
void MainWindow::on_L_BACK_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_BACK_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_34_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_35_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_L_Add_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }

            int cin= ui->lineEdit_cin0->text().toInt();
            QString nom= ui->lineEdit_nom0->text();
            QString prenom= ui->lineEdit_prenom0->text();
            QDate datedenaissance= ui-> dateEdit->date();
            int idl= ui->lineEdit_idl0->text().toInt();


                individus i(cin,nom,prenom,datedenaissance,idl);

               if (idl<1000){ QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr(" Erreur idl necessite 4 chiffres.\n"
                                                                                         "click cancel to exit."),QMessageBox::Cancel);}
                else{  bool test=i.ajouter();

               if (test)
            {
                ui->tabindiv->setModel(tmpindiv.Afficher_individus());

                QMessageBox::information(nullptr,QObject::tr("ajouter individus"),QObject::tr("individus ajouté.\n"
                                                                                        "click cancel to exit."),QMessageBox::Cancel);

            }}

}

void MainWindow::on_L_delete_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }


        int cin=ui->lineEdit_cin_2->text().toInt();
        bool test=tmpindiv.Supprimer_individus(cin);
        if(test)
        {
            ui->tabindiv->setModel(tmpindiv.Afficher_individus());
            QMessageBox::information(nullptr,QObject::tr("supprimer individus"),QObject::tr("individus supprimé.\n"
                                                                                           "click cancel to exit."),QMessageBox::Cancel);
        }
}

void MainWindow::on_L_modify_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }

        QSqlQuery query;
        int cin= ui->lineEdit_cin->text().toInt();
        QString nom= ui->lineEdit_nom->text();
        QString prenom= ui->lineEdit_prenom->text();
        QDate datedenaissance= ui-> dateEdit_modifier->date();
        int idl= ui->lineEdit_idl->text().toInt();


            individus i(cin,nom,prenom,datedenaissance,idl);


    bool test =i.Modifier_individus(cin,nom,prenom,datedenaissance,idl);

        if(test)
        {ui->tabindiv->setModel(i.Afficher_individus());
            QMessageBox::information(nullptr, QObject::tr("modifier individus"),
                                     QObject::tr("individus modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
                   {
                       QMessageBox ::critical(nullptr,QObject::tr("modifier individus"),
                                                         QObject::tr("Erreur.\n"
                                                             "click cancel to exit"),QMessageBox::Cancel);

                   }

}
//***********Print*****************
void MainWindow::on_L_modify_4_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }

        QPrinter printer;
                        printer.setOutputFormat(QPrinter::PdfFormat);
                        printer.setOutputFileName("C://Users//El-Khar//Desktop//ProjetQTT//individus.pdf");
                        QPainter painter;

                        if (! painter.begin(&printer)) { // failed to open file
                            qWarning("failed to open file, is it writable?");
                        }

                        QSqlQuery   query ;
                        qDebug() << query.prepare("select sysdate from dual ");
                        if ( query.exec() )
                        {

                            QString S= QDate::currentDate().toString();
                            painter.drawText(850,50,S);
                            QPen penred(Qt::black);

                            painter.setFont(QFont("Arial", 30));
                            penred.setWidth(1);
                            painter.setPen(penred);

                            painter.drawText(350,100," individus ");
                            painter.setFont(QFont("Arial",30));
                            painter.setPen(Qt::black);

                        }

                        QString  cin,nom,prenom,datedenaissance,idl;
                        QSqlQuery   qry ;
                        int i =50;
                        int k=0;
                        qDebug() << qry.prepare("select * from individus ");

                        if ( qry.exec() )
                        {

                            while(qry.next())
                            {

                                if ( k % 13 ==0)
                                {   i=250;
                                    painter.setFont(QFont("Arial",10));
                                    QPen penblack(Qt::black);

                                    painter.setPen(penblack);
                    painter.drawText (0,200,"cin");
                    painter.drawText (90,200,"nom");
                    painter.drawText (230,200,"prenom");
                    painter.drawText (420,200,"datedenaissance");
                     painter.drawText (600,200,"idl");

                                }

                                painter.setFont(QFont("Arial",10));
                                QPen penblack(Qt::black);

                                painter.setPen(penblack);
                                int j=0;
                                cin= qry.value(0).toString();
                                painter.drawText(j*20,i, cin);
                                j++;
                                nom=qry.value(1).toString();
                                painter.drawText(j*90,i, nom);
                                j++;
                               prenom=qry.value(2).toString();
                                painter.drawText(j*100,i, prenom);
                                j++;
                                datedenaissance=qry.value(3).toString();
                                painter.drawText(j*139,i, datedenaissance);
                                j++;
                               idl=qry.value(5).toString();
                                painter.drawText(j*160,i, idl);

                                i+=80;
                                k++;

                            }
                        }

                        painter.end();

}

void MainWindow::on_pushButton_36_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget_2->setCurrentIndex(4);

}

void MainWindow::on_pushButton_37_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget_2->setCurrentIndex(3);

}

void MainWindow::on_L_BACK_3_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget_2->setCurrentIndex(0);

}

void MainWindow::on_L_BACK_2_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget_2->setCurrentIndex(0);

}

void MainWindow::on_pushButton_38_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    int id= ui->l_id->text().toInt();
    QString nomf= ui->l_nomf->text();
    QString secteur= ui->l_secteur->text();
    int price= ui->l_price->text().toInt();


        logement l(id,nomf,secteur,price);

     if(id<1000){   QMessageBox::information(nullptr,QObject::tr("erreur"),QObject::tr("id incomplet.\n"
                                                                                                 "click cancel to exit."),QMessageBox::Cancel);}
        else{ bool test=l.ajouter();
         if (test)
    {
        ui->tablog->setModel(tmplog.Afficher_logement());

        QMessageBox::information(nullptr,QObject::tr("ajouter logement"),QObject::tr("logement ajouté.\n"
                                                                                       "click cancel to exit."),QMessageBox::Cancel);

    }}

}

void MainWindow::on_L_modify_2_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QSqlQuery query;

    int id= ui->l_id2->text().toInt();
    QString nomf= ui->l_nomf2->text();
    QString secteur= ui->l_secteur2->text();
    int price= ui->l_price2->text().toInt();

  logement l(id,nomf,secteur,price);

bool test =l.Modifier_logement(id,nomf,secteur,price);
if(test)
    {ui->tablog->setModel(l.Afficher_logement());
        QMessageBox::information(nullptr, QObject::tr("modifier logement"),
                                 QObject::tr("logement modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
               {
                   QMessageBox ::critical(nullptr,QObject::tr("modifier logement"),
                                                     QObject::tr("Erreur.\n"
                                                         "click cancel to exit"),QMessageBox::Cancel);

               }

}

void MainWindow::on_L_delete_2_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    int id=ui->l_id3->text().toInt();
    bool test=tmplog.Supprimer_logement(id);
    if(test)
    {
        ui->tablog->setModel(tmplog.Afficher_logement());
        QMessageBox::information(nullptr,QObject::tr("supprimer logement"),QObject::tr("logement supprimé.\n"
                                                                                       "click cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_L_delete_4_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
        ui->tablog->setModel(tmplog.TRIER_logement());
}

void MainWindow::on_L_delete_3_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->tablog->setModel(tmplog.TRIER2_logement());

}

void MainWindow::on_L_delete_5_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QString text;

     text=ui->l_id3->text();

     if(text == "")

     {

         ui->tablog->setModel(tmplog.Afficher_logement());

     }

     else

     {



         ui->tablog->setModel(tmplog.CHERCHER_logement(text));

     }
}
void MainWindow::on_ajouter_11_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_delete_2_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    Arduino1 =new arduinoo(this);
    Arduino1->show();
}

void MainWindow::on_pushButton_delete_3_clicked()
{ QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/JoKerTn/Downloads/Compressed/Smart_Municipality_2A14-gestion_agents_Wael_Hcine_second_branch/Gestion_agents_Wael_Hcine/clic.wav"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    stati s;
    s.exec();
}
void MainWindow::readserial(){

    data= A1.read_from_arduino();
  QString letter;
  letter += QString::fromStdString(data.toStdString());
 qDebug()<<letter;
 ui->lineEdit_user->setText(letter);

}
void MainWindow::on_pushButton_login_clicked()
{
    QString nom,mot_de_passe ;
    nom=ui->lineEdit_user->text();
    mot_de_passe=ui->lineEdit_password->text();
    QMessageBox msgBox;

    QSqlQuery qry ;
    if (qry.exec("select * from LOGIN where id='"+nom+"' and pass='"+mot_de_passe+"'"))
   {
        int count=0;
        while(qry.next())
        {
            count ++ ;
        }
        if(count==1)
        {
            ui->stackedWidget->setCurrentIndex(1);
A1.clear();
A1.write_to_arduino("1");
            msgBox.setText("bienvenue!");
            msgBox.exec();
            ui->label_user_icon->setText("MU");



            //hide();
        }
        if(count<1)
        {
             A1.write_to_arduino("0");
            msgBox.setText("faux compte.");
            msgBox.exec();

        }
    }

}

void MainWindow::on_pushButton_40_clicked()
{
    ftemp.tri_id();
    ui->tableView_8->setModel(ftemp.tri_id());
}

void MainWindow::on_pushButton_41_clicked()
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

void MainWindow::on_pushButton_43_clicked()
{
    devis dtemp;
    dtemp.tri_montant_a(ui);
}

void MainWindow::on_pushButton_45_clicked()
{
    devis dtemp;
    dtemp.tri_montant_d(ui);
}

void MainWindow::on_pushButton_46_clicked()
{
         QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = ui->tableView_8->model()->rowCount();
                 const int columnCount = ui->tableView_8->model()->columnCount();

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
                     if (!ui->tableView_8->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tableView_8->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->tableView_8->isColumnHidden(column)) {
                             QString data = ui->tableView_8->model()->data(ui->tableView_8->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_44_clicked()
{
    ftemp.tri_nom();
    ui->tableView_8->setModel(ftemp.tri_nom());
}

void MainWindow::on_btn_settings_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_user_icon->setText("");
}
