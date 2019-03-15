#ifndef ANRITSUMS9710C_H
#define ANRITSUMS9710C_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>
#include <QTest>

class AnritsuMS9710C : public QObject
{
    Q_OBJECT
public:
    AnritsuMS9710C();
    ~AnritsuMS9710C();

    bool connectSerialPort(const QString&);
    void disconnectSerialPort();
    QSerialPort::SerialPortError serialError();
    QString identifecation();

    QString memorySelect();
    void memorySelect(bool);

    double centralWavelength();
    void centralWavelength(const double&);

    double span();
    void span(const double&);

    QString markerValue();
    void markerValue(const QString&);

    QString valueInVacuum();
    void valueInVacuum(const QString&);

    QString levelScale();

    double dbDiv();
    void dbDiv(const double&);

    double refLevel();
    void refLevel(const double &);

    std::pair<QString,double> linearLevel();
    void linearLevel(const std::pair<QString,double> &);

    bool optAtt();
    void optAtt(bool);

    QString resolution();
    void resoluiton(const QString&);

    bool actualResolution();
    void actualResolution(bool);
    QString actualResolutionValue();

    QString videoBandwidth();
    void videoBandwidth(const QString&);

    int pointAverage();
    void pointAverage(const int&);

    int sweepAverage();
    void sweepAverage(const int&);

    QString smooth();
    void smooth(const QString&);

    QString samplingPoints();
    void samplingPoints(const QString&);

    bool buzzer();
    void buzzer(bool);

    QString error();

    int autoBacklight();
    void autoBacklight(const int&);

    int terminater();
    void terminater(const int&);

    void singleSweep();
    void repeatSweep();
    int isSweep();
    void stopSweep();

    QString receiveSpectrum(bool);

    void peakSearch();
    void dipSearch();
    void peakCenter();
    void tMkrCenter();
    void peakLevel();

signals:
    void errorMessage(const QString&);

private:
    QSerialPort *serial;
    void sendCommand(const QString&);
    QString receiveCommand();

    const int firstWaitTime = 500;
    const int additionalWaitTime = 20;

};

#endif // ANRITSUMS9710C_H
