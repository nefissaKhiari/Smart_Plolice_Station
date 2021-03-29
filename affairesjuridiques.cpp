#include "affairesjuridiques.h"
#include "ui_affairesjuridiques.h"
#include "intervenant.h"
#include "affaire.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QDebug>
#include <QRegExpValidator>

#define Gen_RX "^[A-Z]+(([',. -][a-zA-Z])?[a-zA-Z]*)*$"

AffairesJuridiques::AffairesJuridiques(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AffairesJuridiques)
{
    ui->setupUi(this);
    /*QRegExp rx(Gen_RX);
    QRegExpValidator *GenVal = new QRegExpValidator(rx, this);
    ui->LE_ANomIntervenant->setValidator(GenVal);
    ui->LE_APrenomIntervenant->setValidator(GenVal);
    ui->LE_ALocalIntervenant->setValidator(GenVal);*/
    ui->LE_ACinIntervenant->setValidator(new QIntValidator(1, 99999999, this));
    ui->LE_ChercherNom->setValidator(new QIntValidator(1, 99999999, this));

    ui->stackedWidget->setCurrentIndex(0);

    ui->T_Intervenants->setModel(intervenant.afficher());
    ui->CB_IDIntervenant->setModel(intervenant.listCin());

    ui->T_Affaire->setModel(affaire.afficher());
    ui->CB_IDAffaire->setModel(affaire.listId());
}

AffairesJuridiques::~AffairesJuridiques()
{
    delete ui;
}


void AffairesJuridiques::on_B_GestionIntervenant_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void AffairesJuridiques::on_B_GestioAffaire_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void AffairesJuridiques::on_B_BackToGestions_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void AffairesJuridiques::on_B_BackToGestions_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void AffairesJuridiques::on_B_AjouterAffaire_clicked()
{
    //ui->DE_ADateAffaire->setDate();
    ui->CB_ACinIntAffaire->setModel(intervenant.listCin());
    ui->stackedWidget->setCurrentIndex(5);
}

void AffairesJuridiques::on_B_ModifierIntervenant_clicked()
{
    QSqlQuery qry;
    QString cin_string = QString::number(ui->CB_IDIntervenant->currentText().toInt());
    qry.prepare("SELECT * FROM intervenant where cin=:cin");
    qry.bindValue(0, cin_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->LE_MCinIntervenant->setText(qry.value(0).toString());
            ui->LE_MNomIntervenant->setText(qry.value(1).toString());
            ui->LE_MPrenomIntervenant->setText(qry.value(2).toString());
            ui->CB_ANationaliteIntervenant->setCurrentText(qry.value(3).toString());
            QString Nat = qry.value(3).toString();
            if(Nat == "Tunisienne") {
                ui->CB_MNationaliteIntervenant->setCurrentText("Tunisienne");
            }
            else if(Nat == "Algerienne") {
                ui->CB_MNationaliteIntervenant->setCurrentText("Algerienne");
            }
            else if(Nat == "Francaise") {
                ui->CB_MNationaliteIntervenant->setCurrentText("Francaise");
            }
            else if(Nat == "Libanaise") {
                ui->CB_MNationaliteIntervenant->setCurrentText("Libanaise");
            }
            else if(Nat == "Autres...") {
                ui->CB_MNationaliteIntervenant->setCurrentText("Autres...");
            }
            ui->LE_MLocalIntervenant->setText(qry.value(4).toString());
            ui->LE_MMailIntervenant->setText(qry.value(5).toString());
        }
    }
    ui->stackedWidget->setCurrentIndex(3);
}

void AffairesJuridiques::on_B_AAnnulerIntervenant_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    ui->L_ACinIntAlert->setText("");
    ui->L_ANomIntAlert->setText("");
    ui->L_APrenomIntAlert->setText("");
    ui->L_ALocalIntAlert->setText("");
    ui->L_AMailIntAlert->setText("");

    ui->LE_ACinIntervenant->setText("");
    ui->LE_ANomIntervenant->setText("");
    ui->LE_APrenomIntervenant->setText("");
    ui->LE_ALocalIntervenant->setText("");
    ui->LE_AMailIntervenant->setText("");
}

void AffairesJuridiques::on_B_MAnuulerIntervenant_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void AffairesJuridiques::on_B_ModifierAffaire_clicked()
{  
    QSqlQuery qry;
    QString id_string = QString::number(ui->CB_IDAffaire->currentText().toInt());
    qry.prepare("SELECT * FROM affaires where id=:id");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->LE_MTypeAffaire->setText(qry.value(1).toString());
            ui->LE_MLocalAffaire->setText(qry.value(2).toString());
            ui->TE_MDescAffaire->setText(qry.value(3).toString());
            ui->LE_MCinIntAffaire->setText(qry.value(4).toString());
            ui->DE_MDateAffaire->setDate(qry.value(5).toDate());
        }
    }
    ui->stackedWidget->setCurrentIndex(6);
}

void AffairesJuridiques::on_B_AAnnulerAffaire_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void AffairesJuridiques::on_B_MAnnulerAffaire_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void AffairesJuridiques::on_B_AjouterIntervenant_clicked()
{
    ui->CB_ANationaliteIntervenant->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(2);
}

void AffairesJuridiques::on_B_AConfirmerIntervenant_clicked()
{
    /*************** BEGIN : Controle de Saisir L'ajout d'Intervenant ***************/
    bool overAll = false, cin_B, nom_B, prenom_B, mail_B, local_B;
    int cin = ui->LE_ACinIntervenant->text().toInt();
    QString cin_l = ui->LE_ACinIntervenant->text();
    QString nom = ui->LE_ANomIntervenant->text();
    QString prenom = ui->LE_APrenomIntervenant->text();
    QString nationalite = ui->CB_ANationaliteIntervenant->currentText();
    QString localisation = ui->LE_ALocalIntervenant->text();
    QString mail = ui->LE_AMailIntervenant->text();

    // BEGIN : cin
    if(cin_l.length() < 8) {
        cin_B = false;
        ui->L_ACinIntAlert->setText("Il faut 8 charactere de facon XXXXXXXXXX");
        ui->L_ACinIntAlert->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        cin_B = true;
        ui->L_ACinIntAlert->setText("Ok");
        ui->L_ACinIntAlert->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }
    // END : cin

    // BEGIN : Nom
    if(nom.length() < 3) {
        nom_B = false;
        ui->L_ANomIntAlert->setText("Il faut 3 charactere Minimum");
        ui->L_ANomIntAlert->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        nom_B = true;
        nom[0] = nom[0].toUpper();
        ui->L_ANomIntAlert->setText("Ok");
        ui->L_ANomIntAlert->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }
    // END : Nom

    // BEGIN : Prenom
    if(prenom.length() < 3) {
        prenom_B = false;
        ui->L_APrenomIntAlert->setText("Il faut 3 charactere Minimum");
        ui->L_APrenomIntAlert->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        prenom_B = true;
        prenom[0] = prenom[0].toUpper();
        ui->L_APrenomIntAlert->setText("Ok");
        ui->L_APrenomIntAlert->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }
    // END : Prenom

    // BEGIN : Local
    if(localisation.length() < 10) {
        local_B = false;
        ui->L_ALocalIntAlert->setText("Il faut 10 charactere Minimum");
        ui->L_ALocalIntAlert->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        local_B = true;        
        localisation[0] = localisation[0].toUpper();
        ui->L_ALocalIntAlert->setText("Ok");
        ui->L_ALocalIntAlert->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }
    // END : Local

    // BEGIN : Mail
    // END : Mail

    (cin_B && nom_B && prenom_B && local_B)? overAll = true : overAll = false;
    /*************** END : Controle de Saisir L'ajout d'Intervenant ***************/

    /*************** BEGIN : Ajouter sur BaseDonnee ***************/
    if(overAll) {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout du l'intervenant?", QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes) {
            Intervenant intervenant(cin, nom, prenom, nationalite, localisation, mail);
            if(intervenant.ajouter()) {
                ui->CB_IDIntervenant->setModel(intervenant.listCin());
                ui->T_Intervenants->setModel(intervenant.afficher());
                ui->stackedWidget->setCurrentIndex(1);

                ui->LE_ACinIntervenant->setText("");
                ui->LE_ANomIntervenant->setText("");
                ui->LE_APrenomIntervenant->setText("");
                ui->LE_ALocalIntervenant->setText("");
                ui->LE_AMailIntervenant->setText("");
            }
            else {
                QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
            }
        }
    }
    /*************** END : Ajouter sur BaseDonnee ***************/
}

void AffairesJuridiques::on_B_SupprimerIntervenant_clicked()
{
    Intervenant intervenantS;
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la suppression", "Confirmer la suppression du l'intervenant?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        intervenantS.setCin(ui->CB_IDIntervenant->currentText().toInt());
        if(intervenantS.supprimer(intervenantS.getCin())) {
            qDebug() << "Suppression Complet";
            ui->T_Intervenants->setModel(intervenantS.afficher());
            ui->CB_IDIntervenant->setModel(intervenantS.listCin());

            ui->T_Affaire->setModel(affaire.afficher());
            ui->CB_IDAffaire->setModel(affaire.listId());
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void AffairesJuridiques::on_B_MConfirmerIntervenant_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la modification", "Confirmer la modification du l'intervenant?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        Intervenant affaire;
        affaire.setCin(ui->CB_IDIntervenant->currentText().toInt());
        affaire.setNom(ui->LE_MNomIntervenant->text());
        affaire.setPrenom(ui->LE_MPrenomIntervenant->text());
        affaire.setNationalite(ui->CB_MNationaliteIntervenant->currentText());
        affaire.setLocalisation(ui->LE_MLocalIntervenant->text());
        affaire.setMail(ui->LE_MMailIntervenant->text());
        if(affaire.modifier()) {
            ui->CB_IDIntervenant->setModel(intervenant.listCin());
            ui->T_Intervenants->setModel(intervenant.afficher());
            ui->stackedWidget->setCurrentIndex(1);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void AffairesJuridiques::on_B_AConfirmerAffaire_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout du l'affaire?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        int intervenant = ui->CB_ACinIntAffaire->currentText().toInt();
        QString type = ui->LE_ATypeAffaire->text();
        QString localisation = ui->LE_ALocalAffaire->text();
        QString description = ui->TE_ADescAffaire->toPlainText();
        QDate date = ui->DE_ADateAffaire->date();
        Affaire affaire(type, localisation, date, description, intervenant);
        if(affaire.ajouter()) {
            ui->T_Affaire->setModel(affaire.afficher());
            ui->CB_IDAffaire->setModel(affaire.listId());
            ui->stackedWidget->setCurrentIndex(4);

            ui->LE_ATypeAffaire->setText("");
            ui->LE_ALocalAffaire->setText("");
            ui->LE_ADateAffaire->setText("");
            ui->TE_ADescAffaire->setText("");
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void AffairesJuridiques::on_B_SupprimerAffaire_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la suppression", "Confirmer la suppression du l'affaire?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        affaire.setId(ui->CB_IDAffaire->currentText().toInt());
        if(affaire.supprimer(affaire.getId())) {
            qDebug() << "Suppression Complet";
            ui->T_Affaire->setModel(affaire.afficher());
            ui->CB_IDAffaire->setModel(affaire.listId());
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void AffairesJuridiques::on_B_MConfirmerAffaire_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la modification", "Confirmer la modification du l'affaire?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        affaire.setId(ui->CB_IDAffaire->currentText().toInt());
        affaire.setType(ui->LE_MTypeAffaire->text());
        affaire.setLocalisation(ui->LE_MLocalAffaire->text());
        affaire.setDate(ui->DE_MDateAffaire->date());
        affaire.setDescription(ui->TE_MDescAffaire->toPlainText());
        if(affaire.modifier()) {
            ui->T_Affaire->setModel(affaire.afficher());
            ui->CB_IDAffaire->setModel(affaire.listId());
            ui->stackedWidget->setCurrentIndex(4);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void AffairesJuridiques::on_B_ResetTableIntervenant_clicked()
{
    ui->LE_ChercherNom->setText("");
    ui->LE_ChercherPrenom->setText("");
    ui->T_Intervenants->setModel(intervenant.afficher());
}

void AffairesJuridiques::on_B_Trier_clicked()
{
    QString Tri = ui->CB_TriIntervenant->currentText();
    ui->T_Intervenants->setModel(intervenant.Trier(Tri));
}

void AffairesJuridiques::on_B_Recherche_clicked()
{
    QString cinn = ui->LE_ChercherNom->text();
    QString prenom = ui->LE_ChercherPrenom->text();
    if((cinn != "") && (prenom != "")) {
        QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("Il faut Chercher avec le Nom OU le Prenom.\n" "Cliquer Ok."), QMessageBox::Ok);
    }
    else if((cinn == "") && (prenom == "")) {
        QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("Il faut Chercher avec le Nom OU le Prenom.\n" "Cliquer Ok."), QMessageBox::Ok);
    }
    else if(cinn != ""){
        ui->T_Intervenants->setModel(intervenant.ChercherC(cinn));
    }
    else if(prenom != ""){
        ui->T_Intervenants->setModel(intervenant.ChercherP(prenom));
    }
}

void AffairesJuridiques::on_B_Statistics_clicked()
{
    QSqlQuery qry;

    /*  Getting All rows of DB
    qry.prepare("SELECT COUNT (*) FROM intervenant");
    qry.exec();
    int rows= 0;
    if (qry.next()) {
        rows= qry.value(0).toInt();
    }*/

    qry.prepare("SELECT COUNT (*) FROM intervenant where Nationalite='Autres...'");
    qry.exec();
    int Autres= 0;
    if (qry.next()) {
        Autres= qry.value(0).toInt();
    }

    qry.prepare("SELECT COUNT (*) FROM intervenant where Nationalite='Tunisienne'");
    qry.exec();
    int Tn= 0;
    if (qry.next()) {
        Tn= qry.value(0).toInt();
    }

    qry.prepare("SELECT COUNT (*) FROM intervenant where Nationalite='Algerienne'");
    qry.exec();
    int Ag= 0;
    if (qry.next()) {
        Ag= qry.value(0).toInt();
    }

    qry.prepare("SELECT COUNT (*) FROM intervenant where Nationalite='Francaise'");
    qry.exec();
    int Fr= 0;
    if (qry.next()) {
        Fr= qry.value(0).toInt();
    }

    qry.prepare("SELECT COUNT (*) FROM intervenant where Nationalite='Libanaise'");
    qry.exec();
    int Lb= 0;
    if (qry.next()) {
        Lb= qry.value(0).toInt();
    }

    QPieSeries *series = new QPieSeries();
    series->append("Tunisienne", Tn);
    series->append("Francaise", Fr);
    series->append("Algerienne", Ag);
    series->append("Libanaise", Lb);
    series->append("Autres...", Autres);
    series->setHoleSize(0.5);
    series->setPieSize(0.8);

    QPieSlice *tn = series->slices().at(0);
    QPieSlice *fr = series->slices().at(1);
    QPieSlice *ag = series->slices().at(2);
    QPieSlice *lb = series->slices().at(3);
    QPieSlice *autres = series->slices().at(4);
    tn->setLabelVisible(true);
    tn->setBrush(Qt::red);
    fr->setLabelVisible(true);
    fr->setBrush(Qt::blue);
    ag->setLabelVisible(true);
    ag->setBrush(Qt::green);
    lb->setLabelVisible(true);
    lb->setPen(QPen(Qt::green, 1));
    lb->setBrush(Qt::white);
    autres->setLabelVisible(true);
    fr->setBrush(Qt::darkBlue);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Les statistics de Nationalite : ");

    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->F_Statistic);

    ui->stackedWidget->setCurrentIndex(7);
}

void AffairesJuridiques::on_B_BackToGestions_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void AffairesJuridiques::on_LE_ChercherNom_returnPressed()
{
    QString cinn = ui->LE_ChercherNom->text();
    if(cinn == "") {
        QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("Il faut Chercher avec le Nom OU le Prenom.\n" "Cliquer Ok."), QMessageBox::Ok);
    }
    else {
        ui->T_Intervenants->setModel(intervenant.ChercherC(cinn));
    }
}

void AffairesJuridiques::on_LE_ChercherPrenom_returnPressed()
{
    QString prenom = ui->LE_ChercherPrenom->text();
    if(prenom == "") {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("Il faut Chercher avec le Nom OU le Prenom.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    else {
        ui->T_Intervenants->setModel(intervenant.ChercherP(prenom));
    }
}

void AffairesJuridiques::on_LE_ChercherNom_textChanged(const QString &arg1)
{
    ui->T_Intervenants->setModel(intervenant.ChercherC(arg1));
}

void AffairesJuridiques::on_LE_ChercherPrenom_textChanged(const QString &arg1)
{
    ui->T_Intervenants->setModel(intervenant.ChercherP(arg1));
}
