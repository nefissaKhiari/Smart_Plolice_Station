#ifndef VEHICULEMISSION_H
#define VEHICULEMISSION_H

#include <QMainWindow>
#include "vehicule.h"
#include "missions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class VehiculeMission; }
QT_END_NAMESPACE

class VehiculeMission : public QMainWindow
{
    Q_OBJECT

public:
    VehiculeMission(QWidget *parent = nullptr);
    ~VehiculeMission();

private slots:
    void on_B_GestionVehicule_clicked();

    void on_B_GestionMission_clicked();

    void on_B_BackToGestions_clicked();

    void on_B_ModifierVehicule_clicked();

    void on_B_AjouterVehicule_clicked();

    void on_B_AAnnulerVehicule_clicked();

    void on_B_MAnuulerVehicule_clicked();

    void on_B_MConfirmerVehicule_clicked();

    void on_B_ModifierMission_clicked();

    void on_B_AjouterMission_clicked();

    void on_B_AAnnulerMission_clicked();

    void on_B_MAnnulerMission_clicked();

    void on_B_BackToGestions_2_clicked();

    void on_B_AConfirmerVehicule_clicked();

    void on_B_SupprimerVehicule_clicked();

    void on_B_AConfirmerMission_clicked();

    void on_B_MConfirmerMission_clicked();

    void on_B_SupprimerMission_clicked();

    void on_B_Trier_clicked();

    void on_lineEdit_returnPressed();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::VehiculeMission *ui;
    vehicule v_tmp;
    missions m_tmp;
};
#endif // VEHICULEMISSION_H
