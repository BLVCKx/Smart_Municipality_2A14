#include "mainwindow.h"
#include"conn.h"
#include<QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    conn c;
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
