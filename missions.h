#ifndef MISSIONS_H
#define MISSIONS_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableView>

class missions
{
public:
    missions(){}
    missions( int, QString, QDate, QString, QString, int );

    void setid (int ) ;
    void setnom(QString n);
    void setdatem(QDate d);
    void setlocalisation (QString l);
    void setdescription (QString d);
    void setmatricule (int ) ;

    int get_id();
    QString get_nom();
    QDate get_datem();
    QString get_localisation();
    QString get_description();
    int get_matricule();





    bool ajouter();
    QSqlQueryModel*    afficher();
    bool supprimer(int);
    bool modifier(int, QString, QDate, QString, QString , int);
    QSqlQueryModel* rechercher(QString,QString);
    QSqlQueryModel*    affichern();
    QSqlQueryModel* Trierm(QString);

private:
    QString  nom, localisation,description;
    QDate datem;
   int matricule,id;


};

#endif // MISSIONS_H
