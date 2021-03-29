#ifndef AFFAIRE_H
#define AFFAIRE_H

#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class Affaire
{
private:
    int id;
    QString type;
    QString localisation;
    QDate date;
    QString description;
    int intervenant;
public:
    Affaire();
    Affaire(QString, QString, QDate, QString, int);

    void setId(int);
    int getId();

    void setType(QString);
    QString getType();

    void setLocalisation(QString);
    QString getLocalisation();

    void setDate(QDate);
    QDate getDate();

    void setDescription(QString);
    QString getDescription();

    void setIntervenant(int);
    int getIntervenant();

    bool ajouter();
    bool modifier();
    bool supprimer(int);

    QSqlQueryModel* afficher();
    QSqlQueryModel* afficherById(int);
    QSqlQueryModel* listId();
};

#endif // AFFAIRE_H
