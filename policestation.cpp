#include "policestation.h"
#include "ui_policestation.h"

PoliceStation::PoliceStation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PoliceStation)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    ui->LE_ACinIntervenant->setValidator(new QIntValidator(1, 99999999, this));
}

PoliceStation::~PoliceStation()
{
    delete ui;
}

void PoliceStation::INFORMER(QLabel *label, QString message, int duration){
    label->setVisible(true);
    label->setText(message);
    QTimer::singleShot(duration, ui->L_AlerteIntervenant, &QLabel::hide);
    QTimer::singleShot(duration, ui->L_AlerteAffaire, &QLabel::hide);
}

void PoliceStation::on_B_Connecter_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void PoliceStation::on_B_Deconnecte_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void PoliceStation::on_B_AffaireJuri_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void PoliceStation::on_B_BackToMenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void PoliceStation::on_B_Vehic_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void PoliceStation::on_B_Equip_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void PoliceStation::on_B_BackToMenu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void PoliceStation::on_B_BackToMenu_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void PoliceStation::on_B_GestionIntervenant_clicked()
{
    ui->T_Intervenants->setModel(intervenant.afficher());
    ui->CB_IDIntervenant->setModel(intervenant.listCin());
    ui->stackedWidget->setCurrentIndex(3);
}

void PoliceStation::on_B_GestioAffaire_clicked()
{
    ui->T_Affaire->setModel(affaire.afficher());
    ui->CB_IDAffaire->setModel(affaire.listId());
    ui->stackedWidget->setCurrentIndex(6);
}

void PoliceStation::on_B_BackToGestions_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void PoliceStation::on_B_Statistics_clicked()
{
    /********************* BEGIN : Donut->Nationalite *********************/
    QSqlQuery qry;
    int Autres=intervenant.NatA();
    int Tn=intervenant.NatTn();
    int Ag=intervenant.NatAg();
    int Fr=intervenant.NatFr();
    int Lb=intervenant.NatLb();

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
    lb->setPen(QPen(Qt::green, 1));
    lb->setBrush(Qt::white);
    fr->setBrush(Qt::darkBlue);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Nationalite des Intervenants");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->F_Statistic);
    /********************* END : Donut->Nationalite *********************/

    /********************* BEGIN : Bars->Localisation *********************/
    int NE=intervenant.NE();
    int NO=intervenant.NO();
    int CE=intervenant.CE();
    int CO=intervenant.CO();
    int SE=intervenant.SE();
    int SO=intervenant.SO();

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
    /********************* END : Bars->Localisation *********************/

    /********************* BEGIN : Curve->Localisation *********************/
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
    charttt->setTitle("Salaire des Intervenants");
    QPen pen(QRgb(0x0D74FF));
    pen.setWidth(5);
    seriesss->setPen(pen);
    charttt->setAnimationOptions(QChart::AllAnimations);
    QCategoryAxis *axisX = new QCategoryAxis();
    axisX->append("500DT",0);
    axisX->append("1000DT",1);
    axisX->append("1500DT",2);
    axisX->append("2000DT",3);
    axisX->append("2500DT",4);
    charttt->setAxisX(axisX, seriesss);
    QChartView *chartViewww = new QChartView(charttt);
    chartViewww->setRenderHint(QPainter::Antialiasing);

    chartViewww->setParent(ui->F_StatisticAge);
    /********************* END : Curve->Localisation *********************/

    ui->stackedWidget->setCurrentIndex(9);
}

void PoliceStation::on_B_BackToGestions_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void PoliceStation::on_B_ModifierIntervenant_clicked()
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
            ui->CB_MNationaliteIntervenant->setCurrentText(qry.value(3).toString());
            ui->CB_MLocalIntervenant->setCurrentText(qry.value(4).toString());
            ui->LE_MMailIntervenant->setText(qry.value(5).toString());
        }
    }
    ui->stackedWidget->setCurrentIndex(5);
}

void PoliceStation::on_B_AjouterIntervenant_clicked()
{
    ui->L_ACinIntAlert->clear();
    ui->L_ANomIntAlert->clear();
    ui->L_APrenomIntAlert->clear();
    ui->L_ALocalIntAlert->clear();
    ui->L_AMailIntAlert->clear();
    ui->CB_ANationaliteIntervenant->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(4);
}

void PoliceStation::on_B_SupprimerIntervenant_clicked()
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
            INFORMER(ui->L_AlerteIntervenant,"Intervenat est Supprime",3000);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void PoliceStation::on_B_AConfirmerIntervenant_clicked()
{
    /*************** BEGIN : Controle de Saisir L'ajout d'Intervenant ***************/
    bool overAll = false, cin_B, nom_B, prenom_B; //mail_B
    int cin = ui->LE_ACinIntervenant->text().toInt();
    QString cin_l = ui->LE_ACinIntervenant->text();
    QString nom = ui->LE_ANomIntervenant->text();
    QString prenom = ui->LE_APrenomIntervenant->text();
    QString nationalite = ui->CB_ANationaliteIntervenant->currentText();
    QString localisation = ui->CB_ALocalIntervenant->currentText();
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

    // BEGIN : Mail
    // END : Mail

    (cin_B && nom_B && prenom_B)? overAll = true : overAll = false;
    /*************** END : Controle de Saisir L'ajout d'Intervenant ***************/

    /*************** BEGIN : Ajouter sur BaseDonnee ***************/
    if(overAll) {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de l'ajout", "Confirmer l'ajout du l'intervenant?", QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes) {
            Intervenant intervenant(cin, nom, prenom, nationalite, localisation, mail);
            if(intervenant.ajouter()) {
                ui->CB_IDIntervenant->setModel(intervenant.listCin());
                ui->T_Intervenants->setModel(intervenant.afficher());
                INFORMER(ui->L_AlerteIntervenant,"Intervenat est Ajoute",3000);
                ui->stackedWidget->setCurrentIndex(3);
            }
            else {
                QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
            }
        }
    }
    /*************** END : Ajouter sur BaseDonnee ***************/
}

void PoliceStation::on_B_AAnnulerIntervenant_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void PoliceStation::on_B_MAnuulerIntervenant_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void PoliceStation::on_B_MConfirmerIntervenant_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la modification", "Confirmer la modification du l'intervenant?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        Intervenant affaire;
        affaire.setCin(ui->CB_IDIntervenant->currentText().toInt());
        affaire.setNom(ui->LE_MNomIntervenant->text());
        affaire.setPrenom(ui->LE_MPrenomIntervenant->text());
        affaire.setNationalite(ui->CB_MNationaliteIntervenant->currentText());
        affaire.setLocalisation(ui->CB_MLocalIntervenant->currentText());
        affaire.setMail(ui->LE_MMailIntervenant->text());
        if(affaire.modifier()) {
            ui->CB_IDIntervenant->setModel(intervenant.listCin());
            ui->T_Intervenants->setModel(intervenant.afficher());
            INFORMER(ui->L_AlerteIntervenant,"Intervenat est Modifie",3000);
            ui->stackedWidget->setCurrentIndex(3);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void PoliceStation::on_B_Trier_clicked()
{
    QString Tri = ui->CB_TriIntervenant->currentText();
    ui->T_Intervenants->setModel(intervenant.Trier(Tri));
}

void PoliceStation::on_LE_ChercherPrenom_textChanged(const QString &arg1)
{
    QString by = ui->CB_ChercherIntervenant->currentText();
    ui->T_Intervenants->setModel(intervenant.Chercher(arg1, by));
}

void PoliceStation::on_B_ResetTableIntervenant_clicked()
{
    ui->LE_ChercherPrenom->clear();
    ui->T_Intervenants->setModel(intervenant.afficher());
}

void PoliceStation::on_B_Chat_clicked()
{
    MessengerClient MS;
    MS.exec();
}

void PoliceStation::on_B_BackToGestions_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void PoliceStation::on_B_ModifierAffaire_clicked()
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
    ui->stackedWidget->setCurrentIndex(8);
}

void PoliceStation::on_B_AjouterAffaire_clicked()
{
    ui->LE_ATypeAffaire->clear();
    ui->LE_ALocalAffaire->clear();
    ui->TE_ADescAffaire->clear();
    QDateTime curDataTime=QDateTime::currentDateTime();
    ui->DE_ADateAffaire->setDate(curDataTime.date());
    ui->CB_ACinIntAffaire->setModel(intervenant.listCin());
    ui->stackedWidget->setCurrentIndex(7);
}

void PoliceStation::on_B_SupprimerAffaire_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation de la suppression", "Confirmer la suppression du l'affaire?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        affaire.setId(ui->CB_IDAffaire->currentText().toInt());
        if(affaire.supprimer(affaire.getId())) {
            qDebug() << "Suppression Complet";
            ui->T_Affaire->setModel(affaire.afficher());
            ui->CB_IDAffaire->setModel(affaire.listId());
            INFORMER(ui->L_AlerteAffaire,"Affaire est Supprime",3000);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"),
                        QObject::tr("Suppression a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void PoliceStation::on_B_AAnnulerAffaire_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void PoliceStation::on_B_AConfirmerAffaire_clicked()
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
            INFORMER(ui->L_AlerteAffaire,"Affaire est Ajoute",3000);
            ui->stackedWidget->setCurrentIndex(6);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("L'ajout a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}

void PoliceStation::on_B_MAnnulerAffaire_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void PoliceStation::on_B_MConfirmerAffaire_clicked()
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
            INFORMER(ui->L_AlerteAffaire,"Affaire est Modifie",3000);
            ui->stackedWidget->setCurrentIndex(6);
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Nope"), QObject::tr("La modification a échoué.\n" "Cliquer Ok."), QMessageBox::Ok);
        }
    }
}
