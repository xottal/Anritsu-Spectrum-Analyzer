#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_actionUpdate_COM_ports_triggered();

    serial = new QSerialPort();  // Создать новый объект класса "SerialPort"

    connect(this, SIGNAL(message(QString)),
            this, SLOT(get_message(QString))); // Подключить сигнал получения ответа к слоту
}

MainWindow::~MainWindow()
{
    delete ui;
    delete serial; // Удалить ненужные переменные
}

void MainWindow::on_actionHelp_info_triggered()
{
    help = new HelpWindow(this);
    help->exec();
}

void MainWindow::on_actionUpdate_COM_ports_triggered()
{
    ui->comboBox_ComPort->clear(); // Стереть все имевшиеся старые порты

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) { // Добавление доступных в системе портов
        ui->comboBox_ComPort->addItem(info.portName());
    }

    return;
}

void MainWindow::on_pushButton_Connect_clicked()
{
    if (ui->pushButton_Connect->text() == "Connect") {
        serial->setPortName(ui->comboBox_ComPort->currentText());
        serial->setDataBits(QSerialPort::Data8);
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setParity(QSerialPort::EvenParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);

        if (!serial->open(QIODevice::ReadWrite)) { // Если попытка открыть порт для ввода\вывода не получилось
            QSerialPort::SerialPortError getError = QSerialPort::NoError; // Ошибка открытия порта
            serial->error(getError); // Получить номер ошибки
            emit message(tr("Can't open %1, error code %2").arg(ui->comboBox_ComPort->currentText()).arg(serial->error())); // Выдать сообщение об ошибке
        } else {
            emit message("Connected!");
        }
    } else {
            this->serial->close(); // Закрыть открытый порт
            ui->pushButton_Connect->setText("Connect"); // Перевести кнопку
    }
    return;
}

void MainWindow::get_message(const QString &s)
{
    ui->lineEdit_Greetings->setText(s);
}
