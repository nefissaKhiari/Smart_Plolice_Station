#ifndef CITOYEN_H
#define CITOYEN_H

#include<QString>
#include <QSqlQueryModel>
class Citoyen
{
public:
    Citoyen();

    Citoyen(QString, QString, QString, QString,QString,QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString getdatenaiss();
    QString getlieunaiss();
    QString getmail();
    QString getadresse();
    QString getnompere();
    QString getprofession();
    QString getetatcivil();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setdatenaiss(QString);
    void setlieunaiss(QString);
    void setmail(QString);
    void setadresse(QString);
    void setnompere(QString);
    void setprofession(QString);
    void setetatcivil(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
     bool modifier();
    QSqlQueryModel* listId();

private:
    int id;
    QString nom , prenom , date_Naiss, lieu_Naiss ,mail ,  adresse , nom_pere, profession,etat_civil;

};

#endif // CITOYEN_H
