#include "connexion.h"

connexion::connexion()
{

}

bool connexion::createconnect()
{
    bool test =false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Aba20");
    db.setUserName("Ahmedba");
    db.setPassword("27684240");
    if(db.open())
    {
        test=true;
    }
    return test;
}
