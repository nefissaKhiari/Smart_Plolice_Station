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
    missions( int, QString, QDate, QString, QString );

    void setid (int ) ;
    void setnom(QString n);
    void setdatem(QDate d);
    void setlocalisation (QString l);
    void setdescription (QString d);


    int get_id();
    QString get_nom();
    QDate get_datem();
    QString get_localisation();
    QString get_description();






    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int, QString, QDate, QString, QString );
    QSqlQueryModel* rechercher(QString,QString);
    QSqlQueryModel* affichern();
    QSqlQueryModel* Trierm(QString);
    QSqlQueryModel* affectAll();

private:
    QString  nom, localisation,description;
    QDate datem;
   int id;


};

#endif // MISSIONS_H
