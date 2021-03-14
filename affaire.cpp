#include "affaire.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>


Affaire::Affaire() {
    id=0;   type="";    localisation="";    date="";    description="";
}

Affaire::Affaire(QString type, QString localisation, QString date, QString description) {
    this->type=type;    this->localisation=localisation;    this->date=date;    this->description=description;
}

void Affaire::setId(int id) { this->id=id; }
int Affaire::getId() { return id; }

void Affaire::setType(QString type) { this->type=type; }
QString Affaire::getType() { return type; }

void Affaire::setLocalisation(QString localisation) { this->localisation=localisation; }
QString Affaire::getLocalisation() { return localisation; }

void Affaire::setDate(QString date) { this->date=date; }
QString Affaire::getDate() { return date; }

void Affaire::setDescription(QString description) { this->description=description; }
QString Affaire::getDescription() { return description; }

bool Affaire::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO affaires (type, localisation, description, datea)" "VALUES (:type, :localisation, :description, :datea)");
    query.bindValue(0, type);
    query.bindValue(1, localisation);
    query.bindValue(2, description);
    query.bindValue(3, date);
    return query.exec();
}

bool Affaire::modifier() {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("UPDATE affaires set type=:type, localisation=:localisation, description=:description, datea=:date where id=:id");
    query.bindValue(4, id_string);
    query.bindValue(0, type);
    query.bindValue(1, localisation);
    query.bindValue(2, description);
    query.bindValue(3, date);
    return query.exec();
}

bool Affaire::supprimer(int id) {
    QSqlQuery query;
    query.prepare("delete from affaires where id=:id");
    query.bindValue(0, id);
    return query.exec();
}

QSqlQueryModel* Affaire::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM affaires");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Localisation"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
    return model;
}

QSqlQueryModel* Affaire::listId() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id FROM affaires");
    return model;
}
