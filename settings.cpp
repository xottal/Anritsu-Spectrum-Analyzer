#include "settings.h"
#include "ui_settings.h"


Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    QStringList terminater;
    terminater.push_back("LF,EOI");
    terminater.push_back("CR,LF,EOI");
    ui->comboBox_terminater->addItems(terminater);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::buzzerSlot(bool checked)
{
    if(checked)
        ui->checkBox_buzzer->setChecked(true);
    else
        ui->checkBox_buzzer->setChecked(false);
}

void Settings::autoBacklightSlot(int n)
{
    ui->spinBox_autoBacklight->setValue(n);
}

void Settings::terminaterSlot(int terminater)
{
    if(terminater == 0)
        ui->comboBox_terminater->setCurrentText("LF,EOI");
    else
        ui->comboBox_terminater->setCurrentText("CR,LF,EOI");
}

void Settings::errorSlot(QString error)
{
    ui->lineEdit_error->setText(error);
}

void Settings::buzzerSlotPush()
{
    buzzerSignal(ui->checkBox_buzzer->isChecked());
}

void Settings::autoBacklightSlotPush()
{
    autoBacklightSignal(ui->spinBox_autoBacklight->value());
}

void Settings::terminaterSlotPush()
{
    terminaterSignal(ui->comboBox_terminater->currentText().toInt());
}

void Settings::on_checkBox_buzzer_clicked()
{
    buzzerSignal(ui->checkBox_buzzer->isChecked());
}

void Settings::on_spinBox_autoBacklight_editingFinished()
{
    autoBacklightSignal(ui->spinBox_autoBacklight->value());
}

void Settings::on_comboBox_terminater_activated(const QString &arg1)
{
    terminaterSignal(arg1.toInt());
}
