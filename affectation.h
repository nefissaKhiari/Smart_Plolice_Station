#ifndef AFFECTATION_H
#define AFFECTATION_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableView>

class Affectation
{
private:
    int id, cin;

public:
    Affectation(){};
    Affectation(int, int);

    void setId(int) ;
    void setCin(int );


    int getId();
    int getCin();

      bool ajouterA();
      QSqlQueryModel* afficherA();
      bool supprimerA(int,int);
};

#endif // AFFECTATION_H
