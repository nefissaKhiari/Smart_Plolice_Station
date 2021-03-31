#include "equipement.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Equipement::Equipement()
{
reference=0; quantite=0;taille="";etat="";poid=0;nom="";
}
Equipement :: Equipement(int reference,int quantite, QString taille, QString etat, int poid, QString nom)
{
    this->reference=reference;  this->quantite=quantite;  this->taille=taille;  this->etat=etat;  this->poid=poid;  this->nom=nom;
}
void Equipement::setReference(int reference) { this->reference=reference; }
int Equipement::getReference() { return reference; }

void Equipement::setQuantite(int quantite) { this->quantite=quantite; }
int Equipement::getQuantite() { return quantite; }

void Equipement::setTaille(QString taille) { this->taille=taille; }
QString Equipement::getTaille() { return taille; }

void Equipement::setEtat(QString etat) { this->etat=etat; }
QString Equipement::getEtat() { return etat; }

void Equipement::setPoid(int poid) { this->poid=poid; }
int Equipement::getPoid() { return poid; }

void Equipement::setNom(QString nom) { this->nom=nom; }
QString Equipement::getNom() { return nom; }

bool Equipement::ajouter() {
    QSqlQuery query;
    QString ref_string = QString::number(reference);
    QString poid_string = QString::number(poid);
    QString quantite_string = QString::number(quantite);
    query.prepare("INSERT INTO equipement(reference, quantite, taille, etat, poid, nom)" "VALUES (:reference, :quantite, :taille, :etat, :poid, :nom)");
    query.bindValue(0, ref_string);
    query.bindValue(1, quantite_string);
    query.bindValue(2, taille);
    query.bindValue(3, etat);
    query.bindValue(4, poid_string);
    query.bindValue(5, nom);
    return query.exec();
}

bool Equipement::modifier() {
    QSqlQuery query;
    QString ref_string = QString::number(reference);
    QString poid_string = QString::number(poid);
    QString quantite_string = QString::number(quantite);
    query.prepare("UPDATE equipement set quantite=:quantite, taille=:taille, etat=:etat, poid=:poid, nom=:nom where reference=:reference");
    query.bindValue(5, ref_string);
    query.bindValue(0, quantite_string);
    query.bindValue(1, taille);
    query.bindValue(2, etat);
    query.bindValue(3, poid_string);
    query.bindValue(4, nom);
    return query.exec();
}
bool Equipement::supprimer(int reference) {
    QSqlQuery query;
    query.prepare("delete from equipement where reference=:reference");
    query.bindValue(0, reference);
    return query.exec();
}


QSqlQueryModel* Equipement::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM equipement");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("taille"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("poid"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nom"));
    return model;
}

QSqlQueryModel* Equipement::Trier(QString tri) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(tri=="Nom") {
        model->setQuery("SELECT * FROM equipement ORDER BY nom ASC");
    }
    else if(tri=="Poid") {
        model->setQuery("SELECT * FROM equipement ORDER BY poid ASC");
    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("taille"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("poid"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nom"));
    return model;
}

QSqlQueryModel* Equipement::RechercheNom(QString cherche) {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Equipement WHERE nom LIKE '"+cherche+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("taille"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("poid"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nom"));
    return model;
}

QSqlQueryModel* Equipement::Rechercherref(QString cherche) {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM equipement WHERE reference LIKE '"+cherche+"%' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("taille"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("poid"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nom"));
    return model;
}

QSqlQueryModel* Equipement::listRef() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT reference FROM equipement");
    return model;
}

