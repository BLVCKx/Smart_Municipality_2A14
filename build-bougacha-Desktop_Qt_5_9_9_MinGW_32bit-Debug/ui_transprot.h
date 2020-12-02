/********************************************************************************
** Form generated from reading UI file 'transprot.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSPROT_H
#define UI_TRANSPROT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_transprot
{
public:
    QGroupBox *titre;
    QToolBox *toolBox;
    QWidget *page_3;
    QTabWidget *tabWidget;
    QWidget *tab_8;
    QLineEdit *lineEdit_ref;
    QPushButton *ajouter;
    QLabel *reference;
    QLabel *nom;
    QLabel *quantite;
    QLabel *quantite_2;
    QSpinBox *spinBox_np;
    QLabel *quantite_3;
    QLineEdit *lineEdi_confort;
    QLineEdit *lineEdit_cli;
    QComboBox *comboBox;
    QWidget *tab_10;
    QTableView *tableView;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_supp;
    QLineEdit *lineEdit_sup;
    QLineEdit *lineEdit_ref_2;
    QLineEdit *lineEdi_confort_2;
    QSpinBox *spinBox_np_2;
    QLineEdit *lineEdit_cli_2;
    QLabel *quantite_4;
    QLabel *nom_9;
    QLabel *reference_2;
    QLabel *quantite_5;
    QLabel *quantite_6;
    QPushButton *Refreche;
    QComboBox *comboBox_rechercher;
    QComboBox *comboBox_trier;
    QComboBox *comboBox_2;
    QWidget *tab_5;
    QWidget *page_4;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QLineEdit *lineEdit;
    QLabel *nom_2;
    QLabel *nom_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *nom_4;
    QLabel *nom_5;
    QLabel *nom_6;
    QDateEdit *dateEdit;
    QLabel *nom_7;
    QDateEdit *dateEdit_2;
    QLabel *nom_8;
    QCheckBox *checkBox_2;
    QWidget *tab_2;

    void setupUi(QDialog *transprot)
    {
        if (transprot->objectName().isEmpty())
            transprot->setObjectName(QStringLiteral("transprot"));
        transprot->resize(1275, 598);
        titre = new QGroupBox(transprot);
        titre->setObjectName(QStringLiteral("titre"));
        titre->setGeometry(QRect(80, 10, 931, 601));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        titre->setFont(font);
        titre->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        toolBox = new QToolBox(titre);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(0, 30, 921, 541));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        toolBox->setFont(font1);
        toolBox->setStyleSheet(QLatin1String("background-color: rgb(170, 0, 0);\n"
""));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 921, 481));
        tabWidget = new QTabWidget(page_3);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 921, 551));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setUnderline(false);
        font2.setWeight(75);
        tabWidget->setFont(font2);
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgb(170, 0, 0);"));
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        lineEdit_ref = new QLineEdit(tab_8);
        lineEdit_ref->setObjectName(QStringLiteral("lineEdit_ref"));
        lineEdit_ref->setGeometry(QRect(360, 120, 211, 22));
        lineEdit_ref->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        ajouter = new QPushButton(tab_8);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(550, 380, 131, 28));
        reference = new QLabel(tab_8);
        reference->setObjectName(QStringLiteral("reference"));
        reference->setGeometry(QRect(210, 150, 111, 20));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setUnderline(false);
        font3.setWeight(75);
        reference->setFont(font3);
        nom = new QLabel(tab_8);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(210, 120, 55, 16));
        nom->setFont(font3);
        quantite = new QLabel(tab_8);
        quantite->setObjectName(QStringLiteral("quantite"));
        quantite->setGeometry(QRect(210, 190, 81, 20));
        quantite->setFont(font3);
        quantite->setStyleSheet(QStringLiteral(""));
        quantite_2 = new QLabel(tab_8);
        quantite_2->setObjectName(QStringLiteral("quantite_2"));
        quantite_2->setGeometry(QRect(160, 250, 151, 20));
        quantite_2->setFont(font3);
        quantite_2->setStyleSheet(QStringLiteral(""));
        spinBox_np = new QSpinBox(tab_8);
        spinBox_np->setObjectName(QStringLiteral("spinBox_np"));
        spinBox_np->setGeometry(QRect(380, 250, 42, 22));
        quantite_3 = new QLabel(tab_8);
        quantite_3->setObjectName(QStringLiteral("quantite_3"));
        quantite_3->setGeometry(QRect(180, 300, 111, 20));
        quantite_3->setFont(font3);
        quantite_3->setStyleSheet(QStringLiteral(""));
        lineEdi_confort = new QLineEdit(tab_8);
        lineEdi_confort->setObjectName(QStringLiteral("lineEdi_confort"));
        lineEdi_confort->setGeometry(QRect(360, 200, 211, 22));
        lineEdi_confort->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_cli = new QLineEdit(tab_8);
        lineEdit_cli->setObjectName(QStringLiteral("lineEdit_cli"));
        lineEdit_cli->setGeometry(QRect(360, 290, 211, 22));
        lineEdit_cli->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        comboBox = new QComboBox(tab_8);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(358, 150, 211, 22));
        tabWidget->addTab(tab_8, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        tableView = new QTableView(tab_10);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 130, 501, 301));
        tableView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_mod = new QPushButton(tab_10);
        pushButton_mod->setObjectName(QStringLiteral("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(170, 50, 93, 28));
        pushButton_supp = new QPushButton(tab_10);
        pushButton_supp->setObjectName(QStringLiteral("pushButton_supp"));
        pushButton_supp->setGeometry(QRect(290, 50, 93, 28));
        lineEdit_sup = new QLineEdit(tab_10);
        lineEdit_sup->setObjectName(QStringLiteral("lineEdit_sup"));
        lineEdit_sup->setGeometry(QRect(280, 90, 113, 22));
        lineEdit_sup->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_ref_2 = new QLineEdit(tab_10);
        lineEdit_ref_2->setObjectName(QStringLiteral("lineEdit_ref_2"));
        lineEdit_ref_2->setGeometry(QRect(720, 140, 113, 22));
        lineEdit_ref_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdi_confort_2 = new QLineEdit(tab_10);
        lineEdi_confort_2->setObjectName(QStringLiteral("lineEdi_confort_2"));
        lineEdi_confort_2->setGeometry(QRect(720, 230, 113, 22));
        lineEdi_confort_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        spinBox_np_2 = new QSpinBox(tab_10);
        spinBox_np_2->setObjectName(QStringLiteral("spinBox_np_2"));
        spinBox_np_2->setGeometry(QRect(750, 280, 42, 22));
        lineEdit_cli_2 = new QLineEdit(tab_10);
        lineEdit_cli_2->setObjectName(QStringLiteral("lineEdit_cli_2"));
        lineEdit_cli_2->setGeometry(QRect(720, 330, 113, 22));
        lineEdit_cli_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        quantite_4 = new QLabel(tab_10);
        quantite_4->setObjectName(QStringLiteral("quantite_4"));
        quantite_4->setGeometry(QRect(540, 280, 151, 20));
        quantite_4->setFont(font3);
        quantite_4->setStyleSheet(QStringLiteral(""));
        nom_9 = new QLabel(tab_10);
        nom_9->setObjectName(QStringLiteral("nom_9"));
        nom_9->setGeometry(QRect(590, 150, 55, 16));
        nom_9->setFont(font3);
        reference_2 = new QLabel(tab_10);
        reference_2->setObjectName(QStringLiteral("reference_2"));
        reference_2->setGeometry(QRect(590, 180, 111, 20));
        reference_2->setFont(font3);
        quantite_5 = new QLabel(tab_10);
        quantite_5->setObjectName(QStringLiteral("quantite_5"));
        quantite_5->setGeometry(QRect(590, 220, 81, 20));
        quantite_5->setFont(font3);
        quantite_5->setStyleSheet(QStringLiteral(""));
        quantite_6 = new QLabel(tab_10);
        quantite_6->setObjectName(QStringLiteral("quantite_6"));
        quantite_6->setGeometry(QRect(560, 330, 111, 20));
        quantite_6->setFont(font3);
        quantite_6->setStyleSheet(QStringLiteral(""));
        Refreche = new QPushButton(tab_10);
        Refreche->setObjectName(QStringLiteral("Refreche"));
        Refreche->setGeometry(QRect(530, 410, 93, 28));
        comboBox_rechercher = new QComboBox(tab_10);
        comboBox_rechercher->setObjectName(QStringLiteral("comboBox_rechercher"));
        comboBox_rechercher->setGeometry(QRect(40, 50, 111, 22));
        comboBox_trier = new QComboBox(tab_10);
        comboBox_trier->setObjectName(QStringLiteral("comboBox_trier"));
        comboBox_trier->setGeometry(QRect(410, 50, 73, 31));
        comboBox_2 = new QComboBox(tab_10);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(718, 190, 121, 22));
        tabWidget->addTab(tab_10, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());
        toolBox->addItem(page_3, QStringLiteral("moyens de transport"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 921, 481));
        tabWidget_2 = new QTabWidget(page_4);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(30, 0, 681, 391));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(320, 70, 113, 22));
        nom_2 = new QLabel(tab);
        nom_2->setObjectName(QStringLiteral("nom_2"));
        nom_2->setGeometry(QRect(190, 70, 61, 20));
        nom_2->setFont(font3);
        nom_3 = new QLabel(tab);
        nom_3->setObjectName(QStringLiteral("nom_3"));
        nom_3->setGeometry(QRect(190, 120, 55, 16));
        nom_3->setFont(font3);
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(320, 120, 113, 22));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(320, 170, 113, 22));
        nom_4 = new QLabel(tab);
        nom_4->setObjectName(QStringLiteral("nom_4"));
        nom_4->setGeometry(QRect(190, 170, 81, 16));
        nom_4->setFont(font3);
        nom_5 = new QLabel(tab);
        nom_5->setObjectName(QStringLiteral("nom_5"));
        nom_5->setGeometry(QRect(180, 220, 101, 16));
        nom_5->setFont(font3);
        nom_6 = new QLabel(tab);
        nom_6->setObjectName(QStringLiteral("nom_6"));
        nom_6->setGeometry(QRect(180, 260, 55, 16));
        nom_6->setFont(font3);
        dateEdit = new QDateEdit(tab);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(250, 260, 110, 22));
        nom_7 = new QLabel(tab);
        nom_7->setObjectName(QStringLiteral("nom_7"));
        nom_7->setGeometry(QRect(410, 260, 71, 16));
        nom_7->setFont(font3);
        dateEdit_2 = new QDateEdit(tab);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(520, 260, 110, 22));
        nom_8 = new QLabel(tab);
        nom_8->setObjectName(QStringLiteral("nom_8"));
        nom_8->setGeometry(QRect(190, 310, 55, 16));
        nom_8->setFont(font3);
        checkBox_2 = new QCheckBox(tab);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(290, 310, 81, 20));
        tabWidget_2->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget_2->addTab(tab_2, QString());
        toolBox->addItem(page_4, QStringLiteral("gestion abonnements"));

        retranslateUi(transprot);

        toolBox->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(transprot);
    } // setupUi

    void retranslateUi(QDialog *transprot)
    {
        transprot->setWindowTitle(QApplication::translate("transprot", "Dialog", Q_NULLPTR));
        titre->setTitle(QApplication::translate("transprot", "GESTION DE TRANSPORT : ", Q_NULLPTR));
        ajouter->setText(QApplication::translate("transprot", "Ajouter", Q_NULLPTR));
        reference->setText(QApplication::translate("transprot", "model :", Q_NULLPTR));
        nom->setText(QApplication::translate("transprot", "ref:", Q_NULLPTR));
        quantite->setText(QApplication::translate("transprot", "confort :", Q_NULLPTR));
        quantite_2->setText(QApplication::translate("transprot", "nombres de places :", Q_NULLPTR));
        quantite_3->setText(QApplication::translate("transprot", "climatisation :", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("transprot", "VOITURE", Q_NULLPTR)
         << QApplication::translate("transprot", "BUS", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("transprot", "Ajouter moyen", Q_NULLPTR));
        pushButton_mod->setText(QApplication::translate("transprot", "Modifier", Q_NULLPTR));
        pushButton_supp->setText(QApplication::translate("transprot", "Supprimer", Q_NULLPTR));
        quantite_4->setText(QApplication::translate("transprot", "nombres de places :", Q_NULLPTR));
        nom_9->setText(QApplication::translate("transprot", "ref:", Q_NULLPTR));
        reference_2->setText(QApplication::translate("transprot", "model :", Q_NULLPTR));
        quantite_5->setText(QApplication::translate("transprot", "confort :", Q_NULLPTR));
        quantite_6->setText(QApplication::translate("transprot", "climatisation :", Q_NULLPTR));
        Refreche->setText(QApplication::translate("transprot", "Refreche", Q_NULLPTR));
        comboBox_rechercher->clear();
        comboBox_rechercher->insertItems(0, QStringList()
         << QApplication::translate("transprot", "Rechercher", Q_NULLPTR)
         << QApplication::translate("transprot", "ref", Q_NULLPTR)
         << QApplication::translate("transprot", "modele et confort", Q_NULLPTR)
         << QApplication::translate("transprot", "modele et nombre_de_place et confort", Q_NULLPTR)
        );
        comboBox_trier->clear();
        comboBox_trier->insertItems(0, QStringList()
         << QApplication::translate("transprot", "Trier ", Q_NULLPTR)
         << QApplication::translate("transprot", "ref", Q_NULLPTR)
         << QApplication::translate("transprot", "modele", Q_NULLPTR)
         << QApplication::translate("transprot", "modele et nombre de place ", Q_NULLPTR)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("transprot", "VOITURE", Q_NULLPTR)
         << QApplication::translate("transprot", "BUS", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_10), QApplication::translate("transprot", "Afficher moyen", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("transprot", "r\303\251clamation :", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("transprot", "moyens de transport", Q_NULLPTR));
        nom_2->setText(QApplication::translate("transprot", "ID:", Q_NULLPTR));
        nom_3->setText(QApplication::translate("transprot", "NOM:", Q_NULLPTR));
        nom_4->setText(QApplication::translate("transprot", "prenom :", Q_NULLPTR));
        nom_5->setText(QApplication::translate("transprot", "ref moyen :", Q_NULLPTR));
        nom_6->setText(QApplication::translate("transprot", "Date :", Q_NULLPTR));
        nom_7->setText(QApplication::translate("transprot", "jusqu'au :", Q_NULLPTR));
        nom_8->setText(QApplication::translate("transprot", "payer :", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("transprot", "CheckBox", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("transprot", "ajouter abonn\303\251", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("transprot", "Tab 2", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("transprot", "gestion abonnements", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class transprot: public Ui_transprot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSPROT_H
