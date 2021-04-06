#include "intervenant.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Intervenant::Intervenant() {
    CIN=0;  nom="";  prenom="";  nationalite="";  localisation="";  mail="";
}

Intervenant::Intervenant(int CIN, QString nom, QString prenom, QString nationalite, QString localisation, QString mail){
    this->CIN=CIN;  this->nom=nom;  this->prenom=prenom;  this->nationalite=nationalite;  this->localisation=localisation;  this->mail=mail;
}

void Intervenant::setCin(int CIN) { this->CIN=CIN; }
int Intervenant::getCin() { return CIN; }

void Intervenant::setNom(QString nom) { this->nom=nom; }
QString Intervenant::getNom() { return nom; }

void Intervenant::setPrenom(QString prenom) { this->prenom=prenom; }
QString Intervenant::getPrenom() { return prenom; }

void Intervenant::setNationalite(QString nationalite) { this->nationalite=nationalite; }
QString Intervenant::getNationalite() { return nationalite; }

void Intervenant::setLocalisation(QString localisation) { this->localisation=localisation; }
QString Intervenant::getLocalisation() { return localisation; }

void Intervenant::setMail(QString mail) { this->mail=mail; }
QString Intervenant::getMail() { return mail; }

bool Intervenant::ajouter() {
    QSqlQuery query;
    QString cin_string = QString::number(CIN);
    query.prepare("INSERT INTO intervenant (cin, nom, prenom, nationalite, localisation, mail)" "VALUES (:cin, :nom, :prenom, :nationalite, :localisation, :mail)");
    query.bindValue(0, cin_string);
    query.bindValue(1, nom);
    query.bindValue(2, prenom);
    query.bindValue(3, nationalite);
    query.bindValue(4, localisation);
    query.bindValue(5, mail);
    return query.exec();
}

bool Intervenant::modifier() {
    QSqlQuery query;
    QString cin_string = QString::number(CIN);
    query.prepare("UPDATE intervenant set nom=:nom, prenom=:prenom, nationalite=:nationalite, localisation=:localisation, mail=:mail where CIN=:CIN");
    query.bindValue(5, cin_string);
    query.bindValue(0, nom);
    query.bindValue(1, prenom);
    query.bindValue(2, nationalite);
    query.bindValue(3, localisation);
    query.bindValue(4, mail);
    return query.exec();
}

bool Intervenant::supprimer(int CIN) {
    QSqlQuery query;
    query.prepare("delete from intervenant where cin=:cin");
    query.bindValue(0, CIN);
    return query.exec();
}

QSqlQueryModel* Intervenant::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM intervenant");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nationalité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Localisation"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mail"));
    return model;
}

QSqlQueryModel* Intervenant::Trier(QString tri) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(tri=="Nom") {
        model->setQuery("SELECT * FROM intervenant ORDER BY nom ASC");
    }
    else if(tri=="Prenom") {
        model->setQuery("SELECT * FROM intervenant ORDER BY prenom ASC");
    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nationalité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Localisation"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mail"));
    return model;
}

QSqlQueryModel* Intervenant::Chercher(QString rechercher,QString by) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(by=="CIN") {
        model->setQuery("SELECT * FROM intervenant WHERE cin LIKE '"+rechercher+"%'");
    }
    else if(by=="Localisation") {
       model->setQuery("SELECT * FROM intervenant WHERE localisation LIKE '"+rechercher+"%'");
    }
    else if(by=="Prenom") {
        model->setQuery("SELECT * FROM intervenant WHERE prenom LIKE '"+rechercher+"%'");
    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nationalité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Localisation"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mail"));
    return model;
}

QSqlQueryModel* Intervenant::listCin() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT cin FROM intervenant");
    return model;
}

int Intervenant::NatA() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM intervenant where Nationalite='Autres...'");
    qry.exec();
    int Autres= 0;
    if (qry.next()) {
        Autres= qry.value(0).toInt();
    }
    return Autres;
}

int Intervenant::NatTn() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM intervenant where Nationalite='Tunisienne'");
        qry.exec();
        int Tn= 0;
        if (qry.next()) {
            Tn= qry.value(0).toInt();
        }
    return Tn;
}

int Intervenant::NatAg() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM intervenant where Nationalite='Algerienne'");
    qry.exec();
    int Ag= 0;
    if (qry.next()) {
        Ag= qry.value(0).toInt();
    }
    return Ag;
}

int Intervenant::NatFr() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM intervenant where Nationalite='Francaise'");
    qry.exec();
    int Fr= 0;
    if (qry.next()) {
        Fr= qry.value(0).toInt();
    }
    return Fr;
}

int Intervenant::NatLb() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM intervenant where Nationalite='Libanaise'");
    qry.exec();
    int Lb= 0;
    if (qry.next()) {
        Lb= qry.value(0).toInt();
    }
    return Lb;
}

int Intervenant::NE() {
    int r=0;

    QSqlQuery bqry;
    bqry.prepare("SELECT COUNT (*) FROM intervenant where localisation='Bizerte'");
    bqry.exec();
    //int b = 0;
    if (bqry.next()) {
        r += bqry.value(0).toInt();
    }
    QSqlQuery tqry;
    tqry.prepare("SELECT COUNT (*) FROM intervenant where localisation='Tunis'");
    tqry.exec();
    //int t = 0;
    if (tqry.next()) {
        r += tqry.value(0).toInt();
    }
    QSqlQuery aqry;
    aqry.prepare("SELECT COUNT (*) FROM intervenant where localisation='Ariana'");
    aqry.exec();
    //int a = 0;
    if (aqry.next()) {
        r += aqry.value(0).toInt();
    }
    QSqlQuery mqry;
    mqry.prepare("SELECT COUNT (*) FROM intervenant where localisation='La Manouba'");
    mqry.exec();
    //int m = 0;
    if (mqry.next()) {
        r += mqry.value(0).toInt();
    }
    QSqlQuery baqry;
    baqry.prepare("SELECT COUNT (*) FROM intervenant where localisation='Ben Arous'");
    baqry.exec();
    //int ba = 0;
    if (baqry.next()) {
        r += baqry.value(0).toInt();
    }
    QSqlQuery zqry;
    zqry.prepare("SELECT COUNT (*) FROM intervenant where localisation='Zaghouan'");
    zqry.exec();
    //int z = 0;
    if (zqry.next()) {
        r += zqry.value(0).toInt();
    }
    QSqlQuery nqry;
    nqry.prepare("SELECT COUNT (*) FROM intervenant where localisation='Nabeul'");
    nqry.exec();
    //int z = 0;
    if (nqry.next()) {
        r += nqry.value(0).toInt();
    }

    return r;
}

int Intervenant::NO() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM intervenant where localisation=''");
    qry.exec();
    int Lb= 0;
    if (qry.next()) {
        Lb= qry.value(0).toInt();
    }
    return Lb;
}

int Intervenant::CE() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM intervenant where localisation=''");
    qry.exec();
    int Lb= 0;
    if (qry.next()) {
        Lb= qry.value(0).toInt();
    }
    return Lb;
}

int Intervenant::CO() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM intervenant where localisation=''");
    qry.exec();
    int Lb= 0;
    if (qry.next()) {
        Lb= qry.value(0).toInt();
    }
    return Lb;
}

int Intervenant::SE() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM intervenant where localisation=''");
    qry.exec();
    int Lb= 0;
    if (qry.next()) {
        Lb= qry.value(0).toInt();
    }
    return Lb;
}

int Intervenant::SO() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM intervenant where localisation=''");
    qry.exec();
    int Lb= 0;
    if (qry.next()) {
        Lb= qry.value(0).toInt();
    }
    return Lb;
}

