#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>
#include <QPainter>
#include <QPrinter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_home_clicked();

    void on_ajouter_2_clicked();

    void on_afficher_2_clicked();

    void on_modifier_clicked();

    void on_Statistque_clicked();



    void on_ajouter_0_clicked();



    void on_chercher_agents_cursorPositionChanged(int arg1, int arg2);


    void on_pushButton_13_clicked();

    void on_tab_agents_activated(const QModelIndex &index);

    void on_pushButton_12_clicked();

    void on_tab_agents_pressed(const QModelIndex &index);

    void on_tab_agents_clicked(const QModelIndex &index);

void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_ajouter_profil_clicked();

    void on_chercher_profil_cursorPositionChanged(int arg1, int arg2);

    void on_comboBox_4_activated(const QString &arg1);

    void on_imprimer_clicked();

    void on_pdf_clicked();

    void on_actualiser_clicked();

    void on_tab_profil_activated(const QModelIndex &index);

    void on_modifier_profil_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_CIN_1_cursorPositionChanged(int arg1, int arg2);

    void on_nom_1_cursorPositionChanged(int arg1, int arg2);

    void on_prenom_0_cursorPositionChanged(int arg1, int arg2);

    void on_email_0_cursorPositionChanged(int arg1, int arg2);

    void on_tel_0_cursorPositionChanged(int arg1, int arg2);

    void on_date_0_userDateChanged(const QDate &date);

    void on_date_0_dateChanged(const QDate &date);

    void on_CIN_m_cursorPositionChanged(int arg1, int arg2);

    void on_nom_m_cursorPositionChanged(int arg1, int arg2);

    void on_prenom_m_cursorPositionChanged(int arg1, int arg2);

    void on_date_m_dateChanged(const QDate &date);

    void on_email_m_cursorPositionChanged(int arg1, int arg2);

    void on_tel_m_cursorPositionChanged(int arg1, int arg2);

    void on_ID_0_cursorPositionChanged(int arg1, int arg2);

    void on_nom_profil_0_cursorPositionChanged(int arg1, int arg2);

    void on_salaire_0_cursorPositionChanged(int arg1, int arg2);

    void on_description_0_cursorPositionChanged(int arg1, int arg2);

    void on_nb_0_cursorPositionChanged(int arg1, int arg2);

    void on_IDp_m_cursorPositionChanged(int arg1, int arg2);

    void on_nomp_m_cursorPositionChanged(int arg1, int arg2);

    void on_salairep_m_cursorPositionChanged(int arg1, int arg2);

    void on_descriptionp_m_cursorPositionChanged(int arg1, int arg2);

    void on_nbagentsp_m_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
