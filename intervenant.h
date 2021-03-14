#ifndef INTERVENANT_H
#define INTERVENANT_H

#include <QString>
#include <QSqlQueryModel>

class Intervenant
{
private:
    int CIN;
    QString nom;
    QString prenom;
    QString nationalite;
    QString localisation;
    QString mail;
public:
    Intervenant();
    Intervenant(QString, QString, QString, QString, QString);

    void setCin(int);
    int getCin();

    void setNom(QString);
    QString getNom();

    void setPrenom(QString);
    QString getPrenom();

    void setNationalite(QString);
    QString getNationalite();

    void setLocalisation(QString);
    QString getLocalisation();

    void setMail(QString);
    QString getMail();

    bool ajouter();
    bool modifier();
    bool supprimer(int);

    QSqlQueryModel* afficher();
    QSqlQueryModel* afficherByCin(int);
    QSqlQueryModel* listCin();

};

#endif // INTERVENANT_H
