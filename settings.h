#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();
public slots:
    void buzzerSlot(bool);
    void autoBacklightSlot(int);
    void terminaterSlot(int);
    void errorSlot(QString);

    void buzzerSlotPush();
    void autoBacklightSlotPush();
    void terminaterSlotPush();

private slots:
    void on_checkBox_buzzer_clicked();

    void on_spinBox_autoBacklight_editingFinished();

    void on_comboBox_terminater_activated(const QString &arg1);

signals:
    void buzzerSignal(bool);
    void autoBacklightSignal(int);
    void terminaterSignal(int);

private:
    Ui::Settings *ui;

};

#endif // SETTINGS_H
