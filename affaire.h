#ifndef AFFAIRE_H
#define AFFAIRE_H

#include <QString>
#include <QSqlQueryModel>

class Affaire
{
private:
    int id;
    QString type;
    QString localisation;
    QString date;
    QString description;
public:
    Affaire();
    Affaire(QString, QString, QString, QString);

    void setId(int);
    int getId();

    void setType(QString);
    QString getType();

    void setLocalisation(QString);
    QString getLocalisation();

    void setDate(QString);
    QString getDate();

    void setDescription(QString);
    QString getDescription();

    bool ajouter();
    bool modifier();
    bool supprimer(int);

    QSqlQueryModel* afficher();
    QSqlQueryModel* afficherById(int);
    QSqlQueryModel* listId();
};

#endif // AFFAIRE_H
