#ifndef GESTIONDETENU_H
#define GESTIONDETENU_H

#include <QMainWindow>
#include "detenu.h"
#include "infraction.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GestionDetenu; }
QT_END_NAMESPACE

class GestionDetenu : public QMainWindow
{
    Q_OBJECT

public:
    GestionDetenu(QWidget *parent = nullptr);
    ~GestionDetenu();

private slots:
    void on_B_GestioDetenus_clicked();

    void on_B_GestionInfraction_clicked();

    void on_B_BackToGestions_2_clicked();

    void on_B_ModifierDetenus_clicked();

    void on_B_AjouterDetenus_clicked();

    void on_B_AConfirmerDetenus_clicked();

    void on_B_AAnnulerDetenus_clicked();

    void on_B_MAnnulerInfraction_clicked();

    void on_B_MConfirmerInfraction_clicked();

    void on_B_MAnnulerDetenus_clicked();

    void on_B_MConfirmerDetenus_clicked();

    void on_B_BackToGestions_clicked();

    void on_B_AjouterInfraction_clicked();

    void on_B_ModifierIntervenant_clicked();

    void on_B_AAnnulerInfraction_clicked();

    void on_B_AConfirmerInfraction_clicked();

    void on_B_SupprimerDetenus_clicked();

    void on_B_SupprimerIntervenant_clicked();

private:
    Ui::GestionDetenu *ui;
    Detenu detenu;
    Infraction infraction;
};
#endif // GESTIONDETENU_H
