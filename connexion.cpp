#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createConnection() {
    bool test=false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Project");//inserer le nom de la source de données ODBC
    db.setUserName("omar");//inserer nom de l'utilisateur
    db.setPassword("system");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;
    return  test;
}
