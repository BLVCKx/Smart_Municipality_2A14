#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
private:
    QSqlDatabase test_bd1;
public:
    Connection();
    bool createconnect();
    void fermerconnection();

};

#endif // CONNECTION_H
