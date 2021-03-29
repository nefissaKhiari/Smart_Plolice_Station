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
    missions( QString,QDate, QString, QString );
    void setnom(QString n);
    void setdatem(QDate d);
    void setlocalisation (QString l);
    void setdescription (QString d);


    QString get_nom();
    QDate get_datem();
    QString get_localisation();
    QString get_description();




    bool ajouter();
    QSqlQueryModel*    afficher();
    bool supprimer(QString);
    bool modifier(QString,QDate, QString, QString );




private:
    QString  nom, localisation,description;
    QDate datem;

};

#endif // MISSIONS_H
