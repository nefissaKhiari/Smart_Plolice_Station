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


QSqlQueryModel* affectations::Triera(QString tri) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(tri=="id_M") {
          model->setQuery("SELECT v.matricule, v.cin_policier, v.marque, v.couleur,v.nb_places, v.quantite, m.id, m.nom, m.datem, m.localisation, m.description FROM vehicules v INNER JOIN affectations a ON v.matricule = a.id_vehicule INNER JOIN missions m ON m.id = a.id_mission order by a.id_mission;");

    }
    else if(tri=="matricule_V") {
          model->setQuery("SELECT v.matricule, v.cin_policier, v.marque, v.couleur,v.nb_places, v.quantite, m.id, m.nom, m.datem, m.localisation, m.description FROM vehicules v INNER JOIN affectations a ON v.matricule = a.id_vehicule INNER JOIN missions m ON m.id = a.id_mission order by a.id_vehicule;");
    }

    return model;
}

QSqlQueryModel* affectations::recherchera(QString rechercher,QString by) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(by=="ID_M") {
       model->setQuery("SELECT v.matricule, v.cin_policier, v.marque, v.couleur,v.nb_places, v.quantite, m.id, m.nom, m.datem, m.localisation, m.description FROM vehicules v INNER JOIN affectations a ON v.matricule = a.id_vehicule INNER JOIN missions m ON m.id = a.id_mission WHERE a.id_mission LIKE '"+rechercher+"%' ;");
    }
    else if(by=="matricule_V") {
       model->setQuery("SELECT v.matricule, v.cin_policier, v.marque, v.couleur,v.nb_places, v.quantite, m.id, m.nom, m.datem, m.localisation, m.description FROM vehicules v INNER JOIN affectations a ON v.matricule = a.id_vehicule INNER JOIN missions m ON m.id = a.id_mission WHERE a.id_vehicule LIKE '"+rechercher+"%' ;");
    }


    return model;
}



bool affectations::supprimerA(int id_M, int matricule_V)
{
    QSqlQuery query;
    query.prepare("DELETE FROM affectations WHERE id_M= :id_M");
    query.bindValue(":id_M", id_M);
    return query.exec();
    QSqlQuery qery;
    qery.prepare("DELETE FROM affectations WHERE matricule_V= :matricule_V");
    qery.bindValue(":matricule_V", matricule_V);
    return qery.exec();
}

