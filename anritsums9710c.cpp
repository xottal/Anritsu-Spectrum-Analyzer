#include "anritsums9710c.h"

AnritsuMS9710C::AnritsuMS9710C()
{
    serial = new QSerialPort();
}

AnritsuMS9710C::~AnritsuMS9710C()
{
    delete serial;
}

bool AnritsuMS9710C::connectSerialPort(const QString &s)
{
    serial->setPortName(s);
    serial->setDataBits(QSerialPort::Data8);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setParity(QSerialPort::EvenParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    return serial->open(QIODevice::ReadWrite);
}

void AnritsuMS9710C::disconnectSerialPort()
{
    serial->close();
}

QSerialPort::SerialPortError AnritsuMS9710C::serialError()
{
    QSerialPort::SerialPortError getError = QSerialPort::NoError;
    serial->error(getError);
    return serial->error();
}

QString AnritsuMS9710C::identifecation()
{
    sendCommand("*IDN?");
    return(receiveCommand());
}

QString AnritsuMS9710C::valueInVacuum()
{
    sendCommand("WDP?");
    QString valueInVacuum = receiveCommand();
    if(valueInVacuum == "VACUUM")
        return "Vacuum";
    else
        return "Air";
}

void AnritsuMS9710C::valueInVacuum(const QString &s)
{
    if(s == "Vacuum")
        sendCommand("WDP VACUUM");
    else
        sendCommand("WDP AIR");
}

QString AnritsuMS9710C::levelScale()
{
    sendCommand("LVS?");
    return receiveCommand();
}

double AnritsuMS9710C::dbDiv()
{
    sendCommand("LOG?");
    return receiveCommand().toDouble();
}

void AnritsuMS9710C::dbDiv(const double &d)
{
     sendCommand(QString("LOG %1").arg(d,0,'g',3));
}

double AnritsuMS9710C::refLevel()
{
    sendCommand("RLV?");
    return receiveCommand().toDouble();
}

void AnritsuMS9710C::refLevel(const double &d)
{
    sendCommand(QString("RLV %1").arg(d,0,'g',3));
}

std::pair<QString, double> AnritsuMS9710C::linearLevel()
{
    std::pair<QString,double> par;
    QString linear;
    sendCommand("LLV?");
    linear = receiveCommand();
    if(linear.contains("MW"))
        par.first = "mW";
    if(linear.contains("NW"))
        par.first = "nW";
    if(linear.contains("UW"))
        par.first = "uW";
    if(linear.contains("PW"))
        par.first = "pW";
    linear.chop(2);
    par.second = linear.toDouble();
    return par;
}

void AnritsuMS9710C::linearLevel(const std::pair<QString, double> &p)
{
    if(p.first == "pW")
        sendCommand(QString("LLV %1PW").arg(p.second,0,'g',4));
    if(p.first == "nW")
        sendCommand(QString("LLV %1NW").arg(p.second,0,'g',4));
    if(p.first == "uW")
        sendCommand(QString("LLV %1UW").arg(p.second,0,'g',4));
    if(p.first == "mW")
        sendCommand(QString("LLV %1MW").arg(p.second,0,'g',4));
}

bool AnritsuMS9710C::optAtt()
{
    sendCommand("ATT?");
    if(receiveCommand() == "ON")
        return true;
    else
        return false;
}

void AnritsuMS9710C::optAtt(bool checked)
{
    if(checked)
        sendCommand("ATT ON");
    else
        sendCommand("ATT OFF");
}

QString AnritsuMS9710C::resolution()
{
    sendCommand("RES?");
    return receiveCommand();
}

void AnritsuMS9710C::resoluiton(const QString &s)
{
        sendCommand("RES "+s);
}

bool AnritsuMS9710C::actualResolution()
{
    sendCommand("ARES?");
    if(receiveCommand() == "ON")
        return true;
    else
        return false;
}

void AnritsuMS9710C::actualResolution(bool checked)
{
    if(checked)
        sendCommand("ARES ON");
    else
        sendCommand("ARES OFF");

}

QString AnritsuMS9710C::actualResolutionValue()
{
    sendCommand("ARED?");
    return receiveCommand();
}

QString AnritsuMS9710C::videoBandwidth()
{
    sendCommand("VBW?");
    return receiveCommand();
}

void AnritsuMS9710C::videoBandwidth(const QString &s)
{
    sendCommand("VBW "+s);
}

int AnritsuMS9710C::pointAverage()
{
    sendCommand("AVT?");
    QString pointAverage = receiveCommand();
    if(pointAverage == "OFF")
        return 1;
    else
        return pointAverage.toInt();
}

void AnritsuMS9710C::pointAverage(const int &i)
{
    if(i == 1)
        sendCommand("AVT OFF");
    else
        sendCommand("AVT "+QString::number(i));
}

int AnritsuMS9710C::sweepAverage()
{
    sendCommand("AVS?");
    QString sweepAverage = receiveCommand();
    if(sweepAverage == "OFF")
        return 1;
    else
        return sweepAverage.toInt();
}

void AnritsuMS9710C::sweepAverage(const int &i)
{
    if(i == 1)
        sendCommand("AVS OFF");
    else
        sendCommand("AVS "+QString::number(i));
}

QString AnritsuMS9710C::smooth()
{
    sendCommand("SMT?");
    QString smooth = receiveCommand();
    if(smooth == "OFF")
        return "1";
    else
        return smooth;
}

void AnritsuMS9710C::smooth(const QString &s)
{
    if(s == "1")
        sendCommand("SMT OFF");
    else
        sendCommand("SMT "+s);
}

QString AnritsuMS9710C::samplingPoints()
{
    sendCommand("MPT?");
    return receiveCommand();
}

void AnritsuMS9710C::samplingPoints(const QString &s)
{
    sendCommand("MPT "+ s);
}

bool AnritsuMS9710C::buzzer()
{
    sendCommand("BUZ?");
    if(receiveCommand() == "ON")
        return true;
    else
        return false;
}

void AnritsuMS9710C::buzzer(bool checked)
{
    if(checked)
        sendCommand("BUZ ON");
    else
        sendCommand("BUZ OFF");
}

QString AnritsuMS9710C::error()
{
    sendCommand("ERR?");
    return receiveCommand();
}

int AnritsuMS9710C::autoBacklight()
{
    sendCommand("BKL?");
    return receiveCommand().toInt();
}

void AnritsuMS9710C::autoBacklight(const int &autoBacklight)
{
    sendCommand("BKL " + QString::number(autoBacklight));
}

int AnritsuMS9710C::terminater()
{
    sendCommand("TRM?");
    return receiveCommand().toInt();
}

void AnritsuMS9710C::terminater(const int &terminater)
{
    sendCommand("TRM " + QString::number(terminater));
}

void AnritsuMS9710C::singleSweep()
{
    sendCommand("SSI");
}

void AnritsuMS9710C::repeatSweep()
{
    sendCommand("SRT");
}

int AnritsuMS9710C::isSweep()
{
    sendCommand("MOD?");
    return receiveCommand().toInt();
}

void AnritsuMS9710C::stopSweep()
{
    sendCommand("SST");
}

QString AnritsuMS9710C::receiveSpectrum(bool checked)
{
    if(checked)
        sendCommand("DQA?");
    else
        sendCommand("DQB?");
    return receiveCommand();
}

void AnritsuMS9710C::peakSearch()
{
    sendCommand("PKS NEXT");
    //sendCommand("PKS PEAK");
}

void AnritsuMS9710C::dipSearch()
{
    sendCommand("DPS NEXT");
    //sendCommand("DPS DIP");
}

void AnritsuMS9710C::peakCenter()
{
    sendCommand("PKC");
}

void AnritsuMS9710C::tMkrCenter()
{
    sendCommand("TMC");
}

void AnritsuMS9710C::peakLevel()
{
    sendCommand("PKL");
}

QString AnritsuMS9710C::memorySelect()
{
    sendCommand("MSL?");
    return receiveCommand();
}

void AnritsuMS9710C::memorySelect(bool checked)
{
    if(checked)
        sendCommand("MSL A");
    else
        sendCommand("MSL B");
}

double AnritsuMS9710C::centralWavelength()
{
    sendCommand("CNT?");
    return receiveCommand().toDouble();
}

void AnritsuMS9710C::centralWavelength(const double& center)
{
    sendCommand(QString("CNT %1").arg(center,0,'g',6));
}

double AnritsuMS9710C::span()
{
    sendCommand("SPN?");
    return receiveCommand().toDouble();
}

void AnritsuMS9710C::span(const double& span)
{
    sendCommand(QString("SPN %1").arg(span,0,'g',5));
}

QString AnritsuMS9710C::markerValue()
{
    sendCommand("MKV?");
    QString markerValue = receiveCommand();
    if(markerValue == "WL")
        return "Wavelength";
    else
        return "Frequency";
}

void AnritsuMS9710C::markerValue(const QString &s)
{
    if(s == "Wavelength")
        sendCommand("MKV WL");
    else
        sendCommand("MKV FREQ");
}

void AnritsuMS9710C::sendCommand(const QString &s)
{
    serial->write((s+"\n").toLocal8Bit());
}

QString AnritsuMS9710C::receiveCommand()
{
    QByteArray array;
    if(serial->waitForReadyRead(this->firstWaitTime)) {
        array = serial->readAll();
        while(serial->waitForReadyRead(this->additionalWaitTime))
            array += serial->readAll();
    } else {
        emit errorMessage("Wait write request timeout");
    }
    QString out = QString(array);
    out.chop(2);
    return out;
}
