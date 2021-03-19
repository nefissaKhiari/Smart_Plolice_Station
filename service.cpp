#include "service.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>

Service::Service()
{
    id=0;  type=""; duree="";
    papiers_necess="";description="";
}

Service::Service(QString type, QString duree, QString papiers_necess, QString decription)
{
    this->type=type; this->duree=duree;
    this->papiers_necess=papiers_necess; this->description=description;
}
int Service::getid(){return id;}
QString Service::gettype(){return type;}
QString Service::getduree(){return duree;}
QString Service::getpapiersnecess(){return papiers_necess;}
QString Service::getdescription(){return description;}
void Service::setid(int id){this->id=id;}
void Service::settype(QString type){this->type=type;}
void Service::setduree(QString duree){this->duree=duree;}
void Service::setpapiersnecess(QString papiers_necess){this->papiers_necess=papiers_necess;}
void Service::setdescription(QString desription){this->description=description;}
bool Service::ajouter()
{
    QSqlQuery query;

        query.prepare("INSERT INTO services (type, duree, papiers_necess,description) "
                      "VALUES (:type, :duree, :papiers_necess,:description)");
        query.bindValue(0, type);
        query.bindValue(1, duree);
        query.bindValue(2,papiers_necess);
        query.bindValue(3,description);
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
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("papiers_necess"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("decription"));
    return model;
}
QSqlQueryModel* Service::listId() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id FROM services");
    return model;
}
bool Service::modifier() {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("UPDATE services set type=:type, duree=:duree, papiers_necess=:papiers_necess, description=:description where id=:id");
    query.bindValue(4, id_string);
    query.bindValue(0, type);
    query.bindValue(1, duree);
    query.bindValue(2, papiers_necess);
    query.bindValue(3, description);

    return query.exec();
}
