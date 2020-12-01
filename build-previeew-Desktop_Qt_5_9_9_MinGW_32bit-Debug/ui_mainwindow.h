/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_main;
    QVBoxLayout *verticalLayout;
    QFrame *frame_top;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_toggle;
    QVBoxLayout *verticalLayout_3;
    QPushButton *home;
    QFrame *frame_top_right;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_top_btns;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_label_top_btns;
    QHBoxLayout *horizontalLayout_10;
    QFrame *frame_icon_top_bar;
    QLabel *label_title_bar_top;
    QFrame *frame_btns_right;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_minimize;
    QPushButton *btn_maximize_restore;
    QPushButton *btn_close;
    QFrame *frame_top_info;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_top_info_1;
    QLabel *label_top_info_2;
    QFrame *frame_center;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_left_menu;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_menus;
    QVBoxLayout *layout_menus;
    QPushButton *ajouter_2;
    QPushButton *afficher_2;
    QPushButton *modifier;
    QPushButton *Statistque;
    QFrame *frame_extra_menus;
    QVBoxLayout *layout_menu_bottom;
    QLabel *label_user_icon;
    QPushButton *btn_settings;
    QFrame *frame_content_right;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_content;
    QVBoxLayout *verticalLayout_9;
    QStackedWidget *stackedWidget;
    QWidget *page_home;
    QLabel *label;
    QWidget *ajouter;
    QTabWidget *tabWidget;
    QWidget *agent;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *CIN_1;
    QLineEdit *nom_1;
    QLineEdit *prenom_0;
    QLineEdit *date_0;
    QLineEdit *email_0;
    QLineEdit *tel_0;
    QComboBox *comboBox;
    QPushButton *ajouter_0;
    QFrame *frame;
    QWidget *profil;
    QFrame *frame_2;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *ID_0;
    QLineEdit *nom_profil_0;
    QLineEdit *salaire_0;
    QLineEdit *nb_0;
    QLineEdit *description_0;
    QPushButton *ajouter_profil;
    QWidget *afficher;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QFrame *frame_4;
    QLineEdit *chercher_agents;
    QPushButton *pushButton_10;
    QPushButton *pushButton_13;
    QPushButton *pushButton_15;
    QTableView *tab_agents;
    QPushButton *pushButton_14;
    QCheckBox *check_CIN;
    QCheckBox *check_prenom;
    QCheckBox *check_email;
    QComboBox *comboBox_3;
    QPushButton *pushButton_20;
    QWidget *tab_2;
    QFrame *frame_3;
    QLineEdit *chercher_profil;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_21;
    QTableView *tab_profil;
    QCheckBox *check_ID;
    QCheckBox *check_salaire;
    QComboBox *comboBox_4;
    QPushButton *pdf;
    QPushButton *imprimer;
    QPushButton *actualiser;
    QWidget *Modifier;
    QTabWidget *tabWidget_3;
    QWidget *tab_3;
    QFrame *frame_6;
    QLabel *label_19;
    QLabel *label_20;
    QComboBox *comboBox_2;
    QLineEdit *date_m;
    QLineEdit *nom_m;
    QPushButton *pushButton_12;
    QLineEdit *CIN_m;
    QLineEdit *prenom_m;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *email_m;
    QLineEdit *tel_m;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QWidget *tab_4;
    QFrame *frame_5;
    QLineEdit *nomp_m;
    QLineEdit *descriptionp_m;
    QLabel *label_14;
    QLineEdit *nbagentsp_m;
    QPushButton *modifier_profil;
    QLineEdit *IDp_m;
    QLineEdit *salairep_m;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QWidget *Statistique;
    QWidget *centralwidget_2;
    QFrame *frame_grip;
    QHBoxLayout *horizontalLayout_6;
    QFrame *frame_label_bottom;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_credits;
    QLabel *label_version;
    QFrame *frame_size_grip;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 720);
        MainWindow->setMinimumSize(QSize(1000, 720));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(66, 73, 90, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(55, 61, 75, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(22, 24, 30, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(29, 32, 40, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        QBrush brush6(QColor(210, 210, 210, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        QBrush brush8(QColor(85, 170, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush8);
        palette.setBrush(QPalette::Active, QPalette::Link, brush8);
        QBrush brush9(QColor(255, 0, 127, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush9);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush10(QColor(44, 49, 60, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush11(QColor(210, 210, 210, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        QBrush brush12(QColor(210, 210, 210, 128));
        brush12.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        QBrush brush13(QColor(51, 153, 255, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush13);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        QBrush brush14(QColor(210, 210, 210, 128));
        brush14.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush14);
#endif
        MainWindow->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow {background: transparent; }\n"
"QToolTip {\n"
"	color: #ffffff;\n"
"	background-color: rgba(27, 29, 35, 160);\n"
"	border: 1px solid rgb(100, 100, 100);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QLatin1String("background: transparent;\n"
"color: rgb(210, 210, 210);"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        frame_main = new QFrame(centralwidget);
        frame_main->setObjectName(QStringLiteral("frame_main"));
        frame_main->setStyleSheet(QStringLiteral(""));
        frame_main->setFrameShape(QFrame::NoFrame);
        frame_main->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_main);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_top = new QFrame(frame_main);
        frame_top->setObjectName(QStringLiteral("frame_top"));
        frame_top->setMaximumSize(QSize(16777215, 60));
        frame_top->setStyleSheet(QStringLiteral("background-color: transparent;"));
        frame_top->setFrameShape(QFrame::NoFrame);
        frame_top->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_top);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_toggle = new QFrame(frame_top);
        frame_toggle->setObjectName(QStringLiteral("frame_toggle"));
        frame_toggle->setMaximumSize(QSize(70, 16777215));
        frame_toggle->setStyleSheet(QStringLiteral("background-color: rgb(27, 29, 35);"));
        frame_toggle->setFrameShape(QFrame::NoFrame);
        frame_toggle->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_toggle);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        home = new QPushButton(frame_toggle);
        home->setObjectName(QStringLiteral("home"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(home->sizePolicy().hasHeightForWidth());
        home->setSizePolicy(sizePolicy);
        home->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-image: url(C:/Users/JoKerTn/Documents/final/icons/24x24/cil-home.png);\n"
"	background-position: center;\n"
"	background-repeat: no-reperat;\n"
"	border: none;\n"
"	border-right: 5px solid rgb(44, 49, 60);\n"
"	background-color: rgb(27, 29, 35);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(33, 37, 43);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(85, 170, 255);\n"
"}"));

        verticalLayout_3->addWidget(home);


        horizontalLayout_3->addWidget(frame_toggle);

        frame_top_right = new QFrame(frame_top);
        frame_top_right->setObjectName(QStringLiteral("frame_top_right"));
        frame_top_right->setStyleSheet(QStringLiteral("background: transparent;"));
        frame_top_right->setFrameShape(QFrame::NoFrame);
        frame_top_right->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_top_right);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_top_btns = new QFrame(frame_top_right);
        frame_top_btns->setObjectName(QStringLiteral("frame_top_btns"));
        frame_top_btns->setMaximumSize(QSize(16777215, 30));
        frame_top_btns->setStyleSheet(QStringLiteral("background-color: rgba(33, 37, 43, 150);"));
        frame_top_btns->setFrameShape(QFrame::NoFrame);
        frame_top_btns->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_top_btns);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        frame_label_top_btns = new QFrame(frame_top_btns);
        frame_label_top_btns->setObjectName(QStringLiteral("frame_label_top_btns"));
        frame_label_top_btns->setFrameShape(QFrame::NoFrame);
        frame_label_top_btns->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame_label_top_btns);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(8, 0, 10, 0);
        frame_icon_top_bar = new QFrame(frame_label_top_btns);
        frame_icon_top_bar->setObjectName(QStringLiteral("frame_icon_top_bar"));
        frame_icon_top_bar->setMaximumSize(QSize(30, 30));
        frame_icon_top_bar->setStyleSheet(QLatin1String("background: transparent;\n"
"background-image: url(:/16x16/icons/16x16/cil-terminal.png);\n"
"background-position: center;\n"
"background-repeat: no-repeat;"));
        frame_icon_top_bar->setFrameShape(QFrame::StyledPanel);
        frame_icon_top_bar->setFrameShadow(QFrame::Raised);

        horizontalLayout_10->addWidget(frame_icon_top_bar);

        label_title_bar_top = new QLabel(frame_label_top_btns);
        label_title_bar_top->setObjectName(QStringLiteral("label_title_bar_top"));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_title_bar_top->setFont(font1);
        label_title_bar_top->setStyleSheet(QLatin1String("background: transparent;\n"
"margin-left: 5px;"));

        horizontalLayout_10->addWidget(label_title_bar_top);


        horizontalLayout_4->addWidget(frame_label_top_btns);

        frame_btns_right = new QFrame(frame_top_btns);
        frame_btns_right->setObjectName(QStringLiteral("frame_btns_right"));
        frame_btns_right->setMaximumSize(QSize(120, 16777215));
        frame_btns_right->setFrameShape(QFrame::NoFrame);
        frame_btns_right->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_btns_right);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        btn_minimize = new QPushButton(frame_btns_right);
        btn_minimize->setObjectName(QStringLiteral("btn_minimize"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_minimize->sizePolicy().hasHeightForWidth());
        btn_minimize->setSizePolicy(sizePolicy1);
        btn_minimize->setStyleSheet(QLatin1String("QPushButton {	\n"
"	border: none;\n"
"	background-color: transparent;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(44, 49, 60)\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(85, 170, 255);\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/16x16/icons/16x16/cil-window-minimize.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_minimize->setIcon(icon);

        horizontalLayout_5->addWidget(btn_minimize);

        btn_maximize_restore = new QPushButton(frame_btns_right);
        btn_maximize_restore->setObjectName(QStringLiteral("btn_maximize_restore"));
        sizePolicy1.setHeightForWidth(btn_maximize_restore->sizePolicy().hasHeightForWidth());
        btn_maximize_restore->setSizePolicy(sizePolicy1);
        btn_maximize_restore->setStyleSheet(QLatin1String("QPushButton {	\n"
"	border: none;\n"
"	background-color: transparent;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(44, 49, 60)\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(85, 170, 255);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/16x16/icons/16x16/cil-window-maximize.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_maximize_restore->setIcon(icon1);

        horizontalLayout_5->addWidget(btn_maximize_restore);

        btn_close = new QPushButton(frame_btns_right);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        sizePolicy1.setHeightForWidth(btn_close->sizePolicy().hasHeightForWidth());
        btn_close->setSizePolicy(sizePolicy1);
        btn_close->setStyleSheet(QLatin1String("QPushButton {	\n"
"	border: none;\n"
"	background-color: transparent;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(44, 49, 60)\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(85, 170, 255);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/16x16/icons/16x16/cil-x.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_close->setIcon(icon2);

        horizontalLayout_5->addWidget(btn_close);


        horizontalLayout_4->addWidget(frame_btns_right);


        verticalLayout_2->addWidget(frame_top_btns);

        frame_top_info = new QFrame(frame_top_right);
        frame_top_info->setObjectName(QStringLiteral("frame_top_info"));
        frame_top_info->setStyleSheet(QStringLiteral("background-color: rgb(39, 44, 54);"));
        frame_top_info->setFrameShape(QFrame::NoFrame);
        frame_top_info->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_top_info);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(10, 0, 10, 0);
        label_top_info_1 = new QLabel(frame_top_info);
        label_top_info_1->setObjectName(QStringLiteral("label_top_info_1"));
        QFont font2;
        font2.setFamily(QStringLiteral("Segoe UI"));
        label_top_info_1->setFont(font2);
        label_top_info_1->setStyleSheet(QStringLiteral("color: rgb(98, 103, 111);"));

        horizontalLayout_8->addWidget(label_top_info_1);

        label_top_info_2 = new QLabel(frame_top_info);
        label_top_info_2->setObjectName(QStringLiteral("label_top_info_2"));
        label_top_info_2->setMinimumSize(QSize(0, 0));
        label_top_info_2->setMaximumSize(QSize(250, 16777215));
        QFont font3;
        font3.setFamily(QStringLiteral("Segoe UI"));
        font3.setBold(true);
        font3.setWeight(75);
        label_top_info_2->setFont(font3);
        label_top_info_2->setStyleSheet(QStringLiteral("color: rgb(98, 103, 111);"));
        label_top_info_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_top_info_2);


        verticalLayout_2->addWidget(frame_top_info);


        horizontalLayout_3->addWidget(frame_top_right);


        verticalLayout->addWidget(frame_top);

        frame_center = new QFrame(frame_main);
        frame_center->setObjectName(QStringLiteral("frame_center"));
        frame_center->setStyleSheet(QStringLiteral("background-color: rgb(40, 44, 52);"));
        frame_center->setFrameShape(QFrame::NoFrame);
        frame_center->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_center);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_left_menu = new QFrame(frame_center);
        frame_left_menu->setObjectName(QStringLiteral("frame_left_menu"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_left_menu->sizePolicy().hasHeightForWidth());
        frame_left_menu->setSizePolicy(sizePolicy2);
        frame_left_menu->setMaximumSize(QSize(70, 16777215));
        frame_left_menu->setLayoutDirection(Qt::LeftToRight);
        frame_left_menu->setStyleSheet(QStringLiteral("background-color: rgb(27, 29, 35);"));
        frame_left_menu->setFrameShape(QFrame::NoFrame);
        frame_left_menu->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_left_menu);
        verticalLayout_5->setSpacing(1);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_menus = new QFrame(frame_left_menu);
        frame_menus->setObjectName(QStringLiteral("frame_menus"));
        frame_menus->setFrameShape(QFrame::NoFrame);
        frame_menus->setFrameShadow(QFrame::Raised);
        layout_menus = new QVBoxLayout(frame_menus);
        layout_menus->setSpacing(0);
        layout_menus->setObjectName(QStringLiteral("layout_menus"));
        layout_menus->setContentsMargins(0, 0, 0, 0);
        ajouter_2 = new QPushButton(frame_menus);
        ajouter_2->setObjectName(QStringLiteral("ajouter_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ajouter_2->sizePolicy().hasHeightForWidth());
        ajouter_2->setSizePolicy(sizePolicy3);
        ajouter_2->setMinimumSize(QSize(0, 60));
        ajouter_2->setFont(font2);
        ajouter_2->setLayoutDirection(Qt::LeftToRight);
        ajouter_2->setStyleSheet(QLatin1String("QPushButton {	\n"
"		background-image: url(:/16x16/icons/16x16/cil-user-follow.png);\n"
"	background-position: left center;\n"
"    background-repeat: no-repeat;\n"
"	border: none;\n"
"	border-left: 28px solid rgb(27, 29, 35);\n"
"	background-color: rgb(27, 29, 35);\n"
"	text-align: left;\n"
"	padding-left: 45px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(33, 37, 43);\n"
"	border-left: 28px solid rgb(33, 37, 43);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-left: 28px solid rgb(85, 170, 255);\n"
"}"));

        layout_menus->addWidget(ajouter_2);

        afficher_2 = new QPushButton(frame_menus);
        afficher_2->setObjectName(QStringLiteral("afficher_2"));
        sizePolicy3.setHeightForWidth(afficher_2->sizePolicy().hasHeightForWidth());
        afficher_2->setSizePolicy(sizePolicy3);
        afficher_2->setMinimumSize(QSize(0, 60));
        afficher_2->setFont(font2);
        afficher_2->setLayoutDirection(Qt::LeftToRight);
        afficher_2->setStyleSheet(QLatin1String("QPushButton {	\n"
"	background-image: url(:/16x16/icons/16x16/cil-notes.png);\n"
"	background-position: left center;\n"
"    background-repeat: no-repeat;\n"
"	border: none;\n"
"	border-left: 28px solid rgb(27, 29, 35);\n"
"	background-color: rgb(27, 29, 35);\n"
"	text-align: left;\n"
"	padding-left: 45px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(33, 37, 43);\n"
"	border-left: 28px solid rgb(33, 37, 43);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-left: 28px solid rgb(85, 170, 255);\n"
"}"));

        layout_menus->addWidget(afficher_2);

        modifier = new QPushButton(frame_menus);
        modifier->setObjectName(QStringLiteral("modifier"));
        sizePolicy3.setHeightForWidth(modifier->sizePolicy().hasHeightForWidth());
        modifier->setSizePolicy(sizePolicy3);
        modifier->setMinimumSize(QSize(0, 60));
        modifier->setFont(font2);
        modifier->setLayoutDirection(Qt::LeftToRight);
        modifier->setStyleSheet(QLatin1String("QPushButton {	\n"
"	background-image: url(:/16x16/icons/16x16/cil-equalizer.png);\n"
"	background-position: left center;\n"
"    background-repeat: no-repeat;\n"
"	border: none;\n"
"	border-left: 28px solid rgb(27, 29, 35);\n"
"	background-color: rgb(27, 29, 35);\n"
"	text-align: left;\n"
"	padding-left: 45px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(33, 37, 43);\n"
"	border-left: 28px solid rgb(33, 37, 43);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-left: 28px solid rgb(85, 170, 255);\n"
"}"));

        layout_menus->addWidget(modifier);

        Statistque = new QPushButton(frame_menus);
        Statistque->setObjectName(QStringLiteral("Statistque"));
        sizePolicy3.setHeightForWidth(Statistque->sizePolicy().hasHeightForWidth());
        Statistque->setSizePolicy(sizePolicy3);
        Statistque->setMinimumSize(QSize(0, 60));
        Statistque->setFont(font2);
        Statistque->setLayoutDirection(Qt::LeftToRight);
        Statistque->setStyleSheet(QLatin1String("QPushButton {	\n"
"	background-image: url(:/16x16/icons/16x16/cil-chart.png);\n"
"	background-position: left center;\n"
"    background-repeat: no-repeat;\n"
"	border: none;\n"
"	border-left: 28px solid rgb(27, 29, 35);\n"
"	background-color: rgb(27, 29, 35);\n"
"	text-align: left;\n"
"	padding-left: 45px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(33, 37, 43);\n"
"	border-left: 28px solid rgb(33, 37, 43);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-left: 28px solid rgb(85, 170, 255);\n"
"}"));

        layout_menus->addWidget(Statistque);


        verticalLayout_5->addWidget(frame_menus, 0, Qt::AlignTop);

        frame_extra_menus = new QFrame(frame_left_menu);
        frame_extra_menus->setObjectName(QStringLiteral("frame_extra_menus"));
        sizePolicy2.setHeightForWidth(frame_extra_menus->sizePolicy().hasHeightForWidth());
        frame_extra_menus->setSizePolicy(sizePolicy2);
        frame_extra_menus->setFrameShape(QFrame::NoFrame);
        frame_extra_menus->setFrameShadow(QFrame::Raised);
        layout_menu_bottom = new QVBoxLayout(frame_extra_menus);
        layout_menu_bottom->setSpacing(10);
        layout_menu_bottom->setObjectName(QStringLiteral("layout_menu_bottom"));
        layout_menu_bottom->setContentsMargins(0, 0, 0, 25);
        label_user_icon = new QLabel(frame_extra_menus);
        label_user_icon->setObjectName(QStringLiteral("label_user_icon"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_user_icon->sizePolicy().hasHeightForWidth());
        label_user_icon->setSizePolicy(sizePolicy4);
        label_user_icon->setMinimumSize(QSize(60, 60));
        label_user_icon->setMaximumSize(QSize(60, 60));
        QFont font4;
        font4.setFamily(QStringLiteral("Segoe UI"));
        font4.setPointSize(12);
        label_user_icon->setFont(font4);
        label_user_icon->setStyleSheet(QLatin1String("QLabel {\n"
"	border-radius: 30px;\n"
"	background-color: rgb(44, 49, 60);\n"
"	border: 5px solid rgb(39, 44, 54);\n"
"}"));
        label_user_icon->setAlignment(Qt::AlignCenter);

        layout_menu_bottom->addWidget(label_user_icon, 0, Qt::AlignHCenter);

        btn_settings = new QPushButton(frame_extra_menus);
        btn_settings->setObjectName(QStringLiteral("btn_settings"));
        sizePolicy3.setHeightForWidth(btn_settings->sizePolicy().hasHeightForWidth());
        btn_settings->setSizePolicy(sizePolicy3);
        btn_settings->setMinimumSize(QSize(0, 60));
        btn_settings->setFont(font2);
        btn_settings->setLayoutDirection(Qt::LeftToRight);
        btn_settings->setStyleSheet(QLatin1String("QPushButton {	\n"
"	background-image: url(:/20x20/icons/20x20/cil-settings.png);\n"
"	background-position: left center;\n"
"    background-repeat: no-repeat;\n"
"	border: none;\n"
"	border-left: 26px solid rgb(27, 29, 35);\n"
"	background-color: rgb(27, 29, 35);\n"
"	text-align: left;\n"
"	padding-left: 45px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(33, 37, 43);\n"
"	border-left: 26px solid rgb(33, 37, 43);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-left: 26px solid rgb(85, 170, 255);\n"
"}"));

        layout_menu_bottom->addWidget(btn_settings);


        verticalLayout_5->addWidget(frame_extra_menus, 0, Qt::AlignBottom);


        horizontalLayout_2->addWidget(frame_left_menu);

        frame_content_right = new QFrame(frame_center);
        frame_content_right->setObjectName(QStringLiteral("frame_content_right"));
        frame_content_right->setStyleSheet(QStringLiteral("background-color: rgb(44, 49, 60);"));
        frame_content_right->setFrameShape(QFrame::NoFrame);
        frame_content_right->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_content_right);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        frame_content = new QFrame(frame_content_right);
        frame_content->setObjectName(QStringLiteral("frame_content"));
        frame_content->setFrameShape(QFrame::NoFrame);
        frame_content->setFrameShadow(QFrame::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_content);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(5, 5, 5, 5);
        stackedWidget = new QStackedWidget(frame_content);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral("background: transparent;"));
        page_home = new QWidget();
        page_home->setObjectName(QStringLiteral("page_home"));
        label = new QLabel(page_home);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 250, 553, 71));
        label->setStyleSheet(QLatin1String("font: 40pt \"Segoe UI\";\n"
""));
        label->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_home);
        ajouter = new QWidget();
        ajouter->setObjectName(QStringLiteral("ajouter"));
        tabWidget = new QTabWidget(ajouter);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 991, 711));
        tabWidget->setStyleSheet(QLatin1String("\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #C2C7CB;\n"
"background-color: rgb(44, 49, 60);\n"
"border-color: rgb(44, 49, 60);\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    left: 5px; /* move to the right by 5px */\n"
"background-color: rgb(44, 49, 60);\n"
"border-color: rgb(44, 49, 60);\n"
"}\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 2px solid #C4C4C3;\n"
"    border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"    padding: 2px;\n"
"background-color: rgb(44, 49, 60);\n"
"border-color: rgb(44, 49, 60);\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
""
                        "    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    border-color: #9B9B9B;\n"
"    border-bottom-color: #C2C7CB; /* same as pane color */\n"
"	\n"
"	color: rgb(68, 72, 76);\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    margin-top: 2px; /* make non-selected tabs look smaller */\n"
"\n"
"}\n"
""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(60, 60));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(false);
        agent = new QWidget();
        agent->setObjectName(QStringLiteral("agent"));
        label_2 = new QLabel(agent);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 90, 101, 21));
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(agent);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 130, 101, 21));
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(agent);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 170, 101, 21));
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(agent);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 210, 101, 21));
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(agent);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 250, 101, 21));
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_7 = new QLabel(agent);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(170, 290, 101, 21));
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_8 = new QLabel(agent);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(170, 330, 101, 21));
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        CIN_1 = new QLineEdit(agent);
        CIN_1->setObjectName(QStringLiteral("CIN_1"));
        CIN_1->setGeometry(QRect(280, 90, 241, 20));
        CIN_1->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}"));
        nom_1 = new QLineEdit(agent);
        nom_1->setObjectName(QStringLiteral("nom_1"));
        nom_1->setGeometry(QRect(280, 130, 241, 20));
        nom_1->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}"));
        prenom_0 = new QLineEdit(agent);
        prenom_0->setObjectName(QStringLiteral("prenom_0"));
        prenom_0->setGeometry(QRect(280, 170, 241, 20));
        prenom_0->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}"));
        date_0 = new QLineEdit(agent);
        date_0->setObjectName(QStringLiteral("date_0"));
        date_0->setGeometry(QRect(280, 210, 241, 20));
        date_0->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}"));
        email_0 = new QLineEdit(agent);
        email_0->setObjectName(QStringLiteral("email_0"));
        email_0->setGeometry(QRect(280, 250, 241, 20));
        email_0->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}"));
        tel_0 = new QLineEdit(agent);
        tel_0->setObjectName(QStringLiteral("tel_0"));
        tel_0->setGeometry(QRect(280, 290, 241, 20));
        tel_0->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}"));
        comboBox = new QComboBox(agent);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(280, 330, 181, 31));
        comboBox->setStyleSheet(QLatin1String("QComboBox{\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding: 5px;\n"
"	padding-left: 10px;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 10pt \"Segoe UI\";\n"
"}\n"
"QComboBox:hover{\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"	color: rgb(85, 170, 255);	\n"
"	background-color: rgb(27, 29, 35);\n"
"	padding: 10px;\n"
"	selection-background-color: rgb(39, 44, 54);\n"
"}"));
        ajouter_0 = new QPushButton(agent);
        ajouter_0->setObjectName(QStringLiteral("ajouter_0"));
        ajouter_0->setGeometry(QRect(490, 440, 221, 23));
        ajouter_0->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"}"));
        frame = new QFrame(agent);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 10, 1221, 591));
        frame->setStyleSheet(QStringLiteral("background-color: rgb(44, 49, 60);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tabWidget->addTab(agent, QString());
        frame->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        CIN_1->raise();
        nom_1->raise();
        prenom_0->raise();
        date_0->raise();
        email_0->raise();
        tel_0->raise();
        comboBox->raise();
        ajouter_0->raise();
        profil = new QWidget();
        profil->setObjectName(QStringLiteral("profil"));
        frame_2 = new QFrame(profil);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(-60, 10, 1021, 621));
        frame_2->setStyleSheet(QLatin1String("background-color: rgb(44, 49, 60);\n"
"\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(240, 120, 47, 14));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(240, 160, 71, 16));
        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(240, 200, 47, 14));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(240, 240, 81, 16));
        label_13 = new QLabel(frame_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(240, 280, 101, 16));
        ID_0 = new QLineEdit(frame_2);
        ID_0->setObjectName(QStringLiteral("ID_0"));
        ID_0->setGeometry(QRect(360, 120, 231, 20));
        ID_0->setStyleSheet(QLatin1String("\n"
"QLineEdit {\n"
"	color: rgb(44, 49, 60);\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}QLabel\n"
"{color: rgb(255, 255, 255);\n"
"}"));
        nom_profil_0 = new QLineEdit(frame_2);
        nom_profil_0->setObjectName(QStringLiteral("nom_profil_0"));
        nom_profil_0->setGeometry(QRect(360, 160, 231, 20));
        nom_profil_0->setStyleSheet(QLatin1String("\n"
"QLineEdit {\n"
"	color: rgb(44, 49, 60);\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}QLabel\n"
"{color: rgb(255, 255, 255);\n"
"}"));
        salaire_0 = new QLineEdit(frame_2);
        salaire_0->setObjectName(QStringLiteral("salaire_0"));
        salaire_0->setGeometry(QRect(360, 200, 231, 20));
        salaire_0->setStyleSheet(QLatin1String("\n"
"QLineEdit {\n"
"	color: rgb(44, 49, 60);\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}QLabel\n"
"{color: rgb(255, 255, 255);\n"
"}"));
        nb_0 = new QLineEdit(frame_2);
        nb_0->setObjectName(QStringLiteral("nb_0"));
        nb_0->setGeometry(QRect(360, 280, 231, 20));
        nb_0->setStyleSheet(QLatin1String("\n"
"QLineEdit {\n"
"	color: rgb(44, 49, 60);\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}QLabel\n"
"{color: rgb(255, 255, 255);\n"
"}"));
        description_0 = new QLineEdit(frame_2);
        description_0->setObjectName(QStringLiteral("description_0"));
        description_0->setGeometry(QRect(360, 240, 231, 20));
        description_0->setStyleSheet(QLatin1String("\n"
"QLineEdit {\n"
"	color: rgb(44, 49, 60);\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}QLabel\n"
"{color: rgb(255, 255, 255);\n"
"}"));
        ajouter_profil = new QPushButton(frame_2);
        ajouter_profil->setObjectName(QStringLiteral("ajouter_profil"));
        ajouter_profil->setGeometry(QRect(490, 420, 191, 23));
        ajouter_profil->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"}"));
        tabWidget->addTab(profil, QString());
        stackedWidget->addWidget(ajouter);
        afficher = new QWidget();
        afficher->setObjectName(QStringLiteral("afficher"));
        tabWidget_2 = new QTabWidget(afficher);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(-4, -1, 991, 651));
        tabWidget_2->setStyleSheet(QLatin1String("\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #C2C7CB;\n"
"background-color: rgb(44, 49, 60);\n"
"border-color: rgb(44, 49, 60);\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    left: 5px; /* move to the right by 5px */\n"
"background-color: rgb(44, 49, 60);\n"
"border-color: rgb(44, 49, 60);\n"
"}\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 2px solid #C4C4C3;\n"
"    border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"    padding: 2px;\n"
"background-color: rgb(44, 49, 60);\n"
"border-color: rgb(44, 49, 60);\n"
"\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hov"
                        "er {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    border-color: #9B9B9B;\n"
"    border-bottom-color: #C2C7CB; /* same as pane color */\n"
"	\n"
"	color: rgb(68, 72, 76);\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    margin-top: 2px; /* make non-selected tabs look smaller */\n"
"\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        frame_4 = new QFrame(tab);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(10, 10, 1011, 611));
        frame_4->setStyleSheet(QStringLiteral("background-color: rgb(44, 49, 60);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        chercher_agents = new QLineEdit(frame_4);
        chercher_agents->setObjectName(QStringLiteral("chercher_agents"));
        chercher_agents->setGeometry(QRect(10, 79, 211, 31));
        chercher_agents->setStyleSheet(QLatin1String("\n"
"QLineEdit {\n"
"	color: rgb(44, 49, 60);\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"   color:rgb(242, 242, 242)\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"background-image: url(:/16x16/icons/16x16/cil-magnifying-glass.png);\n"
"	background-position: right center;\n"
"    background-repeat: no-repeat;\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"background-image: url(:/16x16/icons/16x16/cil-magnifying-glass.png);\n"
"	background-position: right center;\n"
"    background-repeat: no-repeat;\n"
"}\n"
"\n"
"QLabel\n"
"{color: rgb(255, 255, 255);\n"
"}"));
        pushButton_10 = new QPushButton(frame_4);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(80, 530, 201, 20));
        pushButton_10->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"background-image: url(:/16x16/icons/16x16/cil-print.png);\n"
"	background-position: Right center;\n"
"    background-repeat: no-repeat;\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"}"));
        pushButton_13 = new QPushButton(frame_4);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(780, 82, 91, 31));
        pushButton_13->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"}"));
        pushButton_15 = new QPushButton(frame_4);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(240, 82, 75, 31));
        pushButton_15->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"}"));
        tab_agents = new QTableView(frame_4);
        tab_agents->setObjectName(QStringLiteral("tab_agents"));
        tab_agents->setGeometry(QRect(0, 120, 871, 381));
        pushButton_14 = new QPushButton(frame_4);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(610, 530, 201, 20));
        pushButton_14->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"background-image: url(:/16x16/icons/16x16/cil-print.png);\n"
"	background-position: Right center;\n"
"    background-repeat: no-repeat;\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"}"));
        check_CIN = new QCheckBox(frame_4);
        check_CIN->setObjectName(QStringLiteral("check_CIN"));
        check_CIN->setGeometry(QRect(20, 10, 70, 18));
        check_prenom = new QCheckBox(frame_4);
        check_prenom->setObjectName(QStringLiteral("check_prenom"));
        check_prenom->setGeometry(QRect(20, 50, 70, 18));
        check_email = new QCheckBox(frame_4);
        check_email->setObjectName(QStringLiteral("check_email"));
        check_email->setGeometry(QRect(140, 50, 70, 18));
        comboBox_3 = new QComboBox(frame_4);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(641, 81, 111, 31));
        comboBox_3->setStyleSheet(QLatin1String("QComboBox{\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding: 5px;\n"
"	padding-left: 10px;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 10pt \"Segoe UI\";\n"
"}\n"
"QComboBox:hover{\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"	color: rgb(85, 170, 255);	\n"
"	background-color: rgb(27, 29, 35);\n"
"	padding: 10px;\n"
"	selection-background-color: rgb(39, 44, 54);\n"
"}"));
        pushButton_20 = new QPushButton(frame_4);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(360, 530, 201, 20));
        pushButton_20->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"background-image: url(:/16x16/icons/16x16/cil-chart.png);\n"
"	background-position: right center;\n"
"    background-repeat: no-repeat;\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"}"));
        tabWidget_2->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        frame_3 = new QFrame(tab_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(-1, -1, 971, 601));
        frame_3->setStyleSheet(QStringLiteral("background-color: rgb(44, 49, 60);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        chercher_profil = new QLineEdit(frame_3);
        chercher_profil->setObjectName(QStringLiteral("chercher_profil"));
        chercher_profil->setGeometry(QRect(20, 80, 211, 31));
        chercher_profil->setStyleSheet(QLatin1String("\n"
"QLineEdit {\n"
"	color: rgb(44, 49, 60);\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"   color:rgb(242, 242, 242)\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"background-image: url(:/16x16/icons/16x16/cil-magnifying-glass.png);\n"
"	background-position: right center;\n"
"    background-repeat: no-repeat;\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"background-image: url(:/16x16/icons/16x16/cil-magnifying-glass.png);\n"
"	background-position: right center;\n"
"    background-repeat: no-repeat;\n"
"}\n"
"\n"
"QLabel\n"
"{color: rgb(255, 255, 255);\n"
"}"));
        pushButton_18 = new QPushButton(frame_3);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(660, 230, 201, 20));
        pushButton_18->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"background-image: url(:/16x16/icons/16x16/cil-equalizer.png);\n"
"background-position: right;\n"
"background-repeat: no-reperat;\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"background-image: url(C:/Users/JoKerTn/Documents/final/icons/24x24/cil-home.png);\n"
"background-position: right;\n"
"background-repeat: no-reperat;\n"
"}"));
        pushButton_19 = new QPushButton(frame_3);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(660, 330, 201, 20));
        pushButton_19->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"background-image: url(:/16x16/icons/16x16/cil-chart.png);\n"
"	background-position: right center;\n"
"    background-repeat: no-repeat;\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"}"));
        pushButton_21 = new QPushButton(frame_3);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(430, 80, 91, 31));
        pushButton_21->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"}"));
        tab_profil = new QTableView(frame_3);
        tab_profil->setObjectName(QStringLiteral("tab_profil"));
        tab_profil->setGeometry(QRect(10, 120, 631, 321));
        check_ID = new QCheckBox(frame_3);
        check_ID->setObjectName(QStringLiteral("check_ID"));
        check_ID->setGeometry(QRect(30, 50, 70, 18));
        check_salaire = new QCheckBox(frame_3);
        check_salaire->setObjectName(QStringLiteral("check_salaire"));
        check_salaire->setGeometry(QRect(140, 50, 70, 18));
        comboBox_4 = new QComboBox(frame_3);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(540, 80, 101, 31));
        comboBox_4->setStyleSheet(QLatin1String("QComboBox{\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding: 5px;\n"
"	padding-left: 10px;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 10pt \"Segoe UI\";\n"
"}\n"
"QComboBox:hover{\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"	color: rgb(85, 170, 255);	\n"
"	background-color: rgb(27, 29, 35);\n"
"	padding: 10px;\n"
"	selection-background-color: rgb(39, 44, 54);\n"
"}"));
        pdf = new QPushButton(frame_3);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(400, 490, 201, 20));
        pdf->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"background-image: url(:/16x16/icons/16x16/cil-print.png);\n"
"	background-position: Right center;\n"
"    background-repeat: no-repeat;\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"}"));
        imprimer = new QPushButton(frame_3);
        imprimer->setObjectName(QStringLiteral("imprimer"));
        imprimer->setGeometry(QRect(120, 490, 201, 20));
        imprimer->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"background-image: url(:/16x16/icons/16x16/cil-print.png);\n"
"	background-position: Right center;\n"
"    background-repeat: no-repeat;\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"}"));
        actualiser = new QPushButton(frame_3);
        actualiser->setObjectName(QStringLiteral("actualiser"));
        actualiser->setGeometry(QRect(240, 80, 91, 31));
        actualiser->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"}"));
        tabWidget_2->addTab(tab_2, QString());
        stackedWidget->addWidget(afficher);
        Modifier = new QWidget();
        Modifier->setObjectName(QStringLiteral("Modifier"));
        tabWidget_3 = new QTabWidget(Modifier);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(0, 0, 1071, 711));
        tabWidget_3->setStyleSheet(QLatin1String("\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #C2C7CB;\n"
"background-color: rgb(44, 49, 60);\n"
"border-color: rgb(44, 49, 60);\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    left: 5px; /* move to the right by 5px */\n"
"background-color: rgb(44, 49, 60);\n"
"border-color: rgb(44, 49, 60);\n"
"}\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"    border: 2px solid #C4C4C3;\n"
"    border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"    padding: 2px;\n"
"background-color: rgb(44, 49, 60);\n"
"border-color: rgb(44, 49, 60);\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
""
                        "    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    border-color: #9B9B9B;\n"
"    border-bottom-color: #C2C7CB; /* same as pane color */\n"
"	\n"
"	color: rgb(68, 72, 76);\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    margin-top: 2px; /* make non-selected tabs look smaller */\n"
"\n"
"}\n"
""));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        frame_6 = new QFrame(tab_3);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(0, 0, 1021, 601));
        frame_6->setStyleSheet(QStringLiteral("background-color: rgb(44, 49, 60);"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_19 = new QLabel(frame_6);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(210, 140, 101, 21));
        label_19->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_20 = new QLabel(frame_6);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(210, 260, 101, 21));
        label_20->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        comboBox_2 = new QComboBox(frame_6);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(320, 340, 181, 31));
        comboBox_2->setStyleSheet(QLatin1String("QComboBox{\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding: 5px;\n"
"	padding-left: 10px;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 10pt \"Segoe UI\";\n"
"}\n"
"QComboBox:hover{\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"	color: rgb(85, 170, 255);	\n"
"	background-color: rgb(27, 29, 35);\n"
"	padding: 10px;\n"
"	selection-background-color: rgb(39, 44, 54);\n"
"}"));
        date_m = new QLineEdit(frame_6);
        date_m->setObjectName(QStringLiteral("date_m"));
        date_m->setGeometry(QRect(320, 220, 241, 20));
        date_m->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}"));
        nom_m = new QLineEdit(frame_6);
        nom_m->setObjectName(QStringLiteral("nom_m"));
        nom_m->setGeometry(QRect(320, 140, 241, 20));
        nom_m->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}"));
        pushButton_12 = new QPushButton(frame_6);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(530, 450, 221, 23));
        pushButton_12->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"}"));
        CIN_m = new QLineEdit(frame_6);
        CIN_m->setObjectName(QStringLiteral("CIN_m"));
        CIN_m->setGeometry(QRect(320, 100, 241, 20));
        CIN_m->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}"));
        prenom_m = new QLineEdit(frame_6);
        prenom_m->setObjectName(QStringLiteral("prenom_m"));
        prenom_m->setGeometry(QRect(320, 180, 241, 20));
        prenom_m->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}"));
        label_21 = new QLabel(frame_6);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(210, 300, 101, 21));
        label_21->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_22 = new QLabel(frame_6);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(210, 220, 101, 21));
        label_22->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        email_m = new QLineEdit(frame_6);
        email_m->setObjectName(QStringLiteral("email_m"));
        email_m->setGeometry(QRect(320, 260, 241, 20));
        email_m->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}"));
        tel_m = new QLineEdit(frame_6);
        tel_m->setObjectName(QStringLiteral("tel_m"));
        tel_m->setGeometry(QRect(320, 300, 241, 20));
        tel_m->setStyleSheet(QLatin1String("QLineEdit {\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}"));
        label_23 = new QLabel(frame_6);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(210, 180, 101, 21));
        label_23->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_24 = new QLabel(frame_6);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(210, 100, 101, 21));
        label_24->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_25 = new QLabel(frame_6);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(210, 340, 101, 21));
        label_25->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        tabWidget_3->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        frame_5 = new QFrame(tab_4);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(0, -30, 981, 661));
        frame_5->setStyleSheet(QStringLiteral("background-color: rgb(44, 49, 60);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        nomp_m = new QLineEdit(frame_5);
        nomp_m->setObjectName(QStringLiteral("nomp_m"));
        nomp_m->setGeometry(QRect(300, 230, 231, 20));
        nomp_m->setStyleSheet(QLatin1String("\n"
"QLineEdit {\n"
"	color: rgb(44, 49, 60);\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}QLabel\n"
"{color: rgb(255, 255, 255);\n"
"}"));
        descriptionp_m = new QLineEdit(frame_5);
        descriptionp_m->setObjectName(QStringLiteral("descriptionp_m"));
        descriptionp_m->setGeometry(QRect(300, 310, 231, 20));
        descriptionp_m->setStyleSheet(QLatin1String("\n"
"QLineEdit {\n"
"	color: rgb(44, 49, 60);\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}QLabel\n"
"{color: rgb(255, 255, 255);\n"
"}"));
        label_14 = new QLabel(frame_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(180, 190, 141, 20));
        nbagentsp_m = new QLineEdit(frame_5);
        nbagentsp_m->setObjectName(QStringLiteral("nbagentsp_m"));
        nbagentsp_m->setGeometry(QRect(300, 350, 231, 20));
        nbagentsp_m->setStyleSheet(QLatin1String("\n"
"QLineEdit {\n"
"	color: rgb(44, 49, 60);\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}QLabel\n"
"{color: rgb(255, 255, 255);\n"
"}"));
        modifier_profil = new QPushButton(frame_5);
        modifier_profil->setObjectName(QStringLiteral("modifier_profil"));
        modifier_profil->setGeometry(QRect(430, 490, 191, 23));
        modifier_profil->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: rgb(255, 255, 255);\n"
"	border: 2px solid rgb(52, 59, 72);\n"
"	font: 9pt \"Segoe UI\";\n"
"	border-radius: 5px;	\n"
"	background-color: rgb(52, 59, 72);\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(57, 65, 80);\n"
"	border: 2px solid rgb(61, 70, 86);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: rgb(35, 40, 49);\n"
"	border: 2px solid rgb(43, 50, 61);\n"
"}"));
        IDp_m = new QLineEdit(frame_5);
        IDp_m->setObjectName(QStringLiteral("IDp_m"));
        IDp_m->setGeometry(QRect(300, 190, 231, 20));
        IDp_m->setStyleSheet(QLatin1String("\n"
"QLineEdit {\n"
"	color: rgb(44, 49, 60);\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}QLabel\n"
"{color: rgb(255, 255, 255);\n"
"}"));
        salairep_m = new QLineEdit(frame_5);
        salairep_m->setObjectName(QStringLiteral("salairep_m"));
        salairep_m->setGeometry(QRect(300, 270, 231, 20));
        salairep_m->setStyleSheet(QLatin1String("\n"
"QLineEdit {\n"
"	color: rgb(44, 49, 60);\n"
"	background-color: rgb(27, 29, 35);\n"
"	border-radius: 5px;\n"
"	border: 2px solid rgb(27, 29, 35);\n"
"	padding-left: 10px;\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(64, 71, 88);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(91, 101, 124);\n"
"}QLabel\n"
"{color: rgb(255, 255, 255);\n"
"}"));
        label_15 = new QLabel(frame_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(180, 230, 61, 16));
        label_16 = new QLabel(frame_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(180, 310, 81, 16));
        label_17 = new QLabel(frame_5);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(180, 270, 47, 14));
        label_18 = new QLabel(frame_5);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(180, 350, 101, 16));
        tabWidget_3->addTab(tab_4, QString());
        stackedWidget->addWidget(Modifier);
        Statistique = new QWidget();
        Statistique->setObjectName(QStringLiteral("Statistique"));
        centralwidget_2 = new QWidget(Statistique);
        centralwidget_2->setObjectName(QStringLiteral("centralwidget_2"));
        centralwidget_2->setGeometry(QRect(0, 0, 951, 601));
        stackedWidget->addWidget(Statistique);

        verticalLayout_9->addWidget(stackedWidget);


        verticalLayout_4->addWidget(frame_content);

        frame_grip = new QFrame(frame_content_right);
        frame_grip->setObjectName(QStringLiteral("frame_grip"));
        frame_grip->setMinimumSize(QSize(0, 25));
        frame_grip->setMaximumSize(QSize(16777215, 25));
        frame_grip->setStyleSheet(QStringLiteral("background-color: rgb(33, 37, 43);"));
        frame_grip->setFrameShape(QFrame::NoFrame);
        frame_grip->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_grip);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 2, 0);
        frame_label_bottom = new QFrame(frame_grip);
        frame_label_bottom->setObjectName(QStringLiteral("frame_label_bottom"));
        frame_label_bottom->setFrameShape(QFrame::NoFrame);
        frame_label_bottom->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_label_bottom);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(10, 0, 10, 0);
        label_credits = new QLabel(frame_label_bottom);
        label_credits->setObjectName(QStringLiteral("label_credits"));
        label_credits->setFont(font2);
        label_credits->setStyleSheet(QStringLiteral("color: rgb(98, 103, 111);"));

        horizontalLayout_7->addWidget(label_credits);

        label_version = new QLabel(frame_label_bottom);
        label_version->setObjectName(QStringLiteral("label_version"));
        label_version->setMaximumSize(QSize(100, 16777215));
        label_version->setFont(font2);
        label_version->setStyleSheet(QStringLiteral("color: rgb(98, 103, 111);"));
        label_version->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_version);


        horizontalLayout_6->addWidget(frame_label_bottom);

        frame_size_grip = new QFrame(frame_grip);
        frame_size_grip->setObjectName(QStringLiteral("frame_size_grip"));
        frame_size_grip->setMaximumSize(QSize(20, 20));
        frame_size_grip->setStyleSheet(QLatin1String("QSizeGrip {\n"
"	background-image: url(:/16x16/icons/16x16/cil-size-grip.png);\n"
"	background-position: center;\n"
"	background-repeat: no-reperat;\n"
"}"));
        frame_size_grip->setFrameShape(QFrame::NoFrame);
        frame_size_grip->setFrameShadow(QFrame::Raised);

        horizontalLayout_6->addWidget(frame_size_grip);


        verticalLayout_4->addWidget(frame_grip);


        horizontalLayout_2->addWidget(frame_content_right);


        verticalLayout->addWidget(frame_center);


        horizontalLayout->addWidget(frame_main);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);
        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        home->setText(QString());
        label_title_bar_top->setText(QApplication::translate("MainWindow", "Municipality", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btn_minimize->setToolTip(QApplication::translate("MainWindow", "Minimize", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btn_minimize->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_maximize_restore->setToolTip(QApplication::translate("MainWindow", "Maximize", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btn_maximize_restore->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_close->setToolTip(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btn_close->setText(QString());
        label_top_info_1->setText(QString());
        label_top_info_2->setText(QApplication::translate("MainWindow", "| HOME", Q_NULLPTR));
        ajouter_2->setText(QApplication::translate("MainWindow", "Open File", Q_NULLPTR));
        afficher_2->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        modifier->setText(QApplication::translate("MainWindow", "New", Q_NULLPTR));
        Statistque->setText(QApplication::translate("MainWindow", "New User", Q_NULLPTR));
        label_user_icon->setText(QApplication::translate("MainWindow", "WM", Q_NULLPTR));
        btn_settings->setText(QApplication::translate("MainWindow", "Open File", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Welcome to our project", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Prenom", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Date de naissance", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Email", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "tel", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Profil", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "service", Q_NULLPTR)
         << QApplication::translate("MainWindow", "parking", Q_NULLPTR)
         << QApplication::translate("MainWindow", "maintenance", Q_NULLPTR)
        );
        ajouter_0->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(agent), QApplication::translate("MainWindow", "Ajouter agent", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "nom_profil", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Salaire", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Description", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Nombre des agents", Q_NULLPTR));
        ajouter_profil->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(profil), QApplication::translate("MainWindow", "Ajouter profil", Q_NULLPTR));
        chercher_agents->setPlaceholderText(QApplication::translate("MainWindow", "Chercher", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow", "Imprimer", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("MainWindow", "Actualiser", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        check_CIN->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        check_prenom->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        check_email->setText(QApplication::translate("MainWindow", "email", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "trier par", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CIN", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "prenom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "tel", Q_NULLPTR)
        );
        pushButton_20->setText(QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("MainWindow", "Afficher les agents", Q_NULLPTR));
        chercher_profil->setPlaceholderText(QApplication::translate("MainWindow", "Chercher", Q_NULLPTR));
        pushButton_18->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        check_ID->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        check_salaire->setText(QApplication::translate("MainWindow", "salaire", Q_NULLPTR));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "trier par", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ID", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nom profil", Q_NULLPTR)
         << QApplication::translate("MainWindow", "salaire", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nombre des agents", Q_NULLPTR)
        );
        pdf->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        imprimer->setText(QApplication::translate("MainWindow", "Imprimer", Q_NULLPTR));
        actualiser->setText(QApplication::translate("MainWindow", "Actualiser", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("MainWindow", "Afficher les profils", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Email", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "service", Q_NULLPTR)
         << QApplication::translate("MainWindow", "New Item", Q_NULLPTR)
         << QApplication::translate("MainWindow", "New Item", Q_NULLPTR)
         << QApplication::translate("MainWindow", "New Item", Q_NULLPTR)
         << QApplication::translate("MainWindow", "New Item", Q_NULLPTR)
         << QApplication::translate("MainWindow", "New Item", Q_NULLPTR)
        );
        pushButton_12->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "tel", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "date de naissance", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "Prenom", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "Profil", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_3), QApplication::translate("MainWindow", "Modifier agent", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        modifier_profil->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "nom_Profil", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Description", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Salaire", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Nombre des agents", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_4), QApplication::translate("MainWindow", "Modifier profil", Q_NULLPTR));
        label_credits->setText(QString());
        label_version->setText(QApplication::translate("MainWindow", "v1.0.0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
