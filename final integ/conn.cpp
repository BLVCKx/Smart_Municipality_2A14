#include "conn.h"

conn::conn()
{

}

bool conn::createconnection()
{
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("2A14");//inserer le nom de la source de données ODBC
    db.setUserName("system");//inserer nom de l'utilisateur
    db.setPassword("esprit10");//inserer mot de passe de cet utilisateur
    bool test=false;
    if (db.open())
    test=true;

        return  test;
    }
void conn::closeconnection(){db.close();}
