#include "equipement.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Equipement::Equipement()
{
reference=0; quantite=0;taille="";etat="";poid=0;nom="";
}
Equipement :: Equipement(int reference,int quantite, QString taille, QString etat, int poid, QString nom, int CIN_policier )
{
    this->reference=reference;  this->quantite=quantite;  this->taille=taille;  this->etat=etat;  this->poid=poid;  this->nom=nom; this->CIN_policier=CIN_policier;
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
    QString cin_policier_string = QString::number(CIN_policier);
    query.prepare("INSERT INTO equipement(reference, quantite, taille, etat, poid, nom, cin_policier)" "VALUES (:reference, :quantite, :taille, :etat, :poid, :nom, :cin_policier)");
    query.bindValue(0, ref_string);
    query.bindValue(1, quantite_string);
    query.bindValue(2, taille);
    query.bindValue(3, etat);
    query.bindValue(4, poid_string);
    query.bindValue(5, nom);
    query.bindValue(6, cin_policier_string);
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

QSqlQueryModel* Equipement::Chercher(QString rechercher,QString by) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(by=="poid") {
        model->setQuery("SELECT * FROM equipement WHERE poid LIKE '"+rechercher+"%'");
    }
    else if(by=="etat") {
       model->setQuery("SELECT * FROM equipement WHERE etat LIKE '"+rechercher+"%'");
    }
    else if(by=="quantite") {
        model->setQuery("SELECT * FROM equipement WHERE quantite LIKE '"+rechercher+"%'");
    }
    else if(by=="reference") {
        model->setQuery("SELECT * FROM equipement WHERE reference LIKE '"+rechercher+"%'");
    }
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
QSqlQueryModel* Equipement::afficherAffectation() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT p.cin_policier, e.nom, e.reference, m.etat FROM maintenance m INNER JOIN equipement e ON m.reference = e.reference INNER JOIN policier p ON p.cin_policier = e.cin_policier");
    return model;
}
QSqlQueryModel* Equipement::listCIN() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT cin_policier FROM policier");
    return model;
}
