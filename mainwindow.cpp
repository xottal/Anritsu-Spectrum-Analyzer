#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_actionUpdate_COM_ports_triggered();
    initialization(false);

    QStringList VacuumAir;
    VacuumAir.push_back("Vacuum");
    VacuumAir.push_back("Air");
    ui->comboBox_VacuumAir->addItems(VacuumAir);

    QStringList MarkerValue;
    MarkerValue.push_back("Wavelength");
    MarkerValue.push_back("Frequency");
    ui->comboBox_MarkerValue->addItems(MarkerValue);

    QStringList LevelScale;
    LevelScale.push_back("Log");
    LevelScale.push_back("Linear");
    ui->comboBox_LogLin->addItems(LevelScale);

    QStringList LinearLevel;
    LinearLevel.push_back("pW");
    LinearLevel.push_back("nW");
    LinearLevel.push_back("microW");
    LinearLevel.push_back("mW");
    ui->comboBox_LinearLevel->addItems(LinearLevel);

    QStringList Resolution;
    Resolution.push_back("0.05");
    Resolution.push_back("0.07");
    Resolution.push_back("0.1");
    Resolution.push_back("0.2");
    Resolution.push_back("0.5");
    Resolution.push_back("1");
    ui->comboBox_Resolution->addItems(Resolution);

    QStringList VBW;
    VBW.push_back("10 Hz");
    VBW.push_back("100 Hz");
    VBW.push_back("1 kHz");
    VBW.push_back("10 kHz");
    VBW.push_back("100 kHz");
    VBW.push_back("1 MHz");
    ui->comboBox_VBW->addItems(VBW);

    QStringList Smooth;
    Smooth.push_back("1");
    Smooth.push_back("3");
    Smooth.push_back("5");
    Smooth.push_back("7");
    Smooth.push_back("11");
    ui->comboBox_Smooth->addItems(Smooth);

    QStringList SamplingPoints;
    SamplingPoints.push_back("51");
    SamplingPoints.push_back("101");
    SamplingPoints.push_back("251");
    SamplingPoints.push_back("501");
    SamplingPoints.push_back("1001");
    SamplingPoints.push_back("2001");
    SamplingPoints.push_back("5001");
    ui->comboBox_SamplingPoints->addItems(SamplingPoints);

    QStringList Sweep;
    Sweep.push_back("Single");
    Sweep.push_back("Repeat");
    ui->comboBox_Sweep->addItems(Sweep);

    serial = new QSerialPort();  // Создать новый объект класса "SerialPort"

    connect(this, SIGNAL(message(QString)),
            this, SLOT(get_message(QString)));
    connect(this, SIGNAL(errorMessage(QString)), this, SLOT(get_error(QString)));// Подключить сигнал получения ответа к слоту
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
            QString idn;
            sendCommand("*IDN?");
            idn = QString(recieveCommand());
            emit message(idn);
            initialization(true);
            ui->pushButton_Connect->setText("Disconnect");
            return;
        }
    } else {
            this->serial->close();
            emit message("Disconnected");// Закрыть открытый порт
            initialization(false);
            ui->pushButton_Connect->setText("Connect"); // Перевести кнопку
    }
    return;
}

void MainWindow::get_message(const QString &s)
{
    ui->lineEdit_Greetings->setText(s);
}

void MainWindow::get_error(const QString &s)
{
    ui->lineEdit_error->setText(s);
}

void MainWindow::initialization(bool bl)
{
    ui->groupBox_Level->setEnabled(bl);
    ui->groupBox_Sweep->setEnabled(bl);
    ui->groupBox_PeaksDips->setEnabled(bl);
    ui->groupBox_Wavelength->setEnabled(bl);
    ui->groupBox_ResolutionVBW->setEnabled(bl);
    ui->groupBox_AverageSampling->setEnabled(bl);
    ui->groupBox_Memory->setEnabled(bl);
}

void MainWindow::settingsPull()
{

}

void MainWindow::sendCommand(const QString &s)
{
    serial->write((s+"\n").toLocal8Bit());
    return;
}

QByteArray MainWindow::recieveCommand()
{
    QByteArray array;
    if(serial->waitForReadyRead(this->firstWaitTime)) {
        array = serial->readAll();
        while(serial->waitForReadyRead(this->additionalWaitTime))
            array += serial->readAll();
    } else {
        emit errorMessage("Wait write request timeout");
    }
    return array;
}

void MainWindow::on_radioButton_memoryA_toggled(bool)
{
    emit message("A");
    return;
}

void MainWindow::on_radioButton_memoryB_toggled(bool)
{
    emit message("B");
    return;
}

void MainWindow::on_pushButton_recieveSpectrum_clicked()
{

}

void MainWindow::on_pushButton_Sweep_clicked()
{
    if(ui->pushButton_Sweep->text() == "Sweep") {
        if(ui->comboBox_Sweep->currentText() == "Single")
            sendCommand("SSI");
        else
            sendCommand("SRT");
        sendCommand("MOD?");
        if((QString(recieveCommand()) == "1")||(QString(recieveCommand()) == "2"))
            ui->pushButton_Sweep->setText("Stop");
    } else {
        sendCommand("SST");
        sendCommand("MOD?");
        if(QString(recieveCommand()) == "0")
            ui->pushButton_Sweep->setText("Sweep");
    }
}
