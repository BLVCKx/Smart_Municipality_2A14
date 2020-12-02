#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase test_bd1 = QSqlDatabase::addDatabase("QODBC");
test_bd1.setDatabaseName("test_bd1");//inserer le nom de la source de données ODBC
test_bd1.setUserName("Ahmed");//inserer nom de l'utilisateur
test_bd1.setPassword("Ahmed");//inserer mot de passe de cet utilisateur

if (test_bd1.open())
test=true;





    return  test;
}
void Connection::fermerconnection()
{

    test_bd1.close();
}
