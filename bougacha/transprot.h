#ifndef TRANSPROT_H
#define TRANSPROT_H
#include <QThread>
#include <QWidget>
#include <QDialog>
#include "gestionmoyen.h"

namespace Ui {
class transprot;
}

class transprot : public QDialog
{
    Q_OBJECT

public:
    explicit transprot(QWidget *parent = nullptr);
    ~transprot();

private slots:
    void on_ajouter_clicked();

    void on_pushButton_mod_clicked();

    void on_pushButton_supp_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_Refreche_clicked();

    void on_comboBox_trier_activated(const QString &arg1);

    void on_comboBox_rechercher_activated(const QString &arg1);

private:
    Ui::transprot *ui;
    gestionmoyen g;
};

#endif // TRANSPROT_H
