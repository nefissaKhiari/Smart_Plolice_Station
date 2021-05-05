#ifndef GESTIONEQUIPEMENT_H
#define GESTIONEQUIPEMENT_H

#include <QMainWindow>
#include "equipement.h"
#include "maintenance.h"
#include "notification.h"
#include <QtCharts>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QHorizontalStackedBarSeries>
#include <QLineSeries>
#include <QCategoryAxis>
#include <QPieSeries>
#include <QPieSlice>
#include <QSound>

QT_BEGIN_NAMESPACE
namespace Ui { class GestionEquipement; }
QT_END_NAMESPACE

class GestionEquipement : public QMainWindow
{
    Q_OBJECT

public:
    GestionEquipement(QWidget *parent = nullptr);
    ~GestionEquipement();
    void INFORMER(QLabel *label ,QString message, int duration);

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

    void on_B_AConfirmerEquipement_clicked();

    void on_B_MConfirmerEquipement_clicked();

    void on_B_SupprimerEquipement_clicked();

    void on_B_AConfirmerMaintenance_clicked();

    void on_B_SupprimerMaintenance_clicked();

    void on_B_MConfirmerMaintenance_clicked();

    void on_B_Trier_clicked();

    void on_B_ResetTableEquipement_clicked();

    void on_pushButton_clicked();

    void on_statestique_clicked();
    void on_LE_ChercherReference_textChanged(const QString &arg1);

    void on_FBack_clicked();

    void on_statestique_3_clicked();

    void on_Cut_clicked();

    void on_paste_clicked();

    void on_copy_clicked();

    void on_controlZ_clicked();

    void on_refresh_clicked();

    void on_New_File_clicked();

    void on_New_Folder_clicked();

    void on_Edit_clicked();

    void on_save_clicked();

    void on_B_AjouterEquipement_3_clicked();

    void on_B_AjouterEquipement_2_clicked();

private:
    Ui::GestionEquipement *ui;
    Equipement equipement;
    Maintenance maintenance;
    Notification notification;
    QSound *song;
    QString file_path;
};
#endif // GESTIONEQUIPEMENT_H
