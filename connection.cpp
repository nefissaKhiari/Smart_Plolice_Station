#include "connection.h"
#include <QSqlDatabase>
/* 000*/

Connection::Connection()
{

}

bool Connection::createConnection(){
    bool test=false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("hadir");
    db.setPassword("hadir");

    if (db.open())
        test=true;
    return  test;

}
