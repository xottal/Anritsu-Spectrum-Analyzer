/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_buzzer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox_autoBacklight;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QComboBox *comboBox_terminater;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLineEdit *lineEdit_error;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(158, 119);
        verticalLayout = new QVBoxLayout(Settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox_buzzer = new QCheckBox(Settings);
        checkBox_buzzer->setObjectName(QString::fromUtf8("checkBox_buzzer"));

        verticalLayout->addWidget(checkBox_buzzer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Settings);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox_autoBacklight = new QSpinBox(Settings);
        spinBox_autoBacklight->setObjectName(QString::fromUtf8("spinBox_autoBacklight"));
        spinBox_autoBacklight->setMinimum(0);
        spinBox_autoBacklight->setMaximum(20);

        horizontalLayout->addWidget(spinBox_autoBacklight);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(Settings);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        comboBox_terminater = new QComboBox(Settings);
        comboBox_terminater->setObjectName(QString::fromUtf8("comboBox_terminater"));
        comboBox_terminater->setEnabled(false);

        horizontalLayout_2->addWidget(comboBox_terminater);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(Settings);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        lineEdit_error = new QLineEdit(Settings);
        lineEdit_error->setObjectName(QString::fromUtf8("lineEdit_error"));
        lineEdit_error->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_error);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Settings", nullptr));
        checkBox_buzzer->setText(QCoreApplication::translate("Settings", "Buzzer", nullptr));
        label->setText(QCoreApplication::translate("Settings", "Auto Backlight (min)", nullptr));
        label_6->setText(QCoreApplication::translate("Settings", "Terminater", nullptr));
        label_7->setText(QCoreApplication::translate("Settings", "Error", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
