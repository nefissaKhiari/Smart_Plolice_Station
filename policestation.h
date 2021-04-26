#ifndef POLICESTATION_H
#define POLICESTATION_H
//********************* Begin : Includes *********************
#include "messengerclient.h"
#include "intervenant.h"
#include "affaire.h"
#include "vehicule.h"
#include "missions.h"
#include "notification.h"
#include "affectations.h"
#include "excel.h"
#include "equipement.h"
#include "maintenance.h"
//***
#include <QRegExpValidator>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QIntValidator>
#include <QSqlQuery>
#include <QMainWindow>
#include <QMessageBox>
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
#include <QLabel>
#include <QDialog>
#include <QSqlError>
#include <QModelIndex>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFile>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QVector2D>
#include <QVector>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include <QValidator>
#include <QTabWidget>
#include <QPrintDialog>
#include <QVariant>
#include <QPrintDialog>
//********************* End : Includes *********************
QT_BEGIN_NAMESPACE
namespace Ui { class PoliceStation; }
QT_END_NAMESPACE

class PoliceStation : public QMainWindow
{
    Q_OBJECT

public:
    PoliceStation(QWidget *parent = nullptr);
    ~PoliceStation();
    void INFORMER(QLabel *label ,QString message, int duration);

private slots:

    void on_B_Connecter_clicked();

    void on_B_Deconnecte_clicked();

    void on_B_AffaireJuri_clicked();

    void on_B_BackToMenu_clicked();

    void on_B_Vehic_clicked();

    void on_B_Equip_clicked();

    void on_B_BackToMenu_2_clicked();

    void on_B_BackToMenu_4_clicked();

    void on_B_GestionIntervenant_clicked();

    void on_B_GestioAffaire_clicked();

    void on_B_BackToGestions_clicked();

    void on_B_Statistics_clicked();

    void on_B_BackToGestions_3_clicked();

    void on_B_ModifierIntervenant_clicked();

    void on_B_AjouterIntervenant_clicked();

    void on_B_SupprimerIntervenant_clicked();

    void on_B_AConfirmerIntervenant_clicked();

    void on_B_AAnnulerIntervenant_clicked();

    void on_B_MAnuulerIntervenant_clicked();

    void on_B_MConfirmerIntervenant_clicked();

    void on_B_Trier_clicked();

    void on_LE_ChercherPrenom_textChanged(const QString &arg1);

    void on_B_ResetTableIntervenant_clicked();

    void on_B_Chat_clicked();

    void on_B_BackToGestions_2_clicked();

    void on_B_ModifierAffaire_clicked();

    void on_B_AjouterAffaire_clicked();

    void on_B_SupprimerAffaire_clicked();

    void on_B_AAnnulerAffaire_clicked();

    void on_B_AConfirmerAffaire_clicked();

    void on_B_MAnnulerAffaire_clicked();

    void on_B_MConfirmerAffaire_clicked();

    void on_B_GestionVehicule_2_clicked();

    void on_B_GestionMission_3_clicked();

    void on_B_GestionMission_4_clicked();

    void on_B_BackToGestions_9_clicked();

    void on_B_BackToGestions_10_clicked();

    void on_B_AjouterVehicule_2_clicked();

    void on_B_AAnnulerVehicule_2_clicked();

    void on_B_AConfirmerVehicule_2_clicked();

    void on_B_ModifierVehicule_2_clicked();

    void on_B_SupprimerVehicule_2_clicked();

    void on_B_MAnuulerVehicule_2_clicked();

    void on_B_MConfirmerVehicule_2_clicked();

    void on_B_Trier_6_clicked();

    void on_molka_2_textChanged(const QString &arg1);

    void on_annulerv_2_clicked();

    void on_annulerM_2_clicked();

    void on_B_Statistics_3_clicked();

    void on_B_GestionEquipement_clicked();

    void on_B_GestionMaintenance_clicked();

    void on_B_BackToGestions_4_clicked();

    void on_B_BackToGestions_5_clicked();

    void on_B_AjouterEquipement_clicked();

    void on_B_BackToGestionEquipement_3_clicked();

    void on_B_AConfirmerEquipement_clicked();

    void on_B_SupprimerEquipement_clicked();

    void on_B_ModifierEquipement_clicked();

    void on_B_BackToGestionsEquipement_4_clicked();

    void on_B_MConfirmerEquipement_clicked();

    void on_B_Trier_2_clicked();

    void on_LE_ChercherReference_textChanged(const QString &arg1);

    void on_B_ResetTableEquipement_clicked();

    void on_B_AjouterMaintenance_clicked();

    void on_B_BackToGestionMaintenance_5_clicked();

    void on_B_AConfirmerMaintenance_clicked();

    void on_B_SupprimerMaintenance_clicked();

    void on_B_ModifierMaintenance_clicked();

    void on_B_BackToGestionmaintenance_6_clicked();

    void on_B_MConfirmerMaintenance_clicked();

    void on_statestique_3_clicked();

    void on_New_File_clicked();

    void on_New_Folder_clicked();

    void on_Edit_clicked();

    void on_save_clicked();

    void on_Cut_clicked();

    void on_copy_clicked();

    void on_paste_clicked();

    void on_refresh_clicked();

    void on_controlZ_clicked();

    void on_FBack_clicked();

    void on_statestique_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::PoliceStation *ui;
    Intervenant intervenant;
    Affaire affaire;
    QSound *son;
    vehicule v_tmp;
    missions m_tmp;
    affectations a_tmp;
    notification n_tmp, notification;
    Equipement equipement;
    Maintenance maintenance;
    QString file_path;
};
#endif // POLICESTATION_H
