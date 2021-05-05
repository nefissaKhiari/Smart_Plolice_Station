#include "gestionequipement.h"
#include "ui_gestionequipement.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QDebug>
#include<equipement.h>
#include <maintenance.h>
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
GestionEquipement::GestionEquipement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GestionEquipement)
{
    ui->setupUi(this);
    song=new QSound(":/ressource/image/cassette-player-button-3.wav");
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

void GestionEquipement::INFORMER(QLabel *label, QString message, int duration){
    label->setVisible(true);
    label->setText(message);
    QTimer::singleShot(duration, ui->labelmessage, &QLabel::hide);
     //QTimer::singleShot(duration, ui->labelmessage_2, &QLabel::hide);

}

void GestionEquipement::on_B_GestionEquipement_clicked()
{
    song->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void GestionEquipement::on_B_AjouterEquipement_clicked()
{
    song->play();
    ui->CB_CIN_Policier->setModel(equipement.listCIN());
    ui->AAlerteRef->setText("");
    ui->AAlerteQuantite->setText("");
    ui->AAlerteEtat->setText("");
    ui->AAlerteNom->setText("");
    ui->AAlertePoid->setText("");
    ui->AAlerteTaille->setText("");
    ui->stackedWidget->setCurrentIndex(2);
}

void GestionEquipement::on_B_ModifierEquipement_clicked()
{
    song->play();
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
    song->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void GestionEquipement::on_B_GestionMaintenance_clicked()
{
    song->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionEquipement::on_B_AjouterMaintenance_clicked()
{
    song->play();
    ui->Cb_AMaintenance->setModel(equipement.listRef());
    ui->stackedWidget->setCurrentIndex(5);
}

void GestionEquipement::on_B_ModifierMaintenance_clicked()
{
    song->play();
    QSqlQuery qry;
    QString id_string = QString::number(ui->CB_IDMaintenance->currentText().toInt());
    qry.prepare("SELECT * FROM maintenance where idmaintenance=:idmaintenance");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->dateEditDebut->setDate(qry.value(1).toDate());
            ui->LE_MCout->setText(qry.value(2).toString());
            ui->dateEdit_2Fin->setDate(qry.value(3).toDate());
            ui->LE_MIDEquipement->setText(qry.value(4).toString());
            ui->CB_MEtat->setCurrentText(qry.value(5).toString());
        }
    }
    ui->stackedWidget->setCurrentIndex(6);
}

void GestionEquipement::on_B_BackToGestionEquipement_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    song->play();
}

void GestionEquipement::on_B_BackToGestionsEquipement_4_clicked()
{
    song->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void GestionEquipement::on_B_BackToGestions_2_clicked()
{
    song->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void GestionEquipement::on_B_BackToGestionMaintenance_5_clicked()
{
    song->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionEquipement::on_B_BackToGestionmaintenance_6_clicked()
{
    song->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionEquipement::on_B_AConfirmerEquipement_clicked()
{
     song->play();
     bool overAll = false, ref_b, quantite_b, taille_B, etat_B,poid_B ,nom_B ;

    int reference = ui->LE_AReferenceEquipement->text().toInt();
    QString ref_l=ui->LE_AReferenceEquipement->text();

    int quantite = ui->LE_AQuantiteEquipement->text().toInt();
    QString quantite_l=ui->LE_AQuantiteEquipement->text();

    QString taille = ui->LE_ATailleEquipement->text();

    QString etat = ui->LE_AEtatEquipement->text();

    int poid = ui->LE_APoidEquipement->text().toInt();
    QString poid_l=ui->LE_APoidEquipement->text();
    int CIN_policier=ui->CB_CIN_Policier->currentText().toInt();

    QString nom = ui->LE_ANomEquipement->text();
    if(ref_l.length()!=9) {
        ref_b = false;
        ui->AAlerteRef->setText("Il faut 9 charactere de facon XXXXXXXXXX");
        ui->AAlerteRef->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        ref_b = true;
        ui->AAlerteRef->setText("Ok");
        ui->AAlerteRef->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }
    // END : reference


    if(quantite<5) {
        quantite_b = false;
        ui->AAlerteQuantite->setText("Il faut une quantite de 5 Minimum");
        ui->AAlerteQuantite->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        quantite_b = true;
        ui->AAlerteQuantite->setText("Ok");
        ui->AAlerteQuantite->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }

    if(taille.length() <2) {
        taille_B = false;
        ui->AAlerteTaille->setText("Il faut 3 charactere Minimum");
        ui->AAlerteTaille->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        taille_B = true;
        taille[0] = taille[0].toUpper();
        ui->AAlerteTaille->setText("Ok");
        ui->AAlerteTaille->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }

    if(etat.length() < 5) {
        etat_B = false;
        ui->AAlerteEtat->setText("Il faut 5 charactere Minimum");
        ui->AAlerteEtat->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        etat_B = true;
        taille[0] = taille[0].toUpper();
        ui->AAlerteEtat->setText("Ok");
        ui->AAlerteEtat->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }

    if(poid<1) {
        poid_B = false;
        ui->AAlertePoid->setText("Il faut un poid de 1kg Minimum");
        ui->AAlertePoid->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        poid_B = true;
        ui->AAlertePoid->setText("Ok");
        ui->AAlertePoid->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }
    if(nom.length() < 5) {
        nom_B = false;
        ui->AAlerteNom->setText("Il faut 5 charactere Minimum");
        ui->AAlerteNom->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        nom_B  = true;
        taille[0] = taille[0].toUpper();
        ui->AAlerteNom->setText("Ok");
        ui->AAlerteNom->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }

    /*************** END : Controle de Saisir L'ajout d'Intervenant ***************/
    (ref_b && quantite_b && taille_B && etat_B && poid_B && nom_B )? overAll = true : overAll = false;

    /*************** BEGIN : Ajouter sur BaseDonnee ***************/
    if(overAll) {
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout de l'equipement?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        Equipement equipement(reference, quantite, taille, etat, poid, nom, CIN_policier);
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
            INFORMER(ui->labelmessage,"Equipement ajouter",3000);

        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
    }
}



void GestionEquipement::on_B_MConfirmerEquipement_clicked()
{
    song->play();
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer modification de l'equipement?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        int reference = ui->LE_MReference->text().toInt();
        int quantite = ui->LE_MQuantiteEquipement->text().toInt();
        QString taille = ui->LE_MTailleEquipement->text();
        QString etat = ui->LE_MEtatEquipement->text();
        int poid = ui->LE_MPoidEquipement->text().toInt();
        QString nom = ui->LE_MNomEquipement->text();
        Equipement equipement(reference, quantite, taille, etat, poid, nom,NULL);
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
            INFORMER(ui->labelmessage,"Equipement modifier",3000);

        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("Modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionEquipement::on_B_SupprimerEquipement_clicked()
{
    song->play();
    Equipement equipement;
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la suppression", "Confirmer la suppression de l'equipement?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        equipement.setReference(ui->CB_IDEquipement->currentText().toInt());
        if(equipement.supprimer(equipement.getReference())) {
            qDebug() << "Suppression Complet";
            ui->T_Equipement->setModel(equipement.afficher());
            ui->CB_IDEquipement->setModel(equipement.listRef());
            INFORMER(ui->labelmessage,"Equipement suprimer",3000);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionEquipement::on_B_AConfirmerMaintenance_clicked()
{
    song->play();
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout de l'equipement au maintenance?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        QDate date = ui->dateEditDebut_2->date();
        int cout = ui->LE_ACout->text().toInt();
        QDate date2 = ui->dateEdit_2Fin_2->date();
        int reference = ui->Cb_AMaintenance->currentText().toInt();
        Maintenance maintenance(date, cout , date2, reference);
        if(maintenance.ajouter()) {
            ui->CB_IDMaintenance->setModel(maintenance.listId());
            ui->T_Maintenance->setModel(maintenance.afficher());
            ui->stackedWidget->setCurrentIndex(4);



            ui->LE_ACout->setText("");


        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void GestionEquipement::on_B_SupprimerMaintenance_clicked()
{
    song->play();
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
    song->play();
    QSqlQuery qry;
    QString etatp;
    QString id_string = QString::number(ui->CB_IDMaintenance->currentText().toInt());
    qry.prepare("SELECT * FROM maintenance where idmaintenance=:idmaintenance");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {
            etatp=qry.value(5).toString();
        }
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la modification", "Confirmer la modification du maintenance?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        maintenance.setIdmaintenance(ui->CB_IDMaintenance->currentText().toInt());
        maintenance.setCout(ui->LE_MCout->text().toInt());
        maintenance.setDatedebut(ui->dateEditDebut_2->date());
        maintenance.setDatefin(ui->dateEdit_2Fin_2->date());
        maintenance.setReference(ui->LE_MIDEquipement->text().toInt());
        maintenance.setEtat(ui->CB_MEtat->currentText());
        if(maintenance.modifier()) {
            if(etatp!=maintenance.getEtat())
            {
                notification.notifications_supprimermaintenance();

            }
            ui->T_Maintenance->setModel(maintenance.afficher());
            ui->CB_IDMaintenance->setModel(maintenance.listId());
            ui->stackedWidget->setCurrentIndex(4);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}



void GestionEquipement::on_B_Trier_clicked()
{
    song->play();
    QString Tri = ui->CB_TriEquipement->currentText();
    ui->T_Equipement->setModel(equipement.Trier(Tri));

}

void GestionEquipement::on_B_ResetTableEquipement_clicked()
{
    song->play();
    ui->LE_ChercherReference->setText("");
    ui->T_Equipement->setModel(equipement.afficher());
}

void GestionEquipement::on_pushButton_clicked()
{
    song->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionEquipement::on_statestique_clicked()
{
    song->play();
    int fixer=maintenance.sfixer();
    int nonfixer=maintenance.snfixer();
    qDebug()<<fixer;
    qDebug()<<nonfixer;

    QPieSeries *series = new QPieSeries();
    series->append("Fixer",fixer);
    series->append("Non Fixer",nonfixer);
    series->setHoleSize(0.5);
    series->setPieSize(0.8);

    QPieSlice *f = series->slices().at(0);
    QPieSlice *nf = series->slices().at(1);
    /*********************** Labels
    tn->setLabelVisible(true);
    fr->setLabelVisible(true);
    ag->setLabelVisible(true);
    lb->setLabelVisible(true);
    autres->setLabelVisible(true);
    ******************************/
    f->setBrush(Qt::red);
    nf->setBrush(Qt::blue);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Etat des equipements");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->F_Statisticc);
    ui->stackedWidget->setCurrentIndex(7);
}


void GestionEquipement::on_LE_ChercherReference_textChanged(const QString &arg1)
{
    song->play();
    QString by = ui->CB_RechercheEquipement->currentText();
    ui->T_Equipement->setModel(equipement.Chercher(arg1, by));
}


void GestionEquipement::on_FBack_clicked()
{
    song->play();
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionEquipement::on_statestique_3_clicked()
{
    song->play();
    ui->text->clear();
    ui->stackedWidget->setCurrentIndex(8);
}

void GestionEquipement::on_Cut_clicked()
{
    ui->text->cut();
}

void GestionEquipement::on_paste_clicked()
{
    ui->text->paste();
}

void GestionEquipement::on_copy_clicked()
{
    ui->text->copy();
}

void GestionEquipement::on_controlZ_clicked()
{
    ui->text->undo();
}

void GestionEquipement::on_refresh_clicked()
{
    ui->text->redo();
}

void GestionEquipement::on_New_File_clicked()
{
    file_path="";
    ui->text->setText("");
}

void GestionEquipement::on_New_Folder_clicked()
{
   QString file_name=QFileDialog::getOpenFileName(this,"choisir le fichier");
   QFile file(file_name);
   file_path=file_name;
   if(!file.open(QFile::ReadOnly | QFile::Text))
   {
      QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("impossible d'ouvrir le fichier.\n" "Cliquer Ok."), QMessageBox::Ok);
      return;
   }
   QTextStream in(&file);
   QString text=in.readAll();
   ui->text->setText(text);
   file.close();
}

void GestionEquipement::on_Edit_clicked()
{
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
       QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("impossible d'ouvrir le fichier.\n" "Cliquer Ok."), QMessageBox::Ok);
       return;
    }
    QTextStream out(&file);
    QString text=ui->text->toPlainText();
    ui->text->setText(text);
    out << text;
    file.flush();
    file.close();
}

void GestionEquipement::on_save_clicked()
{
    QString file_name=QFileDialog::getSaveFileName(this,"choisir le fichier");
    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
       QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("impossible d'ouvrir le fichier.\n" "Cliquer Ok."), QMessageBox::Ok);
       return;
    }
    QTextStream out(&file);
    QString text=ui->text->toPlainText();
    ui->text->setText(text);
    out << text;
    file.flush();
    file.close();
}

void GestionEquipement::on_B_AjouterEquipement_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void GestionEquipement::on_B_AjouterEquipement_2_clicked()
{
    ui->T_AFF_Equipement->setModel(equipement.afficherAffectation());
    ui->stackedWidget->setCurrentIndex(9);

}
