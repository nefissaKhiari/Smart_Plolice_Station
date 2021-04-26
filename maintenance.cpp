#include "maintenance.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Maintenance::Maintenance()
{
idmaintenance=0;cout=0;reference=0;
}
Maintenance :: Maintenance(QDate datedebut, int cout, QDate datefin, int reference)
{
   this->datedebut=datedebut; this->cout=cout; this->datefin=datefin; this->reference=reference;
}

void Maintenance::setIdmaintenance(int idmaintenance) { this->idmaintenance=idmaintenance; }
int Maintenance::getIdmaintenance() { return idmaintenance; }

void Maintenance::setDatedebut(QDate datedebut) { this->datedebut=datedebut; }
QDate Maintenance::getDatedebut() { return datedebut; }

void Maintenance::setCout(int cout) { this->cout=cout; }
int Maintenance::getCout() { return cout; }

void Maintenance::setDatefin(QDate datefin) { this->datefin=datefin; }
QDate Maintenance::getDatefin() { return datefin; }

void Maintenance::setReference(int reference) { this->reference=reference; }
int Maintenance::getReference() { return reference; }

void Maintenance::setEtat(QString etat) { this->etat=etat; }
QString Maintenance::getEtat() { return etat; }

bool Maintenance::ajouter() {
    QSqlQuery query;
    QString cout_string = QString::number(cout);
    QString reference_string = QString::number(reference);
    query.prepare("INSERT INTO maintenance(datedebut, cout, datefin,reference)" "VALUES ( :datedebut, :cout, :datefin, :reference)");
    query.bindValue(0, datedebut);
    query.bindValue(1, cout_string);
    query.bindValue(2, datefin);
    query.bindValue(3, reference_string);
    return query.exec();
}

bool Maintenance::modifier() {
    QSqlQuery query;
    QString id_string = QString::number(idmaintenance);
    QString cout_string = QString::number(cout);
    QString reference_string = QString::number(reference);
    query.prepare("UPDATE maintenance set datedebut=:datedebut, cout=:cout, datefin=:datefin, reference=:reference, etat=:etat  where idmaintenance=:idmaintenance");
    query.bindValue(5, id_string);
    query.bindValue(0, datedebut);
    query.bindValue(1, cout_string);
    query.bindValue(2, datefin);
    query.bindValue(3, reference_string);
    query.bindValue(4, etat);
    return query.exec();
}

bool Maintenance::supprimer(int idmaintenance) {
    QSqlQuery query;
    query.prepare("delete from maintenance where idmaintenance=:idmaintenance");
    query.bindValue(0, idmaintenance);
    return query.exec();
}


QSqlQueryModel* Maintenance::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM maintenance");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idmaintenance"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("datedebut"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("cout"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datefin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("reference"));
    return model;
}
QSqlQueryModel* Maintenance::listId() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT idmaintenance FROM maintenance");
    return model;
}

int Maintenance::sfixer() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM maintenance where etat='Fixer'");
        qry.exec();
        int Tn= 0;
        if (qry.next()) {
            Tn= qry.value(0).toInt();
        }
    return Tn;
}

int Maintenance::snfixer() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM maintenance where etat='Non fixer'");
        qry.exec();
        int Tn= 0;
        if (qry.next()) {
            Tn= qry.value(0).toInt();
        }
    return Tn;
}

