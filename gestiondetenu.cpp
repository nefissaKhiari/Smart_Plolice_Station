#include "gestiondetenu.h"
#include "ui_gestiondetenu.h"
#include "detenu.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QDebug>
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

GestionDetenu::GestionDetenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GestionDetenu)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->T_Detenu->setModel(detenu.afficher());
    ui->T_Infraction->setModel(infraction.afficher());
    ui->CB_IDDetenus->setModel(detenu.listId());
    ui->CB_IDIntervenant->setModel(infraction.listId());
}

GestionDetenu::~GestionDetenu()
{
    delete ui;
}


void GestionDetenu::on_B_GestioDetenus_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionDetenu::on_B_GestionInfraction_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void GestionDetenu::on_B_BackToGestions_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void GestionDetenu::on_B_ModifierDetenus_clicked()
{
    QSqlQuery qry;
    QString id_string = QString::number(ui->CB_IDDetenus->currentText().toInt());
    qry.prepare("SELECT * FROM detenus where cin=:id");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->LE_MCinDetenus->setText(qry.value(0).toString());
            ui->LE_MNomDetenus->setText(qry.value(1).toString());
            ui->LE_MPrenomDetenus->setText(qry.value(2).toString());
            ui->DE_MDateNaissDetenus->setDate(qry.value(3).toDate());
            ui->LE_MNationalitelDetenus->setText(qry.value(4).toString());
            ui->DE_MDateArrestDetenus->setDate(qry.value(5).toDate());
            ui->DE_MHistoriqueDetenus->setText(qry.value(6).toString());
            ui->CB_MNivDangDetenus->setCurrentText(qry.value(7).toString());
        }
    }
    ui->stackedWidget->setCurrentIndex(6);
}

void GestionDetenu::on_B_AjouterDetenus_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void GestionDetenu::on_B_AConfirmerDetenus_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout du l'affaire?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        int cin = ui->LE_ACinDetenus->text().toInt();
        QString nom = ui->LE_ANomDetenus->text();
        QString prenom = ui->LE_APrenomDetenus->text();
        QString nationalite = ui->LE_ANationalitelDetenus->text();
        QString danger = ui->CB_ANivDangDetenus->currentText();
        QString historique = ui->DE_AHistoriqueDetenus->toPlainText();
        QDate dn = ui->DE_ADateNaissDetenus->date();
        QDate da = ui->DE_ADateArrestDetenus->date();
        Detenu detenu(cin, nom, prenom, nationalite, dn, da, historique, danger);
        if(detenu.ajouter()) {
            ui->T_Detenu->setModel(detenu.afficher());
            ui->CB_IDDetenus->setModel(detenu.listId());
            ui->stackedWidget->setCurrentIndex(4);

            ui->LE_ACinDetenus->setText("");
            ui->LE_ANomDetenus->setText("");
            ui->LE_APrenomDetenus->setText("");
            ui->LE_ANationalitelDetenus->setText("");
            ui->DE_AHistoriqueDetenus->setText("");
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionDetenu::on_B_AAnnulerDetenus_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionDetenu::on_B_MAnnulerInfraction_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void GestionDetenu::on_B_MConfirmerInfraction_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la modification", "Confirmer la modification du l'affaire?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        infraction.setId(ui->CB_IDIntervenant->currentText().toInt());
        infraction.setNom(ui->LE_MNomInfraction->text());
        infraction.setType(ui->LE_MTypeInfraction->currentText());
        infraction.setNiveau(ui->CB_MNivInfraction->currentText());
        infraction.setDate(ui->DE_MDatInfraction->date());
        if(infraction.modifier()) {
            ui->T_Infraction->setModel(infraction.afficher());
            ui->CB_IDIntervenant->setModel(infraction.listId());
            ui->stackedWidget->setCurrentIndex(1);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionDetenu::on_B_MAnnulerDetenus_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionDetenu::on_B_MConfirmerDetenus_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la modification", "Confirmer la modification du l'affaire?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        detenu.setId(ui->CB_IDDetenus->currentText().toInt());
        detenu.setNom(ui->LE_MNomDetenus->text());
        detenu.setNationalite(ui->LE_MNationalitelDetenus->text());
        detenu.setPrenom(ui->LE_MPrenomDetenus->text());
        detenu.setDanger(ui->CB_MNivDangDetenus->currentText());
        detenu.setDn(ui->DE_MDateNaissDetenus->date());
        detenu.setDa(ui->DE_MDateArrestDetenus->date());
        detenu.setHistorique(ui->DE_MHistoriqueDetenus->toPlainText());
        if(detenu.modifier()) {
            ui->T_Detenu->setModel(detenu.afficher());
            ui->CB_IDDetenus->setModel(detenu.listId());
            ui->stackedWidget->setCurrentIndex(4);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionDetenu::on_B_BackToGestions_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void GestionDetenu::on_B_AjouterInfraction_clicked()
{
    ui->CB_ADetInfraction->setModel(detenu.listId());
    ui->stackedWidget->setCurrentIndex(2);
}

void GestionDetenu::on_B_ModifierIntervenant_clicked()
{
    QSqlQuery qry;
    QString id_string = QString::number(ui->CB_IDIntervenant->currentText().toInt());
    qry.prepare("SELECT * FROM infractions where id=:id");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->LE_MNomInfraction->setText(qry.value(1).toString());
            ui->LE_MTypeInfraction->setCurrentText(qry.value(2).toString());
            ui->CB_MNivInfraction->setCurrentText(qry.value(3).toString());
            ui->DE_MDatInfraction->setDate(qry.value(4).toDate());
            ui->LE_MDetInf->setText(qry.value(5).toString());
        }
    }
    ui->stackedWidget->setCurrentIndex(3);
}

void GestionDetenu::on_B_AAnnulerInfraction_clicked()
{
    ui->LE_ANomInfraction->setText("");
    ui->stackedWidget->setCurrentIndex(1);
}

void GestionDetenu::on_B_AConfirmerInfraction_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout du l'affaire?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        QString nom = ui->LE_ANomInfraction->text();
        QString type = ui->LE_ATypeInfraction_2->currentText();
        QString niveau = ui->CB_ANivInfraction->currentText();
        QString detenu = ui->CB_ADetInfraction->currentText();
        QDate di = ui->DE_ADatInfraction->date();
        Infraction infraction(nom, type, niveau, di, detenu);
        if(infraction.ajouter()) {
            ui->T_Infraction->setModel(infraction.afficher());
            ui->CB_IDIntervenant->setModel(infraction.listId());
            ui->stackedWidget->setCurrentIndex(1);

            ui->LE_ANomInfraction->setText("");
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionDetenu::on_B_SupprimerDetenus_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la suppression", "Confirmer la suppression du l'affaire?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        detenu.setId(ui->CB_IDDetenus->currentText().toInt());
        if(detenu.supprimer(detenu.getId())) {
            ui->T_Detenu->setModel(detenu.afficher());
            ui->CB_IDDetenus->setModel(detenu.listId());
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionDetenu::on_B_SupprimerIntervenant_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la suppression", "Confirmer la suppression du l'affaire?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        infraction.setId(ui->CB_IDIntervenant->currentText().toInt());
        if(infraction.supprimer(infraction.getId())) {
            ui->T_Infraction->setModel(infraction.afficher());
            ui->CB_IDIntervenant->setModel(infraction.listId());
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionDetenu::on_B_Statistics_clicked()
{
    QSqlQuery qry;
    int dis=infraction.dis();
    int as=infraction.as();
    int hi=infraction.hi();
    int vol=infraction.vol();
    int meurtre=infraction.meurtre();

    QPieSeries *series = new QPieSeries();
    series->append("discrimination", dis);
    series->append("attouchements sexuels", as);
    series->append("homicide involontaire", hi);
    series->append("Vol", vol);
    series->append("Meurtre", meurtre);
    series->setPieSize(0.8);

    QPieSlice *tn = series->slices().at(0);
    QPieSlice *fr = series->slices().at(1);
    QPieSlice *ag = series->slices().at(2);
    QPieSlice *lb = series->slices().at(3);
    //QPieSlice *autres = series->slices().at(4);
    /*********************** Labels
    tn->setLabelVisible(true);
    fr->setLabelVisible(true);
    ag->setLabelVisible(true);
    lb->setLabelVisible(true);
    autres->setLabelVisible(true);
    ******************************/
    tn->setBrush(Qt::red);
    fr->setBrush(Qt::blue);
    ag->setBrush(Qt::green);
    lb->setBrush(Qt::yellow);
    fr->setBrush(Qt::darkBlue);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Type d'infraction");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->F_Statistic);

    ui->stackedWidget->setCurrentIndex(7);
}

void GestionDetenu::on_B_BackToGestions_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void GestionDetenu::on_B_Trier_2_clicked()
{
    QString Tri = ui->CB_TriInfr_2->currentText();
    ui->T_Detenu->setModel(detenu.Trier(Tri));
}

void GestionDetenu::on_B_ResetTableIntervenant_2_clicked()
{
    ui->LE_Chercher_2->clear();
    ui->T_Detenu->setModel(detenu.afficher());
}

void GestionDetenu::on_LE_Chercher_2_textChanged(const QString &arg1)
{
    QString by = ui->CB_ChercherInfr_2->currentText();
    ui->T_Detenu->setModel(detenu.Chercher(arg1, by));
}

void GestionDetenu::on_B_ConfirmerAffectation_clicked()
{
    int id = ui->CB_IDInfAffectation->currentText().toInt();
   int cin = ui->CB_CinDetAffectation->currentText().toInt();
   QMessageBox msgBox;

    Affectation A( cin, id);
    bool test=A.ajouterA();
    if(test)
    {
        msgBox.setText("Ajout avec succés.");
            ui->T_Affectation->setModel(affectation.afficherA());
    }
}

void GestionDetenu::on_B_GestionMission_2_clicked()
{
    ui->CB_CinDetAffectation->setModel(detenu.listId());
    ui->CB_IDInfAffectation->setModel(infraction.listId());
    ui->T_Affectation->setModel(affectation.afficherA());
    ui->stackedWidget->setCurrentIndex(8);
}

void GestionDetenu::on_B_BackToGestions_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
