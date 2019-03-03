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
    LinearLevel.push_back("uW");
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

    connect(this, &MainWindow::message, this, &MainWindow::get_message);
    connect(this, &MainWindow::errorMessage, this, &MainWindow::get_error);

    settings = new Settings(this);
    help = new HelpWindow(this);
    //communication Window->Settings
    connect(this, &MainWindow::buzzerSignal,settings,&Settings::buzzerSlot);
    connect(this, &MainWindow::errorSignal,settings,&Settings::errorSlot);
    connect(this, &MainWindow::autoBacklightSignal,settings,&Settings::autoBacklightSlot);
    connect(this, &MainWindow::terminaterSignal,settings,&Settings::terminaterSlot);
    //communication Settings->Window
    connect(settings, &Settings::buzzerSignal,this,&MainWindow::buzzerSlot);
    connect(settings, &Settings::autoBacklightSignal,this,&MainWindow::autoBacklightSlot);
    connect(settings, &Settings::terminaterSignal,this,&MainWindow::terminaterSlot);
    //communication Window->Settings->Window
    connect(this, &MainWindow::buzzerSignalPush,settings,&Settings::buzzerSlotPush);
    connect(this, &MainWindow::autoBacklightSignalPush,settings,&Settings::autoBacklightSlotPush);
    connect(this, &MainWindow::terminaterSignalPush,settings,&Settings::terminaterSlotPush);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete serial; // Удалить ненужные переменные
}

void MainWindow::on_actionHelp_info_triggered()
{
    help->exec();
}

void MainWindow::on_actionPush_Settings_triggered()
{
    settingsPush();
}

void MainWindow::on_actionPull_Settings_triggered()
{
    settingsPull();
}

void MainWindow::on_actionSettings_triggered()
{
    settings->show();
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
            idn = recieveCommand();
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
    ui->actionSettings->setEnabled(bl);
    ui->actionPull_Settings->setEnabled(bl);
    ui->actionPush_Settings->setEnabled(bl);
}

void MainWindow::settingsPull()
{
    //memory select
    QString memorySelect;
    sendCommand("MSL?");
    memorySelect = recieveCommand();
    if(memorySelect == "A") {
        ui->radioButton_memoryA->setChecked(true);
        ui->radioButton_memoryB->setChecked(false);
    }
    else {
        ui->radioButton_memoryA->setChecked(false);
        ui->radioButton_memoryB->setChecked(true);
    }

    //wavelength
    double center;
    sendCommand("CNT?");
    center = recieveCommand().toDouble();
    ui->doubleSpinBox_Center->setValue(center);

    double span;
    sendCommand("SPN?");
    span = recieveCommand().toDouble();
    ui->doubleSpinBox_Span->setValue(span);

    QString markerValue;
    sendCommand("MKV?");
    markerValue = recieveCommand();
    if(markerValue == "WL")
        ui->comboBox_MarkerValue->setCurrentText("Wavelength");
    if(markerValue == "FREQ")
        ui->comboBox_MarkerValue->setCurrentText("Frequency");

    QString valueInVacuum;
    sendCommand("WDP?");
    valueInVacuum = recieveCommand();
    if(valueInVacuum == "VACUUM")
        ui->comboBox_VacuumAir->setCurrentText("Vacuum");
    if(valueInVacuum == "AIR")
        ui->comboBox_VacuumAir->setCurrentText("Air");

    //level
    QString levelScale;
    sendCommand("LVS?");
    levelScale = recieveCommand();
    if(levelScale == "LOG") {
        ui->comboBox_LogLin->setCurrentText("Log");
        ui->groupBox_log->setEnabled(true);
        ui->groupBox_linear->setEnabled(false);

        double logDiv;
        sendCommand("LOG?");
        logDiv = recieveCommand().toDouble();
        ui->doubleSpinBox_dBdiv->setValue(logDiv);

        double refLevel;
        sendCommand("RLV?");
        refLevel = recieveCommand().toDouble();
        ui->doubleSpinBox_Ref_Level->setValue(refLevel);
    }
    if(levelScale == "LIN") {
        ui->comboBox_LogLin->setCurrentText("Linear");
        ui->groupBox_linear->setEnabled(true);
        ui->groupBox_log->setEnabled(false);

        //НЕОБХОДИМО ПОСМОТРЕТЬ ВИД ВЫВОДА!!!!!!
        double linear;
        sendCommand("LLV?");
        linear = recieveCommand().toDouble();
        ui->doubleSpinBox_LinearLevel->setValue(linear);
        ui->comboBox_LinearLevel->setCurrentText("mW");
    }

    QString optAtt;
    sendCommand("ATT?");
    optAtt = recieveCommand();
    if(optAtt == "ON")
        ui->checkBox_OptAtt->setChecked(true);
    if(optAtt == "OFF")
        ui->checkBox_OptAtt->setChecked(false);

    //resolution
    QString res;
    sendCommand("RES?");
    res = recieveCommand();
    for(int i = 0; i < ui->comboBox_Resolution->count(); i++) {
        if(res == ui->comboBox_Resolution->itemText(i)) {
            ui->comboBox_Resolution->setCurrentIndex(i);
            break;
        }
    }

    QString actualRes;
    sendCommand("ARES?");
    actualRes = recieveCommand();
    if(actualRes == "ON")
        ui->checkBox_actualRes->setChecked(true);
    if(actualRes == "OFF")
        ui->checkBox_actualRes->setChecked(false);

    QString actualResValue;
    sendCommand("ARED?");
    actualResValue = recieveCommand();
    ui->lineEdit_ActualResolution->setText(actualResValue);

    //video bandwidth
    //НЕОБХОДИМО ПОСМОТРЕТЬ ВИД ВЫВОДА!!!!!!
    QString VBW;
    sendCommand("VBW?");
    VBW = recieveCommand();
    ui->comboBox_VBW->setCurrentText(VBW);

    //average
    QString pointAverage;
    sendCommand("AVT?");
    pointAverage = recieveCommand();
    if(pointAverage == "OFF")
        ui->spinBox_PointAverage->setValue(1);
    else
        ui->spinBox_PointAverage->setValue(pointAverage.toInt());

    QString sweepAverage;
    sendCommand("AVS?");
    sweepAverage = recieveCommand();
    if(sweepAverage == "OFF")
        ui->spinBox_SweepAverage->setValue(1);
    else
        ui->spinBox_SweepAverage->setValue(sweepAverage.toInt());

    QString smooth;
    sendCommand("SMT?");
    smooth = recieveCommand();
    if(smooth == "OFF")
        ui->comboBox_Smooth->setCurrentText("1");
    else
        ui->comboBox_Smooth->setCurrentText(smooth);

    //sampling points
    QString samlpingPoints;
    sendCommand("MPT?");
    samlpingPoints = recieveCommand();
    for(int i = 0; i < ui->comboBox_SamplingPoints->count(); i++) {
        if(samlpingPoints == ui->comboBox_SamplingPoints->itemText(i)) {
            ui->comboBox_SamplingPoints->setCurrentIndex(i);
            break;
        }
    }

    //settings
    QString buzzer;
    sendCommand("BUZ?");
    buzzer = recieveCommand();
    if(buzzer == "ON")
        emit buzzerSignal(true);
    if(buzzer == "OFF")
        emit buzzerSignal(false);

    QString error;
    sendCommand("ERR?");
    error = recieveCommand();
    emit errorSignal(error);

    int terminater;
    sendCommand("TRM?");
    terminater = recieveCommand().toInt();
    emit terminaterSignal(terminater);

    int autoBacklight;
    sendCommand("BKL?");
    autoBacklight = recieveCommand().toInt();
    emit autoBacklightSignal(autoBacklight);
}

void MainWindow::settingsPush()
{
    //memory select
    if(ui->radioButton_memoryA->isChecked())
        sendCommand("MSL A");
    else
        sendCommand("MSL B");

    //wavelength
    sendCommand(QString("CNT %1").arg(ui->doubleSpinBox_Center->value(),0,'g',6));
    sendCommand(QString("SPN %1").arg(ui->doubleSpinBox_Span->value(),0,'g',5));

    QString markerValue;
    markerValue = ui->comboBox_MarkerValue->currentText();
    if(markerValue == "Wavelength")
        sendCommand("MKV WL");
    if(markerValue == "Frequency")
        sendCommand("MKV FREQ");

    QString valueInVacuum;
    valueInVacuum = ui->comboBox_VacuumAir->currentText();
    if(valueInVacuum == "Vacuum")
        sendCommand("WDP VACUUM");
    if(valueInVacuum == "Air")
        sendCommand("WDP AIR");

    //level
    QString levelScale;
    levelScale = ui->comboBox_LogLin->currentText();
    if(levelScale == "Log") {
        sendCommand(QString("LOG %1").arg(ui->doubleSpinBox_dBdiv->value(),0,'g',3));
        sendCommand(QString("RLV %1").arg(ui->doubleSpinBox_Ref_Level->value(),0,'g',3));
    }
    if(levelScale == "Linear") {
        if(ui->comboBox_LinearLevel->currentText() == "pW")
            sendCommand(QString("LLV %1PW").arg(ui->doubleSpinBox_LinearLevel->value(),0,'g',4));
        if(ui->comboBox_LinearLevel->currentText() == "nW")
            sendCommand(QString("LLV %1NW").arg(ui->doubleSpinBox_LinearLevel->value(),0,'g',4));
        if(ui->comboBox_LinearLevel->currentText() == "uW")
            sendCommand(QString("LLV %1UW").arg(ui->doubleSpinBox_LinearLevel->value(),0,'g',4));
        if(ui->comboBox_LinearLevel->currentText() == "mW")
            sendCommand(QString("LLV %1MW").arg(ui->doubleSpinBox_LinearLevel->value(),0,'g',4));
    }

    if(ui->checkBox_OptAtt->isChecked())
        sendCommand("ATT ON");
    else
        sendCommand("ATT OFF");

    //resolution
    sendCommand("RES "+ui->comboBox_Resolution->currentText());

    if(ui->checkBox_actualRes->isChecked())
        sendCommand("ARES ON");
    else
        sendCommand("ARES OFF");

    //video bandwidth
    sendCommand("VBW "+ui->comboBox_VBW->currentText());

    //average
    if(ui->spinBox_PointAverage->value() == 1)
        sendCommand("AVT OFF");
    else
        sendCommand("AVT "+QString(ui->spinBox_PointAverage->value()));

    if(ui->spinBox_SweepAverage->value() == 1)
        sendCommand("AVS OFF");
    else
        sendCommand("AVS "+QString(ui->spinBox_SweepAverage->value()));

    if(ui->comboBox_Sweep->currentText() == "1")
        sendCommand("SMT OFF");
    else
        sendCommand("SMT "+ui->comboBox_Sweep->currentText());

    //sampling points
    sendCommand("MPT "+ui->comboBox_SamplingPoints->currentText());

    emit autoBacklightSignalPush();
    emit buzzerSignalPush();
    emit terminaterSignalPush();
}

void MainWindow::sendCommand(const QString &s)
{
    serial->write((s+"\n").toLocal8Bit());
    return;
}

QString MainWindow::recieveCommand()
{
    QByteArray array;
    if(serial->waitForReadyRead(this->firstWaitTime)) {
        array = serial->readAll();
        while(serial->waitForReadyRead(this->additionalWaitTime))
            array += serial->readAll();
    } else {
        emit errorMessage("Wait write request timeout");
    }
//    array.chop(1);
    return QString(array);
}

void MainWindow::on_pushButton_recieveSpectrum_clicked()
{
    if(ui->radioButton_memoryA->isChecked())
        sendCommand("DQA?");
    else
        sendCommand("DQB?");
    QString spectrum = recieveCommand();
    QRegExp rx(",");
    QStringList spct = spectrum.split(rx);
    emit message(spectrum);
}

void MainWindow::on_pushButton_Sweep_clicked()
{
    if(ui->pushButton_Sweep->text() == "Sweep") {
        if(ui->comboBox_Sweep->currentText() == "Single")
            sendCommand("SSI");
        else
            sendCommand("SRT");
        sendCommand("MOD?");
        if((recieveCommand() == "1")||(recieveCommand() == "2"))
            ui->pushButton_Sweep->setText("Stop");
    } else {
        sendCommand("SST");
        sendCommand("MOD?");
        if(recieveCommand() == "0")
            ui->pushButton_Sweep->setText("Sweep");
    }
}

void MainWindow::buzzerSlot(bool checked)
{
    if(checked)
        sendCommand("BUZ ON");
    else
        sendCommand("BUZ OFF");
}

void MainWindow::autoBacklightSlot(int n)
{
    sendCommand("BKL " + QString(n));
}

void MainWindow::terminaterSlot(int terminater)
{
    sendCommand("TRM " + QString(terminater));
}

void MainWindow::on_radioButton_memoryA_toggled(bool)
{
    sendCommand("MSL A");
    settingsPull();
}

void MainWindow::on_radioButton_memoryB_toggled(bool)
{
    sendCommand("MSL B");
    settingsPull();
}

void MainWindow::on_doubleSpinBox_Center_editingFinished()
{
    sendCommand(QString("CNT %1").arg(ui->doubleSpinBox_Center->value(),0,'g',6));
}

void MainWindow::on_doubleSpinBox_Span_editingFinished()
{
    sendCommand(QString("SPN %1").arg(ui->doubleSpinBox_Span->value(),0,'g',5));
}

void MainWindow::on_comboBox_MarkerValue_activated(const QString &arg1)
{
    if(arg1 == "Wavelength")
        sendCommand("MKV WL");
    else
        sendCommand("MKV FREQ");
}

void MainWindow::on_comboBox_VacuumAir_activated(const QString &arg1)
{
    if(arg1 == "Vacuum")
       sendCommand("WDP VACUUM");
    else
        sendCommand("WDP AIR");
}

void MainWindow::on_comboBox_LogLin_activated(const QString &arg1)
{
    if(arg1 == "Log") {
        sendCommand(QString("LOG %1").arg(ui->doubleSpinBox_dBdiv->value(),0,'g',3));
        sendCommand(QString("RLV %1").arg(ui->doubleSpinBox_Ref_Level->value(),0,'g',3));
        ui->groupBox_linear->setEnabled(false);
        ui->groupBox_log->setEnabled(true);
    }
    else {
            sendCommand(QString("LLV %1PW").arg(ui->doubleSpinBox_LinearLevel->value(),0,'g',4));
        if(ui->comboBox_LinearLevel->currentText() == "nW")
            sendCommand(QString("LLV %1NW").arg(ui->doubleSpinBox_LinearLevel->value(),0,'g',4));
        if(ui->comboBox_LinearLevel->currentText() == "uW")
            sendCommand(QString("LLV %1UW").arg(ui->doubleSpinBox_LinearLevel->value(),0,'g',4));
        if(ui->comboBox_LinearLevel->currentText() == "mW")
            sendCommand(QString("LLV %1MW").arg(ui->doubleSpinBox_LinearLevel->value(),0,'g',4));
        ui->groupBox_log->setEnabled(false);
        ui->groupBox_linear->setEnabled(true);
    }
}

void MainWindow::on_checkBox_OptAtt_clicked()
{
    if(ui->checkBox_OptAtt->isChecked())
        sendCommand("ATT ON");
    else
        sendCommand("ATT OFF");
}

void MainWindow::on_doubleSpinBox_dBdiv_editingFinished()
{
    sendCommand(QString("LOG %1").arg(ui->doubleSpinBox_dBdiv->value(),0,'g',3));
}

void MainWindow::on_doubleSpinBox_Ref_Level_editingFinished()
{
    sendCommand(QString("RLV %1").arg(ui->doubleSpinBox_Ref_Level->value(),0,'g',3));
}

void MainWindow::on_doubleSpinBox_LinearLevel_editingFinished()
{
    if(ui->comboBox_LinearLevel->currentText() == "pW")
        sendCommand(QString("LLV %1PW").arg(ui->doubleSpinBox_Span->value(),0,'g',4));
    if(ui->comboBox_LinearLevel->currentText() == "nW")
        sendCommand(QString("LLV %1NW").arg(ui->doubleSpinBox_Span->value(),0,'g',4));
    if(ui->comboBox_LinearLevel->currentText() == "uW")
        sendCommand(QString("LLV %1UW").arg(ui->doubleSpinBox_Span->value(),0,'g',4));
    if(ui->comboBox_LinearLevel->currentText() == "mW")
        sendCommand(QString("LLV %1MW").arg(ui->doubleSpinBox_Span->value(),0,'g',4));
}

void MainWindow::on_comboBox_LinearLevel_activated(const QString &arg1)
{
    if(arg1 == "pW")
        sendCommand(QString("LLV %1PW").arg(ui->doubleSpinBox_LinearLevel->value(),0,'g',4));
    if(arg1 == "nW")
        sendCommand(QString("LLV %1NW").arg(ui->doubleSpinBox_LinearLevel->value(),0,'g',4));
    if(arg1 == "uW")
        sendCommand(QString("LLV %1UW").arg(ui->doubleSpinBox_LinearLevel->value(),0,'g',4));
    if(arg1 == "mW")
        sendCommand(QString("LLV %1MW").arg(ui->doubleSpinBox_LinearLevel->value(),0,'g',4));
}

void MainWindow::on_comboBox_Resolution_activated(const QString &arg1)
{
    sendCommand("RES " + arg1);
}

void MainWindow::on_checkBox_actualRes_clicked()
{
    if(ui->checkBox_actualRes->isChecked())
        sendCommand("ARES ON");
    else
        sendCommand("ARES OFF");
}

void MainWindow::on_comboBox_VBW_activated(const QString &arg1)
{
    sendCommand(arg1);
}

void MainWindow::on_spinBox_PointAverage_editingFinished()
{
    if(ui->spinBox_PointAverage->value() == 1)
        sendCommand("AVT OFF");
    else
        sendCommand("AVT " + QString(ui->spinBox_PointAverage->value()));
}

void MainWindow::on_spinBox_SweepAverage_editingFinished()
{
    if(ui->spinBox_SweepAverage->value() == 1)
        sendCommand("AVS OFF");
    else
        sendCommand("AVS " + QString(ui->spinBox_SweepAverage->value()));
}

void MainWindow::on_comboBox_Smooth_activated(const QString &arg1)
{
    if(arg1 == "1")
        sendCommand("SMT OFF");
    else
        sendCommand("SMT " + arg1);
}

void MainWindow::on_comboBox_SamplingPoints_activated(const QString &arg1)
{
    sendCommand("MPT " + arg1);
}
