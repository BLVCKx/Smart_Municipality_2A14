#include "connection.h"
#include <QSqlDatabase>

Connection::Connection()
{

}
bool Connection::createConnect()
{
    bool test =false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("test_bd");
        db.setUserName("system");
        db.setPassword("imen");

        if(db.open()) test = true;

        return test;
}
