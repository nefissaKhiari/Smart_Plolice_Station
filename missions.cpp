#include "missions.h"
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>


missions::missions(int id, QString nom, QDate datem, QString localisation, QString description)
{
    this->id = id;
    this->nom = nom;
    this->datem = datem;
    this->localisation = localisation;
    this->description = description;



}

void missions::setid(int i){id =i;}
void missions::setnom(QString n){nom = n;}
void missions::setdatem(QDate d){datem = d;}
void missions::setlocalisation(QString l){localisation = l;}
void missions::setdescription(QString d){description = d;}





int missions::get_id(){return id;}
QString missions::get_nom(){return nom;}
QDate missions::get_datem(){return datem;}
QString missions::get_localisation(){return localisation;}
QString missions::get_description(){return description;}




bool missions::ajouter()
{
    QSqlQuery query;
            query.prepare("INSERT INTO missions (nom, datem, localisation, description)"
                  "VALUES ( :nom, :datem, :localisation, :description)");
    query.bindValue(":nom", nom);
    query.bindValue(":datem", datem);
    query.bindValue(":localisation", localisation);
    query.bindValue(":description", description);
    return query.exec();
}

QSqlQueryModel * missions::afficher()

{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM missions");

    return model;
}

QSqlQueryModel * missions::affichern()

{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT id FROM missions");
    return model;
}


bool missions::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM missions WHERE id= :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool missions::modifier(int id, QString nom, QDate datem, QString localisation, QString description)
{
    QSqlQuery query;
         query.prepare("UPDATE missions SET  nom= :nom, datem= :datem, localisation='"+localisation+"', description='"+description+"'  where id= :id");
         query.bindValue(":datem", datem);
         query.bindValue(":nom", nom);

         query.bindValue(":id", id);


      return query.exec();
}


QSqlQueryModel* missions::rechercher(QString rechercher,QString by) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(by=="nom") {
        model->setQuery("SELECT * FROM missions WHERE nom LIKE '"+rechercher+"%'");
    }
    else if(by=="localisation") {
       model->setQuery("SELECT * FROM missions WHERE localisation LIKE '"+rechercher+"%'");
    }
    else if(by=="description") {
        model->setQuery("SELECT * FROM missions WHERE description LIKE '"+rechercher+"%'");
    }


    return model;
}

QSqlQueryModel* missions::Trierm(QString tri) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(tri=="nom") {
        model->setQuery("SELECT * FROM missions ORDER BY nom");
    }
    else if(tri=="localisation") {
        model->setQuery("SELECT * FROM missions ORDER BY localisation");
    }
    else if(tri=="description") {
        model->setQuery("SELECT * FROM missions ORDER BY description ");
    }

    return model;
}

QSqlQueryModel * missions::affectAll(){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT p.cin_policier, p.nom_policier, p.prenom_policier, m.nom, v.matricule FROM missions m INNER JOIN affectations a ON a.id_mission = m.id INNER JOIN vehicules v ON v.matricule = a.id_vehicule INNER JOIN policier p ON v.cin_policier = p.cin_policier");
    return model;
}
