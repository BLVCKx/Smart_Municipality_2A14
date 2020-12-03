#include "acceuil.h"
#include "ui_acceuil.h"
#include "gestionprojet.h"
#include "gestioncategorie.h"
Acceuil::Acceuil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acceuil)
{
    ui->setupUi(this);
}

Acceuil::~Acceuil()
{
    delete ui;
}

void Acceuil::on_btn_projets_clicked()
{
    gestionprojet p;
    p.exec();
}

void Acceuil::on_btn_categorie_clicked()
{
    gestioncategorie s;
    s.exec();
}
