#include "mainwindow.h"

#include <QApplication>
#include "connection.h"
#include "acceuil.h"
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
   Acceuil w;
   bool test =c.createConnect();
   if(test)
   {
       w.show();
       QMessageBox::information(nullptr,QObject::tr("data base is open"),QObject::tr("connection successful \n "
                                                                                     "Click cancel to exit"),QMessageBox::Cancel);

}else  QMessageBox::information(nullptr,QObject::tr("data base is not open"),QObject::tr("connection failed \n "
                                                                                     "Click cancel to exit"),QMessageBox::Cancel);


    return a.exec();
}
