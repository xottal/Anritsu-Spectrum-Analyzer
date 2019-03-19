#ifndef ANRITSUMS9710C_H
#define ANRITSUMS9710C_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>

class AnritsuMS9710C : public QObject
{
    Q_OBJECT
public:
    AnritsuMS9710C();
    ~AnritsuMS9710C();

    bool connectSerialPort(const QString&);
    void disconnectSerialPort() const;
    QSerialPort::SerialPortError serialError() const;
    QString identifecation() const;

    QString memorySelect() const;
    void memorySelect(bool) const;

    double centralWavelength() const;
    void centralWavelength(const double&) const;

    double span() const;
    void span(const double&) const;

    QString markerValue() const;
    void markerValue(const QString&) const;

    QString valueInVacuum() const;
    void valueInVacuum(const QString&) const;

    QString levelScale() const;

    double dbDiv() const;
    void dbDiv(const double&) const;

    double refLevel() const;
    void refLevel(const double &) const;

    std::pair<QString,double> linearLevel() const;
    void linearLevel(const std::pair<QString,double> &) const;

    bool optAtt() const;
    void optAtt(bool) const;

    QString resolution() const;
    void resoluiton(const QString&) const;

    bool actualResolution() const;
    void actualResolution(bool) const;
    QString actualResolutionValue() const;

    QString videoBandwidth() const;
    void videoBandwidth(const QString&) const;

    int pointAverage() const;
    void pointAverage(const int&) const;

    int sweepAverage() const;
    void sweepAverage(const int&) const;

    QString smooth() const;
    void smooth(const QString&) const;

    QString samplingPoints() const;
    void samplingPoints(const QString&) const;

    bool buzzer() const;
    void buzzer(bool) const;

    int autoBacklight() const;
    void autoBacklight(const int&) const;

    int terminater() const;
    void terminater(const int&) const;

    void singleSweep() const;
    void repeatSweep() const;
    int isSweep() const;
    void stopSweep() const;

    QString receiveSpectrum(bool) const;

    void peakSearch() const;
    void dipSearch() const;
    void peakCenter() const;
    void tMkrCenter() const;
    void peakLevel() const;
public slots:
    QString error();
signals:
    void errorMessage(const QString&) const;

private:
    QSerialPort *serial;
    void sendCommand(const QString&) const;
    QString receiveCommand() const;

    const int firstWaitTime = 500;
    const int additionalWaitTime = 20;

};

#endif // ANRITSUMS9710C_H
