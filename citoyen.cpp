#include "citoyen.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QDate>

Citoyen::Citoyen()
{
    id=0;  nom=""; prenom="";
    lieu_Naiss="";mail="";
    adresse="";nom_pere="";profession="";
    etat_civil="";
}

Citoyen::Citoyen(QString nom, QString prenom, QDate date_Naiss, QString lieu_Naiss,QString mail,QString adresse,QString nom_pere,QString profession,QString etat_civil)
{
    this->nom=nom; this->prenom=prenom;
    this->date_Naiss=date_Naiss; this->lieu_Naiss=lieu_Naiss;
    this->mail=mail; this->adresse=adresse; this->nom_pere=nom_pere;
    this->profession=profession; this->etat_civil=etat_civil;
}
int Citoyen::getid(){return id;}
QString Citoyen::getnom(){return nom;}
QString Citoyen::getprenom(){return prenom;}
QDate Citoyen::getdatenaiss(){return date_Naiss;}
QString Citoyen::getlieunaiss(){return lieu_Naiss;}
QString Citoyen::getmail(){return mail;}
QString Citoyen::getadresse(){return adresse;}
QString Citoyen::getnompere(){return nom_pere;}
QString Citoyen::getprofession(){return profession;}
QString Citoyen::getetatcivil(){return etat_civil;}
void Citoyen::setid(int id){this->id=id;}
void Citoyen::setnom(QString nom){this->nom=nom;}
void Citoyen::setprenom(QString prenom){this->prenom=prenom;}
void Citoyen::setdatenaiss(QDate date_Naiss){this->date_Naiss=date_Naiss;}
void Citoyen::setlieunaiss(QString lieu_Naiss){this->lieu_Naiss=lieu_Naiss;}
void Citoyen::setmail(QString mail){this->mail=mail;}
void Citoyen::setadresse(QString adresse){this->adresse=adresse;}
void Citoyen::setnompere(QString nom_pere){this->nom_pere=nom_pere;}
void Citoyen::setprofession(QString profession){this->profession=profession;}
void Citoyen::setetatcivil(QString etat_civil){this->etat_civil=etat_civil;}
bool Citoyen::ajouter()
{
    QSqlQuery query;

        query.prepare("INSERT INTO citoyens (nom, prenom, date_Naiss,lieu_Naiss,mail,adresse,nom_pere,profession, etat_civil) "
                      "VALUES (:nom, :prenom, :date_Naiss,:lieu_Naiss,:mail,:adresse,:nom_pere,:profession, :etat_civil)");
        query.bindValue(0, nom);
        query.bindValue(1, prenom);
        query.bindValue(2,date_Naiss);
        query.bindValue(3,lieu_Naiss);
        query.bindValue(4,mail);
        query.bindValue(5,adresse);
        query.bindValue(6,nom_pere);
        query.bindValue(7,profession);
        query.bindValue(8,etat_civil);
    return query.exec();

}
bool Citoyen::supprimer(int id)
{
    QSqlQuery query;

        query.prepare("Delete from citoyens where id=:id");
        query.bindValue(0, id);

    return query.exec();
}
QSqlQueryModel* Citoyen::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM citoyens ");
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_Naiss"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("LIEU_Naiss"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("NOM_PERE"));
          model->setHeaderData(8, Qt::Horizontal, QObject::tr("PROFESSION"));
          model->setHeaderData(9, Qt::Horizontal, QObject::tr("ETAT_CIVIL"));

    return model;
}
QSqlQueryModel* Citoyen::listId() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id FROM citoyens");
    return model;
}


bool Citoyen::modifier() {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("UPDATE citoyens set nom=:nom, prenom=:prenom, date_Naiss=:date_Naiss, lieu_Naiss=:lieu_Naiss, mail=:mail,adresse=:adresse,nom_pere=:nom_pere,profession=:profession,etat_civil=:etat_civil where id=:id");
    query.bindValue(9, id_string);
    query.bindValue(0, nom);
    query.bindValue(1, prenom);
    query.bindValue(2, date_Naiss);
    query.bindValue(3, lieu_Naiss);
    query.bindValue(4, mail);
    query.bindValue(5, adresse);
    query.bindValue(6, nom_pere);
    query.bindValue(7, profession);
    query.bindValue(8, etat_civil);
    return query.exec();
}
QSqlQueryModel* Citoyen::rechercher(QString rechercher,QString by) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(by=="id") {
        model->setQuery("SELECT * FROM citoyens WHERE id LIKE '"+rechercher+"%'");
    }
    else if(by=="nom") {
       model->setQuery("SELECT * FROM citoyens WHERE nom LIKE '"+rechercher+"%'");
    }
    else if(by=="prenom") {
        model->setQuery("SELECT * FROM citoyens WHERE prenom LIKE '"+rechercher+"%'");
    }


    return model;
}

QSqlQueryModel* Citoyen::Trier(QString tri) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(tri=="nom") {
        model->setQuery("SELECT * FROM citoyens ORDER BY nom ");
    }
    else if(tri=="prenom") {
        model->setQuery("SELECT * FROM citoyens ORDER BY prenom ");
    }

    return model;
}


