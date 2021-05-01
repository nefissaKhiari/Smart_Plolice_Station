#include "connection.h"
#include <QSqlDatabase>

Connection::Connection()
{

}

bool Connection::createConnection(){
    bool test=false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-bd");
    db.setUserName("system");
    db.setPassword("Mokki321");

    if (db.open())
        test=true;
    return  test;
}
