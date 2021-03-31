#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include<QString>
#include <QSqlQueryModel>
#include <QDate>

class Maintenance
{
private:
    int idmaintenance;
    QDate datedebut;
    int cout;
    QDate datefin;
    int reference;
public:
    Maintenance();
    Maintenance(QDate,int,QDate,int);

    void setIdmaintenance(int);
    int getIdmaintenance();

    void setDatedebut(QDate);
    QDate getDatedebut();

    void setCout(int);
    int getCout();

    void setDatefin(QDate);
    QDate getDatefin();

    void setReference(int);
    int getReference();

    bool ajouter();
    bool modifier();
    bool supprimer(int);

    QSqlQueryModel* afficher();
    QSqlQueryModel* listId();
};

#endif // MAINTENANCE_H
