#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "arduin.h"
#include <QMainWindow>
#include <QAbstractItemModel>
#include <QPainter>
#include <QPrinter>
#include <QMainWindow>
#include<QPropertyAnimation>
#include<QtMultimedia/QMediaPlayer>
#include<QDebug>
#include "gestionmoyen.h"
#include "abonnement.h"
#include "categorie.h"
#include "projet.h"
#include "devis.h"
#include "fournisseur.h"
#include "individus.h"
#include "logement.h"
#include"arduinoo.h"
#include <QSerialPort>
#include <QSerialPortInfo>



#include <QByteArray>
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





    void on_ajouter_0_clicked();



    void on_chercher_agents_cursorPositionChanged(int arg1, int arg2);


    void on_pushButton_13_clicked();

    void on_tab_agents_activated(const QModelIndex &index);

    void on_pushButton_12_clicked();

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

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();
    //**********bougacha******//


    void on_pushButton_mod_clicked();

    void on_pushButton_supp_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_Refreche_clicked();

    void on_comboBox_trier_activated(const QString &arg1);

    void on_comboBox_rechercher_activated(const QString &arg1);



    void on_pushButton_AJOUTER_clicked();

    void on_pushButton_mod_2_clicked();

    void on_pushButton_supp_2_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_Refreche_2_clicked();

    void on_comboBox_rechercher_2_activated(const QString &arg1);

    void on_comboBox_trier_2_activated(const QString &arg1);

    void on_pushButton_PDF_clicked();

    void on_pushButton_imprimer_clicked();

    void on_pushButton_PDF_2_clicked();

    void on_pushButton_imprimer_2_clicked();

    void on_ajouter_3_clicked();
    //*******imen*****//
    void on_btn_ajouter_clicked();

    void on_btn_modifier_c_clicked();

    void on_btn_supprimer_c_clicked();

    void on_btn_rechercher_c_clicked();

    void on_btn_refresh_clicked();

    void on_btn_pdf_clicked();

    void on_tri_id_clicked();

    void on_tri_nom_clicked();
    void on_pushButton_clicked();

    void on_btn_modifier_p_clicked();

    void on_btn_supprimer_p_clicked();

    void on_btn_refreshp_clicked();

    void on_btn_rechercher_p_clicked();

    void on_btn_pdf_p_clicked();

    void on_btn_tri_nom_p_clicked();

    void on_btn_tri_id_p_clicked();


    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_11_clicked();

    void on_ajouter_9_clicked();

    void on_ajouter_12_clicked();

    void on_ajouter_13_clicked();

    void on_btn_categorie_clicked();

    void on_btn_projets_clicked();

    void on_ajouter_14_clicked();



    void on_ajouter_10_clicked();
    //*******ben adbhallah***********//
    void on_pushButton_6_clicked();

    void on_tabWidget_2_currentChanged(int index);

    void on_pushButton_delete_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_recherche_clicked();

    void on_tableView_4_activated(const QModelIndex &index);



    void on_radioButton_clicked();



    void on_radioButton_2_clicked();

    void on_pushButton_actualiser_clicked();

    void on_pushButton_sauvgarderreservatio_clicked();

    void on_tabWidget_3_currentChanged(int index);

    void on_tableView_3_activated(const QModelIndex &index);

    void on_pushButton_modifierreservation_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

     void on_pushButton_8_clicked();
     //********bouteraa**********//
      void on_pushButton_26_clicked();
     void on_pushButton_22_clicked();
     void on_pushButton_23_clicked();
    void on_tableView_5_clicked(const QModelIndex &index);
    void on_tableView_6_clicked(const QModelIndex &index);
    void on_comboBox_8_activated(const QString &arg1);
    void on_pushButton_25_clicked();
    void on_pushButton_30_clicked();
    void on_pushButton_31_clicked();
    void on_pushButton_29_clicked();
void on_comboBox_7_activated(const QString &arg1);
//********achref*********//
void on_L_BACK_clicked();

void on_pushButton_BACK_clicked();

void on_pushButton_34_clicked();

void on_pushButton_35_clicked();

void on_L_Add_clicked();

void on_L_delete_clicked();

void on_L_modify_clicked();

void on_L_modify_4_clicked();

void on_pushButton_36_clicked();

void on_pushButton_37_clicked();

void on_L_BACK_3_clicked();

void on_L_BACK_2_clicked();

void on_pushButton_38_clicked();

void on_L_modify_2_clicked();

void on_L_delete_2_clicked();

void on_L_delete_4_clicked();

void on_L_delete_3_clicked();

void on_L_delete_5_clicked();


void on_tableView_8_clicked(const QModelIndex &index);

void on_ajouter_11_clicked();

void on_pushButton_delete_2_clicked();

void on_pushButton_delete_3_clicked();

void on_pushButton_7_clicked();

void readSerial();
void update(QString);
void lire();
void readserial();
void on_pushButton_login_clicked();

void on_pushButton_40_clicked();

void on_pushButton_41_clicked();

void on_pushButton_42_clicked();

void on_pushButton_43_clicked();

void on_pushButton_45_clicked();

void on_pushButton_46_clicked();

void on_pushButton_44_clicked();

void on_btn_settings_clicked();

private:
    Ui::MainWindow *ui;

    abonnement a;
    Categorie tmpc;
    Projet tmpp;
    devis dtemp;
    fournisseur ftemp;
    individus tmpindiv;
    logement tmplog;
    arduinoo* Arduino1;
    Arduino A1;
    QByteArray data;
    QMediaPlayer* player;

};
#endif // MAINWINDOW_H
