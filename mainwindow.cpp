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
    VBW.push_back("10HZ");
    VBW.push_back("100HZ");
    VBW.push_back("1KHZ");
    VBW.push_back("10KHZ");
    VBW.push_back("100KHZ");
    VBW.push_back("1MHZ");
    ui->comboBox_VBW->addItems(VBW);

    QStringList Smooth;
    Smooth.push_back("1");
    Smooth.push_back("3");
    Smooth.push_back("5");
    Smooth.push_back("7");
    Smooth.push_back("9");
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

    connect(this, &MainWindow::message, this, &MainWindow::get_message);
    connect(this, &MainWindow::errorMessage, this, &MainWindow::get_error);

    settings = new Settings(this);
    help = new HelpWindow(this);
    anritsu = new AnritsuMS9710C();

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

    connect(anritsu,&AnritsuMS9710C::errorMessage,this,&MainWindow::get_error);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete help;
    delete settings;
    delete anritsu;
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
    ui->comboBox_ComPort->clear();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->comboBox_ComPort->addItem(info.portName());
    }
}

void MainWindow::on_pushButton_Connect_clicked()
{
    if (ui->pushButton_Connect->text() == "Connect") {
        if (!anritsu->connectSerialPort(ui->comboBox_ComPort->currentText())) {
            emit message(tr("Can't open %1, error code %2").arg(ui->comboBox_ComPort->currentText()).arg(anritsu->serialError()));
            return;
        } else {
            emit message(anritsu->identifecation());
            initialization(true);
            ui->pushButton_Connect->setText("Disconnect");
            settingsPull();
            ui->widget_graph->addGraph();
            if(ui->comboBox_LogLin->currentText() == "Log")
                ui->widget_graph->yAxis->setLabel("dB/div");
            else {
                ui->widget_graph->yAxis->setLabel(ui->comboBox_LinearLevel->currentText());
            }
            ui->widget_graph->xAxis->setLabel("nm");
            ui->widget_graph->xAxis->setRange(ui->doubleSpinBox_Center->value()-ui->doubleSpinBox_Span->value()/2.0,ui->doubleSpinBox_Center->value()+ui->doubleSpinBox_Span->value()/2.0);
            ui->widget_graph->replot();
            return;
        }
    } else {
            anritsu->disconnectSerialPort();
            emit message("Disconnected");// Закрыть открытый порт
            initialization(false);
            ui->pushButton_Connect->setText("Connect"); // Перевести кнопку
    }
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
    ui->lineEdit_nameOfFile->setEnabled(bl);
    ui->label_nameOfFile->setEnabled(bl);
    ui->pushButton_exportToFile->setEnabled(bl);
    ui->pushButton_recieveSpectrum->setEnabled(bl);
}

void MainWindow::settingsPull()
{
    //memory select
    if(anritsu->memorySelect() == "A") {
        ui->radioButton_memoryA->setChecked(true);
        ui->radioButton_memoryB->setChecked(false);
    }
    else {
        ui->radioButton_memoryA->setChecked(false);
        ui->radioButton_memoryB->setChecked(true);
    }

    //wavelength
    ui->doubleSpinBox_Center->setValue(anritsu->centralWavelength());
    ui->doubleSpinBox_Span->setValue(anritsu->span());
    ui->comboBox_MarkerValue->setCurrentText(anritsu->markerValue());
    ui->comboBox_VacuumAir->setCurrentText(anritsu->valueInVacuum());

    //level
    if(anritsu->levelScale() == "LOG") {
        ui->comboBox_LogLin->setCurrentText("Log");
        ui->groupBox_log->setEnabled(true);
        ui->groupBox_linear->setEnabled(false);
        ui->doubleSpinBox_dBdiv->setValue(anritsu->dbDiv());
        ui->doubleSpinBox_Ref_Level->setValue(anritsu->refLevel());
    }
    else {
        ui->comboBox_LogLin->setCurrentText("Linear");
        ui->groupBox_linear->setEnabled(true);
        ui->groupBox_log->setEnabled(false);
        std::pair<QString,double> par = anritsu->linearLevel();
        ui->comboBox_LinearLevel->setCurrentText(par.first);
        ui->doubleSpinBox_LinearLevel->setValue(par.second);
    }
    ui->checkBox_OptAtt->setChecked(anritsu->optAtt());

    //resolution
    QString res = anritsu->resolution();
    for(int i = 0; i < ui->comboBox_Resolution->count(); i++) {
        if(res == ui->comboBox_Resolution->itemText(i)) {
            ui->comboBox_Resolution->setCurrentIndex(i);
            break;
        }
    }

    ui->checkBox_actualRes->setChecked(anritsu->actualResolution());
    ui->lineEdit_ActualResolution->setText(anritsu->actualResolutionValue());

    //video bandwidth
    ui->comboBox_VBW->setCurrentText(anritsu->videoBandwidth());

    //average
    ui->spinBox_PointAverage->setValue(anritsu->pointAverage());
    ui->spinBox_SweepAverage->setValue(anritsu->sweepAverage());
    ui->comboBox_Smooth->setCurrentText(anritsu->smooth());

    //sampling points
    ui->comboBox_SamplingPoints->setCurrentText(anritsu->samplingPoints());

    //settings
    emit buzzerSignal(anritsu->buzzer());
    emit errorSignal(anritsu->error());
    emit terminaterSignal(anritsu->terminater());
    emit autoBacklightSignal(anritsu->autoBacklight());

    ui->widget_graph->replot();

    emit message("Sync finished");
}

void MainWindow::settingsPush()
{
    anritsu->memorySelect(ui->radioButton_memoryA->isChecked());
    anritsu->centralWavelength(ui->doubleSpinBox_Center->value());
    anritsu->span(ui->doubleSpinBox_Span->value());
    anritsu->markerValue(ui->comboBox_MarkerValue->currentText());
    anritsu->valueInVacuum(ui->comboBox_VacuumAir->currentText());

    QString levelScale;
    levelScale = ui->comboBox_LogLin->currentText();
    if(levelScale == "Log") {
        anritsu->dbDiv(ui->doubleSpinBox_dBdiv->value());
        anritsu->refLevel(ui->doubleSpinBox_Ref_Level->value());
    }
    if(levelScale == "Linear") {
        std::pair<QString,double> pair;
        pair.first = ui->comboBox_LinearLevel->currentText();
        pair.second = ui->doubleSpinBox_LinearLevel->value();
        anritsu->linearLevel(pair);
    }
    anritsu->optAtt(ui->checkBox_OptAtt->isChecked());
    anritsu->resoluiton(ui->comboBox_Resolution->currentText());
    anritsu->actualResolution(ui->checkBox_actualRes->isChecked());
    anritsu->videoBandwidth(ui->comboBox_VBW->currentText());
    anritsu->pointAverage(ui->spinBox_PointAverage->value());
    anritsu->sweepAverage(ui->spinBox_SweepAverage->value());
    anritsu->smooth(ui->comboBox_Sweep->currentText());

    //sampling points
    anritsu->samplingPoints(ui->comboBox_SamplingPoints->currentText());
    emit autoBacklightSignalPush();
    emit buzzerSignalPush();
    emit terminaterSignalPush();
}

void MainWindow::on_pushButton_recieveSpectrum_clicked()
{
    QString spectrum = anritsu->receiveSpectrum(ui->radioButton_memoryA->isChecked());
    QRegExp rx(",");
    QStringList spec = spectrum.split(rx);
    for(int i = 0; i < spec.size(); i++)
        y.push_back(spec[i].toDouble());
    for (int i = 0; i<spec.size(); i++)
        x[i] = ui->doubleSpinBox_Center->value()-ui->doubleSpinBox_Span->value()/2+ui->doubleSpinBox_Span->value()*double(i)/double(ui->comboBox_SamplingPoints->currentText().toInt());
    ui->widget_graph->graph(0)->setData(x,y);
    if(ui->comboBox_LogLin->currentText() == "Log")
        ui->widget_graph->yAxis->setLabel("dB/div");
    else {
        ui->widget_graph->yAxis->setLabel(ui->comboBox_LinearLevel->currentText());
    }
    ui->widget_graph->xAxis->setLabel("nm");
    ui->widget_graph->xAxis->setRange(ui->doubleSpinBox_Center->value()-ui->doubleSpinBox_Span->value()/2.0,ui->doubleSpinBox_Center->value()+ui->doubleSpinBox_Span->value()/2.0);
    ui->widget_graph->replot();
}

void MainWindow::on_pushButton_Sweep_clicked()
{
    if(ui->pushButton_Sweep->text() == "Sweep") {
        if(ui->comboBox_Sweep->currentText() == "Single")
            anritsu->singleSweep();
        else
            anritsu->repeatSweep();
        ui->pushButton_Sweep->setText("Stop");
    } else {
        anritsu->stopSweep();
        ui->pushButton_Sweep->setText("Sweep");
    }
}

void MainWindow::buzzerSlot(bool checked)
{
    anritsu->buzzer(checked);
}

void MainWindow::autoBacklightSlot(int n)
{
    anritsu->autoBacklight(n);
}

void MainWindow::terminaterSlot(int terminater)
{
    anritsu->terminater(terminater);
}

void MainWindow::on_radioButton_memoryA_clicked()
{
    anritsu->memorySelect(true);
    ui->radioButton_memoryA->setChecked(true);
    QTest::qWait(5000);
    settingsPull();
}

void MainWindow::on_radioButton_memoryB_clicked()
{
    anritsu->memorySelect(false);
    ui->radioButton_memoryB->setChecked(true);
    QTest::qWait(5000);
    settingsPull();
}

void MainWindow::on_doubleSpinBox_Center_editingFinished()
{
    anritsu->centralWavelength(ui->doubleSpinBox_Center->value());
}

void MainWindow::on_doubleSpinBox_Span_editingFinished()
{
    anritsu->span(ui->doubleSpinBox_Span->value());
}

void MainWindow::on_comboBox_MarkerValue_activated(const QString &arg1)
{
    anritsu->markerValue(arg1);
}

void MainWindow::on_comboBox_VacuumAir_activated(const QString &arg1)
{
    anritsu->valueInVacuum(arg1);
}

void MainWindow::on_comboBox_LogLin_activated(const QString &arg1)
{
    if(arg1 == "Log") {
        anritsu->dbDiv(ui->doubleSpinBox_dBdiv->value());
        anritsu->refLevel(ui->doubleSpinBox_Ref_Level->value());
        ui->groupBox_linear->setEnabled(false);
        ui->groupBox_log->setEnabled(true);
    }
    else {
        std::pair<QString,double> pair;
        pair.first = ui->comboBox_LinearLevel->currentText();
        pair.second = ui->doubleSpinBox_LinearLevel->value();
        anritsu->linearLevel(pair);
        ui->groupBox_log->setEnabled(false);
        ui->groupBox_linear->setEnabled(true);
    }
}

void MainWindow::on_checkBox_OptAtt_clicked()
{
    anritsu->optAtt(ui->checkBox_OptAtt->isChecked());
}

void MainWindow::on_doubleSpinBox_dBdiv_editingFinished()
{
    anritsu->dbDiv(ui->doubleSpinBox_dBdiv->value());
}

void MainWindow::on_doubleSpinBox_Ref_Level_editingFinished()
{
    anritsu->refLevel(ui->doubleSpinBox_Ref_Level->value());
}

void MainWindow::on_doubleSpinBox_LinearLevel_editingFinished()
{
    std::pair<QString,double> pair;
    pair.first = ui->comboBox_LinearLevel->currentText();
    pair.second = ui->doubleSpinBox_LinearLevel->value();
    anritsu->linearLevel(pair);
}

void MainWindow::on_comboBox_LinearLevel_activated(const QString &arg1)
{
    std::pair<QString,double> pair;
    pair.first = arg1;
    pair.second = ui->doubleSpinBox_LinearLevel->value();
    anritsu->linearLevel(pair);
}

void MainWindow::on_comboBox_Resolution_activated(const QString &arg1)
{
    anritsu->resoluiton(arg1);
}

void MainWindow::on_checkBox_actualRes_clicked()
{
    anritsu->actualResolution(ui->checkBox_actualRes->isChecked());
}

void MainWindow::on_comboBox_VBW_activated(const QString &arg1)
{
    anritsu->videoBandwidth(arg1);
}

void MainWindow::on_spinBox_PointAverage_editingFinished()
{
    anritsu->pointAverage(ui->spinBox_PointAverage->value());
}

void MainWindow::on_spinBox_SweepAverage_editingFinished()
{
    anritsu->sweepAverage(ui->spinBox_SweepAverage->value());
}
void MainWindow::on_comboBox_Smooth_activated(const QString &arg1)
{
    anritsu->smooth(arg1);
}

void MainWindow::on_comboBox_SamplingPoints_activated(const QString &arg1)
{
    anritsu->samplingPoints(arg1);
}

void MainWindow::on_pushButton_exportToFile_clicked()
{
    QFile file(ui->lineEdit_nameOfFile->text()+".dat"+QTime::currentTime().toString());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    QTextStream out(&file);
    if(ui->comboBox_LogLin->currentText() == "Log")
        out << "nm" << '\t' << "dB/div" << "\r\n";
    else
        out << "nm" << '\t' << "mW" << "\r\n";
    for(int i = 0; x.size(); i++)
        out << x[i] << '\t' << y[i] << "\r\n";
    file.close();
}

void MainWindow::on_pushButton_peakSearch_clicked()
{
    anritsu->peakSearch();
}

void MainWindow::on_pushButton_dipSearch_clicked()
{
    anritsu->dipSearch();
}

void MainWindow::on_pushButton_peakToCenter_clicked()
{
    anritsu->peakCenter();
}

void MainWindow::on_pushButton_TMkrToCenter_clicked()
{
    anritsu->tMkrCenter();
}

void MainWindow::on_pushButton_peakToLevel_clicked()
{
    anritsu->peakLevel();
}
