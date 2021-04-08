#include "affectation.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableView>



Affectation::Affectation(int id, int cin)
{
    this->id = id;
    this->cin = cin;
}

void Affectation::setId(int i){id =i;}
void Affectation::setCin(int m){cin = m;}


int Affectation::getId(){return id;}
int Affectation::getCin(){return cin;}




bool Affectation::ajouterA()
{
    QSqlQuery query;
    query.prepare("INSERT INTO daffectations ( cin_detenu, id_infraction)"
          "VALUES ( :cin, :id)");
    query.bindValue(0, cin);
    query.bindValue(1, id);
    return query.exec();
}

QSqlQueryModel * Affectation::afficherA()

{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT i.id, i.nom, i.type, i.niveau, i.datei, i.detenu, d.cin, d.nom, d.prenom, d.nationalite, d.historique, d.niveau_danger, d.date_arrest FROM detenus d INNER JOIN daffectations a ON d.cin = a.cin_detenu INNER JOIN infractions i ON i.id = a.id_infraction;");
    return model;
}
bool Affectation::supprimerA(int id , int cin )
{
        QSqlQuery query;
        query.prepare("DELETE FROM daffectations WHERE id= :id AND cin= :cin");
        query.bindValue(":id", id);
        query.bindValue(":cin", cin);
        return query.exec();
}
