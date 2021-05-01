#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "citoyen.h"
#include "service.h"
#include "notification.h"
#include "smtp.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QDebug>
#include <QProcess>
#include <QDialog>
#include <QFileDialog>
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
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPieSeries>
#include <QPlainTextEdit>
#include <QDebug>
#include<excel.h>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     son=new QSound(":/ressources/cassette-player-button-3.wav");
    ui->stackedWidget->setCurrentIndex(0);
    ui->mdp->setEchoMode(QLineEdit::Password);
    ui->LE_ADureeService->setValidator(new QIntValidator(1, 99999999, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_B_GestionCitoyen_clicked()
{
             son->play();
    ui->T_Citoyens ->setModel(C.afficher());
       ui->CB_IDCitoyen ->setModel(C.listId());
       ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_B_GestioService_clicked()
{
      son->play();
    ui->T_Service ->setModel(S.afficher());
    ui->CB_IDService->setModel(S.listId());
    ui->CB_NomCitoyen->setModel(C.listId());
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_B_BackToGestions_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
      son->play();
}

void MainWindow::on_B_AccederProfil_clicked()
{
    son->play();
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
            ui->LE_PAdresseCit->setText(qry.value(6).toString());
            ui->LE_PNomPereCit->setText(qry.value(7).toString());
            ui->LE_PProfessionCit->setText(qry.value(8).toString());
            ui->LE_PEtatCitoyen->setText(qry.value(9).toString());
            ui->LE_Pregion->setText(qry.value(10).toString());
            ui->stackedWidget->setCurrentIndex(4);
        }
    }

}

void MainWindow::on_B_AjouterCitoyen_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
  son->play();
}

void MainWindow::on_B_AAnnulerCitoyen_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
      son->play();
}

void MainWindow::on_B_AConfirmerCitoyen_clicked()
{
    son->play();
    bool overAll = false, nom_B,prenom_B ;

    QString nom = ui->LE_ANomCitoyen->text();
    QString prenom = ui->LE_APrenomCitoyen->text();
    QDate date_Naiss= ui->DE_ADateNaissCit->date();
    QString lieu_Naiss = ui->LE_ALieuNaissCit->text();
    QString mail = ui->LE_AMailCitoyen->text();
    QString adresse = ui->LE_AAdresseCit->text();
    QString nom_pere = ui->LE_ANomPereCit->text();
    QString profession = ui->CB_Aprofession ->currentText();
    QString etat_civil = ui->CB_Aetatciv->currentText();
    QString region = ui->CB_Aregion->currentText();
        if(nom.length() < 3) {
                nom_B = false;
                ui->L_ANomCitoyenA->setText(" 3 characteres minimum pour le Nom");
                ui->L_ANomCitoyenA->setStyleSheet("QLabel{color: red; font-size: 12px;}");
            }
            else {
                nom_B = true;
                nom[0] = nom[0].toUpper();
                ui->L_ANomCitoyenA->setText("Validé");
                ui->L_ANomCitoyenA->setStyleSheet("QLabel{color: green; font-size: 12px;}");
            }
        if(prenom.length() < 3) {
               prenom_B = false;
                ui->L_APrenomCitoyenA->setText(" 3 characteres minimum pour le Prenom");
                ui->L_APrenomCitoyenA->setStyleSheet("QLabel{color: red; font-size: 12px;}");
            }
            else {
                prenom_B = true;
                prenom[0] = prenom[0].toUpper();
                ui->L_APrenomCitoyenA->setText("Validé");
                ui->L_APrenomCitoyenA->setStyleSheet("QLabel{color: green; font-size: 12px;}");
            }
(nom_B&& prenom_B )? overAll = true : overAll = false;
 if(overAll){


  QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout du citoyen?", QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes) {

       Citoyen C(nom,prenom,date_Naiss,lieu_Naiss,mail, adresse,nom_pere,profession,etat_civil,region);
       if(C.ajouter()) {
                ui->T_Citoyens ->setModel(C.afficher());
                ui->CB_IDCitoyen ->setModel(C.listId());
                ui->stackedWidget->setCurrentIndex(1);

                ui->LE_ANomCitoyen ->setText("");
                ui->LE_APrenomCitoyen ->setText("");
                //ui->DE_ADateNaissCit->setDate();
                ui->LE_ALieuNaissCit->setText("");
                ui->LE_AMailCitoyen->setText("");
                ui->LE_AAdresseCit ->setText("");
                ui->LE_ANomPereCit ->setText("");
                ui->CB_Aprofession->setCurrentText("");
                ui->CB_Aetatciv ->setCurrentText("");
                ui->CB_Aregion ->setCurrentText("");
                N.notifications_ajoutercitoyen();
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
    }
    }
 }

}

void MainWindow::on_B_MAnnulerCitoyen_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
      son->play();
}

void MainWindow::on_B_MConfirmerCitoyen_clicked()
{
     son->play();
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la modification", "Confirmer la modification du citoyen?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        Citoyen C;
        C.setid(ui->CB_IDCitoyen ->currentText().toInt());
        C.setnom(ui->LE_MNomCitoyen ->text());
        C.setprenom(ui->LE_MPrenomCitoyen ->text());
        C.setdatenaiss(ui->DE_MDateNaissCit ->date());
        C.setlieunaiss(ui->LE_MLieuNaissCit ->text());
        C.setmail(ui->LE_MMailCitoyen ->text());
        C.setadresse(ui->LE_MAdresseCit ->text());
        C.setnompere(ui->LE_MNomPereCit->text());
        C.setprofession(ui->CB_Mprofession ->currentText());
        C.setetatcivil(ui->CB_Metatciv ->currentText());
        C.setregion(ui->CB_Mregion ->currentText());
qDebug() << C.getdatenaiss();
        if(C.modifier()) {
            ui->T_Citoyens->setModel(C.afficher());
            ui->CB_IDCitoyen->setModel(C.listId());
            ui->stackedWidget->setCurrentIndex(1);
            ui->LE_ANomCitoyen->setText("");
            ui->LE_APrenomCitoyen->setText("");
            //QDate date_Naiss = ui->DE_MDateNaissCit->date();
          //  ui->DE_MDateNaissCit->setDate();
            ui->LE_ALieuNaissCit->setText("");
            ui->LE_AMailCitoyen->setText("");
            ui->LE_AAdresseCit->setText("");
            ui->LE_ANomPereCit->setText("");
            ui->CB_Aprofession->setCurrentText("");
            ui->CB_Aetatciv->setCurrentText("");
             ui->CB_Aregion->setCurrentText("");
            N.notifications_modifiercitoyen();
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }

}

void MainWindow::on_B_SupprimerCitoyen_clicked()
{
     son->play();
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la suppression", "Confirmer la suppression du lcitoyen?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        C.setid(ui->CB_IDCitoyen ->currentText().toInt());
        if(C.supprimer(C.getid())) {
            qDebug() << "Suppression Complet";
            ui->T_Citoyens ->setModel(C.afficher());
            ui->CB_IDCitoyen ->setModel(C.listId());
             ui->stackedWidget->setCurrentIndex(1);
              N.notifications_supprimercitoyen();
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }

}

void MainWindow::on_B_MConfirmerCitoyen_2_clicked()
{
    son->play();
    QSqlQuery qry;
    QString id_string = QString::number(ui->CB_IDCitoyen->currentText().toInt());
    qry.prepare("SELECT * FROM citoyens where id=:id");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->LE_MNomCitoyen ->setText(qry.value(1).toString());
            ui->LE_MPrenomCitoyen->setText(qry.value(2).toString());
            ui->DE_MDateNaissCit->setDate(qry.value(3).toDate());
            ui->LE_MLieuNaissCit->setText(qry.value(4).toString());
            ui->LE_MMailCitoyen->setText(qry.value(5).toString());
            ui->LE_MAdresseCit->setText(qry.value(6).toString());
            ui->LE_MNomPereCit->setText(qry.value(7).toString());
            ui->CB_Mprofession->setCurrentText(qry.value(8).toString());
            ui->CB_Metatciv->setCurrentText(qry.value(9).toString());
            ui->CB_Mregion->setCurrentText(qry.value(10).toString());
        }
    }
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_B_returnCitoyen_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
      son->play();
}

void MainWindow::on_B_AjouterService_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
      son->play();
}

void MainWindow::on_B_ModifierService_clicked()
{
    son->play();
    QSqlQuery qry;
    QString id_string = QString::number(ui->CB_IDService->currentText().toInt());
    QString duree_string = QString::number(ui->LE_MDureeService->text().toInt());
    qry.prepare("SELECT * FROM services where id=:id");
    qry.bindValue(0, id_string);
    qry.bindValue(2, duree_string);
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

void MainWindow::on_B_AAnnulerService_clicked()
{
    son->play();
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_B_AConfirmerService_clicked()
{
    son->play();

     bool overAll = false, descrip_B;
        QString libelle = ui->LE_ATypeService->text();
        int duree = ui->LE_ADureeService->text().toInt();
        QString duree_l = ui->LE_ADureeService->text();
        QString papiers_necess = ui->LE_APapierService->text();
        QString description = ui->TE_ADescService->toPlainText();
        int id_citoyen=ui->CB_NomCitoyen->currentText().toInt();
         int id_policier=ui->CB_Idpolicier->currentText().toInt();

         if(description.length() < 8) {
                descrip_B = false;
                ui->L_ADescripServiceA->setText("Il faut au minimum 20 characteres ");
                ui->L_ADescripServiceA->setStyleSheet("QLabel{color: red; font-size: 12px;}");
            }
            else {
                descrip_B = true;
                ui->L_ADescripServiceA->setText("Validé");
                ui->L_ADescripServiceA->setStyleSheet("QLabel{color: green; font-size: 12px;}");
            }
          (descrip_B )? overAll = true : overAll = false;
         if(overAll) {
 QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout du service?", QMessageBox::Yes | QMessageBox::No);
         if(reply == QMessageBox::Yes) {
    Service S(libelle,duree,papiers_necess,description,id_citoyen,id_policier);
    if(S.ajouter()) {
        ui->T_Service ->setModel(S.afficher());
        ui->CB_IDService ->setModel(S.listId());
        ui->CB_Idpolicier ->setModel(S.listId());
        ui->stackedWidget->setCurrentIndex(5);

        ui->LE_ATypeService ->setText("");
        ui->LE_ADureeService ->setText("");
        ui->LE_APapierService->setText("");
        ui->TE_ADescService->setText("");
        N.notifications_ajouterservice();

    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
    }
    }
         }

}

void MainWindow::on_B_MAnnulerService_clicked()
{
    son->play();
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_B_MConfirmerService_clicked()
{
    son->play();
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la modification", "Confirmer la modification du service?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        Service S;
        S.setid(ui->CB_IDService ->currentText().toInt());
        S.setlibelle(ui->LE_MTypeService ->text());
        S.setduree(ui->LE_MDureeService ->text().toInt());
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
            N.notifications_modifierservice();
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }

}

void MainWindow::on_B_BackToGestions_2_clicked()
{
         son->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_B_SupprimerService_clicked()
{
    son->play();
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la suppression", "Confirmer la suppression du service?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        S.setid(ui->CB_IDService->currentText().toInt());
        if(S.supprimer(S.getid())) {
            qDebug() << "Suppression Complet";
            ui->T_Service->setModel(S.afficher());
            ui->CB_IDService->setModel(S.listId());
             N.notifications_supprimerservice();
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }

}

void MainWindow::on_LE_recherche_textChanged(const QString &arg1)
{
    QString by=ui->CB_recherche->currentText();
            ui->T_Citoyens->setModel(C.rechercher(arg1,by));

}

void MainWindow::on_LE_rechercheS_textChanged(const QString &arg1)
{
    QString by=ui->CB_rechercheS->currentText();
            ui->T_Service->setModel(S.rechercher(arg1,by));
}

void MainWindow::on_B_Trier_clicked()
{
    son->play();
    QString Tri = ui->CB_Tricitoyen->currentText();
            ui->T_Citoyens->setModel(C.Trier(Tri));

}






void MainWindow::on_B_TrierS_clicked()
{
               son->play();
    QString Tri = ui->CB_TriService->currentText();
            ui->T_Service->setModel(S.Trier(Tri));

}

void MainWindow::on_B_ResetTableIntervenant_2_clicked()
{
    son->play();
    ui->T_Citoyens ->setModel(C.afficher());

}

void MainWindow::on_B_ResetTableIntervenant_clicked()
{
     son->play();
    ui->T_Service ->setModel(S.afficher());
}

void MainWindow::on_B_EnvoyeMail_clicked()
{
    son->play();
    QSqlQuery qry;
    QString id_string = QString::number(ui->CB_IDCitoyen->currentText().toInt());
    qry.prepare("SELECT * FROM citoyens where id=:id");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->lineEdit->setText(qry.value(5).toString());
        }
    }
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_pushButton_2_clicked()

    {
    son->play();
        Smtp* smtp = new Smtp("myriam.brahmi@esprit.tn",ui->mdp->text(), "smtp.gmail.com");
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
 if( !files.isEmpty() )
          smtp->sendMail("myriam.brahmi@esprit.tn", ui->lineEdit->text() , ui->lineEdit_3->text(),ui->msg->toPlainText(),files);
 else
     smtp->sendMail("myriam.brahmi@esprit.tn", ui->lineEdit->text() , ui->lineEdit_3->text(),ui->msg->toPlainText());
          ui->stackedWidget->setCurrentIndex(4);
          N.notifications_envoyermail();
           son->play();
    }


void MainWindow::on_B_returnCitoyen_3_clicked()
{
    son->play();
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_browseBtn_clicked()
{
    son->play();
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );
}

void MainWindow::on_B_ModifierService_2_clicked()
{
    son->play();
    QPrinter printer (QPrinter::PrinterResolution);
        QPrintDialog dlg(&printer,this);
        if (dlg.exec() == QDialog::Rejected)
        {
            return;
        }
    QString strStream;
        QString currentDate = QDateTime().currentDateTime().toString();
        QTextStream out(&strStream);
        const int rowCount = ui->T_Service->model()->rowCount();
        const int columnCount = ui->T_Service->model()->columnCount();
        out <<
         "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<QString("<title>%1</title>\n").arg("strTitle")
        <<"</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
         <<QString(currentDate)
        <<//"<align='right'> " << datefich << "</align>"
        "<center> <img src=""lien logo mtaa application"" width=""100"" height=""100"" > <br> <br><H1>EXTRAIT DE NAISSANCE</H1> <br> <br><table border=1 cellspacing=0 cellpadding=2>\n";
        // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
        for (int column = 0; column < columnCount; column++)
        if (!ui->T_Service->isColumnHidden(column))
        out << QString("<th>%1</th>").arg(ui->T_Service->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";
        // data table
        for (int row = 0; row < rowCount; row++)
        {
        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
        for (int column = 0; column < columnCount; column++)
        {
        if (!ui->T_Service->isColumnHidden(column))
        {
        QString data = ui->T_Service->model()->data(ui->T_Service->model()->index(row, column)).toString().simplified();
        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
        }
        }
        out << "</tr>\n";
        }
        out <<  "</table> </center>\n"
             "<br> <br> <br> <br>"
        "</body>\n"
        "<footer>\n"
                "<div class = ""container"">"
                    "<div class = ""row"">"
                        "<div>"
                            "<div><img src="":/ressources/image/logoo.png"" width=""60"" height=""60""> <span>DEBUG_ENTITY</div>\n"
                            "<br>"

                        "</div>"
                    "</div>"
                "</div>"
        "</footer>\n"
        "</html>\n";
        QString filter = "pdf (*.pdf) ";
        QString fileName = QFileDialog::getSaveFileName(this, "save in", QDir::homePath(),filter);
        if (QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".pdf");
        }

        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);
        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer.pageRect().size());
        doc.print(&printer);
            N.notifications_pdfservice();

}

void MainWindow::on_pdf_clicked()
{
    son->play();
    QPrinter printer (QPrinter::PrinterResolution);
        QPrintDialog dlg(&printer,this);
        if (dlg.exec() == QDialog::Rejected)
        {
            return;
        }
    QString strStream;
        QString currentDate = QDateTime().currentDateTime().toString();
        QTextStream out(&strStream);
        const int rowCount = ui->T_Service->model()->rowCount();
        const int columnCount = ui->T_Service->model()->columnCount();
        out <<
         "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<QString("<title>%1</title>\n").arg("strTitle")
        <<"</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
         <<QString(currentDate)
        <<//"<align='right'> " << datefich << "</align>"
        "<center> <img src=""lien logo mtaa application"" width=""100"" height=""100"" > <br> <br><H1>EXTRAIT DE NAISSANCE</H1> <br> <br><table border=1 cellspacing=0 cellpadding=2>\n";
        // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
        for (int column = 0; column < columnCount; column++)
        if (!ui->T_Service->isColumnHidden(column))
        out << QString("<th>%1</th>").arg(ui->T_Service->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";
        // data table
        for (int row = 0; row < rowCount; row++)
        {
        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
        for (int column = 0; column < columnCount; column++)
        {
        if (!ui->T_Service->isColumnHidden(column))
        {
        QString data = ui->T_Service->model()->data(ui->T_Service->model()->index(row, column)).toString().simplified();
        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
        }
        }
        out << "</tr>\n";
        }
        out <<  "</table> </center>\n"
             "<br> <br> <br> <br>"
        "</body>\n"
        "<footer>\n"
                "<div class = ""container"">"
                    "<div class = ""row"">"
                        "<div>"
                            "<div><img src="":/ressources/image/logoo.png"" width=""60"" height=""60""> <span>DEBUG_ENTITY</div>\n"
                            "<br>"

                        "</div>"
                    "</div>"
                "</div>"
        "</footer>\n"
        "</html>\n";
        QString filter = "pdf (*.pdf) ";
        QString fileName = QFileDialog::getSaveFileName(this, "save in", QDir::homePath(),filter);
        if (QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".pdf");
        }

        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);
        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer.pageRect().size());
        doc.print(&printer);
            N.notifications_pdfservice();

}

void MainWindow::on_B_BackToGestions_7_clicked()
{
    son->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_statistics_clicked()
{
    son->play();
    QSqlQuery qry;
    int Autres=C.ProfA();
    int Em=C.ProfEm();
    int Pr=C.ProfPr();
    int Med=C.ProfMed();
    int Dir=C.ProfDir();

    QPieSeries *series = new QPieSeries();
    series->append("Employe", Em);
    series->append("Directeur",Dir);
    series->append("Medecin", Med);
    series->append("Professeur", Pr);
    series->append("Autres...", Autres);
    series->setHoleSize(0.5);
    series->setPieSize(0.8);

    QPieSlice *em = series->slices().at(0);
    QPieSlice *dir = series->slices().at(1);
    QPieSlice *med= series->slices().at(2);
    QPieSlice *pr= series->slices().at(3);
    em->setBrush(Qt::red);
    med->setBrush(Qt::blue);
    pr->setBrush(Qt::green);
    dir->setPen(QPen(Qt::green, 1));
    dir->setBrush(Qt::white);
    med->setBrush(Qt::darkBlue);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Profession des Citoyens");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->F_Statistic);
    QLineSeries *seriesss = new QLineSeries();
    seriesss->append(0, 12);
    seriesss->append(1, 8);
    seriesss->append(2, 10);
    seriesss->append(3, 8);
    seriesss->append(4, 4);
    QChart *charttt = new QChart();
    charttt->legend()->hide();
    charttt->addSeries(seriesss);
    charttt->createDefaultAxes();
    QFont font;
    font.setPixelSize(18);
    charttt->setTitleFont(font);
    charttt->setTitleBrush(QBrush(Qt::black));
    charttt->setTitle("Ages des Citoyens");
    QPen pen(QRgb(0x000000));
    pen.setWidth(5);
    seriesss->setPen(pen);
    charttt->setAnimationOptions(QChart::AllAnimations);
    QCategoryAxis *axisX = new QCategoryAxis();
    axisX->append("18-25ans",0);
    axisX->append("26-35ans",1);
    axisX->append("36-45ans",2);
    axisX->append("46-60ans",3);
    axisX->append("+60ans",4);
    charttt->setAxisX(axisX, seriesss);
    QChartView *chartViewww = new QChartView(charttt);
    chartViewww->setRenderHint(QPainter::Antialiasing);

    chartViewww->setParent(ui->F_StatisticAge);
    /********************* BEGIN : Bars->Localisation *********************/
    int NE=C.NE();
    int NO=C.NO();
    int CE=C.CE();
    int CO=C.CO();
    int SE=C.SE();
    int SO=C.SO();

    QBarSet *set0 = new QBarSet("Tunis, Bizerte..");
    QBarSet *set1 = new QBarSet("Beja, Le Kef..");
    QBarSet *set2 = new QBarSet("Sousse, Mehdia..");
    QBarSet *set3 = new QBarSet("Kairouan..");
    QBarSet *set4 = new QBarSet("Sfax, Gabes..");
    QBarSet *set5 = new QBarSet("Gafsa, Tozeur..");

    *set0 << NE << 0 << 0 << 0 << 0 << 0;
    *set1 << 0 << NO << 0 << 0 << 0 << 0;
    *set2 << 0 << 0 << CE << 0 << 0 << 0;
    *set3 << 0 << 0 << 0 << CO << 0 << 0;
    *set4 << 0 << 0 << 0 << 0 << SE << 0;
    *set5 << 0 << 0 << 0 << 0 << 0 << SO;

    QBarSeries *seriess = new QBarSeries();
    seriess->append(set0);
    seriess->append(set1);
    seriess->append(set2);
    seriess->append(set3);
    seriess->append(set4);
    seriess->append(set5);

    QChart *charts = new QChart();
    charts->addSeries(seriess);
    charts->setTitle("Localisation des Intervenants");
    charts->setAnimationOptions(QChart::AllAnimations);
    QStringList categories;
    categories << "Nord-Est" << "Nord-Ouest" << "Centre-Est" << "Centre-Ouest" << "Sud-Est" << "Sud-Ouest";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    charts->createDefaultAxes();
    charts->setAxisX(axis, seriess);
    charts->legend()->setVisible(true);
    charts->legend()->setAlignment(Qt::AlignBottom);
    QChartView *chartsView = new QChartView(charts);
    chartsView->setRenderHint(QPainter::Antialiasing);
    chartsView->setParent(ui->F_StatisticLocal);
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_clicked()
{
    son->play();
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        EXCEL obj(fileName, "mydata", ui->T_Citoyens);

        //colums to export

        obj.addField(0, "Nom", "char(50)");
        obj.addField(1, "Prenom", "char(50)");
        obj.addField(2, "Date_Naiss", "date");
         obj.addField(3, "Lieu_Naiss", "char(20)");
         obj.addField(4, "Mail", "char(50)");
         obj.addField(5, "Adresse", "char(50)");
         obj.addField(6, "Nom_pere", "char(20)");
         obj.addField(6, "Profession", "char(50)");
         obj.addField(6, "Etat_civil", "char(50)");
         obj.addField(6, "région", "char(20)");

}
