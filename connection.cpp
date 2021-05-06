#include "connection.h"
#include <QSqlDatabase>
/* 000*/

Connection::Connection()
{

}

bool Connection::createConnection(){
    bool test=false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Project");
    db.setUserName("omar");
    db.setPassword("system");

    if (db.open())
        test=true;
    return  test;

}
