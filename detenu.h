#ifndef DETENU_H
#define DETENU_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class Detenu
{
private:
    int id;
    QString nom;
    QString prenom;
    QString nationalite;
    QDate date_naiss;
    QDate date_arrest;
    QString historique ;
    QString niveau_danger;
public:
    Detenu();
    Detenu(int, QString, QString, QString, QDate, QDate, QString, QString);

    void setId(int);
    int getId();

    void setNom(QString);
    QString getNom();

    void setPrenom(QString);
    QString getPrenom();

    void setNationalite(QString);
    QString getNationalite();

    void setHistorique(QString);
    QString getHistorique();

    void setDanger(QString);
    QString getDanger();

    void setDn(QDate);
    QDate getDn();

    void setDa(QDate);
    QDate getDa();

    bool ajouter();
    bool modifier();
    bool supprimer(int);

    QSqlQueryModel* afficher();
    QSqlQueryModel* listId();

    QSqlQueryModel* Trier(QString);
    QSqlQueryModel* Chercher(QString,QString);
};

#endif // DETENU_H
