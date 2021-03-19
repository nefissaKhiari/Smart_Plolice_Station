#ifndef SERVICE_H
#define SERVICE_H


#include<QString>
#include <QSqlQueryModel>
class Service
{
public:
    Service();

    Service(QString, QString, QString, QString);
    int getid();
    QString gettype();
    QString getduree();
    QString getpapiersnecess();
    QString getdescription();
    void setid(int);
    void settype(QString);
    void setduree(QString);
    void setpapiersnecess(QString);
    void setdescription(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
     bool modifier();
    QSqlQueryModel* listId();
private:
    int id;
    QString type , duree , papiers_necess, description;

};


#endif // SERVICE_H
