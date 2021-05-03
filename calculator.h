#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

// Use the standard UI namespace which is tied to the .ui file
namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    // Declares our class as a QObject which is the base class
    // for all Qt objects
    // QObjects handle events
    Q_OBJECT

public:

    // Declare a constructor and by passing 0 we state this widget
    // has no parent
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private:
    Ui::Calculator *ui;

    // These slots are executed when a signal is
    // submitted (Ex. Number button is clicked)
private slots :
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ChangeNumberSign();
};

#endif // CALCULATOR_H
