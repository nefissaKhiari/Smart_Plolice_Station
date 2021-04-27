#ifndef CALC_H
#define CALC_H

#include <QDialog>

namespace Ui {
class Calc;
}

class Calc : public QDialog
{
    Q_OBJECT

public:
    explicit Calc(QWidget *parent = nullptr);
    ~Calc();

private:
    Ui::Calc *ui;

private slots :
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ChangeNumberSign();
    void on_Clear_clicked();
};

#endif // CALC_H
