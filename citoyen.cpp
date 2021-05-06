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
    etat_civil="";region="";
}

Citoyen::Citoyen(QString nom, QString prenom, QDate date_Naiss, QString lieu_Naiss,QString mail,QString adresse,QString nom_pere,QString profession,QString etat_civil,QString region)
{
    this->nom=nom; this->prenom=prenom;
    this->date_Naiss=date_Naiss; this->lieu_Naiss=lieu_Naiss;
    this->mail=mail; this->adresse=adresse; this->nom_pere=nom_pere;
    this->profession=profession; this->etat_civil=etat_civil;
    this->region=region;
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
QString Citoyen::getregion(){return region;}
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
void Citoyen::setregion(QString region){this->region=region;}
bool Citoyen::ajouter()
{
    QSqlQuery query;

        query.prepare("INSERT INTO citoyens (nom, prenom, date_Naiss,lieu_Naiss,mail,adresse,nom_pere,profession, etat_civil,region) "
                      "VALUES (:nom, :prenom, :date_Naiss,:lieu_Naiss,:mail,:adresse,:nom_pere,:profession, :etat_civil,:region)");
        query.bindValue(0, nom);
        query.bindValue(1, prenom);
        query.bindValue(2,date_Naiss);
        query.bindValue(3,lieu_Naiss);
        query.bindValue(4,mail);
        query.bindValue(5,adresse);
        query.bindValue(6,nom_pere);
        query.bindValue(7,profession);
        query.bindValue(8,etat_civil);
        query.bindValue(9,region);
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
          model->setHeaderData(10, Qt::Horizontal, QObject::tr("REGION"));

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
    query.prepare("UPDATE citoyens set nom=:nom, prenom=:prenom, date_Naiss=:date_Naiss, lieu_Naiss=:lieu_Naiss, mail=:mail,adresse=:adresse,nom_pere=:nom_pere,profession=:profession,etat_civil=:etat_civil,region=:region where id=:id");
    query.bindValue(10, id_string);
    query.bindValue(0, nom);
    query.bindValue(1, prenom);
    query.bindValue(2, date_Naiss);
    query.bindValue(3, lieu_Naiss);
    query.bindValue(4, mail);
    query.bindValue(5, adresse);
    query.bindValue(6, nom_pere);
    query.bindValue(7, profession);
    query.bindValue(8, etat_civil);
    query.bindValue(9, region);

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
int Citoyen::ProfA() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM citoyens where profession='Autres...'");
    qry.exec();
    int Autres= 0;
    if (qry.next()) {
        Autres= qry.value(0).toInt();
    }
    return Autres;
}

int Citoyen::ProfEm() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM citoyens where profession='Employe'");
        qry.exec();
        int Em= 0;
        if (qry.next()) {
            Em= qry.value(0).toInt();
        }
    return Em;
}

int Citoyen::ProfDir() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM citoyens where profession='Directeur'");
    qry.exec();
    int Dir= 0;
    if (qry.next()) {
        Dir= qry.value(0).toInt();
    }
    return Dir;
}

int Citoyen::ProfMed() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM citoyens where profession='Medecin'");
    qry.exec();
    int Med= 0;
    if (qry.next()) {
        Med= qry.value(0).toInt();
    }
    return Med;
}

int Citoyen::ProfPr() {
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM citoyens where profession='Professeur'");
    qry.exec();
    int Pr= 0;
    if (qry.next()) {
        Pr= qry.value(0).toInt();
    }
    return Pr;
}
int Citoyen::NE() {
    int r=0;

    QSqlQuery bqry;
    bqry.prepare("SELECT COUNT (*) FROM citoyens where region='Bizerte'");
    bqry.exec();
    if (bqry.next()) {
        r += bqry.value(0).toInt();
    }
    QSqlQuery tqry;
    tqry.prepare("SELECT COUNT (*) FROM citoyens where region='Tunis'");
    tqry.exec();
    if (tqry.next()) {
        r += tqry.value(0).toInt();
    }
    QSqlQuery zqry;
    zqry.prepare("SELECT COUNT (*) FROM citoyens where region='Zaghouan'");
    zqry.exec();
    if (zqry.next()) {
        r += zqry.value(0).toInt();
    }
    QSqlQuery nqry;
    nqry.prepare("SELECT COUNT (*) FROM citoyens where region='Nabeul'");
    nqry.exec();
    if (nqry.next()) {
        r += nqry.value(0).toInt();
    }

    return r;
}

int Citoyen::NO() {
    int  r=0;

    QSqlQuery jqry;
    jqry.prepare("SELECT COUNT (*) FROM citoyens where region='Jendouba'");
    jqry.exec();
    if (jqry.next()) {
        r += jqry.value(0).toInt();
    }
    QSqlQuery bqry;
    bqry.prepare("SELECT COUNT (*) FROM citoyens where region='Beja'");
    bqry.exec();
    if (bqry.next()) {
        r += bqry.value(0).toInt();
    }
    QSqlQuery kqry;
    kqry.prepare("SELECT COUNT (*) FROM citoyens where region='Kef'");
    kqry.exec();
    if (kqry.next()) {
        r += kqry.value(0).toInt();
    }


    return r;
}

int Citoyen::CE() {
    int r=0;

    QSqlQuery sqry;
    sqry.prepare("SELECT COUNT (*) FROM citoyens where region='Sousse'");
    sqry.exec();
    if (sqry.next()) {
        r += sqry.value(0).toInt();
    }
    QSqlQuery mqry;
    mqry.prepare("SELECT COUNT (*) FROM citoyens where region='Monastir'");
    mqry.exec();
    if (mqry.next()) {
        r += mqry.value(0).toInt();
    }
    QSqlQuery maqry;
    maqry.prepare("SELECT COUNT (*) FROM citoyens where region='Mahdia'");
    maqry.exec();
    if (maqry.next()) {
        r += maqry.value(0).toInt();
    }

    return r;
}

int Citoyen::CO() {
    int r=0;

    QSqlQuery sqry;
    sqry.prepare("SELECT COUNT (*) FROM citoyens where region='Sidi Bouzid'");
    sqry.exec();
    if (sqry.next()) {
        r += sqry.value(0).toInt();
    }
    QSqlQuery mqry;
    mqry.prepare("SELECT COUNT (*) FROM citoyens where region='Kasserine'");
    mqry.exec();
    if (mqry.next()) {
        r += mqry.value(0).toInt();
    }
    QSqlQuery maqry;
    maqry.prepare("SELECT COUNT (*) FROM citoyens where region='Kairouan'");
    maqry.exec();
    if (maqry.next()) {
        r += maqry.value(0).toInt();
    }

    return r;
}

int Citoyen::SE() {
    int  r=0;

    QSqlQuery jqry;
    jqry.prepare("SELECT COUNT (*) FROM citoyens where region='Tataouin'");
    jqry.exec();
    if (jqry.next()) {
        r += jqry.value(0).toInt();
    }
    QSqlQuery bqry;
    bqry.prepare("SELECT COUNT (*) FROM citoyens where region='Medenine'");
    bqry.exec();
    if (bqry.next()) {
        r += bqry.value(0).toInt();
    }
    QSqlQuery kqry;
    kqry.prepare("SELECT COUNT (*) FROM citoyens where region='Gabes'");
    kqry.exec();
    if (kqry.next()) {
        r += kqry.value(0).toInt();
    }
    QSqlQuery sqry;
    sqry.prepare("SELECT COUNT (*) FROM citoyens where region='Sfax'");
    sqry.exec();
    if (sqry.next()) {
        r += sqry.value(0).toInt();
    }

    return r;
}

int Citoyen::SO() {
    int r=0;

    QSqlQuery sqry;
    sqry.prepare("SELECT COUNT (*) FROM citoyens where region='Kebili'");
    sqry.exec();
    if (sqry.next()) {
        r += sqry.value(0).toInt();
    }
    QSqlQuery mqry;
    mqry.prepare("SELECT COUNT (*) FROM citoyens where region='Tozeur'");
    mqry.exec();
    if (mqry.next()) {
        r += mqry.value(0).toInt();
    }
    QSqlQuery maqry;
    maqry.prepare("SELECT COUNT (*) FROM citoyens where region='Gafsa'");
    maqry.exec();
    if (maqry.next()) {
        r += maqry.value(0).toInt();
    }

    return r;
}
