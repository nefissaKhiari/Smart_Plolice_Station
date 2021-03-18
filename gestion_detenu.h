#ifndef gestiondetenu_H
#define gestiondetenu_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class gestiondetenu; }
QT_END_NAMESPACE

class gestiondetenu : public QMainWindow
{
    Q_OBJECT

public:
    gestiondetenu(QWidget *parent = nullptr);
    ~gestiondetenu();

private slots:
    void on_B_GestionIntervenant_clicked();

    void on_B_GestioAffaire_clicked();

    void on_B_BackToGestions_clicked();

    void on_B_BackToGestions_2_clicked();

    void on_B_AjouterAffaire_clicked();

    void on_B_ModifierIntervenant_clicked();

    void on_B_AAnnulerIntervenant_clicked();

    void on_B_MAnuulerIntervenant_clicked();

    void on_B_ModifierAffaire_clicked();

    void on_B_AAnnulerAffaire_clicked();

    void on_B_MAnnulerAffaire_clicked();

    void on_B_AjouterIntervenant_clicked();

private:
    Ui::gestiondetenu *ui;
};
#endif // gestiondetenu_H
