#include "amende.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Amende::Amende() {
    ID_amende=0;  type_amende="";  prix_amende=0;  description_amende="";  lieu_amende="";   date_amende="";
}

Amende::Amende(int ID_amende, QString type_amende, int prix_amende, QString description_amende , QString lieu_amende, QString date_amende)
{
     this->ID_amende=ID_amende;
     this->type_amende=type_amende;
     this->prix_amende=prix_amende;
     this->description_amende=description_amende;
     this->lieu_amende=lieu_amende;
     this->date_amende=date_amende;

}


void Amende::setId_amende(int ID_amende) { this->ID_amende=ID_amende; }
int Amende::getId_amende() { return ID_amende; }

void Amende::setType_amende(QString type_amende) { this->type_amende=type_amende; }
QString Amende::getType_amende() { return type_amende; }

void Amende::setPrix_amende(int prix_amende) { this->prix_amende=prix_amende; }
int Amende::getPrix_amende() { return prix_amende; }

void Amende::setDescription_amende(QString description_amende) { this->description_amende=description_amende; }
QString Amende::getDescription_amende() { return description_amende; }

void Amende::setLieu_amende(QString lieu_amende) { this->lieu_amende=lieu_amende; }
QString Amende::getLieu_amende() { return lieu_amende; }

void Amende::setDate_amende(QString date_amende) { this->date_amende=date_amende; }
QString Amende::getDate_amende() { return date_amende; }



bool Amende::ajouter_amende() {
    QSqlQuery query;
    QString id_amende_string = QString::number(ID_amende);
    query.prepare("INSERT INTO amende ( type_amende, prix_amende, description_amende, lieu_amende, date_amende)" "VALUES ( :type_amende, :prix_amende, :description_amende, :lieu_amende,  :date_amende )");
    query.bindValue(0, type_amende);
    query.bindValue(1, prix_amende);
    query.bindValue(2, description_amende);
    query.bindValue(3, lieu_amende);
    query.bindValue(4, date_amende);

    return query.exec();
}

bool Amende::modifier_amende() {
    QSqlQuery query;
    QString id_amende_string = QString::number(ID_amende);
    query.prepare("UPDATE amende set type_amende=:type_amende, prix_amende=:prix_amende, description_amende=:description_amende, lieu_amende=:lieu_amende, date_amende=:prix_amende where id_amende=:id_amende");
    query.bindValue(5, id_amende_string);
    query.bindValue(0, type_amende);
    query.bindValue(1, prix_amende);
    query.bindValue(2, description_amende);
    query.bindValue(3, lieu_amende);
    query.bindValue(4, date_amende);

    return query.exec();
}



bool Amende::supprimer_amende(int ID_amende) {
    QSqlQuery query;
    query.prepare("delete from amende where id_amende=:id_amende");
    query.bindValue(0, ID_amende);
    return query.exec();
}


QSqlQueryModel* Amende::afficher_amende() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM amende");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_amende"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_amende"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_amende"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description_amende"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("lieu_amende"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_amende"));

    return model;
}


QSqlQueryModel* Amende::listId_amende() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id_amende FROM amende");
    return model;
}


QSqlQueryModel* Envoyer_sms_amende(QString)
{

}
