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
    db.setUserName("selim");
    db.setPassword("selim");

    if (db.open())
        test=true;
    return  test;

}
