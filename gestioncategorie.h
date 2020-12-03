#ifndef GESTIONCATEGORIE_H
#define GESTIONCATEGORIE_H

#include <QDialog>
#include "categorie.h"
namespace Ui {
class gestioncategorie;
}

class gestioncategorie : public QDialog
{
    Q_OBJECT

public:
    explicit gestioncategorie(QWidget *parent = nullptr);
    ~gestioncategorie();

private slots:
    void on_btn_ajouter_clicked();

    void on_btn_modifier_c_clicked();

    void on_btn_supprimer_c_clicked();

    void on_btn_rechercher_c_clicked();

    void on_btn_refresh_clicked();

    void on_btn_pdf_clicked();

    void on_tri_id_clicked();

    void on_tri_nom_clicked();

private:
    Ui::gestioncategorie *ui;
    Categorie tmpc;
};

#endif // GESTIONCATEGORIE_H
