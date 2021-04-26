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

void PoliceStation::on_B_GestionVehicule_2_clicked()
{
    ui->T_Vehicules_2->setModel(v_tmp.afficher());
    ui->CB_IDAffVeh_2->setModel(v_tmp.afficherm());
    ui->CB_IDVehicule_2->setModel(v_tmp.afficherm());
    ui->stackedWidget->setCurrentIndex(20);
}

void PoliceStation::on_B_GestionMission_3_clicked()
{
    ui->T_Mission_2->setModel(m_tmp.afficher());
    ui->CB_IDAffMiss_2->setModel(m_tmp.affichern());
    ui->CB_IDMission_2->setModel(m_tmp.affichern());
    ui->stackedWidget->setCurrentIndex(23);
}

void PoliceStation::on_B_GestionMission_4_clicked()
{
    ui->T_Affectation_2->setModel(a_tmp.afficherA());
    ui->T_Affectation_2->setModel(a_tmp.afficherA());
}

void PoliceStation::on_B_BackToGestions_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void PoliceStation::on_B_BackToGestions_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void PoliceStation::on_B_AjouterVehicule_2_clicked()
{
    ui->LE_AMarqueVehicule_2->clear();
    ui->LE_AMatriculeVehicule_2->clear();
    ui->LE_ANbplacesVehicule_2->clear();
    ui->LE_ACouleurVehicule_2->clear();
    ui->LE_AQuantiteVehicule_2->clear();
    ui->LE_ACinVehicule_2->clear();
    ui->stackedWidget->setCurrentIndex(21);
}

void PoliceStation::on_B_AAnnulerVehicule_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}

void PoliceStation::on_B_AConfirmerVehicule_2_clicked()
{
    bool overAll = false, matricule_B, marque_B, couleur_B, quantite_B,nb_places_B;
    int matricule = ui->LE_AMatriculeVehicule_2->text().toInt();
    QString matriculel = ui->LE_AMatriculeVehicule_2->text();
    QString marque = ui->LE_AMarqueVehicule_2->text();
    QString couleur = ui->LE_ACouleurVehicule_2->text();
    int quantite = ui->LE_AQuantiteVehicule_2->text().toInt();
    QString quantitel = ui->LE_AQuantiteVehicule_2->text();
    int nb_places = ui->LE_ANbplacesVehicule_2->text().toInt();
    QString nb_placesl = ui->LE_ANbplacesVehicule_2->text();
    int CIN_policier = ui->LE_ACinVehicule_2->text().toInt();
    if(matriculel.length() < 3) {
        matricule_B = false;
        ui->matriculealert_2->setText("Il faut 3 characteres de facon XXX");
        ui->matriculealert_2->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        matricule_B = true;
        ui->matriculealert_2->setText("Ok");
        ui->matriculealert_2->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }
    if(marque.length() >10) {
        marque_B = false;
        ui->marquealert_2->setText("Il faut 10 charactere au maximum");
        ui->marquealert_2->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        marque_B = true;
        marque[0] = marque[0].toUpper();
        ui->marquealert_2->setText("Ok");
        ui->marquealert_2->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }
    if(couleur.length() < 3) {
        couleur_B = false;
        ui->couleuralert_2->setText("Il faut  au moins 3 charactere ");
        ui->couleuralert_2->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        couleur_B = true;
        couleur[0] = couleur[0].toUpper();
        ui->couleuralert_2->setText("Ok");
        ui->couleuralert_2->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }
    if(quantitel.length() >2) {
        quantite_B = false;
        ui->quantitealerte_2->setText("Il faut maximum 2 characteres ");
        ui->quantitealerte_2->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        quantite_B = true;
        ui->quantitealerte_2->setText("Ok");
        ui->quantitealerte_2->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }
    if(nb_placesl.length() >2) {
        nb_places_B = false;
        ui->nb_placesalert_2->setText("Il faut maximum 2 characteres ");
        ui->nb_placesalert_2->setStyleSheet("QLabel{color: red; font-size: 12px;}");
    }
    else {
        quantite_B = true;
        ui->nb_placesalert_2->setText("Ok");
        ui->nb_placesalert_2->setStyleSheet("QLabel{color: green; font-size: 12px;}");
    }
    /*************** END : Controle de Saisir L'ajout d'Intervenant ***************/

    /*************** BEGIN : Ajouter sur BaseDonnee */
    (matricule_B && marque_B && couleur_B && quantite_B && nb_places_B  )? overAll = true : overAll = false;
    if(overAll) {
        QMessageBox msgBox;
        vehicule E(matricule, marque, couleur, nb_places, quantite, CIN_policier);
        bool test=E.ajouter();
        if(test)
        {
            msgBox.setText("Ajout avec succés.");
            ui->T_Vehicules_2->setModel(v_tmp.afficher());
            QSqlQuery *query = new QSqlQuery();
            QSqlQueryModel * modal = new QSqlQueryModel();
            query->prepare("SELECT matricule from vehicules");
            query->exec();
            modal->setQuery(*query);
            ui->CB_IDVehicule_2->setModel(modal);
            ui->stackedWidget->setCurrentIndex(20);
        }
        else {
            msgBox.setText("Echec au niveau de l'ajout.");
        }
        msgBox.exec();
    }
}

void PoliceStation::on_B_ModifierVehicule_2_clicked()
{
    QString matricule = ui->CB_IDVehicule_2->currentText();
    ui->LE_MMatriculeVehicule_2->setText(matricule);
    QSqlQuery query;
    query.prepare("SELECT * from vehicules where matricule = :matricule");
    query.bindValue(":matricule" , matricule);
    if (query.exec())
    {
        while (query.next())
        {
            ui->LE_MMarqueVehicule_2->setText(query.value(1).toString());
            ui->LE_MQuantiteVehicule_2->setText(query.value(2).toString());
            ui->LE_MCouleurVehicule_2->setText(query.value(3).toString());
            ui->LE_MNbplacesVehicule_2->setText(query.value(4).toString());
            ui->LE_MCinVehicule_2->setText(query.value(5).toString());
        }

    }
    ui->stackedWidget->setCurrentIndex(22);
}

void PoliceStation::on_B_SupprimerVehicule_2_clicked()
{
    int matricule = ui->CB_IDVehicule_2->currentText().toInt();
    QMessageBox msgbox;
    bool test=v_tmp.supprimer(matricule);
    if (test) {
        msgbox.setText("Suppression avec succés.");
        ui->T_Vehicules_2->setModel(v_tmp.afficher());
        ui->T_Mission_2->setModel(m_tmp.afficher());
        QSqlQuery *query = new QSqlQuery();
        QSqlQueryModel * modal = new QSqlQueryModel();
        query->prepare("SELECT matricule from vehicules");
        query->exec();
        modal->setQuery(*query);
        ui->CB_IDVehicule_2->setModel(modal);
    }
    else
        msgbox.setText("Echec au niveau de la Suppression");
    msgbox.exec();
}

void PoliceStation::on_B_MAnuulerVehicule_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}

void PoliceStation::on_B_MConfirmerVehicule_2_clicked()
{
    int matricule = ui->CB_IDVehicule_2->currentText().toInt();
    QString marque = ui->LE_MMarqueVehicule_2->text();
    QString couleur = ui->LE_MCouleurVehicule_2->text();
    int quantite=ui->LE_MQuantiteVehicule_2->text().toInt();
    int nb_places=ui->LE_MNbplacesVehicule_2->text().toInt();
    int CIN_policier=ui->LE_MCinVehicule_2->text().toInt();
    QMessageBox msgBox;
    bool test = v_tmp.modifier(marque, couleur, quantite, nb_places, matricule, CIN_policier);
    if (test) {
        ui->T_Vehicules_2->setModel(v_tmp.afficher());
        msgBox.setText("modification avec succes");
        n_tmp.notifications_modifiervehicule();
        ui->stackedWidget->setCurrentIndex(20);
    }
    else
        msgBox.setText("echec au niveau de la modification");
    msgBox.exec();
}

void PoliceStation::on_B_Trier_6_clicked()
{
    QString Tri = ui->comboBox_4->currentText();
    ui->T_Vehicules_2->setModel(v_tmp.Trier(Tri));
}

void PoliceStation::on_molka_2_textChanged(const QString &arg1)
{
    QString by=ui->rr_2->currentText();
    ui->T_Vehicules_2->setModel(v_tmp.rechercherv(arg1,by));
}

void PoliceStation::on_annulerv_2_clicked()
{
    ui->molka_2->clear();
    ui->T_Vehicules_2->setModel(v_tmp.afficher());
}

void PoliceStation::on_annulerM_2_clicked()
{
    ui->T_Mission_2->setModel(m_tmp.afficher());
}

void PoliceStation::on_B_Statistics_3_clicked()
{
    QPrinter printer (QPrinter::PrinterResolution);
    QPrintDialog dlg(&printer,this);
    if (dlg.exec() == QDialog::Rejected) {
        return;
    }
    QString strStream;
    QString currentDate = QDateTime().currentDateTime().toString();
    QTextStream out(&strStream);
    const int rowCount = ui->T_Vehicules_2->model()->rowCount();
    const int columnCount = ui->T_Vehicules_2->model()->columnCount();
    out <<
    "<html>\n"
    "<head>\n"
    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
    <<QString("<title>%1</title>\n").arg("strTitle")
    <<"</head>\n"
    "<body bgcolor=#ffffff link=#5000A0>\n"
    <<QString(currentDate)
    <<//"<align='right'> " << datefich << "</align>"
    "<center> <img src=""C:/Users/lenovo/Desktop/Smart_Plolice_Station_2A19/images/logo.png"" width=""100"" height=""100"" > <br> <br><H1>EXTRAIT DES VEHICULES</H1> <br> <br><table border=1 cellspacing=0 cellpadding=2>\n";
    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
    if (!ui->T_Vehicules_2->isColumnHidden(column))
    out << QString("<th>%1</th>").arg(ui->T_Vehicules_2->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";
    // data table
    for (int row = 0; row < rowCount; row++)
    {
    out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
    for (int column = 0; column < columnCount; column++)
    {
    if (!ui->T_Vehicules_2->isColumnHidden(column))
    {
    QString data = ui->T_Vehicules_2->model()->data(ui->T_Vehicules_2->model()->index(row, column)).toString().simplified();
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
    "<div><img src="":/resources/images/fb.png""> <span>Debug Entity</div>\n"
    "<br>"
    "<div><img src="":/resources/images/insta.png""> <span>Debug_Entity </div>\n"
    "</div>"
    "</div>"
    "</div>"
    "</footer>\n"
    "</html>\n";
    QString filter = "pdf (*.pdf) ";
    QString fileName = QFileDialog::getSaveFileName(this, "save in", QDir::homePath(),filter);
    if (QFileInfo(fileName).suffix().isEmpty()) {
        fileName.append(".pdf");
    }
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);
}
