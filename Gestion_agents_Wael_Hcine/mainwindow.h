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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
