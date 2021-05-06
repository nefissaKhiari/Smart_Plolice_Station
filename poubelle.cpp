#include "poubelle.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Poubelle::Poubelle()
{

}
Poubelle :: Poubelle(int reference,int quantite, QString taille, QString etat, int poid, QString nom, int CIN_policier )
{
    this->reference=reference;  this->quantite=quantite;  this->taille=taille;  this->etat=etat;  this->poid=poid;  this->nom=nom; this->CIN_policier=CIN_policier;
}
    bool Poubelle::ajouter() {
        QSqlQuery query;
        QString ref_string = QString::number(reference);
        QString poid_string = QString::number(poid);
        QString quantite_string = QString::number(quantite);
        QString cin_policier_string = QString::number(CIN_policier);
        query.prepare("INSERT INTO poubelle(reference, quantite, taille, etat, poid, nom, cin_policier)" "VALUES (:reference, :quantite, :taille, :etat, :poid, :nom, :cin_policier)");
        query.bindValue(0, ref_string);
        query.bindValue(1, quantite_string);
        query.bindValue(2, taille);
        query.bindValue(3, etat);
        query.bindValue(4, poid_string);
        query.bindValue(5, nom);
        query.bindValue(6, cin_policier_string);
        return query.exec();
    }
    bool Poubelle::supprimer() {
        QSqlQuery query;
        query.prepare("delete from poubelle");
        return query.exec();
    }


    QSqlQueryModel* Poubelle::afficherPoubelle() {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM poubelle");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("quantite"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("taille"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("poid"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("nom"));
        return model;
    }
