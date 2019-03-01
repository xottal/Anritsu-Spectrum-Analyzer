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

signals:
    void message(const QString &s); // Отправка ответа в слот

private:
    Ui::MainWindow *ui;
    HelpWindow *help;

    int firstWaitTime = 500; // Первичное время ожидания новых данных, мс
    int additionalWaitTime = 10; // Дополнительное время ожидания новых данных, мс
    QSerialPort *serial; // SerialPort
};

#endif // MAINWINDOW_H
