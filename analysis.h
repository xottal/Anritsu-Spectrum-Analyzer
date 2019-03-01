#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <QWidget>

namespace Ui {
class analysis;
}

class analysis : public QWidget
{
    Q_OBJECT

public:
    explicit analysis(QWidget *parent = nullptr);
    ~analysis();

private:
    Ui::analysis *analysisWindow;
};

#endif // ANALYSIS_H
