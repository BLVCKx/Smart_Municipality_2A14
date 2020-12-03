#ifndef ACCEUIL_H
#define ACCEUIL_H

#include <QDialog>

namespace Ui {
class Acceuil;
}

class Acceuil : public QDialog
{
    Q_OBJECT

public:
    explicit Acceuil(QWidget *parent = nullptr);
    ~Acceuil();

private slots:
    void on_btn_projets_clicked();

    void on_btn_categorie_clicked();

private:
    Ui::Acceuil *ui;
};

#endif // ACCEUIL_H
