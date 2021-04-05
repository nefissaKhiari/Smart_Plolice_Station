#ifndef AFFECTATIONS_H
#define AFFECTATIONS_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableView>

class affectations
{

public:
    affectations(){};
    affectations(int, int);
    void setid_M (int ) ;
    void setmatricule_V(int );


    int get_id_M();
    int get_matricule_V();

      bool ajouterA();
      QSqlQueryModel*    afficherA();
      bool supprimerA(int,int);

private:
 int  id_M, matricule_V;




};

#endif // AFFECTATIONS_H
