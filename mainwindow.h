#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTime>
#include <QDebug>
#include <QTest>
#include "helpwindow.h"

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
    void on_actionUpdate_COM_ports_triggered(); // Обновление списка портов

    void on_pushButton_Connect_clicked();
    void get_message(const QString &s);
    void get_error(const QString &s);
    void initialization(bool);
    void settingsPull();
    void sendCommand(const QString &s);
    QByteArray recieveCommand();

    void on_radioButton_memoryA_toggled(bool checked);

    void on_radioButton_memoryB_toggled(bool checked);

    void on_pushButton_recieveSpectrum_clicked();

    void on_pushButton_Sweep_clicked();

signals:
    void message(const QString &s); // Отправка ответа в слот
    void errorMessage(const QString &s);

private:
    Ui::MainWindow *ui;
    HelpWindow *help;

    int firstWaitTime = 100; // Первичное время ожидания новых данных, мс
    int additionalWaitTime = 10; // Дополнительное время ожидания новых данных, мс
    QSerialPort *serial; // SerialPort
};

#endif // MAINWINDOW_H
