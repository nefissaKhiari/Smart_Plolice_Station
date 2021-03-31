#include "vehicule.h"
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>


vehicule::vehicule(int matricule, QString marque, QString couleur, int nb_places, int quantite)
{
    this->matricule = matricule;
    this->marque = marque;
    this->couleur = couleur;
    this->nb_places = nb_places;
    this->quantite = quantite;


}

void vehicule::setmatricule(int m){matricule = m;}
void vehicule::setmarque(QString m){marque = m;}
void vehicule::setcouleur(QString c){couleur = c;}
void vehicule::setnb_places(int nb){nb_places = nb;}
void vehicule::setquantite(int q){quantite = q;}



int vehicule::get_matricule(){return matricule;}
QString vehicule::get_marque(){return marque;}
QString vehicule::get_couleur(){return couleur;}
int vehicule::get_nb_places(){return nb_places;}
int vehicule::get_quantite(){return quantite;}


bool vehicule::ajouter()
{
    QSqlQuery query;
            query.prepare("INSERT INTO vehicules (matricule, marque, quantite, couleur, nb_places)"
                  "VALUES (:matricule, :marque, :quantite, :couleur, :nb_places)");
    query.bindValue(":matricule", matricule);
    query.bindValue(":marque", marque);
    query.bindValue(":quantite", quantite);
    query.bindValue(":couleur", couleur);
    query.bindValue(":nb_places", nb_places);


    return query.exec();
}

QSqlQueryModel * vehicule::afficher()

{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM vehicules");

    return model;
}


QSqlQueryModel * vehicule::afficherm()

{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT matricule FROM vehicules");

    return model;
}


bool vehicule::supprimer(int matricule)
{
    QSqlQuery query;
    query.prepare("DELETE FROM vehicules WHERE matricule = :matricule");
    query.bindValue(":matricule", matricule);
    return query.exec();
}

bool vehicule::modifier(QString marque, QString couleur, int quantite, int nb_places, int matricule)
{
    QSqlQuery query;
         query.prepare("UPDATE vehicules SET marque='"+marque+"',  couleur='"+couleur+"', quantite= :quantite, nb_places= :nb_places where matricule= :matricule");
         query.bindValue(":quantite", quantite);
         query.bindValue(":nb_places", nb_places);
         query.bindValue(":matricule", matricule);
      return query.exec();
}


QSqlQueryModel* vehicule::Trier(QString tri) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(tri=="matricule") {
        model->setQuery("SELECT * FROM vehicules ORDER BY matricule");
    }
    else if(tri=="marque") {
        model->setQuery("SELECT * FROM vehicules ORDER BY marque");
    }
    else if(tri=="quantite") {
        model->setQuery("SELECT * FROM vehicules ORDER BY quantite ");
    }
    else if(tri=="couleur") {
        model->setQuery("SELECT * FROM vehicules ORDER BY couleur ");
    }
    else if(tri=="nb_places") {
        model->setQuery("SELECT * FROM vehicules ORDER BY nb_places ");
    }

    return model;
}
