#include "detenu.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Detenu::Detenu()
{
    nom=""; prenom=""; nationalite=""; historique=""; niveau_danger="";
}

Detenu::Detenu(int cin, QString nom, QString prenom, QString natioanlite, QDate date_naissance, QDate date_arrest, QString historique, QString niveau_danger, int cin_policier) {
    this->id=cin; this->nom=nom; this->prenom=prenom;  this->date_naiss=date_naissance; this->date_arrest=date_arrest;  this->nationalite=natioanlite;  this->historique=historique;  this->niveau_danger=niveau_danger; this->cin_policier=cin_policier;
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
    QString cin_string = QString::number(cin_policier);
    query.prepare("INSERT INTO detenus (cin, nom, prenom, date_naissance, nationalite, date_arrest, historique, niveau_danger, cin_policier)" "VALUES (:cin, :nom, :prenom, :date_naissance, :nationalite, :date_arrest, :historique, :niveau_danger, :cin_policier)");
    query.bindValue(0, id);
    query.bindValue(1, nom);
    query.bindValue(2, prenom);
    query.bindValue(3, date_naiss);
    query.bindValue(4, nationalite);
    query.bindValue(5, date_arrest);
    query.bindValue(6, historique);
    query.bindValue(7, niveau_danger);
    query.bindValue(8, cin_string);
    return query.exec();
}

bool Detenu::modifier() {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("UPDATE detenus SET nom=:nom, prenom=:prenom, date_naissance=:daten, nationalite=:nationalite, date_arrest=:datea, historique=:historique, niveau_danger=:niveaud WHERE cin=:id");
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
    query.prepare("delete from detenus where cin=:id");
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
    model->setQuery("SELECT cin FROM detenus");
    return model;
}

QSqlQueryModel* Detenu::Chercher(QString rechercher,QString by) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(by=="CIN") {
        model->setQuery("SELECT * FROM detenus WHERE cin LIKE '"+rechercher+"%'");
    }
    else if(by=="Danger") {
       model->setQuery("SELECT * FROM detenus WHERE niveau_danger LIKE '%"+rechercher+"%'");
    }
    else if(by=="Prenom") {
        model->setQuery("SELECT * FROM detenus WHERE prenom LIKE '"+rechercher+"%'");
    }
    return model;
}

QSqlQueryModel* Detenu::Trier(QString tri) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(tri=="CIN") {
        model->setQuery("SELECT * FROM detenus ORDER BY cin ASC");
    }
    else if(tri=="Danger") {
        model->setQuery("SELECT * FROM detenus ORDER BY niveau_danger ASC");
    }
    else if(tri=="Prenom") {
        model->setQuery("SELECT * FROM detenus ORDER BY prenom ASC");
    }
    return model;
}

QSqlQueryModel * Detenu::affectAll(){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT p.cin_policier, d.cin, i.nom, i.type FROM policier p INNER JOIN detenus d ON d.cin_policier = p.cin_policier INNER JOIN daffectations da ON d.cin = da.cin_detenu INNER JOIN infractions i ON i.id = da.id_infraction");
    return model;
}
