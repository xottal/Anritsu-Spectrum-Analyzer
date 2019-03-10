#include "helpwindow.h"
#include "ui_helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    ui->label_3->setStyleSheet("backround image: url(:/pinout.png)");
}

HelpWindow::~HelpWindow()
{
    delete ui;
}
