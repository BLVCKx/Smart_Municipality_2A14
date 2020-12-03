#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include <QMessageBox>
#include <QObject>
#include<QDate>
#include<QDebug>

#include <QPrinter>
#include<QPainter>
#include <QWidget>
#include "individus.h"
#include "logement.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabindiv->setModel(tmpindiv.Afficher_individus());
    ui->tablog->setModel(tmplog.Afficher_logement());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_L_BACK_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_BACK_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_L_Add_clicked()
{
    musicClick();
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
{

    musicClick();
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
{
    musicClick();
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
{
   musicClick();
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

void MainWindow::on_pushButton_5_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_11_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_L_BACK_3_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_L_BACK_2_clicked()
{musicClick();
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_7_clicked()
{musicClick();
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
{  musicClick();
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
{musicClick();
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
{musicClick();
        ui->tablog->setModel(tmplog.TRIER_logement());
}

void MainWindow::on_L_delete_3_clicked()
{musicClick();
    ui->tablog->setModel(tmplog.TRIER2_logement());

}

void MainWindow::on_L_delete_5_clicked()
{musicClick();
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
void MainWindow::musicClick()
{
    musicC=new QMediaPlayer();
    musicC->setMedia(QUrl("qrc:/new/prefix1/10706.mp3"));
    musicC->setVolume(200);
    musicC->play();
}
