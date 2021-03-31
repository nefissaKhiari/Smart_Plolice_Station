
#include "serviceadministratif.h"
#include "ui_serviceadministratif.h"
#include "citoyen.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QDebug>
ServiceAdministratif::ServiceAdministratif(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ServiceAdministratif)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->T_Citoyens->setModel(C.afficher());
    ui->CB_IDCitoyen->setModel(C.listId());
    ui->T_Service ->setModel(S.afficher());
    ui->CB_IDService->setModel(S.listId());
    ui->CB_NomCitoyen->setModel(C.listId());
    //ui->CB_NomCitoyen_2->setModel(C.listId());

}

ServiceAdministratif::~ServiceAdministratif()
{
    delete ui;
}


void ServiceAdministratif::on_B_GestionCitoyen_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void ServiceAdministratif::on_B_BackToGestions_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void ServiceAdministratif::on_B_AccederProfil_clicked()
{
    QSqlQuery qry;
    QString id_string = QString::number(ui->CB_IDCitoyen->currentText().toInt());
    qry.prepare("SELECT * FROM citoyens where id=:id");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->LE_PNomCitoyen ->setText(qry.value(1).toString());
            ui->LE_PPrenomCitoyen->setText(qry.value(2).toString());
            ui->LE_PDateNaissCit->setText(qry.value(3).toString());
            ui->LE_PLieuNaissCit->setText(qry.value(4).toString());
            ui->LE_PMailCitoyen->setText(qry.value(5).toString());
            ui->LE_PAdresseCit->setText(qry.value(5).toString());
            ui->LE_PNomPereCit->setText(qry.value(5).toString());
            ui->LE_PProfessionCit->setText(qry.value(5).toString());
            ui->LE_PEtatCitoyen->setText(qry.value(5).toString());
            ui->stackedWidget->setCurrentIndex(4);
        }
    }

}

void ServiceAdministratif::on_B_AjouterCitoyen_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

//void ServiceAdministratif::on_B_AConfirmerCitoyen_clicked()
//{
  //   ui->stackedWidget->setCurrentIndex(1);
//}

void ServiceAdministratif::on_B_AAnnulerCitoyen_clicked()
{
    ui->LE_ANomCitoyen ->setText("");
    ui->LE_APrenomCitoyen ->setText("");
    ui->LE_ADateNaissCit->setText("");
    ui->LE_ALieuNaissCit->setText("");
    ui->LE_AMailCitoyen->setText("");
    ui->LE_AAdresseCit ->setText("");
    ui->LE_ANomPereCit ->setText("");
    ui->LE_AProfessionCit->setText("");
    ui->LE_AEtatCitoyen ->setText("");
    ui->stackedWidget->setCurrentIndex(1);
}

void ServiceAdministratif::on_B_MConfirmerCitoyen_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la modification", "Confirmer la modification du citoyen?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        Citoyen C;
        C.setid(ui->CB_IDCitoyen ->currentText().toInt());
        C.setnom(ui->LE_MNomCitoyen ->text());
        C.setprenom(ui->LE_MPrenomCitoyen ->text());
        C.setdatenaiss(ui->LE_MDateNaissCit_2 ->text());
        C.setlieunaiss(ui->LE_MLieuNaissCit ->text());
        C.setmail(ui->LE_MMailCitoyen ->text());
        C.setadresse(ui->LE_MAdresseCit ->text());
        C.setnompere(ui->LE_MNomPereCit->text());
        C.setprofession(ui->LE_MProfessionCit ->text());
        C.setetatcivil(ui->LE_MEtatCitoyen ->text());

        if(C.modifier()) {
            ui->T_Citoyens->setModel(C.afficher());
            ui->CB_IDCitoyen->setModel(C.listId());
            ui->stackedWidget->setCurrentIndex(1);
            ui->LE_ANomCitoyen->setText("");
            ui->LE_APrenomCitoyen->setText("");
            ui->LE_ADateNaissCit->setText("");
            ui->LE_ALieuNaissCit->setText("");
            ui->LE_AMailCitoyen->setText("");
            ui->LE_AAdresseCit->setText("");
            ui->LE_ANomPereCit->setText("");
            ui->LE_AProfessionCit->setText("");
            ui->LE_AEtatCitoyen->setText("");
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void ServiceAdministratif::on_B_MAnnulerCitoyen_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void ServiceAdministratif::on_B_returnCitoyen_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void ServiceAdministratif::on_B_MConfirmerCitoyen_2_clicked()
{
    QSqlQuery qry;
    QString id_string = QString::number(ui->CB_IDCitoyen->currentText().toInt());
    qry.prepare("SELECT * FROM citoyens where id=:id");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->LE_MNomCitoyen ->setText(qry.value(1).toString());
            ui->LE_MPrenomCitoyen->setText(qry.value(2).toString());
            ui->LE_MDateNaissCit_2->setText(qry.value(3).toString());
            ui->LE_MLieuNaissCit->setText(qry.value(4).toString());
            ui->LE_MMailCitoyen->setText(qry.value(5).toString());
            ui->LE_MAdresseCit->setText(qry.value(5).toString());
            ui->LE_MNomPereCit->setText(qry.value(5).toString());
            ui->LE_MProfessionCit->setText(qry.value(5).toString());
            ui->LE_MEtatCitoyen->setText(qry.value(5).toString());
        }
    }
    ui->stackedWidget->setCurrentIndex(3);
}

void ServiceAdministratif::on_B_SupprimerCitoyen_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la suppression", "Confirmer la suppression du lcitoyen?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        C.setid(ui->CB_IDCitoyen ->currentText().toInt());
        if(C.supprimer(C.getid())) {
            qDebug() << "Suppression Complet";
            ui->T_Citoyens ->setModel(C.afficher());
            ui->CB_IDCitoyen ->setModel(C.listId());
             ui->stackedWidget->setCurrentIndex(1);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void ServiceAdministratif::on_B_AConfirmerCitoyen_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout du citoyen?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        QString nom = ui->LE_ANomCitoyen->text();
        QString prenom = ui->LE_APrenomCitoyen->text();
        QString date_Naiss = ui->LE_ADateNaissCit->text();
        QString lieu_Naiss = ui->LE_ALieuNaissCit->text();
        QString mail = ui->LE_AMailCitoyen->text();
        QString adresse = ui->LE_AAdresseCit->text();
        QString nom_pere = ui->LE_ANomPereCit->text();
        QString profession = ui->LE_AProfessionCit ->text();
        QString etat_civil = ui->LE_AEtatCitoyen->text();
    Citoyen C(nom,prenom,date_Naiss,lieu_Naiss,mail, adresse,nom_pere,profession,etat_civil);
    if(C.ajouter()) {
        ui->T_Citoyens ->setModel(C.afficher());
        ui->CB_IDCitoyen ->setModel(C.listId());
        ui->stackedWidget->setCurrentIndex(1);

        ui->LE_ANomCitoyen ->setText("");
        ui->LE_APrenomCitoyen ->setText("");
        ui->LE_ADateNaissCit->setText("");
        ui->LE_ALieuNaissCit->setText("");
        ui->LE_AMailCitoyen->setText("");
        ui->LE_AAdresseCit ->setText("");
        ui->LE_ANomPereCit ->setText("");
        ui->LE_AProfessionCit->setText("");
        ui->LE_AEtatCitoyen ->setText("");
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
    }
    }
}

void ServiceAdministratif::on_B_BackToGestions_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void ServiceAdministratif::on_B_GestioService_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void ServiceAdministratif::on_B_AjouterService_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}



void ServiceAdministratif::on_B_ModifierService_clicked()
{
    QSqlQuery qry;
    QString id_string = QString::number(ui->CB_IDService->currentText().toInt());
    qry.prepare("SELECT * FROM services where id=:id");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->LE_MTypeService->setText(qry.value(1).toString());
            ui->LE_MDureeService->setText(qry.value(2).toString());
            ui->LE_MPapierService->setText(qry.value(3).toString());
            ui->TE_MDescService->setText(qry.value(4).toString());
            ui->LE_Nomci->setText(qry.value(5).toString());

        }
    }
    ui->stackedWidget->setCurrentIndex(8);
}





void ServiceAdministratif::on_B_AConfirmerService_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout du service?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        QString type = ui->LE_ATypeService->text();
        QString duree = ui->LE_ADureeService->text();
        QString papiers_necess = ui->LE_APapierService->text();
        QString description = ui->TE_ADescService->toPlainText();
        int id_citoyen=ui->CB_NomCitoyen->currentText().toInt();
    Service S(type,duree,papiers_necess,description,id_citoyen);
    if(S.ajouter()) {
        ui->T_Service ->setModel(S.afficher());
        ui->CB_IDService ->setModel(S.listId());
        ui->stackedWidget->setCurrentIndex(5);

        ui->LE_ATypeService ->setText("");
        ui->LE_ADureeService ->setText("");
        ui->LE_APapierService->setText("");
        ui->TE_ADescService->setText("");

    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
    }
    }
}

void ServiceAdministratif::on_B_AAnnulerService_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}


void ServiceAdministratif::on_B_MAnnulerService_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void ServiceAdministratif::on_B_MConfirmerService_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la modification", "Confirmer la modification du service?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        Service S;
        S.setid(ui->CB_IDService ->currentText().toInt());
        S.settype(ui->LE_MTypeService ->text());
        S.setduree(ui->LE_MDureeService ->text());
        S.setpapiersnecess(ui->LE_MPapierService ->text());
        S.setdescription(ui->TE_MDescService->toPlainText());
       // S.setid_citoyen(ui->LE_Nomci->text().toInt());


qDebug()<<S.getdescription();

        if(S.modifier()) {
            ui->T_Service->setModel(S.afficher());
            ui->CB_IDService->setModel(S.listId());
            ui->stackedWidget->setCurrentIndex(5);
            ui->LE_MTypeService->setText("");
            ui->LE_MDureeService->setText("");
            ui->LE_MPapierService->setText("");
            ui->TE_MDescService->setText("");
             //ui->LE_Nomci->setText("");

        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void ServiceAdministratif::on_B_SupprimerService_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la suppression", "Confirmer la suppression du service?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        S.setid(ui->CB_IDService->currentText().toInt());
        if(S.supprimer(S.getid())) {
            qDebug() << "Suppression Complet";
            ui->T_Service->setModel(S.afficher());
            ui->CB_IDService->setModel(S.listId());
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void ServiceAdministratif::on_B_Recherche_clicked()
{

}

//void ServiceAdministratif::on_LE_recherche_cursorPositionChanged(int arg1, int arg2)
//{
//}


void ServiceAdministratif::on_LE_recherche_textChanged(const QString &arg1)
{
    QString by=ui->CB_recherche->currentText();
            ui->T_Citoyens->setModel(C.rechercher(arg1,by));
}
