#ifndef GESTIONPROJET_H
#define GESTIONPROJET_H
#include "projet.h"
#include <QDialog>

namespace Ui {
class gestionprojet;
}

class gestionprojet : public QDialog
{
    Q_OBJECT

public:
    explicit gestionprojet(QWidget *parent = nullptr);
    ~gestionprojet();

private slots:
    void on_pushButton_clicked();

    void on_btn_modifier_p_clicked();

    void on_btn_supprimer_p_clicked();

    void on_btn_refreshp_clicked();

    void on_btn_rechercher_p_clicked();

    void on_btn_pdf_p_clicked();

    void on_btn_tri_nom_p_clicked();

    void on_btn_tri_id_p_clicked();

private:
    Ui::gestionprojet *ui;
    Projet tmpp;
};

#endif // GESTIONPROJET_H
