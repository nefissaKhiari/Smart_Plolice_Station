#ifndef VEHICULE_H
#define VEHICULE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableView>
#include <QSound>

class vehicule
{
public:
    vehicule(){}
    vehicule(int, QString, QString, int, int, int);
    void setmatricule(int m);
    void setmarque(QString m);
    void setcouleur (QString c);
    void setnb_places (int nb);
    void setquantite (int q);
    void setCIN_policier (int q);


    int get_matricule();
    QString get_marque();
    QString get_couleur();
    int get_nb_places();
    int get_quantite();
    int get_CIN_policier();



    bool ajouter();
    QSqlQueryModel*    afficher();
    bool supprimer(int);
    bool modifier(QString, QString, int , int , int, int);
    QSqlQueryModel* Trier(QString);
    QSqlQueryModel*    afficherm();
    QSqlQuery   impression(int);

     QSqlQueryModel* rechercherv(QString,QString);



private:
    QString  marque, couleur;
    int matricule,nb_places,quantite,CIN_policier;
    QSound *son;
};


#endif // VEHICULE_H
