/********************************************************************************
** Form generated from reading UI file 'statistiques.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIQUES_H
#define UI_STATISTIQUES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statistiques
{
public:
    QWidget *centralwidget_1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *statistiques)
    {
        if (statistiques->objectName().isEmpty())
            statistiques->setObjectName(QStringLiteral("statistiques"));
        statistiques->resize(800, 600);
        centralwidget_1 = new QWidget(statistiques);
        centralwidget_1->setObjectName(QStringLiteral("centralwidget_1"));
        statistiques->setCentralWidget(centralwidget_1);
        menubar = new QMenuBar(statistiques);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        statistiques->setMenuBar(menubar);
        statusbar = new QStatusBar(statistiques);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statistiques->setStatusBar(statusbar);

        retranslateUi(statistiques);

        QMetaObject::connectSlotsByName(statistiques);
    } // setupUi

    void retranslateUi(QMainWindow *statistiques)
    {
        statistiques->setWindowTitle(QApplication::translate("statistiques", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class statistiques: public Ui_statistiques {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIQUES_H
