#include "connection.h"
#include <QSqlDatabase>
/* 000*/

Connection::Connection()
{

}

bool Connection::createConnection(){
    bool test=false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("project");
    db.setUserName("ibtihel");
    db.setPassword("ibtihel1812");

    if (db.open())
        test=true;
    return  test;
}
