/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart;
    QAction *actionInformation;
    QAction *action_consistent;
    QAction *action_parallel;
    QAction *action_bridge;
    QAction *action_single;
    QAction *action_several;
    QAction *action_const;
    QAction *action_dipasone;
    QAction *action_triangular;
    QAction *actionExport_rnd;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_rnd;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView_rnd;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pB_genRnd;
    QPushButton *pB_ClearRnd;
    QPushButton *pB_buf_rnd;
    QTabWidget *tabWidget_start_p_m3;
    QWidget *tab_7;
    QTableView *tableView_probab;
    QWidget *tab_8;
    QGroupBox *groupBox;
    QTableView *tableView_start_p_m2;
    QGroupBox *groupBox_3;
    QTableView *tableView_rnd_p_diap_m2;
    QWidget *tab_9;
    QGridLayout *gridLayout_23;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_21;
    QTableView *tableView_start_p_m3;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_22;
    QTableView *tableView_rnd_p_diap_m3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pB_add_probab;
    QPushButton *pB_del_probab;
    QPushButton *pB_clear_probab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *spinBox_run;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpinBox *spinBox_test;
    QWidget *tab_2;
    QGroupBox *groupBox_stat_res_parallel_2;
    QTableView *tableView_graph_info_bridge;
    QPushButton *pB_gi_bridge_buf;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_25;
    QFormLayout *formLayout_3;
    QLabel *label_18;
    QDoubleSpinBox *dbSpB_M_bridge;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_20;
    QDoubleSpinBox *dbSpB_D_bridge;
    QLabel *label_19;
    QDoubleSpinBox *dbSpB_SKO_bridge;
    QGroupBox *groupBox_step_stat_parallel_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_15;
    QDoubleSpinBox *dbSpB_max_bridge;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_16;
    QDoubleSpinBox *dbSpB_step_bridge;
    QTableView *tableView_frequency;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_17;
    QDoubleSpinBox *dbSpB_min_bridge;
    QPushButton *pushButton_freq_buffer;
    QWidget *tab_3;
    QCustomPlot *widget1;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_graph_format;
    QPushButton *pushButton_save_graph;
    QPushButton *pushButton_reset_graph_zoom;
    QPushButton *pushButton_clear_graph;
    QPushButton *pushButton_buffer_graph;
    QLabel *label_struct_name;
    QListView *listView;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_struct_system;
    QMenu *menu_calc_params;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1167, 647);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart->setIcon(icon);
        actionInformation = new QAction(MainWindow);
        actionInformation->setObjectName(QStringLiteral("actionInformation"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/inspection-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInformation->setIcon(icon1);
        action_consistent = new QAction(MainWindow);
        action_consistent->setObjectName(QStringLiteral("action_consistent"));
        action_consistent->setCheckable(true);
        action_consistent->setChecked(false);
        action_parallel = new QAction(MainWindow);
        action_parallel->setObjectName(QStringLiteral("action_parallel"));
        action_parallel->setCheckable(true);
        action_bridge = new QAction(MainWindow);
        action_bridge->setObjectName(QStringLiteral("action_bridge"));
        action_bridge->setCheckable(true);
        action_bridge->setChecked(false);
        action_single = new QAction(MainWindow);
        action_single->setObjectName(QStringLiteral("action_single"));
        action_single->setCheckable(true);
        action_single->setChecked(false);
        action_several = new QAction(MainWindow);
        action_several->setObjectName(QStringLiteral("action_several"));
        action_several->setCheckable(true);
        action_const = new QAction(MainWindow);
        action_const->setObjectName(QStringLiteral("action_const"));
        action_const->setCheckable(true);
        action_dipasone = new QAction(MainWindow);
        action_dipasone->setObjectName(QStringLiteral("action_dipasone"));
        action_dipasone->setCheckable(true);
        action_triangular = new QAction(MainWindow);
        action_triangular->setObjectName(QStringLiteral("action_triangular"));
        action_triangular->setCheckable(true);
        actionExport_rnd = new QAction(MainWindow);
        actionExport_rnd->setObjectName(QStringLiteral("actionExport_rnd"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/microsoftoffice2007excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_rnd->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox_rnd = new QGroupBox(tab);
        groupBox_rnd->setObjectName(QStringLiteral("groupBox_rnd"));
        gridLayout = new QGridLayout(groupBox_rnd);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableView_rnd = new QTableView(groupBox_rnd);
        tableView_rnd->setObjectName(QStringLiteral("tableView_rnd"));

        verticalLayout_2->addWidget(tableView_rnd);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pB_genRnd = new QPushButton(groupBox_rnd);
        pB_genRnd->setObjectName(QStringLiteral("pB_genRnd"));

        horizontalLayout_5->addWidget(pB_genRnd);

        pB_ClearRnd = new QPushButton(groupBox_rnd);
        pB_ClearRnd->setObjectName(QStringLiteral("pB_ClearRnd"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/Seanau-Email-Clear.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pB_ClearRnd->setIcon(icon3);

        horizontalLayout_5->addWidget(pB_ClearRnd);

        pB_buf_rnd = new QPushButton(groupBox_rnd);
        pB_buf_rnd->setObjectName(QStringLiteral("pB_buf_rnd"));

        horizontalLayout_5->addWidget(pB_buf_rnd);


        verticalLayout_2->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_rnd, 0, 0, 2, 1);

        tabWidget_start_p_m3 = new QTabWidget(tab);
        tabWidget_start_p_m3->setObjectName(QStringLiteral("tabWidget_start_p_m3"));
        tabWidget_start_p_m3->setMaximumSize(QSize(601, 500));
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tableView_probab = new QTableView(tab_7);
        tableView_probab->setObjectName(QStringLiteral("tableView_probab"));
        tableView_probab->setGeometry(QRect(9, 9, 521, 431));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView_probab->sizePolicy().hasHeightForWidth());
        tableView_probab->setSizePolicy(sizePolicy);
        tabWidget_start_p_m3->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        groupBox = new QGroupBox(tab_8);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(9, 9, 571, 406));
        tableView_start_p_m2 = new QTableView(groupBox);
        tableView_start_p_m2->setObjectName(QStringLiteral("tableView_start_p_m2"));
        tableView_start_p_m2->setGeometry(QRect(12, 29, 481, 161));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 200, 551, 201));
        tableView_rnd_p_diap_m2 = new QTableView(groupBox_3);
        tableView_rnd_p_diap_m2->setObjectName(QStringLiteral("tableView_rnd_p_diap_m2"));
        tableView_rnd_p_diap_m2->setGeometry(QRect(12, 29, 471, 161));
        tabWidget_start_p_m3->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        gridLayout_23 = new QGridLayout(tab_9);
        gridLayout_23->setSpacing(6);
        gridLayout_23->setContentsMargins(11, 11, 11, 11);
        gridLayout_23->setObjectName(QStringLiteral("gridLayout_23"));
        groupBox_4 = new QGroupBox(tab_9);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_21 = new QGridLayout(groupBox_4);
        gridLayout_21->setSpacing(6);
        gridLayout_21->setContentsMargins(11, 11, 11, 11);
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        tableView_start_p_m3 = new QTableView(groupBox_4);
        tableView_start_p_m3->setObjectName(QStringLiteral("tableView_start_p_m3"));

        gridLayout_21->addWidget(tableView_start_p_m3, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_22 = new QGridLayout(groupBox_5);
        gridLayout_22->setSpacing(6);
        gridLayout_22->setContentsMargins(11, 11, 11, 11);
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        tableView_rnd_p_diap_m3 = new QTableView(groupBox_5);
        tableView_rnd_p_diap_m3->setObjectName(QStringLiteral("tableView_rnd_p_diap_m3"));

        gridLayout_22->addWidget(tableView_rnd_p_diap_m3, 0, 0, 1, 1);


        gridLayout_21->addWidget(groupBox_5, 1, 0, 1, 1);


        gridLayout_23->addWidget(groupBox_4, 0, 0, 1, 1);

        tabWidget_start_p_m3->addTab(tab_9, QString());

        gridLayout_2->addWidget(tabWidget_start_p_m3, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pB_add_probab = new QPushButton(tab);
        pB_add_probab->setObjectName(QStringLiteral("pB_add_probab"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pB_add_probab->setIcon(icon4);

        verticalLayout_3->addWidget(pB_add_probab);

        pB_del_probab = new QPushButton(tab);
        pB_del_probab->setObjectName(QStringLiteral("pB_del_probab"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        pB_del_probab->setIcon(icon5);

        verticalLayout_3->addWidget(pB_del_probab);

        pB_clear_probab = new QPushButton(tab);
        pB_clear_probab->setObjectName(QStringLiteral("pB_clear_probab"));
        pB_clear_probab->setIcon(icon3);

        verticalLayout_3->addWidget(pB_clear_probab);


        gridLayout_2->addLayout(verticalLayout_3, 0, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(165, 0));

        horizontalLayout->addWidget(label_2);

        spinBox_run = new QSpinBox(tab);
        spinBox_run->setObjectName(QStringLiteral("spinBox_run"));
        spinBox_run->setAlignment(Qt::AlignCenter);
        spinBox_run->setMinimum(1);
        spinBox_run->setMaximum(10000);

        horizontalLayout->addWidget(spinBox_run);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        spinBox_test = new QSpinBox(tab);
        spinBox_test->setObjectName(QStringLiteral("spinBox_test"));
        spinBox_test->setAlignment(Qt::AlignCenter);
        spinBox_test->setMinimum(1);
        spinBox_test->setMaximum(10000);

        horizontalLayout_4->addWidget(spinBox_test);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(verticalLayout, 1, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_stat_res_parallel_2 = new QGroupBox(tab_2);
        groupBox_stat_res_parallel_2->setObjectName(QStringLiteral("groupBox_stat_res_parallel_2"));
        groupBox_stat_res_parallel_2->setEnabled(true);
        groupBox_stat_res_parallel_2->setGeometry(QRect(200, 2, 831, 591));
        tableView_graph_info_bridge = new QTableView(groupBox_stat_res_parallel_2);
        tableView_graph_info_bridge->setObjectName(QStringLiteral("tableView_graph_info_bridge"));
        tableView_graph_info_bridge->setGeometry(QRect(12, 31, 791, 501));
        pB_gi_bridge_buf = new QPushButton(groupBox_stat_res_parallel_2);
        pB_gi_bridge_buf->setObjectName(QStringLiteral("pB_gi_bridge_buf"));
        pB_gi_bridge_buf->setGeometry(QRect(670, 550, 136, 21));
        layoutWidget = new QWidget(groupBox_stat_res_parallel_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 540, 522, 29));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMaximumSize(QSize(90, 16777215));
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_18);

        dbSpB_M_bridge = new QDoubleSpinBox(layoutWidget);
        dbSpB_M_bridge->setObjectName(QStringLiteral("dbSpB_M_bridge"));
        dbSpB_M_bridge->setAlignment(Qt::AlignCenter);
        dbSpB_M_bridge->setDecimals(5);
        dbSpB_M_bridge->setMaximum(1e+08);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, dbSpB_M_bridge);


        horizontalLayout_25->addLayout(formLayout_3);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMaximumSize(QSize(90, 16777215));
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_26->addWidget(label_20);

        dbSpB_D_bridge = new QDoubleSpinBox(layoutWidget);
        dbSpB_D_bridge->setObjectName(QStringLiteral("dbSpB_D_bridge"));
        dbSpB_D_bridge->setAlignment(Qt::AlignCenter);
        dbSpB_D_bridge->setDecimals(5);
        dbSpB_D_bridge->setMaximum(100000);

        horizontalLayout_26->addWidget(dbSpB_D_bridge);


        horizontalLayout_25->addLayout(horizontalLayout_26);

        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMaximumSize(QSize(90, 16777215));
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_25->addWidget(label_19);

        dbSpB_SKO_bridge = new QDoubleSpinBox(layoutWidget);
        dbSpB_SKO_bridge->setObjectName(QStringLiteral("dbSpB_SKO_bridge"));
        dbSpB_SKO_bridge->setAlignment(Qt::AlignCenter);
        dbSpB_SKO_bridge->setDecimals(5);
        dbSpB_SKO_bridge->setMaximum(100000);

        horizontalLayout_25->addWidget(dbSpB_SKO_bridge);


        horizontalLayout_3->addLayout(horizontalLayout_25);

        groupBox_step_stat_parallel_2 = new QGroupBox(tab_2);
        groupBox_step_stat_parallel_2->setObjectName(QStringLiteral("groupBox_step_stat_parallel_2"));
        groupBox_step_stat_parallel_2->setGeometry(QRect(10, 0, 181, 591));
        gridLayout_3 = new QGridLayout(groupBox_step_stat_parallel_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_15 = new QLabel(groupBox_step_stat_parallel_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMaximumSize(QSize(60, 16777215));
        label_15->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_21->addWidget(label_15);

        dbSpB_max_bridge = new QDoubleSpinBox(groupBox_step_stat_parallel_2);
        dbSpB_max_bridge->setObjectName(QStringLiteral("dbSpB_max_bridge"));
        dbSpB_max_bridge->setAlignment(Qt::AlignCenter);
        dbSpB_max_bridge->setDecimals(5);
        dbSpB_max_bridge->setMaximum(1);
        dbSpB_max_bridge->setSingleStep(0.01);

        horizontalLayout_21->addWidget(dbSpB_max_bridge);


        gridLayout_3->addLayout(horizontalLayout_21, 1, 0, 1, 1);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_16 = new QLabel(groupBox_step_stat_parallel_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMaximumSize(QSize(60, 16777215));
        label_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_22->addWidget(label_16);

        dbSpB_step_bridge = new QDoubleSpinBox(groupBox_step_stat_parallel_2);
        dbSpB_step_bridge->setObjectName(QStringLiteral("dbSpB_step_bridge"));
        dbSpB_step_bridge->setAlignment(Qt::AlignCenter);
        dbSpB_step_bridge->setDecimals(5);
        dbSpB_step_bridge->setMaximum(1);
        dbSpB_step_bridge->setSingleStep(0.01);
        dbSpB_step_bridge->setValue(0.01);

        horizontalLayout_22->addWidget(dbSpB_step_bridge);


        gridLayout_3->addLayout(horizontalLayout_22, 2, 0, 1, 1);

        tableView_frequency = new QTableView(groupBox_step_stat_parallel_2);
        tableView_frequency->setObjectName(QStringLiteral("tableView_frequency"));
        tableView_frequency->setMinimumSize(QSize(102, 0));

        gridLayout_3->addWidget(tableView_frequency, 3, 0, 1, 1);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        label_17 = new QLabel(groupBox_step_stat_parallel_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMaximumSize(QSize(60, 16777215));
        label_17->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_23->addWidget(label_17);

        dbSpB_min_bridge = new QDoubleSpinBox(groupBox_step_stat_parallel_2);
        dbSpB_min_bridge->setObjectName(QStringLiteral("dbSpB_min_bridge"));
        dbSpB_min_bridge->setAlignment(Qt::AlignCenter);
        dbSpB_min_bridge->setDecimals(5);
        dbSpB_min_bridge->setMaximum(1);
        dbSpB_min_bridge->setSingleStep(0.01);

        horizontalLayout_23->addWidget(dbSpB_min_bridge);


        gridLayout_3->addLayout(horizontalLayout_23, 0, 0, 1, 1);

        pushButton_freq_buffer = new QPushButton(groupBox_step_stat_parallel_2);
        pushButton_freq_buffer->setObjectName(QStringLiteral("pushButton_freq_buffer"));

        gridLayout_3->addWidget(pushButton_freq_buffer, 4, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        widget1 = new QCustomPlot(tab_3);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 10, 991, 521));
        layoutWidget1 = new QWidget(tab_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(520, 560, 509, 26));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBox_graph_format = new QComboBox(layoutWidget1);
        comboBox_graph_format->addItem(QString());
        comboBox_graph_format->addItem(QString());
        comboBox_graph_format->addItem(QString());
        comboBox_graph_format->addItem(QString());
        comboBox_graph_format->setObjectName(QStringLiteral("comboBox_graph_format"));

        horizontalLayout_2->addWidget(comboBox_graph_format);

        pushButton_save_graph = new QPushButton(layoutWidget1);
        pushButton_save_graph->setObjectName(QStringLiteral("pushButton_save_graph"));

        horizontalLayout_2->addWidget(pushButton_save_graph);

        pushButton_reset_graph_zoom = new QPushButton(layoutWidget1);
        pushButton_reset_graph_zoom->setObjectName(QStringLiteral("pushButton_reset_graph_zoom"));

        horizontalLayout_2->addWidget(pushButton_reset_graph_zoom);

        pushButton_clear_graph = new QPushButton(layoutWidget1);
        pushButton_clear_graph->setObjectName(QStringLiteral("pushButton_clear_graph"));
        pushButton_clear_graph->setIcon(icon3);

        horizontalLayout_2->addWidget(pushButton_clear_graph);

        pushButton_buffer_graph = new QPushButton(layoutWidget1);
        pushButton_buffer_graph->setObjectName(QStringLiteral("pushButton_buffer_graph"));

        horizontalLayout_2->addWidget(pushButton_buffer_graph);

        label_struct_name = new QLabel(tab_3);
        label_struct_name->setObjectName(QStringLiteral("label_struct_name"));
        label_struct_name->setGeometry(QRect(30, 530, 88, 16));
        listView = new QListView(tab_3);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(30, 560, 481, 21));
        tabWidget->addTab(tab_3, QString());

        gridLayout_5->addWidget(tabWidget, 0, 0, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout_5->addWidget(progressBar, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 1167, 20));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_struct_system = new QMenu(menuBar);
        menu_struct_system->setObjectName(QStringLiteral("menu_struct_system"));
        menu_struct_system->setEnabled(false);
        menu_struct_system->setMouseTracking(true);
        menu_calc_params = new QMenu(menuBar);
        menu_calc_params->setObjectName(QStringLiteral("menu_calc_params"));
        menu_calc_params->setEnabled(false);
        menu_calc_params->setGeometry(QRect(402, 99, 259, 69));
        menu_calc_params->setMouseTracking(true);
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_calc_params->menuAction());
        menuBar->addAction(menu_struct_system->menuAction());
        menu->addAction(action_const);
        menu->addAction(action_dipasone);
        menu->addAction(action_triangular);
        menu_struct_system->addAction(action_bridge);
        menu_calc_params->addAction(action_single);
        mainToolBar->addAction(actionStart);
        mainToolBar->addAction(actionInformation);
        mainToolBar->addAction(actionExport_rnd);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);
        tabWidget_start_p_m3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\234\320\276\321\201\321\202\320\276\320\262\320\260\321\217 \321\201\320\270\321\201\321\202\320\265\320\274\320\260", nullptr));
        actionStart->setText(QApplication::translate("MainWindow", "Start", nullptr));
#ifndef QT_NO_TOOLTIP
        actionStart->setToolTip(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\320\272 \320\262\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\320\271", nullptr));
#endif // QT_NO_TOOLTIP
        actionInformation->setText(QApplication::translate("MainWindow", "Information", nullptr));
#ifndef QT_NO_TOOLTIP
        actionInformation->setToolTip(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
#endif // QT_NO_TOOLTIP
        action_consistent->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\260\321\217", nullptr));
        action_parallel->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\260\321\217", nullptr));
        action_bridge->setText(QApplication::translate("MainWindow", "\320\234\320\276\321\201\321\202\320\276\320\262\320\260\321\217", nullptr));
        action_single->setText(QApplication::translate("MainWindow", "\320\224\320\273\321\217 \320\272\320\276\320\275\320\272\321\200\320\265\321\202\320\275\320\276\320\271 \321\201\321\202\321\200\321\203\320\272\321\202\321\203\321\200\321\213 \321\201\320\265\321\202\320\270", nullptr));
        action_several->setText(QApplication::translate("MainWindow", "\320\224\320\273\321\217 \320\275\320\265\321\201\320\272\320\276\320\273\321\214\320\272\320\270\321\205 \321\201\321\202\321\200\321\203\320\272\321\202\321\203\321\200 \321\201\320\265\321\202\320\270", nullptr));
        action_const->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214 \320\277\320\276\320\273\320\275\320\276\320\271 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\321\221\320\275\320\275\320\276\321\201\321\202\320\270", nullptr));
        action_dipasone->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\320\270", nullptr));
        action_triangular->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214 \321\202\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\276\320\263\320\276 \321\200\320\260\321\201\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\321\217", nullptr));
        actionExport_rnd->setText(QApplication::translate("MainWindow", "Export_rnd", nullptr));
        groupBox_rnd->setTitle(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \321\201\320\276 \321\201\320\273\321\203\321\207\320\260\320\271\320\275\321\213\320\274\320\270 \321\207\320\270\321\201\320\273\320\260\320\274\320\270", nullptr));
        pB_genRnd->setText(QApplication::translate("MainWindow", "\320\223\320\265\320\275\320\265\321\200\320\260\321\206\320\270\321\217 \320\241\320\247", nullptr));
        pB_ClearRnd->setText(QString());
        pB_buf_rnd->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\262 \320\261\321\203\321\204\320\265\321\200", nullptr));
        tabWidget_start_p_m3->setTabText(tabWidget_start_p_m3->indexOf(tab_7), QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\275\320\276\320\271 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\321\221\320\275\320\275\320\276\321\201\321\202\320\270", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\275\321\213\320\265 \320\262\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\320\270:", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\222\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\320\270 \320\262 \320\267\320\260\320\264\320\260\320\275\320\275\320\276\320\274 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275\320\265:", nullptr));
        tabWidget_start_p_m3->setTabText(tabWidget_start_p_m3->indexOf(tab_8), QApplication::translate("MainWindow", "\320\237\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\320\270", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\275\321\213\320\265 \320\262\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\320\270:", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\320\222\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\320\270 \320\262 \320\267\320\260\320\264\320\260\320\275\320\275\320\276\320\274 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275\320\265:", nullptr));
        tabWidget_start_p_m3->setTabText(tabWidget_start_p_m3->indexOf(tab_9), QApplication::translate("MainWindow", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\276\320\263\320\276 \321\200\320\260\321\201\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\321\217", nullptr));
        pB_add_probab->setText(QString());
        pB_del_probab->setText(QString());
        pB_clear_probab->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("MainWindow", "\320\241\320\272\320\276\320\273\321\214\320\272\320\276 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\320\265\320\271 \320\241\320\247 \320\261\321\203\320\264\320\265\321\202 \321\201\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\276", nullptr));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\321\213\320\261\320\276\321\200\320\276\320\272 \320\241\320\247:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\215\320\272\321\201\320\277\320\265\321\200\320\270\320\274\320\265\320\275\321\202\320\276\320\262:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        groupBox_stat_res_parallel_2->setTitle(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272\320\270:", nullptr));
        pB_gi_bridge_buf->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\202.\320\276\320\266\320\270\320\264\320\260\320\275\320\270\320\265:", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "\320\224\320\270\321\201\320\277\320\265\321\200\321\201\320\270\321\217:", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\320\241\320\232\320\236:", nullptr));
        groupBox_step_stat_parallel_2->setTitle(QApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\321\202\320\265\320\273\321\214\320\275\320\260\321\217 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260:", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274:", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\320\250\320\260\320\263:", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\321\203\320\274:", nullptr));
        pushButton_freq_buffer->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\207\320\260\321\201\321\202\320\276\321\201\321\202\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213", nullptr));
        comboBox_graph_format->setItemText(0, QApplication::translate("MainWindow", "*.jpg", nullptr));
        comboBox_graph_format->setItemText(1, QApplication::translate("MainWindow", "*.png", nullptr));
        comboBox_graph_format->setItemText(2, QApplication::translate("MainWindow", "*.bmp", nullptr));
        comboBox_graph_format->setItemText(3, QApplication::translate("MainWindow", "*.pdf", nullptr));

        pushButton_save_graph->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        pushButton_reset_graph_zoom->setText(QApplication::translate("MainWindow", "1x1", nullptr));
        pushButton_clear_graph->setText(QString());
        pushButton_buffer_graph->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272 \320\262 \320\261\321\203\321\204\320\265\321\200", nullptr));
        label_struct_name->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\200\321\203\320\272\321\202\321\203\321\200\320\260 \321\201\320\265\321\202\320\270: ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272\320\270", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        menu_struct_system->setTitle(QString());
        menu_calc_params->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
