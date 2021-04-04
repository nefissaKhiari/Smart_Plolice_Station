#include "service.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>

Service::Service()
{
    id=0;  libelle=""; duree="";
    papiers_necess="";description="";
}

Service::Service(QString libelle, QString duree, QString papiers_necess, QString description,int id_citoyen)
{
    this->libelle=libelle; this->duree=duree;
    this->papiers_necess=papiers_necess; this->description=description;
    this->id_citoyen=id_citoyen;
}
int Service::getid(){return id;}
QString Service::getlibelle(){return libelle;}
QString Service::getduree(){return duree;}
QString Service::getpapiersnecess(){return papiers_necess;}
QString Service::getdescription(){return description;}
int Service::getid_citoyen(){return id_citoyen;}
void Service::setid(int id){this->id=id;}
void Service::setlibelle(QString libelle){this->libelle=libelle;}
void Service::setduree(QString duree){this->duree=duree;}
void Service::setpapiersnecess(QString papiers_necess){this->papiers_necess=papiers_necess;}
void Service::setdescription(QString description){this->description=description;}
void Service::setid_citoyen(int id_citoyen){this->id_citoyen=id_citoyen;}
bool Service::ajouter()
{
    QSqlQuery query;

        query.prepare("INSERT INTO services (libelle, duree, papiers_necess,description,id_citoyen) "
                      "VALUES (:libelle, :duree, :papiers_necess,:description,:id_citoyen)");
        query.bindValue(0, libelle);
        query.bindValue(1, duree);
        query.bindValue(2,papiers_necess);
        query.bindValue(3,description);
        query.bindValue(4,id_citoyen);

    return query.exec();

}
bool Service::supprimer(int id)
{
    QSqlQuery query;

        query.prepare("Delete from services where id=:id");
        query.bindValue(0, id);

    return query.exec();
}
QSqlQueryModel* Service::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM services ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("papiers_necess"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("decription"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_citoyen"));
    return model;
}
QSqlQueryModel* Service::listId() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id FROM services");
    return model;
}
QSqlQueryModel* Service::listNom() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT libelle FROM services");
    return model;
}
bool Service::modifier() {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("UPDATE services set libelle=:libelle, duree=:duree, papiers_necess=:papiers_necess, description=:description where id=:id");
    query.bindValue(4, id_string);
    query.bindValue(0, libelle);
    query.bindValue(1, duree);
    query.bindValue(2, papiers_necess);
    query.bindValue(3, description);

    return query.exec();
}
QSqlQueryModel* Service::rechercher(QString rechercher,QString by) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(by=="id") {
        model->setQuery("SELECT * FROM services WHERE id LIKE '"+rechercher+"%'");
    }
    else if(by=="libelle") {
       model->setQuery("SELECT * FROM services WHERE libelle LIKE '"+rechercher+"%'");
    }



    return model;
}
