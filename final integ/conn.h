#ifndef CONN_H
#define CONN_H
#include<QSqlDatabase>

class conn
{ QSqlDatabase db;
public:
    conn();
    bool createconnection();
    void closeconnection();

};
#endif // CONN_H
