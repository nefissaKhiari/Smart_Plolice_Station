#include "infraction.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Infraction::Infraction()
{
    nom=""; type=""; detenu=""; niveau="";
}

Infraction::Infraction(QString nom, QString type, QString niveau, QDate date, QString detenu) {
    this->nom=nom; this->type=type; this->niveau=niveau; this->date=date; this->detenu=detenu;
}

void Infraction::setId(int id) { this->id=id; }
int Infraction::getId() { return id; }

void Infraction::setNom(QString nom) { this->nom=nom; }
QString Infraction::getNom() { return nom; }

void Infraction::setType(QString type) { this->type=type; }
QString Infraction::getType() { return type; }

void Infraction::setDetenu(QString detenu) { this->detenu=detenu; }
QString Infraction::getDetenu() { return detenu; }

void Infraction::setNiveau(QString niveau) { this->niveau=niveau; }
QString Infraction::getNiveau() { return niveau; }

void Infraction::setDate(QDate date) { this->date=date; }
QDate Infraction::getDate() { return date; }

bool Infraction::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO infractions (nom, type, niveau, datei, detenu)" "VALUES (:nom, :type, :niveau, :datei, :detenu)");
    query.bindValue(0, nom);
    query.bindValue(1, type);
    query.bindValue(2, niveau);
    query.bindValue(3, date);
    query.bindValue(4, detenu);
    return query.exec();
}

bool Infraction::modifier() {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("UPDATE infractions SET nom=:nom, type=:type, niveau=:niveau, datei=:datei WHERE id=:id");
    query.bindValue(4, id_string);
    query.bindValue(0, nom);
    query.bindValue(1, type);
    query.bindValue(2, niveau);
    query.bindValue(3, date);
    return query.exec();
}

bool Infraction::supprimer(int id) {
    QSqlQuery query;
    query.prepare("delete from infractions where id=:id");
    query.bindValue(0, id);
    return query.exec();
}

QSqlQueryModel* Infraction::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM infractions");
    return model;
}

QSqlQueryModel* Infraction::listId() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id FROM infractions");
    return model;
}
