#include "gestionequipement.h"
#include "ui_gestionequipement.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QDebug>
#include<equipement.h>
#include <maintenance.h>
GestionEquipement::GestionEquipement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GestionEquipement)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->CB_IDEquipement->setModel(equipement.listRef());
    ui->T_Equipement->setModel(equipement.afficher());
    ui->CB_IDMaintenance->setModel(maintenance.listId());
    ui->T_Maintenance->setModel(maintenance.afficher());
}

GestionEquipement::~GestionEquipement()
{
    delete ui;
}


void GestionEquipement::on_B_GestionEquipement_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void GestionEquipement::on_B_AjouterEquipement_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void GestionEquipement::on_B_ModifierEquipement_clicked()
{
    QSqlQuery qry;
    QString ref_string = QString::number(ui->CB_IDEquipement->currentText().toInt());
    qry.prepare("SELECT * FROM equipement where reference= :reference");
    qry.bindValue(0, ref_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->LE_MReference->setText(qry.value(0).toString());
            ui->LE_MQuantiteEquipement->setText(qry.value(1).toString());
            ui->LE_MTailleEquipement->setText(qry.value(2).toString());
            ui->LE_MEtatEquipement->setText(qry.value(3).toString());
            ui->LE_MPoidEquipement->setText(qry.value(4).toString());
            ui->LE_MNomEquipement->setText(qry.value(5).toString());
        }
    }
    ui->stackedWidget->setCurrentIndex(3);


}

void GestionEquipement::on_B_BackToGestions_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void GestionEquipement::on_B_GestionMaintenance_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionEquipement::on_B_AjouterMaintenance_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void GestionEquipement::on_B_ModifierMaintenance_clicked()
{
    QSqlQuery qry;
    QString id_string = QString::number(ui->CB_IDMaintenance->currentText().toInt());
    qry.prepare("SELECT * FROM maintenance where idmaintenance=:idmaintenance");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->LE_MDateDebut->setText(qry.value(1).toString());
            ui->LE_MCout->setText(qry.value(2).toString());
            ui->LE_MDatefin->setText(qry.value(3).toString());
            ui->LE_MIDEquipement->setText(qry.value(4).toString());
        }
    }
    ui->stackedWidget->setCurrentIndex(6);
}

void GestionEquipement::on_B_BackToGestionEquipement_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void GestionEquipement::on_B_BackToGestionsEquipement_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void GestionEquipement::on_B_BackToGestions_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void GestionEquipement::on_B_BackToGestionMaintenance_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionEquipement::on_B_BackToGestionmaintenance_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionEquipement::on_B_AConfirmerEquipement_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout de l'equipement?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        int reference = ui->LE_AReferenceEquipement->text().toInt();
        int quantite = ui->LE_AQuantiteEquipement->text().toInt();
        QString taille = ui->LE_ATailleEquipement->text();
        QString etat = ui->LE_AEtatEquipement->text();
        int poid = ui->LE_APoidEquipement->text().toInt();
        QString nom = ui->LE_ANomEquipement->text();
        Equipement equipement(reference, quantite, taille, etat, poid, nom);
        if(equipement.ajouter()) {
            ui->CB_IDEquipement->setModel(equipement.listRef());
            ui->T_Equipement->setModel(equipement.afficher());
            ui->stackedWidget->setCurrentIndex(1);

            ui->LE_AReferenceEquipement->setText("");
            ui->LE_AQuantiteEquipement->setText("");
            ui->LE_ATailleEquipement->setText("");
            ui->LE_AEtatEquipement->setText("");
            ui->LE_APoidEquipement->setText("");
            ui->LE_ANomEquipement->setText("");

        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}



void GestionEquipement::on_B_MConfirmerEquipement_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer modification de l'equipement?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        int reference = ui->LE_MReference->text().toInt();
        int quantite = ui->LE_MQuantiteEquipement->text().toInt();
        QString taille = ui->LE_MTailleEquipement->text();
        QString etat = ui->LE_MEtatEquipement->text();
        int poid = ui->LE_MPoidEquipement->text().toInt();
        QString nom = ui->LE_MNomEquipement->text();
        Equipement equipement(reference, quantite, taille, etat, poid, nom);
        if(equipement.modifier()) {
            ui->CB_IDEquipement->setModel(equipement.listRef());
            ui->T_Equipement->setModel(equipement.afficher());
            ui->stackedWidget->setCurrentIndex(1);

            ui->LE_MReference->setText("");
            ui->LE_MQuantiteEquipement->setText("");
            ui->LE_MTailleEquipement->setText("");
            ui->LE_MEtatEquipement->setText("");
            ui->LE_MPoidEquipement->setText("");
            ui->LE_MNomEquipement->setText("");

        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("Modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionEquipement::on_B_SupprimerEquipement_clicked()
{
    Equipement equipement;
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la suppression", "Confirmer la suppression de l'equipement?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        equipement.setReference(ui->CB_IDEquipement->currentText().toInt());
        if(equipement.supprimer(equipement.getReference())) {
            qDebug() << "Suppression Complet";
            ui->T_Equipement->setModel(equipement.afficher());
            ui->CB_IDEquipement->setModel(equipement.listRef());
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionEquipement::on_B_AConfirmerMaintenance_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout de l'equipement au maintenance?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        QString datedebut = ui->LE_ADateDebut->text();
        int cout = ui->LE_ACout->text().toInt();
        QString datefin = ui->LE_ADateFin->text();
        int reference = ui->LE_ReferenceEq->text().toInt();
        Maintenance maintenance(datedebut, cout , datefin, reference);
        if(maintenance.ajouter()) {
            ui->CB_IDMaintenance->setModel(maintenance.listId());
            ui->T_Maintenance->setModel(maintenance.afficher());
            ui->stackedWidget->setCurrentIndex(1);


            ui->LE_ADateDebut->setText("");
            ui->LE_ACout->setText("");
            ui->LE_ADateFin->setText("");

        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionEquipement::on_B_SupprimerMaintenance_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la suppression", "Confirmer la fixation de l'equipement?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        maintenance.setIdmaintenance(ui->CB_IDMaintenance->currentText().toInt());
        if(maintenance.supprimer(maintenance.getIdmaintenance())) {
            qDebug() << "Suppression Complet";
            ui->T_Maintenance->setModel(maintenance.afficher());
            ui->CB_IDMaintenance->setModel(maintenance.listId());
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionEquipement::on_B_MConfirmerMaintenance_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la modification", "Confirmer la modification du maintenance?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        maintenance.setIdmaintenance(ui->CB_IDMaintenance->currentText().toInt());
        maintenance.setCout(ui->LE_MCout->text().toInt());
        maintenance.setDatedebut(ui->LE_MDateDebut->text());
        maintenance.setDatefin(ui->LE_MDatefin->text());
        maintenance.setReference(ui->LE_MIDEquipement->text().toInt());
        if(maintenance.modifier()) {
            ui->T_Maintenance->setModel(maintenance.afficher());
            ui->CB_IDMaintenance->setModel(maintenance.listId());
            ui->stackedWidget->setCurrentIndex(4);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}
