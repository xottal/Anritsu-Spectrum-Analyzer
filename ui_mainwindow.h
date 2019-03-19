/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUpdate_COM_ports;
    QAction *actionSettings;
    QAction *actionHelp_info;
    QAction *actionPush_Settings;
    QAction *actionPull_Settings;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_ComPort;
    QPushButton *pushButton_Connect;
    QLineEdit *lineEdit_Greetings;
    QGroupBox *groupBox_Wavelength;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_3;
    QDoubleSpinBox *doubleSpinBox_Center;
    QDoubleSpinBox *doubleSpinBox_Span;
    QComboBox *comboBox_MarkerValue;
    QComboBox *comboBox_VacuumAir;
    QGroupBox *groupBox_Level;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox_LogLin;
    QCheckBox *checkBox_OptAtt;
    QGroupBox *groupBox_log;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_5;
    QDoubleSpinBox *doubleSpinBox_dBdiv;
    QDoubleSpinBox *doubleSpinBox_Ref_Level;
    QGroupBox *groupBox_linear;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_LinearLevel;
    QComboBox *comboBox_LinearLevel;
    QGroupBox *groupBox_ResolutionVBW;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_8;
    QCheckBox *checkBox_actualRes;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_8;
    QComboBox *comboBox_Resolution;
    QLineEdit *lineEdit_ActualResolution;
    QComboBox *comboBox_VBW;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_14;
    QLineEdit *lineEdit_error;
    QVBoxLayout *verticalLayout_17;
    QCustomPlot *widget_graph;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_15;
    QGroupBox *groupBox_AverageSampling;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_11;
    QSpinBox *spinBox_PointAverage;
    QSpinBox *spinBox_SweepAverage;
    QComboBox *comboBox_Smooth;
    QComboBox *comboBox_SamplingPoints;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *groupBox_Sweep;
    QVBoxLayout *verticalLayout_12;
    QComboBox *comboBox_Sweep;
    QPushButton *pushButton_Sweep;
    QGroupBox *groupBox_Memory;
    QVBoxLayout *verticalLayout_14;
    QRadioButton *radioButton_memoryA;
    QRadioButton *radioButton_memoryB;
    QVBoxLayout *verticalLayout_16;
    QPushButton *pushButton_recieveSpectrum;
    QGroupBox *groupBox_PeaksDips;
    QVBoxLayout *verticalLayout_13;
    QPushButton *pushButton_peakSearch;
    QPushButton *pushButton_dipSearch;
    QPushButton *pushButton_peakToCenter;
    QPushButton *pushButton_TMkrToCenter;
    QPushButton *pushButton_peakToLevel;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_nameOfFile;
    QLineEdit *lineEdit_nameOfFile;
    QPushButton *pushButton_exportToFile;
    QMenuBar *menuBar;
    QMenu *menuGodDamn;
    QMenu *menuSync;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(556, 644);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionUpdate_COM_ports = new QAction(MainWindow);
        actionUpdate_COM_ports->setObjectName(QString::fromUtf8("actionUpdate_COM_ports"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionHelp_info = new QAction(MainWindow);
        actionHelp_info->setObjectName(QString::fromUtf8("actionHelp_info"));
        actionPush_Settings = new QAction(MainWindow);
        actionPush_Settings->setObjectName(QString::fromUtf8("actionPush_Settings"));
        actionPull_Settings = new QAction(MainWindow);
        actionPull_Settings->setObjectName(QString::fromUtf8("actionPull_Settings"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_12 = new QHBoxLayout(centralWidget);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox_ComPort = new QComboBox(groupBox);
        comboBox_ComPort->setObjectName(QString::fromUtf8("comboBox_ComPort"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox_ComPort->sizePolicy().hasHeightForWidth());
        comboBox_ComPort->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(comboBox_ComPort);

        pushButton_Connect = new QPushButton(groupBox);
        pushButton_Connect->setObjectName(QString::fromUtf8("pushButton_Connect"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_Connect->sizePolicy().hasHeightForWidth());
        pushButton_Connect->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(pushButton_Connect);


        verticalLayout->addLayout(horizontalLayout);

        lineEdit_Greetings = new QLineEdit(groupBox);
        lineEdit_Greetings->setObjectName(QString::fromUtf8("lineEdit_Greetings"));
        lineEdit_Greetings->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_Greetings);


        verticalLayout_9->addWidget(groupBox);

        groupBox_Wavelength = new QGroupBox(centralWidget);
        groupBox_Wavelength->setObjectName(QString::fromUtf8("groupBox_Wavelength"));
        groupBox_Wavelength->setEnabled(true);
        sizePolicy3.setHeightForWidth(groupBox_Wavelength->sizePolicy().hasHeightForWidth());
        groupBox_Wavelength->setSizePolicy(sizePolicy3);
        groupBox_Wavelength->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(groupBox_Wavelength);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(groupBox_Wavelength);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(10);
        label->setFont(font1);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(groupBox_Wavelength);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        verticalLayout_2->addWidget(label_2);

        label_6 = new QLabel(groupBox_Wavelength);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(groupBox_Wavelength);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy4.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(label_7);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        doubleSpinBox_Center = new QDoubleSpinBox(groupBox_Wavelength);
        doubleSpinBox_Center->setObjectName(QString::fromUtf8("doubleSpinBox_Center"));
        doubleSpinBox_Center->setMinimum(600.000000000000000);
        doubleSpinBox_Center->setMaximum(1750.000000000000000);
        doubleSpinBox_Center->setSingleStep(0.010000000000000);

        verticalLayout_3->addWidget(doubleSpinBox_Center);

        doubleSpinBox_Span = new QDoubleSpinBox(groupBox_Wavelength);
        doubleSpinBox_Span->setObjectName(QString::fromUtf8("doubleSpinBox_Span"));
        doubleSpinBox_Span->setDecimals(1);
        doubleSpinBox_Span->setMinimum(0.100000000000000);
        doubleSpinBox_Span->setMaximum(1200.000000000000000);
        doubleSpinBox_Span->setSingleStep(0.100000000000000);

        verticalLayout_3->addWidget(doubleSpinBox_Span);

        comboBox_MarkerValue = new QComboBox(groupBox_Wavelength);
        comboBox_MarkerValue->setObjectName(QString::fromUtf8("comboBox_MarkerValue"));

        verticalLayout_3->addWidget(comboBox_MarkerValue);

        comboBox_VacuumAir = new QComboBox(groupBox_Wavelength);
        comboBox_VacuumAir->setObjectName(QString::fromUtf8("comboBox_VacuumAir"));

        verticalLayout_3->addWidget(comboBox_VacuumAir);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_9->addWidget(groupBox_Wavelength);

        groupBox_Level = new QGroupBox(centralWidget);
        groupBox_Level->setObjectName(QString::fromUtf8("groupBox_Level"));
        groupBox_Level->setEnabled(true);
        sizePolicy3.setHeightForWidth(groupBox_Level->sizePolicy().hasHeightForWidth());
        groupBox_Level->setSizePolicy(sizePolicy3);
        verticalLayout_6 = new QVBoxLayout(groupBox_Level);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBox_LogLin = new QComboBox(groupBox_Level);
        comboBox_LogLin->setObjectName(QString::fromUtf8("comboBox_LogLin"));

        horizontalLayout_3->addWidget(comboBox_LogLin);

        checkBox_OptAtt = new QCheckBox(groupBox_Level);
        checkBox_OptAtt->setObjectName(QString::fromUtf8("checkBox_OptAtt"));
        QFont font2;
        font2.setPointSize(8);
        checkBox_OptAtt->setFont(font2);

        horizontalLayout_3->addWidget(checkBox_OptAtt);


        verticalLayout_6->addLayout(horizontalLayout_3);

        groupBox_log = new QGroupBox(groupBox_Level);
        groupBox_log->setObjectName(QString::fromUtf8("groupBox_log"));
        sizePolicy3.setHeightForWidth(groupBox_log->sizePolicy().hasHeightForWidth());
        groupBox_log->setSizePolicy(sizePolicy3);
        groupBox_log->setFont(font);
        horizontalLayout_4 = new QHBoxLayout(groupBox_log);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new QLabel(groupBox_log);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        verticalLayout_4->addWidget(label_4);

        label_5 = new QLabel(groupBox_log);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        verticalLayout_4->addWidget(label_5);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        doubleSpinBox_dBdiv = new QDoubleSpinBox(groupBox_log);
        doubleSpinBox_dBdiv->setObjectName(QString::fromUtf8("doubleSpinBox_dBdiv"));
        doubleSpinBox_dBdiv->setDecimals(1);
        doubleSpinBox_dBdiv->setMinimum(0.100000000000000);
        doubleSpinBox_dBdiv->setMaximum(10.000000000000000);
        doubleSpinBox_dBdiv->setSingleStep(0.100000000000000);

        verticalLayout_5->addWidget(doubleSpinBox_dBdiv);

        doubleSpinBox_Ref_Level = new QDoubleSpinBox(groupBox_log);
        doubleSpinBox_Ref_Level->setObjectName(QString::fromUtf8("doubleSpinBox_Ref_Level"));
        doubleSpinBox_Ref_Level->setMinimum(-90.000000000000000);
        doubleSpinBox_Ref_Level->setMaximum(30.000000000000000);
        doubleSpinBox_Ref_Level->setSingleStep(0.100000000000000);

        verticalLayout_5->addWidget(doubleSpinBox_Ref_Level);


        horizontalLayout_4->addLayout(verticalLayout_5);


        verticalLayout_6->addWidget(groupBox_log);

        groupBox_linear = new QGroupBox(groupBox_Level);
        groupBox_linear->setObjectName(QString::fromUtf8("groupBox_linear"));
        groupBox_linear->setEnabled(true);
        sizePolicy3.setHeightForWidth(groupBox_linear->sizePolicy().hasHeightForWidth());
        groupBox_linear->setSizePolicy(sizePolicy3);
        horizontalLayout_5 = new QHBoxLayout(groupBox_linear);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(groupBox_linear);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_5->addWidget(label_3);

        doubleSpinBox_LinearLevel = new QDoubleSpinBox(groupBox_linear);
        doubleSpinBox_LinearLevel->setObjectName(QString::fromUtf8("doubleSpinBox_LinearLevel"));
        doubleSpinBox_LinearLevel->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(doubleSpinBox_LinearLevel->sizePolicy().hasHeightForWidth());
        doubleSpinBox_LinearLevel->setSizePolicy(sizePolicy5);
        doubleSpinBox_LinearLevel->setDecimals(3);
        doubleSpinBox_LinearLevel->setMinimum(1.000000000000000);
        doubleSpinBox_LinearLevel->setMaximum(1000.000000000000000);
        doubleSpinBox_LinearLevel->setSingleStep(0.010000000000000);

        horizontalLayout_5->addWidget(doubleSpinBox_LinearLevel);

        comboBox_LinearLevel = new QComboBox(groupBox_linear);
        comboBox_LinearLevel->setObjectName(QString::fromUtf8("comboBox_LinearLevel"));

        horizontalLayout_5->addWidget(comboBox_LinearLevel);


        verticalLayout_6->addWidget(groupBox_linear);


        verticalLayout_9->addWidget(groupBox_Level);

        groupBox_ResolutionVBW = new QGroupBox(centralWidget);
        groupBox_ResolutionVBW->setObjectName(QString::fromUtf8("groupBox_ResolutionVBW"));
        groupBox_ResolutionVBW->setEnabled(true);
        horizontalLayout_6 = new QHBoxLayout(groupBox_ResolutionVBW);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_8 = new QLabel(groupBox_ResolutionVBW);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);
        label_8->setFont(font1);

        verticalLayout_7->addWidget(label_8);

        checkBox_actualRes = new QCheckBox(groupBox_ResolutionVBW);
        checkBox_actualRes->setObjectName(QString::fromUtf8("checkBox_actualRes"));
        checkBox_actualRes->setChecked(false);

        verticalLayout_7->addWidget(checkBox_actualRes);

        label_9 = new QLabel(groupBox_ResolutionVBW);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        verticalLayout_7->addWidget(label_9);


        horizontalLayout_6->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        comboBox_Resolution = new QComboBox(groupBox_ResolutionVBW);
        comboBox_Resolution->setObjectName(QString::fromUtf8("comboBox_Resolution"));
        sizePolicy4.setHeightForWidth(comboBox_Resolution->sizePolicy().hasHeightForWidth());
        comboBox_Resolution->setSizePolicy(sizePolicy4);

        verticalLayout_8->addWidget(comboBox_Resolution);

        lineEdit_ActualResolution = new QLineEdit(groupBox_ResolutionVBW);
        lineEdit_ActualResolution->setObjectName(QString::fromUtf8("lineEdit_ActualResolution"));

        verticalLayout_8->addWidget(lineEdit_ActualResolution);

        comboBox_VBW = new QComboBox(groupBox_ResolutionVBW);
        comboBox_VBW->setObjectName(QString::fromUtf8("comboBox_VBW"));

        verticalLayout_8->addWidget(comboBox_VBW);


        horizontalLayout_6->addLayout(verticalLayout_8);


        verticalLayout_9->addWidget(groupBox_ResolutionVBW);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_9->addWidget(label_14);

        lineEdit_error = new QLineEdit(centralWidget);
        lineEdit_error->setObjectName(QString::fromUtf8("lineEdit_error"));
        lineEdit_error->setReadOnly(true);

        horizontalLayout_9->addWidget(lineEdit_error);


        verticalLayout_9->addLayout(horizontalLayout_9);


        horizontalLayout_12->addLayout(verticalLayout_9);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        widget_graph = new QCustomPlot(centralWidget);
        widget_graph->setObjectName(QString::fromUtf8("widget_graph"));
        sizePolicy3.setHeightForWidth(widget_graph->sizePolicy().hasHeightForWidth());
        widget_graph->setSizePolicy(sizePolicy3);

        verticalLayout_17->addWidget(widget_graph);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        groupBox_AverageSampling = new QGroupBox(centralWidget);
        groupBox_AverageSampling->setObjectName(QString::fromUtf8("groupBox_AverageSampling"));
        groupBox_AverageSampling->setEnabled(true);
        horizontalLayout_7 = new QHBoxLayout(groupBox_AverageSampling);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_10 = new QLabel(groupBox_AverageSampling);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_10->addWidget(label_10);

        label_11 = new QLabel(groupBox_AverageSampling);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_10->addWidget(label_11);

        label_12 = new QLabel(groupBox_AverageSampling);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_10->addWidget(label_12);

        label_13 = new QLabel(groupBox_AverageSampling);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_10->addWidget(label_13);


        horizontalLayout_7->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        spinBox_PointAverage = new QSpinBox(groupBox_AverageSampling);
        spinBox_PointAverage->setObjectName(QString::fromUtf8("spinBox_PointAverage"));
        spinBox_PointAverage->setMinimum(1);
        spinBox_PointAverage->setMaximum(1000);

        verticalLayout_11->addWidget(spinBox_PointAverage);

        spinBox_SweepAverage = new QSpinBox(groupBox_AverageSampling);
        spinBox_SweepAverage->setObjectName(QString::fromUtf8("spinBox_SweepAverage"));
        spinBox_SweepAverage->setMinimum(1);
        spinBox_SweepAverage->setMaximum(1000);

        verticalLayout_11->addWidget(spinBox_SweepAverage);

        comboBox_Smooth = new QComboBox(groupBox_AverageSampling);
        comboBox_Smooth->setObjectName(QString::fromUtf8("comboBox_Smooth"));

        verticalLayout_11->addWidget(comboBox_Smooth);

        comboBox_SamplingPoints = new QComboBox(groupBox_AverageSampling);
        comboBox_SamplingPoints->setObjectName(QString::fromUtf8("comboBox_SamplingPoints"));

        verticalLayout_11->addWidget(comboBox_SamplingPoints);


        horizontalLayout_7->addLayout(verticalLayout_11);


        verticalLayout_15->addWidget(groupBox_AverageSampling);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        groupBox_Sweep = new QGroupBox(centralWidget);
        groupBox_Sweep->setObjectName(QString::fromUtf8("groupBox_Sweep"));
        groupBox_Sweep->setEnabled(true);
        verticalLayout_12 = new QVBoxLayout(groupBox_Sweep);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        comboBox_Sweep = new QComboBox(groupBox_Sweep);
        comboBox_Sweep->setObjectName(QString::fromUtf8("comboBox_Sweep"));

        verticalLayout_12->addWidget(comboBox_Sweep);

        pushButton_Sweep = new QPushButton(groupBox_Sweep);
        pushButton_Sweep->setObjectName(QString::fromUtf8("pushButton_Sweep"));
        sizePolicy3.setHeightForWidth(pushButton_Sweep->sizePolicy().hasHeightForWidth());
        pushButton_Sweep->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setPointSize(12);
        pushButton_Sweep->setFont(font3);

        verticalLayout_12->addWidget(pushButton_Sweep);


        horizontalLayout_8->addWidget(groupBox_Sweep);

        groupBox_Memory = new QGroupBox(centralWidget);
        groupBox_Memory->setObjectName(QString::fromUtf8("groupBox_Memory"));
        verticalLayout_14 = new QVBoxLayout(groupBox_Memory);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        radioButton_memoryA = new QRadioButton(groupBox_Memory);
        radioButton_memoryA->setObjectName(QString::fromUtf8("radioButton_memoryA"));

        verticalLayout_14->addWidget(radioButton_memoryA);

        radioButton_memoryB = new QRadioButton(groupBox_Memory);
        radioButton_memoryB->setObjectName(QString::fromUtf8("radioButton_memoryB"));

        verticalLayout_14->addWidget(radioButton_memoryB);


        horizontalLayout_8->addWidget(groupBox_Memory);


        verticalLayout_15->addLayout(horizontalLayout_8);


        horizontalLayout_10->addLayout(verticalLayout_15);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        pushButton_recieveSpectrum = new QPushButton(centralWidget);
        pushButton_recieveSpectrum->setObjectName(QString::fromUtf8("pushButton_recieveSpectrum"));

        verticalLayout_16->addWidget(pushButton_recieveSpectrum);

        groupBox_PeaksDips = new QGroupBox(centralWidget);
        groupBox_PeaksDips->setObjectName(QString::fromUtf8("groupBox_PeaksDips"));
        groupBox_PeaksDips->setEnabled(true);
        verticalLayout_13 = new QVBoxLayout(groupBox_PeaksDips);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        pushButton_peakSearch = new QPushButton(groupBox_PeaksDips);
        pushButton_peakSearch->setObjectName(QString::fromUtf8("pushButton_peakSearch"));
        sizePolicy3.setHeightForWidth(pushButton_peakSearch->sizePolicy().hasHeightForWidth());
        pushButton_peakSearch->setSizePolicy(sizePolicy3);

        verticalLayout_13->addWidget(pushButton_peakSearch);

        pushButton_dipSearch = new QPushButton(groupBox_PeaksDips);
        pushButton_dipSearch->setObjectName(QString::fromUtf8("pushButton_dipSearch"));
        sizePolicy3.setHeightForWidth(pushButton_dipSearch->sizePolicy().hasHeightForWidth());
        pushButton_dipSearch->setSizePolicy(sizePolicy3);

        verticalLayout_13->addWidget(pushButton_dipSearch);

        pushButton_peakToCenter = new QPushButton(groupBox_PeaksDips);
        pushButton_peakToCenter->setObjectName(QString::fromUtf8("pushButton_peakToCenter"));
        sizePolicy3.setHeightForWidth(pushButton_peakToCenter->sizePolicy().hasHeightForWidth());
        pushButton_peakToCenter->setSizePolicy(sizePolicy3);

        verticalLayout_13->addWidget(pushButton_peakToCenter);

        pushButton_TMkrToCenter = new QPushButton(groupBox_PeaksDips);
        pushButton_TMkrToCenter->setObjectName(QString::fromUtf8("pushButton_TMkrToCenter"));
        sizePolicy3.setHeightForWidth(pushButton_TMkrToCenter->sizePolicy().hasHeightForWidth());
        pushButton_TMkrToCenter->setSizePolicy(sizePolicy3);

        verticalLayout_13->addWidget(pushButton_TMkrToCenter);

        pushButton_peakToLevel = new QPushButton(groupBox_PeaksDips);
        pushButton_peakToLevel->setObjectName(QString::fromUtf8("pushButton_peakToLevel"));
        sizePolicy3.setHeightForWidth(pushButton_peakToLevel->sizePolicy().hasHeightForWidth());
        pushButton_peakToLevel->setSizePolicy(sizePolicy3);

        verticalLayout_13->addWidget(pushButton_peakToLevel);


        verticalLayout_16->addWidget(groupBox_PeaksDips);


        horizontalLayout_10->addLayout(verticalLayout_16);


        verticalLayout_17->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_nameOfFile = new QLabel(centralWidget);
        label_nameOfFile->setObjectName(QString::fromUtf8("label_nameOfFile"));

        horizontalLayout_11->addWidget(label_nameOfFile);

        lineEdit_nameOfFile = new QLineEdit(centralWidget);
        lineEdit_nameOfFile->setObjectName(QString::fromUtf8("lineEdit_nameOfFile"));

        horizontalLayout_11->addWidget(lineEdit_nameOfFile);

        pushButton_exportToFile = new QPushButton(centralWidget);
        pushButton_exportToFile->setObjectName(QString::fromUtf8("pushButton_exportToFile"));

        horizontalLayout_11->addWidget(pushButton_exportToFile);


        verticalLayout_17->addLayout(horizontalLayout_11);


        horizontalLayout_12->addLayout(verticalLayout_17);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 556, 17));
        menuGodDamn = new QMenu(menuBar);
        menuGodDamn->setObjectName(QString::fromUtf8("menuGodDamn"));
        menuSync = new QMenu(menuBar);
        menuSync->setObjectName(QString::fromUtf8("menuSync"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGodDamn->menuAction());
        menuBar->addAction(menuSync->menuAction());
        menuGodDamn->addAction(actionUpdate_COM_ports);
        menuGodDamn->addAction(actionSettings);
        menuGodDamn->addAction(actionHelp_info);
        menuSync->addAction(actionPush_Settings);
        menuSync->addAction(actionPull_Settings);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Anritsu v1.0.0", nullptr));
        actionUpdate_COM_ports->setText(QCoreApplication::translate("MainWindow", "Update COM ports", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        actionHelp_info->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionPush_Settings->setText(QCoreApplication::translate("MainWindow", "Push Settings", nullptr));
        actionPull_Settings->setText(QCoreApplication::translate("MainWindow", "Pull Settings", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "COM port", nullptr));
        pushButton_Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        groupBox_Wavelength->setTitle(QCoreApplication::translate("MainWindow", "Wavelength", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Center (nm)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Span (nm)", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Marker Value", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Value in Vacuum/Air", nullptr));
        groupBox_Level->setTitle(QCoreApplication::translate("MainWindow", "Level", nullptr));
        checkBox_OptAtt->setText(QCoreApplication::translate("MainWindow", "Opt Att", nullptr));
        groupBox_log->setTitle(QCoreApplication::translate("MainWindow", "Log", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "dB/div", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Ref Level (dBm)", nullptr));
        groupBox_linear->setTitle(QCoreApplication::translate("MainWindow", "Linear", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Level", nullptr));
        groupBox_ResolutionVBW->setTitle(QCoreApplication::translate("MainWindow", "Resolution and VBW", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Resolution (nm)", nullptr));
        checkBox_actualRes->setText(QCoreApplication::translate("MainWindow", "Actual Resolution", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "VBW", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Error Message", nullptr));
        groupBox_AverageSampling->setTitle(QCoreApplication::translate("MainWindow", "Average and sampling points", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Point Average", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Sweep Average", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Smooth", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Sampling points", nullptr));
        groupBox_Sweep->setTitle(QCoreApplication::translate("MainWindow", "Sweep", nullptr));
        pushButton_Sweep->setText(QCoreApplication::translate("MainWindow", "Sweep", nullptr));
        groupBox_Memory->setTitle(QCoreApplication::translate("MainWindow", "Memory choice", nullptr));
        radioButton_memoryA->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        radioButton_memoryB->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        pushButton_recieveSpectrum->setText(QCoreApplication::translate("MainWindow", "Recieve Spectrum", nullptr));
        groupBox_PeaksDips->setTitle(QCoreApplication::translate("MainWindow", "Peaks and Dips", nullptr));
        pushButton_peakSearch->setText(QCoreApplication::translate("MainWindow", "Peak Search", nullptr));
        pushButton_dipSearch->setText(QCoreApplication::translate("MainWindow", "Dip Search", nullptr));
        pushButton_peakToCenter->setText(QCoreApplication::translate("MainWindow", "Peak -> Center", nullptr));
        pushButton_TMkrToCenter->setText(QCoreApplication::translate("MainWindow", "TMkr -> Center", nullptr));
        pushButton_peakToLevel->setText(QCoreApplication::translate("MainWindow", "Peak -> Level", nullptr));
        label_nameOfFile->setText(QCoreApplication::translate("MainWindow", "Name of file", nullptr));
        pushButton_exportToFile->setText(QCoreApplication::translate("MainWindow", "Export to File", nullptr));
        menuGodDamn->setTitle(QCoreApplication::translate("MainWindow", "GodDamn", nullptr));
        menuSync->setTitle(QCoreApplication::translate("MainWindow", "Sync", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
