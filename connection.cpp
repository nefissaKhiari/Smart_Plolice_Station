#include "connection.h"
#include <QSqlDatabase>

Connection::Connection()
{

}

bool Connection::createConnection(){
    bool test=false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet");
    db.setUserName("selim");
    db.setPassword("selim");

    if (db.open())
        test=true;
    return  test;
}
