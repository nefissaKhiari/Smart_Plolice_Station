#ifndef GESTIONAMENDE_H
#define GESTIONAMENDE_H

#include <QMainWindow>
#include "amende.h"
#include "policier.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GestionAmende; }
QT_END_NAMESPACE

class GestionAmende : public QMainWindow
{
    Q_OBJECT

public:
    GestionAmende(QWidget *parent = nullptr);
    ~GestionAmende();



private slots:


 void on_B_GestionPolicier_clicked();

 void on_B_AjouterPolicier_clicked();

 void on_B_AConfirmerPolicier_clicked();

 void on_B_AAnnulerPolicier_clicked();

 void on_B_ModifierPolicier_clicked();

 void on_B_MConfirmerPolicier_clicked();

 void on_B_MAnuulerPolicier_clicked();

 void on_B_SupprimerPolicier_clicked();

 void on_B_BackToGestionAmende_clicked();

 void on_B_Trier_clicked();

 void on_B_ResetTablePolicier_clicked();

 void on_B_GestionAmende_2_clicked();

 void on_B_BackToGestionPolicier_clicked();

 void on_B_AjouterAmende_clicked();

 void on_B_AConfirmerAmende_clicked();

 void on_B_AAnnulerAmende_clicked();

 void on_B_ModifierAmende_clicked();

 void on_B_MConfirmerAmende_clicked();

 void on_B_MAnnulerAmende_clicked();

 void on_B_BackToMenu_clicked();

 void on_B_SupprimerAmende_clicked();

 void on_B_Excel_clicked();

 void on_B_Recherche_clicked();

private:
    Ui::GestionAmende *ui;
    Amende amende;
    Policier policier;
};
#endif // GESTIONAMENDE_H
