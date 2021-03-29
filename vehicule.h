#ifndef VEHICULE_H
#define VEHICULE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableView>


class vehicule
{
public:
    vehicule(){}
    vehicule(int, QString, QString, int, int );
    void setmatricule(int m);
    void setmarque(QString m);
    void setcouleur (QString c);
    void setnb_places (int nb);
    void setquantite (int q);

    int get_matricule();
    QString get_marque();
    QString get_couleur();
    int get_nb_places();
    int get_quantite();



    bool ajouter();
    QSqlQueryModel*    afficher();
    bool supprimer(int);
    bool modifier(QString, QString, int , int , int);
    QSqlQueryModel* Trier(QString);




private:
    QString  marque, couleur;
    int matricule,nb_places,quantite;

};


#endif // VEHICULE_H
