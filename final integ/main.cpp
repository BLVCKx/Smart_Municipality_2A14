#include "mainwindow.h"
#include"conn.h"
#include<QMessageBox>
#include <QApplication>
#include<QTranslator>
#include<QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    conn c;
    QTranslator T;
       QStringList langs;
       langs <<"francais"<<"arabic"<<"english";
       const QString lang =QInputDialog ::getItem(NULL,"language","select a language",langs);
       if (lang=="english" )
        {T.load(":/english.qm");
       }
           else if
        (lang=="arabic")
       {T.load(":/16x16/arabic.qm");}

       if (lang!="francais")
       {a.installTranslator(&T);}

   bool test=c.createconnection();
    w.show();
    if(test)
    {

        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
    else

        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n""Click Cancel to exit."), QMessageBox::Cancel);
    return a.exec();
}
