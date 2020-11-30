#ifndef PROFIL_H
#define PROFIL_H
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

class profil
{
protected:
    QString ID,nom_profil,description;
    QString nb_agents,salaire;
public:
    profil();
    profil(QString ID,QString nom_profil,QString salaire,QString description ,QString nb_agents);
    QString get_ID();
    QString get_nom_profil();
    QString get_salaire();
    QString get_description();
    QString get_nb_agents();
    void set_ID(QString ID1){ID=ID1;};
    void set_nom_profil(QString nom_profil1 ){nom_profil=nom_profil1;}
    void set_salaire(QString salaire1){salaire=salaire1;}
    void set_description(QString description1){description=description1;}
    void set_date(QString nb_agents1){nb_agents=nb_agents1;}
    bool ajouter_p(QString ID, QString nom_profil, QString salaire, QString description,QString nb_agents);
    void afficher_P(Ui::MainWindow *ui);
    QSqlQueryModel *getModelSpecial(QString inputValue,QString filterChecked);
    QSqlQueryModel *afficher_choix_p(QString choix);
    bool modifier_p(Ui::MainWindow *ui);
    bool supprimer_p(Ui::MainWindow *ui);
};
#endif // PROFIL_H
