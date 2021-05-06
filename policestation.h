#ifndef POLICESTATION_H
#define POLICESTATION_H
//********************* Begin : Includes *********************
#include "messengerclient.h"
#include "cam.h"
#include "intervenant.h"
#include "affaire.h"
#include "vehicule.h"
#include "missions.h"
#include "notification.h"
#include "affectations.h"
#include "excel.h"
#include "exceli.h"
#include "equipement.h"
#include "maintenance.h"
#include "citoyen.h"
#include "service.h"
#include "smtp.h"
#include "amende.h"
#include "policier.h"
#include "calc.h"
#include "detenu.h"
#include "infraction.h"
#include "affectation.h"
#include "login.h"
#include "poubelle.h"
//****
#include <QDialog>
#include <QUrl>
#include <qfiledialog.h>
#include <QScrollBar>
#include <QDateTime>
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
#include <QModelIndex>
#include <QtPrintSupport/QPrintDialog>
#include <QPdfWriter>
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
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include <QValidator>
#include <QTabWidget>
#include <QPrintDialog>
#include <QVariant>
#include <QPrintDialog>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QTimer>
#include "QrCode.hpp"
#include <QMediaPlayer>
#include<QDebug>
#include<QDateTime>
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

    void on_B_GestionCitoyen_clicked();

    void on_B_GestioService_clicked();

    void on_B_BackToGestions_6_clicked();

    void on_B_BackToGestions_7_clicked();

    void on_B_AjouterCitoyen_clicked();

    void on_B_AAnnulerCitoyen_clicked();

    void on_B_AConfirmerCitoyen_clicked();

    void on_B_AccederProfil_clicked();

    void on_B_SupprimerCitoyen_clicked();

    void on_B_MConfirmerCitoyen_2_clicked();

    void on_B_MAnnulerCitoyen_clicked();

    void on_B_MConfirmerCitoyen_clicked();

    void on_B_EnvoyeMail_clicked();

    void on_B_returnCitoyen_3_clicked();

    void on_pushButton_2_clicked();

    void on_browseBtn_clicked();

    void on_B_Trier_3_clicked();

    void on_LE_recherche_textChanged(const QString &arg1);

    void on_B_ResetTableIntervenant_2_clicked();

    void on_B_ServiceAdminis_clicked();

    void on_B_returnCitoyen_clicked();

    void on_B_AjouterService_clicked();

    void on_B_AAnnulerService_clicked();

    void on_B_ModifierService_clicked();

    void on_B_AConfirmerService_clicked();

    void on_B_MAnnulerService_clicked();

    void on_B_MConfirmerService_clicked();

    void on_B_SupprimerService_clicked();

    void on_B_TrierS_clicked();

    void on_LE_rechercheS_textChanged(const QString &arg1);

    void on_B_ResetTableIntervenant_3_clicked();

    void on_pdf_clicked();

    void on_B_AjouterMission_2_clicked();

    void on_B_AAnnulerMission_2_clicked();

    void on_B_AConfirmerMission_2_clicked();

    void on_B_ModifierMission_2_clicked();

    void on_B_MAnnulerMission_2_clicked();

    void on_B_MConfirmerMission_2_clicked();

    void on_B_SupprimerMission_2_clicked();

    void on_B_Trier_7_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_export_excel_2_clicked();

    void on_B_Trier_8_clicked();

    void on_annulera_2_clicked();

    void on_recherchera_2_textChanged(const QString &arg1);

    void on_B_BackToGestions_11_clicked();

    void on_B_ConfirmerAffectation_2_clicked();

    void on_supprimera_2_clicked();

    void on_B_BackToMenu_3_clicked();

    void on_B_Amende_clicked();

    void on_B_BackToMenu_5_clicked();

    void on_B_GestionPolicier_clicked();

    void on_B_GestionAmende_2_clicked();

    void on_B_BackToGestionAmende_clicked();

    void on_B_BackToGestionPolicier_clicked();

    void on_B_AjouterPolicier_clicked();

    void on_B_AAnnulerPolicier_clicked();

    void on_B_AConfirmerPolicier_clicked();

    void on_B_SupprimerPolicier_clicked();

    void on_B_ModifierPolicier_clicked();

    void on_B_MAnuulerPolicier_clicked();

    void on_B_MConfirmerPolicier_clicked();

    void on_B_Trier_4_clicked();

    void on_B_Recherche_clicked();

    void on_B_ResetTablePolicier_clicked();

    void on_B_imprimer_clicked();

    void on_B_Excel_clicked();

    void on_B_AjouterAmende_clicked();

    void on_B_AConfirmerAmende_clicked();

    void on_B_AAnnulerAmende_clicked();

    void on_B_SupprimerAmende_clicked();

    void on_B_ModifierAmende_clicked();

    void on_B_MAnnulerAmende_clicked();

    void on_B_MConfirmerAmende_clicked();

    void on_B_calculator_clicked();

    void on_pushButton_4_clicked();

    void on_statistics_clicked();

    void on_excel_clicked();

    void myFunction();

    void on_export_excel_3_clicked();

    void on_statistics_2_clicked();
      
    void on_qrcodeb_clicked();

    void on_B_Google_clicked();

    void on_B_Detenu_clicked();

    void on_B_BackToMenu_6_clicked();

    void on_B_BackToMenu_7_clicked();

    void on_signup_clicked();

    void on_sliderprogress_sliderMoved(int position);

    void on_slidervolume_sliderMoved(int position);

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_positionChanged(qint64 position);

    void on_durationChanged(qint64 position);

    void on_pushButton_clicked();

    void on_B_PolicierParticipants_clicked();

    void on_B_RetourMiss_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_B_AjouterEquipement_2_clicked();

    void on_B_AjouterEquipement_3_clicked();

    void on_pushButton_11_clicked();

    void on_map_clicked();

    void on_ret_clicked();

    void on_repart_clicked();

    void on_B_historique_clicked();

    void on_combo_action_currentIndexChanged(const QString &arg1);

    void on_comboBox_mp_currentIndexChanged(const QString &arg1);

    void on_B_Retouuuur_clicked();

    void on_B_GestionInfraction_clicked();

    void on_B_GestioDetenus_clicked();

    void on_B_GestionMission_2_clicked();

    void on_B_BackToGestions_12_clicked();

    void on_B_BackToGestions_8_clicked();

    void on_B_BackToGestions_14_clicked();

    void on_B_SupprimerDetenus_clicked();

    void on_B_AjouterDetenus_clicked();

    void on_B_AAnnulerDetenus_clicked();

    void on_B_AConfirmerDetenus_clicked();

    void on_B_ModifierDetenus_clicked();

    void on_B_MAnnulerDetenus_clicked();

    void on_B_Trier_5_clicked();

    void on_B_ResetTableIntervenant_4_clicked();

    void on_LE_Chercher_2_textChanged(const QString &arg1);

    void on_B_MConfirmerDetenus_clicked();

    void on_B_SupprimerIntervenant_2_clicked();

    void on_B_AjouterInfraction_clicked();

    void on_B_AConfirmerInfraction_clicked();

    void on_B_AAnnulerInfraction_clicked();

    void on_B_ModifierIntervenant_2_clicked();

    void on_B_Statistics_2_clicked();

    void on_B_BackToGestions_13_clicked();

    void on_B_MAnnulerInfraction_clicked();

    void on_B_MConfirmerInfraction_clicked();


    void on_B_ConfirmerAffectation_clicked();

    void on_pushButton_12_clicked();

    void on_Poubelle_clicked();

    void on_vider_corbeille_clicked();

    void on_EQ_retour_clicked();

    void on_B_Theme_clicked();

private:
    Ui::PoliceStation *ui;
    Intervenant intervenant;
    Affaire affaire;
    QSound *son;
    vehicule v_tmp;
    missions m_tmp;
    affectations a_tmp;
    notification n_tmp, notification, N;
    Equipement equipement;
    Maintenance maintenance;
    QString file_path;
    Citoyen C;
    Service S;
    QStringList files;
    Amende amende;
    Policier policier;
    QTimer *timer;
    login *log;
    QMediaPlayer* player;
    Detenu detenu;
    Infraction infraction;
    Affectation affectation;
    Poubelle poubelle;
signals:
    void setCenter(QVariant , QVariant);
};
#endif // POLICESTATION_H
