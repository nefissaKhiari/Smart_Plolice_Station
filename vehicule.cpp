#include "vehicule.h"
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlQuery>

vehicule::vehicule(int matricule, QString marque, QString couleur, int nb_places, int quantite, int CIN_policier)
{
    this->matricule = matricule;
    this->marque = marque;
    this->couleur = couleur;
    this->nb_places = nb_places;
    this->quantite = quantite;
    this->CIN_policier = CIN_policier;


}

void vehicule::setmatricule(int m){matricule = m;}
void vehicule::setmarque(QString m){marque = m;}
void vehicule::setcouleur(QString c){couleur = c;}
void vehicule::setnb_places(int nb){nb_places = nb;}
void vehicule::setquantite(int q){quantite = q;}
void vehicule::setCIN_policier(int p){CIN_policier = p;}


int vehicule::get_matricule(){return matricule;}
QString vehicule::get_marque(){return marque;}
QString vehicule::get_couleur(){return couleur;}
int vehicule::get_nb_places(){return nb_places;}
int vehicule::get_quantite(){return quantite;}
int vehicule::get_CIN_policier(){return CIN_policier;}


bool vehicule::ajouter()
{
    QSqlQuery query;
            query.prepare("INSERT INTO vehicules (matricule, marque, quantite, couleur, nb_places, CIN_policier)"
                  "VALUES (:matricule, :marque, :quantite, :couleur, :nb_places, :CIN_policier)");
    query.bindValue(":matricule", matricule);
    query.bindValue(":marque", marque);
    query.bindValue(":quantite", quantite);
    query.bindValue(":couleur", couleur);
    query.bindValue(":nb_places", nb_places);
    query.bindValue(":CIN_policier", CIN_policier);


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

QSqlQuery  vehicule::impression(int matricule)

{
    QSqlQuery qeury;

       qeury.prepare("select * from vehicule where matricule = :matricule");

       if(qeury.exec())

       {

           return qeury;

       }
}





bool vehicule::supprimer(int matricule)
{
    QSqlQuery query;
    query.prepare("DELETE FROM vehicules WHERE matricule = :matricule");
    query.bindValue(":matricule", matricule);
    return query.exec();
}

bool vehicule::modifier(QString marque, QString couleur, int quantite, int nb_places, int matricule, int CIN_policier)
{
    QSqlQuery query;
         query.prepare("UPDATE vehicules SET marque='"+marque+"',  couleur='"+couleur+"', quantite= :quantite, nb_places= :nb_places, CIN_policier= :CIN_policier where matricule= :matricule");
         query.bindValue(":quantite", quantite);
         query.bindValue(":nb_places", nb_places);
         query.bindValue(":matricule", matricule);
         query.bindValue(":CIN_policier", CIN_policier);
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


QSqlQueryModel* vehicule::rechercherv(QString rechercherv,QString by) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(by=="matricule") {
        model->setQuery("SELECT * FROM vehicules WHERE matricule LIKE '"+rechercherv+"%'");
    }
    else if(by=="marque") {
       model->setQuery("SELECT * FROM vehicules WHERE marque LIKE '"+rechercherv+"%'");
    }
    else if(by=="quantite") {
        model->setQuery("SELECT * FROM vehicules WHERE quantite LIKE '"+rechercherv+"%'");
    }
    else if(by=="couleur") {
        model->setQuery("SELECT * FROM vehicules WHERE couleur LIKE '"+rechercherv+"%'");
    }
    else if(by=="nb_places") {
        model->setQuery("SELECT * FROM vehicules WHERE nb_places LIKE '"+rechercherv+"%'");
    }


    return model;
}
