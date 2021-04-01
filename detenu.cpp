#include "detenu.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Detenu::Detenu()
{
    nom=""; prenom=""; nationalite=""; historique=""; niveau_danger="";
}

Detenu::Detenu(QString nom, QString prenom, QString natioanlite, QDate date_naissance, QDate date_arrest, QString historique, QString niveau_danger) {
    this->nom=nom; this->prenom=prenom;  this->date_naiss=date_naissance; this->date_arrest=date_arrest;  this->nationalite=natioanlite;  this->historique=historique;  this->niveau_danger=niveau_danger;
}

void Detenu::setId(int id) { this->id=id; }
int Detenu::getId() { return id; }

void Detenu::setNom(QString nom) { this->nom=nom; }
QString Detenu::getNom() { return nom; }

void Detenu::setPrenom(QString prenom) { this->prenom=prenom; }
QString Detenu::getPrenom() { return prenom; }

void Detenu::setNationalite(QString nationalite) { this->nationalite=nationalite; }
QString Detenu::getNationalite() { return nationalite; }

void Detenu::setHistorique(QString historique) { this->historique=historique; }
QString Detenu::getHistorique() { return historique; }

void Detenu::setDanger(QString niveau_danger) { this->niveau_danger=niveau_danger; }
QString Detenu::getDanger() { return niveau_danger; }

void Detenu::setDn(QDate Dn) { this->date_naiss=Dn; }
QDate Detenu::getDn() { return date_naiss; }

void Detenu::setDa(QDate Da) { this->date_arrest=Da; }
QDate Detenu::getDa() { return date_arrest; }

bool Detenu::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO detenus (nom, prenom, date_naissance, nationalite, date_arrest, historique, niveau_danger)" "VALUES (:nom, :prenom, :date_naissance, :nationalite, :date_arrest, :historique, :niveau_danger)");
    query.bindValue(0, nom);
    query.bindValue(1, prenom);
    query.bindValue(2, date_naiss);
    query.bindValue(3, nationalite);
    query.bindValue(4, date_arrest);
    query.bindValue(5, historique);
    query.bindValue(6, niveau_danger);
    return query.exec();
}

bool Detenu::modifier() {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("UPDATE detenus SET nom=:nom, prenom=:prenom, date_naissance=:daten, nationalite=:nationalite, date_arrest=:datea, historique=:historique, niveau_danger=:niveaud WHERE id=:id");
    query.bindValue(7, id_string);
    query.bindValue(0, nom);
    query.bindValue(1, prenom);
    query.bindValue(2, date_naiss);
    query.bindValue(3, nationalite);
    query.bindValue(4, date_arrest);
    query.bindValue(5, historique);
    query.bindValue(6, niveau_danger);
    return query.exec();
}

bool Detenu::supprimer(int id) {
    QSqlQuery query;
    query.prepare("delete from detenus where id=:id");
    query.bindValue(0, id);
    return query.exec();
}

QSqlQueryModel* Detenu::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM detenus");
    return model;
}

QSqlQueryModel* Detenu::listId() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id FROM detenus");
    return model;
}
