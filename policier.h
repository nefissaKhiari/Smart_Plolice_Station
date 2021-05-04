#ifndef POLICIER_H
#define POLICIER_H

#include <QString>
#include <QSqlQueryModel>


class Policier
{
private:
    int CIN_policier;
    QString nom_policier;
    QString prenom_policier;
    QString grade_policier;
    QString mail_policier;
    int mdp_policier;
    QString secteur_policier;
public:
   Policier();
    Policier(int, QString, QString, QString, QString, int,  QString);

    void setCin_policier(int);
    int getCin_policier();

    void setNom_policier(QString);
    QString getNom_policier();

    void setPrenom_policier(QString);
    QString getPrenom_policier();

    void setGrade_policier(QString);
    QString getGrade_policier();

    void setMail_policier(QString);
    QString getMail_policier();

    void setMdp_policier(int);
    int getMdp_policier();

    void setSecteur_policier(QString);
    QString getSecteur_policier();

    bool ajouter_policier();
    bool modifier_policier();
    bool supprimer_policier(int );

    QSqlQueryModel* afficher_policier();
    QSqlQueryModel* listCin_policier();

    QSqlQueryModel* Trier_policier(QString);
    QSqlQueryModel* Chercher_policier1(QString );
    QSqlQueryModel* Chercher_policier2( QString );
    QSqlQueryModel* Exporter_policier_excel();
  QSqlQueryModel* listId();

};

#endif // POLICIER_H
