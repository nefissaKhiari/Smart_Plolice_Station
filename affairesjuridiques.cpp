#include "affairesjuridiques.h"
#include "ui_affairesjuridiques.h"
#include "intervenant.h"
#include "affaire.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QDebug>

AffairesJuridiques::AffairesJuridiques(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AffairesJuridiques)
{
    ui->setupUi(this);
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
            ui->LE_MNomIntervenant->setText(qry.value(1).toString());
            ui->LE_MPrenomIntervenant->setText(qry.value(2).toString());
            ui->LE_MNationaliteIntervenant->setText(qry.value(3).toString());
            ui->LE_MLocalIntervenant->setText(qry.value(4).toString());
            ui->LE_MMailIntervenant->setText(qry.value(5).toString());
        }
    }
    ui->stackedWidget->setCurrentIndex(3);
}

void AffairesJuridiques::on_B_AAnnulerIntervenant_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    ui->LE_ANationaliteIntervenant->setText("");
    ui->LE_APrenomIntervenant->setText("");
    ui->LE_ANationaliteIntervenant->setText("");
    ui->LE_ALocalIntervenant->setText("");
    ui->LE_AMailIntervenant->setText("");
}

void AffairesJuridiques::on_B_MAnuulerIntervenant_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    ui->LE_MNationaliteIntervenant->setText("");
    ui->LE_MPrenomIntervenant->setText("");
    ui->LE_MNationaliteIntervenant->setText("");
    ui->LE_MLocalIntervenant->setText("");
    ui->LE_MMailIntervenant->setText("");
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
            ui->LE_MDateAffaire->setText(qry.value(4).toString());
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
    ui->stackedWidget->setCurrentIndex(2);
}

void AffairesJuridiques::on_B_AConfirmerIntervenant_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout du l'intervenant?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        QString nom = ui->LE_ANomIntervenant->text();
        QString prenom = ui->LE_APrenomIntervenant->text();
        QString nationalite = ui->LE_ANationaliteIntervenant->text();
        QString localisation = ui->LE_ALocalIntervenant->text();
        QString mail = ui->LE_AMailIntervenant->text();
        Intervenant intervenant(nom, prenom, nationalite, localisation, mail);
        if(intervenant.ajouter()) {
            ui->CB_IDIntervenant->setModel(intervenant.listCin());
            ui->T_Intervenants->setModel(intervenant.afficher());
            ui->stackedWidget->setCurrentIndex(1);

            ui->LE_ANationaliteIntervenant->setText("");
            ui->LE_APrenomIntervenant->setText("");
            ui->LE_ANationaliteIntervenant->setText("");
            ui->LE_ALocalIntervenant->setText("");
            ui->LE_AMailIntervenant->setText("");
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
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
        affaire.setNationalite(ui->LE_MNationaliteIntervenant->text());
        affaire.setLocalisation(ui->LE_MLocalIntervenant->text());
        affaire.setMail(ui->LE_MMailIntervenant->text());
        if(affaire.modifier()) {
            ui->CB_IDIntervenant->setModel(intervenant.listCin());
            ui->T_Intervenants->setModel(intervenant.afficher());
            ui->stackedWidget->setCurrentIndex(1);

            ui->LE_ANationaliteIntervenant->setText("");
            ui->LE_APrenomIntervenant->setText("");
            ui->LE_ANationaliteIntervenant->setText("");
            ui->LE_ALocalIntervenant->setText("");
            ui->LE_AMailIntervenant->setText("");
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
        QString type = ui->LE_ATypeAffaire->text();
        QString localisation = ui->LE_ALocalAffaire->text();
        QString description = ui->TE_ADescAffaire->toPlainText();
        QString date = ui->LE_ADateAffaire->text();
        Affaire affaire(type, localisation, date, description);
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
        affaire.setDate(ui->LE_MDateAffaire->text());
        affaire.setDescription(ui->TE_MDescAffaire->toPlainText());
        if(affaire.modifier()) {
            ui->T_Affaire->setModel(affaire.afficher());
            ui->CB_IDAffaire->setModel(affaire.listId());
            ui->stackedWidget->setCurrentIndex(4);

            ui->LE_ATypeAffaire->setText("");
            ui->LE_ALocalAffaire->setText("");
            ui->LE_ADateAffaire->setText("");
            ui->TE_ADescAffaire->setText("");
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}
