#ifndef GESTIONEQUIPEMENT_H
#define GESTIONEQUIPEMENT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class GestionEquipement; }
QT_END_NAMESPACE

class GestionEquipement : public QMainWindow
{
    Q_OBJECT

public:
    GestionEquipement(QWidget *parent = nullptr);
    ~GestionEquipement();

private slots:
    void on_B_GestionEquipement_clicked();

    void on_B_AjouterEquipement_clicked();

    void on_B_ModifierEquipement_clicked();

    void on_B_BackToGestions_clicked();

    void on_B_GestionMaintenance_clicked();

    void on_B_AjouterMaintenance_clicked();

    void on_B_ModifierMaintenance_clicked();

    void on_B_BackToGestionEquipement_3_clicked();

    void on_B_BackToGestionsEquipement_4_clicked();

    void on_B_BackToGestions_2_clicked();

    void on_B_BackToGestionMaintenance_5_clicked();

    void on_B_BackToGestionmaintenance_6_clicked();

private:
    Ui::GestionEquipement *ui;
};
#endif // GESTIONEQUIPEMENT_H
