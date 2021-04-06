#include "connection.h"
#include <QSqlDatabase>

Connection::Connection()
{

}

bool Connection::createConnection(){
    bool test=false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Project");
    db.setUserName("ibtihel");
    db.setPassword("ibtihel1812");

    if (db.open())
        test=true;
    return  test;
}
