#ifndef INFRACTION_H
#define INFRACTION_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class Infraction
{
private:
    int id;
    QString nom;
    QString type;
    QString niveau;
    QDate date;
    QString detenu;
public:
    Infraction();
    Infraction(QString, QString, QString, QDate, QString);

    void setId(int);
    int getId();

    void setNom(QString);
    QString getNom();

    void setType(QString);
    QString getType();

    void setNiveau(QString);
    QString getNiveau();

    void setDetenu(QString);
    QString getDetenu();

    void setDate(QDate);
    QDate getDate();

    bool ajouter();
    bool modifier();
    bool supprimer(int);

    int dis();
    int as();
    int hi();
    int vol();
    int meurtre();

    QSqlQueryModel* afficher();
    QSqlQueryModel* listId();

};

#endif // INFRACTION_H
