#include "gestionamende.h"
#include "ui_gestionamende.h"
#include "policier.h"
#include "amende.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QDebug>


#include <QFileDialog>
#include <QDialog>
#include <QTextDocument>
#include<QPdfWriter>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include <QIntValidator>
#include <QPrinter>
#include<QPrintDialog>
#include<excel.h>


GestionAmende::GestionAmende(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GestionAmende)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    ui->T_Amende->setModel(amende.afficher_amende());
    ui->CB_IDAmende->setModel(amende.listId_amende());

    ui->T_Policier->setModel(policier.afficher_policier());
    ui->comboBoxCin->setModel(policier.listCin_policier());
}

GestionAmende::~GestionAmende()
{
    delete ui;
}



void GestionAmende::on_B_GestionPolicier_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void GestionAmende::on_B_AjouterPolicier_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void GestionAmende::on_B_AConfirmerPolicier_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout du Policier?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        int cin_policier= ui->LE_ACin->text().toInt();
        QString nom_policier = ui->LE_ANomPolicier->text();
        QString prenom_policier = ui->LE_APrenomPolicier->text();
        QString grade_policier = ui->LE_AGradePolicier->text();
        QString mail_policier = ui->LE_AMailPolicier->text();
        QString mdp_policier = ui->LE_AMdpPolicier->text();
         QString photo_policier = ui->LE_APhotoPolicier->text();
          QString secteur_policier = ui->LE_ASecteurPolicier->text();
       Policier policier(cin_policier, nom_policier, prenom_policier, grade_policier, mail_policier, mdp_policier, photo_policier, secteur_policier);
        if(policier.ajouter_policier()) {
            ui->comboBoxCin->setModel(policier.listCin_policier());
            ui->T_Policier->setModel(policier.afficher_policier());
            ui->stackedWidget->setCurrentIndex(1);

            ui->LE_ACin->setText("");
            ui->LE_ANomPolicier->setText("");
            ui->LE_APrenomPolicier->setText("");
            ui->LE_AGradePolicier->setText("");
            ui->LE_AMailPolicier->setText("");
            ui->LE_AMdpPolicier->setText("");
            ui->LE_APhotoPolicier->setText("");
             ui->LE_ASecteurPolicier->setText("");

        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionAmende::on_B_AAnnulerPolicier_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    ui->LE_ACin->setText("");
    ui->LE_ANomPolicier->setText("");
    ui->LE_APrenomPolicier->setText("");
    ui->LE_AGradePolicier->setText("");
    ui->LE_AMailPolicier->setText("");
    ui->LE_AMdpPolicier->setText("");
    ui->LE_APhotoPolicier->setText("");
     ui->LE_ASecteurPolicier->setText("");
}

void GestionAmende::on_B_ModifierPolicier_clicked()
{
    QSqlQuery qry;
    QString cin_string = QString::number(ui->comboBoxCin->currentText().toInt());
    qry.prepare("SELECT * FROM policier where cin_policier=:cin");
    qry.bindValue(0, cin_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->LE_ACin->setText(qry.value(0).toString());
            ui->LE_ANomPolicier->setText(qry.value(1).toString());
            ui->LE_APrenomPolicier->setText(qry.value(2).toString());
            ui->LE_AGradePolicier->setText(qry.value(3).toString());
            ui->LE_AMailPolicier->setText(qry.value(4).toString());
            ui->LE_AMdpPolicier->setText(qry.value(5).toString());
            ui->LE_APhotoPolicier->setText(qry.value(6).toString());
            ui->LE_ASecteurPolicier->setText(qry.value(7).toString());
        }
    }
    ui->stackedWidget->setCurrentIndex(3);
}

void GestionAmende::on_B_MConfirmerPolicier_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la modification", "Confirmer la modification du Policier?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        Policier amende;
        amende.setCin_policier(ui->comboBoxCin->currentText().toInt());
        amende.setNom_policier(ui->LE_MNomPolicier->text());
        amende.setPrenom_policier(ui->LE_MPrenomPolicier->text());
        amende.setGrade_policier(ui->LE_MGradePolicier->text());
        amende.setMail_policier(ui->LE_MMailPolicier->text());
       amende.setMdp_policier(ui->LE_MMdpPolicier->text());
       amende.setPhoto_policier(ui->LE_MPhotoPolicier->text());
       amende.setSecteur_policier(ui->LE_MSecteurPolicier->text());
        if(amende.modifier_policier()) {
            ui->comboBoxCin->setModel(policier.listCin_policier());
            ui->T_Policier->setModel(policier.afficher_policier());
            ui->stackedWidget->setCurrentIndex(1);


            ui->LE_MNomPolicier->setText("");
            ui->LE_MPrenomPolicier->setText("");
            ui->LE_MGradePolicier->setText("");
            ui->LE_MMailPolicier->setText("");
            ui->LE_MMdpPolicier->setText("");
            ui->LE_MPhotoPolicier->setText("");
             ui->LE_MSecteurPolicier->setText("");
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionAmende::on_B_MAnuulerPolicier_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    ui->LE_MNomPolicier->setText("");
    ui->LE_MPrenomPolicier->setText("");
    ui->LE_MGradePolicier->setText("");
    ui->LE_MMailPolicier->setText("");
    ui->LE_MMdpPolicier->setText("");
    ui->LE_MPhotoPolicier->setText("");
     ui->LE_MSecteurPolicier->setText("");
}

void GestionAmende::on_B_SupprimerPolicier_clicked()
{
   Policier policier;
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la suppression", "Confirmer la suppression du Policier?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        policier.setCin_policier(ui->comboBoxCin->currentText().toInt());
        if(policier.supprimer_policier(policier.getCin_policier())) {
            qDebug() << "Suppression Complet";
            ui->T_Policier->setModel(policier.afficher_policier());
            ui->comboBoxCin->setModel(policier. listCin_policier());
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionAmende::on_B_BackToGestionAmende_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}

void GestionAmende::on_B_Trier_clicked()
{
    QString Tri = ui->CB_TriPolicier->currentText();
    ui->T_Policier->setModel(policier.Trier_policier(Tri));
}

void GestionAmende::on_B_ResetTablePolicier_clicked()
{
    ui->LE_ChercherNom->setText("");
    ui->LE_ChercherPrenom->setText("");
    ui->T_Policier->setModel(policier.afficher_policier());
}

void GestionAmende::on_B_GestionAmende_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void GestionAmende::on_B_BackToGestionPolicier_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
}


void GestionAmende::on_B_AjouterAmende_clicked()
{
    ui->CB_IDAmende->setModel(policier.listCin_policier());
    ui->stackedWidget->setCurrentIndex(5);
}

void GestionAmende::on_B_AConfirmerAmende_clicked()
{

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout de l'Amende?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        int id_amende = ui->LE_AIDAmende->text().toInt();
        QString type_amende = ui->LE_ATypeAmende->text();
       float prix_amende = ui->LE_APrixAmende->text().toFloat() ;
        QString description_amende = ui->LE_ADescAmende->toPlainText();
        QString lieu_amende = ui->LE_ALieuAmende->text();
        QString date_amende = ui->LE_ADateAmende->text();
        int CIN_policier = ui->LE_ACINpolicier->text().toInt();
         Amende amende (id_amende, type_amende, prix_amende, description_amende, lieu_amende, date_amende,CIN_policier);
        if(amende.ajouter_amende()) {
            ui->T_Amende->setModel(amende.afficher_amende());
            ui->CB_IDAmende->setModel(amende.listId_amende());
            ui->stackedWidget->setCurrentIndex(4);


            ui->LE_ATypeAmende->setText("");
            ui->LE_APrixAmende->setText("");
            ui->LE_ADescAmende->setText("");
            ui->LE_ALieuAmende->setText("");
            ui->LE_ADateAmende->setText("");
            ui->LE_ACINpolicier->setText("");
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionAmende::on_B_AAnnulerAmende_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionAmende::on_B_ModifierAmende_clicked()
{
    QSqlQuery qry;
    QString id_string = QString::number(ui->CB_IDAmende->currentText().toInt());
    qry.prepare("SELECT * FROM amende where id_amende=:id_amende");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->LE_MIDAmende->setText(qry.value(0).toString());
            ui->LE_MTypeAmende->setText(qry.value(1).toString());
            ui->LE_MPrixAmende->setText(qry.value(2).toString());
            ui->LE_MDescAmende->setText(qry.value(3).toString());
            ui->LE_MLieuAmende->setText(qry.value(4).toString());
            ui->LE_MDateAmende->setText(qry.value(5).toString());
            ui->LE_MCINpolicier->setText(qry.value(6).toString());
        }
    }
    ui->CB_IDAmende->setModel(amende.listId_amende());
    ui->stackedWidget->setCurrentIndex(6);
}

void GestionAmende::on_B_MConfirmerAmende_clicked()
{

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la modification", "Confirmer la modification de l'Amende?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        amende.setId_amende(ui->LE_MIDAmende->text().toInt());
        amende.setType_amende(ui->LE_MTypeAmende->text());
        amende.setPrix_amende(ui->LE_MPrixAmende->text().toFloat());
        amende.setDescription_amende(ui->LE_MDescAmende->toPlainText());
        amende.setLieu_amende(ui->LE_MLieuAmende->text());
        amende.setDate_amende(ui->LE_MDateAmende->text());
        amende.setCIN_policier(ui->LE_MCINpolicier->text().toInt());
        if(amende.modifier_amende()) {
            ui->T_Amende->setModel(amende.afficher_amende());
            ui->CB_IDAmende->setModel(amende.listId_amende());
            ui->stackedWidget->setCurrentIndex(4);

            ui->LE_ATypeAmende->setText("");
            ui->LE_APrixAmende->setText("");
            ui->LE_ADescAmende->setText("");
            ui->LE_ALieuAmende->setText("");
            ui->LE_ADateAmende->setText("");
            ui->LE_MCINpolicier->setText("");

        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionAmende::on_B_MAnnulerAmende_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionAmende::on_B_BackToMenu_clicked()
{

}

void GestionAmende::on_B_SupprimerAmende_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la suppression", "Confirmer la suppression de l'Amende?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        amende.setId_amende(ui->CB_IDAmende->currentText().toInt());
        if(amende.supprimer_amende(amende.getId_amende())) {
            qDebug() << "Suppression Complet";
            ui->T_Amende->setModel(amende.afficher_amende());
            ui->CB_IDAmende->setModel(amende.listId_amende());
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionAmende::on_B_Excel_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        EXCEL obj(fileName, "mydata", ui->T_Policier);

        //colums to export

        obj.addField(1, "cin_policier", "number");
        obj.addField(2, "nom_policier", "char(20)");
        obj.addField(3, "prenom_policier", "char(20)");
         obj.addField(4, "grade_policier", "char(20)");
         obj.addField(5, "mdp_policier", "char(20)");
         obj.addField(6, "photo_policier", "char(20)");
         obj.addField(7, "secteur_policier", "char(20)");




        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }





        /*QPrinter printer (QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);
                QTextDocument doc;
                doc.setHtml(strStream);
                doc.setPageSize(printer.pageRect().size());
                doc.print(&printer);*/
}

void GestionAmende::on_B_Recherche_clicked()
{
       QString nom_policier =ui->LE_ChercherNom->text();
        QString prenom_policier = ui->LE_ChercherPrenom->text();

        if (nom_policier != ""){
       ui->T_Policier->setModel(policier.Chercher_policier1( nom_policier)) ;}
        if (prenom_policier != ""){
           ui->T_Policier->setModel(policier.Chercher_policier2(prenom_policier)) ;}



}
