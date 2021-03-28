#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include<QString>
#include <QSqlQueryModel>

class Maintenance
{
private:
    int idmaintenance;
    QString datedebut;
    int cout;
    QString datefin;
    int reference;
public:
    Maintenance();
    Maintenance(QString,int,QString,int);

    void setIdmaintenance(int);
    int getIdmaintenance();

    void setDatedebut(QString);
    QString getDatedebut();

    void setCout(int);
    int getCout();

    void setDatefin(QString);
    QString getDatefin();

    void setReference(int);
    int getReference();

    bool ajouter();
    bool modifier();
    bool supprimer(int);

    QSqlQueryModel* afficher();
    QSqlQueryModel* listId();
};

#endif // MAINTENANCE_H
