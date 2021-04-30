#include "connection.h"
#include <QSqlDatabase>

Connection::Connection()
{

}

bool Connection::createConnection(){
    bool test=false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet");
    db.setUserName("hadir");
    db.setPassword("hadir");

    if (db.open())
        test=true;
    return  test;
}
