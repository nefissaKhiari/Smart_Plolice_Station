#ifndef POUBELLE_H
#define POUBELLE_H
#include<QString>
#include <QSqlQueryModel>

class Poubelle
{
private:
    int reference;
    int quantite;
    QString taille;
    QString etat;
    int poid;
    QString nom;
    int CIN_policier;
public:
    Poubelle();
    Poubelle(int,int,QString,QString,int,QString,int);

    bool ajouter();
    bool supprimer();

    QSqlQueryModel* afficherPoubelle();

};

#endif // POUBELLE_H
