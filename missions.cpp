#include "missions.h"
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>


missions::missions(QString nom, QDate datem, QString localisation, QString description)
{
    this->nom = nom;
    this->datem = datem;
    this->localisation = localisation;
    this->description = description;



}

void missions::setnom(QString n){nom = n;}
void missions::setdatem(QDate d){datem = d;}
void missions::setlocalisation(QString l){localisation = l;}
void missions::setdescription(QString d){description = d;}




QString missions::get_nom(){return nom;}
QDate missions::get_datem(){return datem;}
QString missions::get_localisation(){return localisation;}
QString missions::get_description(){return description;}



bool missions::ajouter()
{
    QSqlQuery query;
            query.prepare("INSERT INTO missions (nom, datem, localisation, description)"
                  "VALUES (:nom, :datem, :localisation, :description)");
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


bool missions::supprimer(QString nom)
{
    QSqlQuery query;
    query.prepare("DELETE FROM missions WHERE nom = :nom");
    query.bindValue(":nom", nom);
    return query.exec();
}

bool missions::modifier(QString nom, QDate datem, QString localisation, QString description)
{
    QSqlQuery query;
         query.prepare("UPDATE missions SET datem= :datem, localisation='"+localisation+"', description='"+description+"' where nom= :nom");
         query.bindValue(":datem", datem);
         query.bindValue(":nom", nom);

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
