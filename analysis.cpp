#include "analysis.h"
#include "ui_analysis.h"

analysis::analysis(QWidget *parent) :
    QWidget(parent),
    analysisWindow(new Ui::analysis)
{
    analysisWindow->setupUi(this);
}

analysis::~analysis()
{
    delete analysisWindow;
}
