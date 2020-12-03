#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "individus.h"
#include "logement.h"
#include<QMediaPlayer>
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QDate>
#include <QString>
#include <QObject>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void musicClick();
private slots:
    void on_L_BACK_clicked();

    void on_pushButton_BACK_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_L_Add_clicked();

    void on_L_delete_clicked();

    void on_L_modify_clicked();

    void on_L_modify_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_11_clicked();

    void on_L_BACK_3_clicked();

    void on_L_BACK_2_clicked();

    void on_pushButton_7_clicked();

    void on_L_modify_2_clicked();

    void on_L_delete_2_clicked();

    void on_L_delete_4_clicked();

    void on_L_delete_3_clicked();

    void on_L_delete_5_clicked();

private:
    Ui::MainWindow *ui;
 individus tmpindiv;
 logement tmplog;
 QMediaPlayer *musicC= new QMediaPlayer();

};
#endif // MAINWINDOW_H
