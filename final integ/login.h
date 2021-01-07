#ifndef login_H
#define login_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
class login
{
public:
    login();
    login(QString , QString);
    bool chercher(QString ID, QString MDP);
private:
    QString id;
    QString mdp;
};

#endif // login_H
