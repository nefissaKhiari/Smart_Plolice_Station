#ifndef POLICESTATION_H
#define POLICESTATION_H
//********************* Begin : Includes *********************
#include "messengerclient.h"
#include "intervenant.h"
#include "affaire.h"
//***
#include <QRegExpValidator>
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

private:
    Ui::PoliceStation *ui;
    Intervenant intervenant;
    Affaire affaire;
    QSound *son;
};
#endif // POLICESTATION_H
