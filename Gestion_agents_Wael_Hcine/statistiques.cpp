#include "statistiques.h"
#include "ui_statistiques.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"agents.h"
statistiques::statistiques(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);

    agents m;

    QBarSet *set1=new QBarSet("nombre des agents");


    *set1 <<m.calculercatego("service")<<m.calculercatego("parking")<<m.calculercatego("maintenance");
    QBarSeries *series=new QBarSeries();
    series->append(set1);

    QChart *chart =new QChart();
    chart->addSeries(series);
    chart->setTitle("statistiques agents");
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList categories;
    categories <<"service"<<"parking"<<"maintenance";
    QBarCategoryAxis *axis=new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    QChartView *chartview=new QChartView(chart);

    this->setCentralWidget(chartview);
}

statistiques::~statistiques()
{
    delete ui;
}
