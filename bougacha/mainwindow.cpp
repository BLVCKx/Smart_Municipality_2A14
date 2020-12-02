#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "transprot.h"
#include<QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        play= new QMediaPlayer(this);
        anim= new QPropertyAnimation(ui->label_6, "geometry");
        anim->setDuration(3000);
        anim->setStartValue(ui->label_6->geometry());
        anim->setEndValue(QRect(450,50,200,200));
        anim->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    transprot t;
    play->setMedia(QUrl::fromLocalFile("C:\\"));
    play->play();
    qDebug()<<play->errorString();
    t.exec();
}
