#include "vehiculemission.h"
#include "ui_vehiculemission.h"
#include"vehicule.h"
#include "missions.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDebug>
#include<QMessageBox>
#include<QIntValidator>
#include<QLabel>
#include<QDialog>
#include<QSqlQuery>
#include<QSqlError>
#include <QModelIndex>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include <QMessageBox>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QSound>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPieSeries>



VehiculeMission::VehiculeMission(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VehiculeMission)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->T_Vehicules->setModel(v_tmp.afficher());
    ui->T_Mission->setModel(m_tmp.afficher());


    ui->CB_IDVehicule->setModel(v_tmp.afficherm());


    ui->CB_IDMission->setModel(m_tmp.affichern());

    ui->comboBox_5->setModel(v_tmp.afficherm());




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
            ui->LE_MCinVehicule->setText(query.value(5).toString());
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
    ui->LE_ACinVehicule->setText("");


}

void VehiculeMission::on_B_MAnuulerVehicule_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void VehiculeMission::on_B_ModifierMission_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    int id = ui->CB_IDMission->currentText().toInt();
     ui->LE_Mbox->setModel(v_tmp.afficherm());
    QSqlQuery query;
    query.prepare("SELECT * from missions where id = :id");
    query.bindValue(":id" , id);
    if (query.exec())
    {
        while (query.next())
        {
            ui->LE_MNomMission->setText(query.value(0).toString());
            ui->dateEdit_2->setDate(query.value(1).toDate());
            ui->LE_MLocalMission->setText(query.value(2).toString());
            ui->TE_MDescMission->setText(query.value(3).toString());
            ui->LE_Mbox->setCurrentText(query.value(4).toString());

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
       int CIN_policier = ui->LE_ACinVehicule->text().toInt();

       QMessageBox msgBox;

       vehicule E(matricule, marque, couleur, nb_places, quantite, CIN_policier);
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
               ui->LE_ACinVehicule->setText("");
               ui->comboBox_5->setModel(modal);



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
              ui->T_Mission->setModel(m_tmp.afficher());
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
    int CIN_policier=ui->LE_MCinVehicule->text().toInt();

    QMessageBox msgBox;

    bool test = v_tmp.modifier(marque, couleur, quantite, nb_places, matricule, CIN_policier);

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
    int id;
    QString nom = ui->LE_ANomMission->text();
    QDate datem = ui->dateEdit->date();
    QString localisation = ui->LE_ALocalMission->text();
    QString description = ui->TE_ADescMission->toPlainText();
    int matricule=ui->comboBox_5->currentText().toInt();
    QMessageBox msgBox;

    missions E( id, nom, datem, localisation, description, matricule);
    bool test=E.ajouter();
    if(test)
    {
        msgBox.setText("Ajout avec succés.");
         ui->stackedWidget->setCurrentIndex(4);
            ui->T_Mission->setModel(m_tmp.afficher());
            QSqlQuery *query = new QSqlQuery();
            QSqlQueryModel * modal = new QSqlQueryModel();
            query->prepare("SELECT id from missions");
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
    int id = ui->CB_IDMission->currentText().toInt();
     QString nom = ui->LE_MNomMission->text();
    QDate datem = ui->dateEdit_2->date();
    QString localisation = ui->LE_MLocalMission->text();
    QString description = ui->TE_MDescMission->toPlainText();
    int matricule=ui->LE_Mbox->currentText().toInt();

     QMessageBox msgBox;

    bool test = m_tmp.modifier(id, nom, datem, localisation, description, matricule);

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
    int id = ui->CB_IDMission->currentText().toInt();
    QMessageBox msgbox;

    bool test=m_tmp.supprimer(id);
    if (test)
    {
        msgbox.setText("Suppression avec succés.");
              ui->T_Mission->setModel(m_tmp.afficher());
              QSqlQuery *query = new QSqlQuery();
              QSqlQueryModel * modal = new QSqlQueryModel();
              query->prepare("SELECT id from missions");
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

void VehiculeMission::on_B_Statistics_clicked()
{
    QString strStream;
                                      QTextStream out(&strStream);

                                      const int rowCount = ui->T_Vehicules->model()->rowCount();
                                      const int columnCount = ui->T_Vehicules->model()->columnCount();

                                      out <<  "<html>\n"
                                          "<head>\n"
                                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                          <<  QString("<title>%1</title>\n").arg("strTitle")
                                          <<  "</head>\n"
                                          "<body bgcolor=#ffffff link=#5000A0>\n"

                                         //     "<align='right'> " << datefich << "</align>"
                                          "<center> <H1>Tableaux des vehicules </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                      // headers
                                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                      for (int column = 0; column < columnCount; column++)
                                          if (!ui->T_Vehicules->isColumnHidden(column))
                                              out << QString("<th>%1</th>").arg(ui->T_Vehicules->model()->headerData(column, Qt::Horizontal).toString());
                                      out << "</tr></thead>\n";

                                      // data table
                                      for (int row = 0; row < rowCount; row++) {
                                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                          for (int column = 0; column < columnCount; column++) {
                                              if (!ui->T_Vehicules->isColumnHidden(column)) {
                                                  QString data = ui->T_Vehicules->model()->data(ui->T_Vehicules->model()->index(row, column)).toString().simplified();
                                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                              }
                                          }
                                          out << "</tr>\n";
                                      }
                                      out <<  "</table> </center>\n"
                                          "</body>\n"
                                          "</html>\n";

                                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                                 QPrinter printer (QPrinter::PrinterResolution);
                                  printer.setOutputFormat(QPrinter::PdfFormat);
                                 printer.setPaperSize(QPrinter::A4);
                                printer.setOutputFileName(fileName);

                                 QTextDocument doc;
                                  doc.setHtml(strStream);
                                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                                  doc.print(&printer);
}

void VehiculeMission::on_B_Statistics_2_clicked()
{
    QPrinter printer;
        QPrintDialog dialog(&printer,this);
        dialog.setWindowTitle("imprimer un document");

        if (dialog.exec() != QDialog::Accepted)
            return;


}
