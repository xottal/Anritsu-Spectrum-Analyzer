#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTime>
#include <QDebug>
#include <QDir>
#include "helpwindow.h"
#include "settings.h"
#include "anritsums9710c.h"
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionHelp_info_triggered(); //Вызов окна Help
    void on_actionSettings_triggered();
    void on_actionUpdate_COM_ports_triggered(); // Обновление списка портов
    void on_actionPush_Settings_triggered();
    void on_actionPull_Settings_triggered();

    void on_pushButton_Connect_clicked();
    void get_message(const QString &s);
    void get_error(const QString &s);
    void initialization(bool);
    void settingsPull();
    void settingsPush();

    void on_radioButton_memoryA_clicked();

    void on_radioButton_memoryB_clicked();

    void on_pushButton_recieveSpectrum_clicked();

    void on_pushButton_Sweep_clicked();

    //settings slots
    void buzzerSlot(bool);
    void autoBacklightSlot(int);
    void terminaterSlot(int);

    void on_doubleSpinBox_Center_editingFinished();

    void on_doubleSpinBox_Span_editingFinished();

    void on_comboBox_MarkerValue_activated(const QString &arg1);

    void on_comboBox_VacuumAir_activated(const QString &arg1);

    void on_comboBox_LogLin_activated(const QString &arg1);

    void on_checkBox_OptAtt_clicked();

    void on_doubleSpinBox_dBdiv_editingFinished();

    void on_doubleSpinBox_Ref_Level_editingFinished();

    void on_doubleSpinBox_LinearLevel_editingFinished();

    void on_comboBox_LinearLevel_activated(const QString &arg1);

    void on_comboBox_Resolution_activated(const QString &arg1);

    void on_checkBox_actualRes_clicked();

    void on_comboBox_VBW_activated(const QString &arg1);

    void on_spinBox_PointAverage_editingFinished();

    void on_spinBox_SweepAverage_editingFinished();

    void on_comboBox_Smooth_activated(const QString &arg1);

    void on_comboBox_SamplingPoints_activated(const QString &arg1);

    void on_pushButton_exportToFile_clicked();

    void on_pushButton_peakSearch_clicked();

    void on_pushButton_dipSearch_clicked();

    void on_pushButton_peakToCenter_clicked();

    void on_pushButton_TMkrToCenter_clicked();

    void on_pushButton_peakToLevel_clicked();

signals:
    void message(const QString &s); // Отправка ответа в слот
    void errorMessage(const QString &s);

    //settings signals
    void buzzerSignal(bool);
    void autoBacklightSignal(int);
    void terminaterSignal(int);
    void errorSignal(QString);

    void buzzerSignalPush();
    void autoBacklightSignalPush();
    void terminaterSignalPush();

private:
    Ui::MainWindow *ui;
    HelpWindow *help;
    Settings *settings;

    int firstWaitTime = 500; // Первичное время ожидания новых данных, мс
    int additionalWaitTime = 10; // Дополнительное время ожидания новых данных, мс
    AnritsuMS9710C *anritsu;

    QVector<double> x,y;
};

#endif // MAINWINDOW_H
