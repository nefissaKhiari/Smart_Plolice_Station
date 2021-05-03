#include "connection.h"
#include <QSqlDatabase>
/* 000*/

Connection::Connection()
{

}

bool Connection::createConnection(){
    bool test=false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test");
    db.setUserName("system");
    db.setPassword("98768833");

    if (db.open())
        test=true;
    return  test;
}
