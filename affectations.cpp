#include "affectations.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableView>



affectations::affectations(int id_M, int matricule_V)
{
    this->id_M = id_M;
    this->matricule_V = matricule_V;

}

void affectations::setid_M(int i){id_M =i;}
void affectations::setmatricule_V(int m){matricule_V = m;}


int affectations::get_id_M(){return id_M;}
int affectations::get_matricule_V(){return matricule_V;}




bool affectations::ajouterA()
{
    QSqlQuery query;
    query.prepare("INSERT INTO affectations ( id_vehicule, id_mission)"
          "VALUES ( :matricule_V, :id_M)");
    query.bindValue(":matricule_V", matricule_V);
    query.bindValue(":id_M", id_M);
    return query.exec();
}

QSqlQueryModel * affectations::afficherA()

{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT v.matricule, v.cin_policier, v.marque, v.couleur,v.nb_places, v.quantite, m.id, m.nom, m.datem, m.localisation, m.description FROM vehicules v INNER JOIN affectations a ON v.matricule = a.id_vehicule INNER JOIN missions m ON m.id = a.id_mission;");
    return model;
}
