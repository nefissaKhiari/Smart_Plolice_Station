#include "intervenant.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Intervenant::Intervenant() {
    CIN=0;  nom="";  prenom="";  nationalite="";  localisation="";  mail="";
}

Intervenant::Intervenant(QString nom, QString prenom, QString nationalite, QString localisation, QString mail){
    this->nom=nom;  this->prenom=prenom;  this->nationalite=nationalite;  this->localisation=localisation;  this->mail=mail;
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
    query.prepare("INSERT INTO intervenant (nom, prenom, nationalite, localisation, mail)" "VALUES (:nom, :prenom, :nationalite, :localisation, :mail)");
    query.bindValue(0, nom);
    query.bindValue(1, prenom);
    query.bindValue(2, nationalite);
    query.bindValue(3, localisation);
    query.bindValue(4, mail);
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

QSqlQueryModel* Intervenant::listCin() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT cin FROM intervenant");
    return model;
}
