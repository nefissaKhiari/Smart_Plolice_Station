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
    missions( QString,QDate, QString, QString, int );
    void setnom(QString n);
    void setdatem(QDate d);
    void setlocalisation (QString l);
    void setdescription (QString d);
    void setmatricule (int ) ;

    QString get_nom();
    QDate get_datem();
    QString get_localisation();
    QString get_description();
    int get_matricule();





    bool ajouter();
    QSqlQueryModel*    afficher();
    bool supprimer(QString);
    bool modifier(QString,QDate, QString, QString );
    QSqlQueryModel* rechercher(QString,QString);
    QSqlQueryModel*    affichern();


private:
    QString  nom, localisation,description;
    QDate datem;
   int matricule;


};

#endif // MISSIONS_H
