#include "vehiculemission.h"
#include "ui_vehiculemission.h"
#include"vehicule.h"
#include "missions.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>


VehiculeMission::VehiculeMission(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VehiculeMission)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->T_Vehicules->setModel(v_tmp.afficher());
    ui->T_Mission->setModel(m_tmp.afficher());

    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel * modal = new QSqlQueryModel();
    query->prepare("SELECT matricule from vehicules");
    query->exec();
    modal->setQuery(*query);
    ui->CB_IDVehicule->setModel(modal);
    query->prepare("SELECT nom from missions");
    query->exec();
    modal->setQuery(*query);
    ui->CB_IDMission->setModel(modal);


}

VehiculeMission::~VehiculeMission()
{
    delete ui;
}


void VehiculeMission::on_B_GestionVehicule_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void VehiculeMission::on_B_GestionMission_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}


void VehiculeMission::on_B_BackToGestions_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void VehiculeMission::on_B_ModifierVehicule_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

    QString matricule = ui->CB_IDVehicule->currentText();
    ui->LE_MMatriculeVehicule->setText(matricule);
    QSqlQuery query;
    query.prepare("SELECT * from vehicules where matricule = :matricule");
    query.bindValue(":matricule" , matricule);
    if (query.exec())
    {
        while (query.next())
        {
            ui->LE_MMarqueVehicule->setText(query.value(1).toString());
            ui->LE_MQuantiteVehicule->setText(query.value(2).toString());
            ui->LE_MCouleurVehicule->setText(query.value(3).toString());
            ui->LE_MNbplacesVehicule->setText(query.value(4).toString());
        }

    }
}

void VehiculeMission::on_B_AjouterVehicule_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void VehiculeMission::on_B_AAnnulerVehicule_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->LE_AMarqueVehicule->setText("");
    ui->LE_AMatriculeVehicule->setText("");
    ui->LE_ANbplacesVehicule->setText("");
    ui->LE_ACouleurVehicule->setText("");
    ui->LE_AQuantiteVehicule->setText("");


}

void VehiculeMission::on_B_MAnuulerVehicule_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void VehiculeMission::on_B_ModifierMission_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    QString nom = ui->CB_IDMission->currentText();
    ui->LE_MNomMission->setText(nom);
    QSqlQuery query;
    query.prepare("SELECT * from missions where nom = :nom");
    query.bindValue(":nom" , nom);
    if (query.exec())
    {
        while (query.next())
        {
            ui->dateEdit_2->setDate(query.value(1).toDate());
            ui->LE_MLocalMission->setText(query.value(2).toString());
            ui->TE_MDescMission->setText(query.value(3).toString());

        }

    }
}

void VehiculeMission::on_B_AjouterMission_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void VehiculeMission::on_B_AAnnulerMission_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->LE_ANomMission->setText("");
    ui->LE_ALocalMission->setText("");
    ui->TE_ADescMission->setText("");


}

void VehiculeMission::on_B_MAnnulerMission_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void VehiculeMission::on_B_BackToGestions_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void VehiculeMission::on_B_AConfirmerVehicule_clicked()
{
       int matricule = ui->LE_AMatriculeVehicule->text().toInt();
       QString marque = ui->LE_AMarqueVehicule->text();
       QString couleur = ui->LE_ACouleurVehicule->text();
       int quantite = ui->LE_AQuantiteVehicule->text().toInt();
       int nb_places = ui->LE_ANbplacesVehicule->text().toInt();

       QMessageBox msgBox;

       vehicule E(matricule, marque, couleur, nb_places, quantite);
       bool test=E.ajouter();
       if(test)
       {
           msgBox.setText("Ajout avec succés.");
           ui->stackedWidget->setCurrentIndex(1);
               ui->T_Vehicules->setModel(v_tmp.afficher());
               QSqlQuery *query = new QSqlQuery();
               QSqlQueryModel * modal = new QSqlQueryModel();
               query->prepare("SELECT matricule from vehicules");
               query->exec();
               modal->setQuery(*query);
               ui->CB_IDVehicule->setModel(modal);
               ui->LE_AMarqueVehicule->setText("");
               ui->LE_AMatriculeVehicule->setText("");
               ui->LE_ANbplacesVehicule->setText("");
               ui->LE_ACouleurVehicule->setText("");
               ui->LE_AQuantiteVehicule->setText("");



       }

           else {

           msgBox.setText("Echec au niveau de l'ajout.");
       }

       msgBox.exec();
}

void VehiculeMission::on_B_SupprimerVehicule_clicked()
{
    int matricule = ui->CB_IDVehicule->currentText().toInt();
    QMessageBox msgbox;

    bool test=v_tmp.supprimer(matricule);
    if (test)
    {
        msgbox.setText("Suppression avec succés.");
              ui->T_Vehicules->setModel(v_tmp.afficher());
              QSqlQuery *query = new QSqlQuery();
              QSqlQueryModel * modal = new QSqlQueryModel();
              query->prepare("SELECT matricule from vehicules");
              query->exec();
              modal->setQuery(*query);
              ui->CB_IDVehicule->setModel(modal);
    }
    else
        msgbox.setText("Echec au niveau de la Suppression");

      msgbox.exec();

}

void VehiculeMission::on_B_MConfirmerVehicule_clicked()
{
    int matricule = ui->CB_IDVehicule->currentText().toInt();
    QString marque = ui->LE_MMarqueVehicule->text();
    QString couleur = ui->LE_MCouleurVehicule->text();
    int quantite=ui->LE_MQuantiteVehicule->text().toInt();
    int nb_places=ui->LE_MNbplacesVehicule->text().toInt();

    QMessageBox msgBox;

    bool test = v_tmp.modifier(marque, couleur, quantite, nb_places, matricule);

    if (test)
    {
        ui->T_Vehicules->setModel(v_tmp.afficher());
        msgBox.setText("modification avec succes");
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
                msgBox.setText("echec au niveau de la modification");

    msgBox.exec();
}

void VehiculeMission::on_B_AConfirmerMission_clicked()
{
    QString nom = ui->LE_ANomMission->text();
    QDate datem = ui->dateEdit->date();
    QString localisation = ui->LE_ALocalMission->text();
    QString description = ui->TE_ADescMission->toPlainText();

    QMessageBox msgBox;

    missions E(nom, datem, localisation, description);
    bool test=E.ajouter();
    if(test)
    {
        msgBox.setText("Ajout avec succés.");
         ui->stackedWidget->setCurrentIndex(4);
            ui->T_Mission->setModel(m_tmp.afficher());
            QSqlQuery *query = new QSqlQuery();
            QSqlQueryModel * modal = new QSqlQueryModel();
            query->prepare("SELECT nom from missions");
            query->exec();
            modal->setQuery(*query);
            ui->CB_IDMission->setModel(modal);

            ui->LE_ANomMission->setText("");
            ui->LE_ALocalMission->setText("");
            ui->TE_ADescMission->setText("");

}
}

void VehiculeMission::on_B_MConfirmerMission_clicked()
{
    QString nom = ui->CB_IDMission->currentText();
    QDate datem = ui->dateEdit_2->date();
    QString localisation = ui->LE_MLocalMission->text();
    QString description = ui->TE_MDescMission->toPlainText();


    QMessageBox msgBox;

    bool test = m_tmp.modifier(nom, datem, localisation, description);

    if (test)
    {
        ui->T_Mission->setModel(m_tmp.afficher());
        msgBox.setText("modification avec succes");
        ui->stackedWidget->setCurrentIndex(4);

    }
    else
                msgBox.setText("echec au niveau de la modification");

    msgBox.exec();
}

void VehiculeMission::on_B_SupprimerMission_clicked()
{
    QString nom = ui->CB_IDMission->currentText();
    QMessageBox msgbox;

    bool test=m_tmp.supprimer(nom);
    if (test)
    {
        msgbox.setText("Suppression avec succés.");
              ui->T_Mission->setModel(m_tmp.afficher());
              QSqlQuery *query = new QSqlQuery();
              QSqlQueryModel * modal = new QSqlQueryModel();
              query->prepare("SELECT nom from missions");
              query->exec();
              modal->setQuery(*query);
              ui->CB_IDMission->setModel(modal);
    }
    else
        msgbox.setText("Echec au niveau de la Suppression");

      msgbox.exec();
}

void VehiculeMission::on_B_Trier_clicked()
{
    QString Tri = ui->comboBox_2->currentText();
        ui->T_Vehicules->setModel(v_tmp.Trier(Tri));
}

void VehiculeMission::on_lineEdit_returnPressed()
{

}

void VehiculeMission::on_lineEdit_textChanged(const QString &arg1)
{
       QString by=ui->comboBox->currentText();
        ui->T_Mission->setModel(m_tmp.rechercher(arg1,by));

}
