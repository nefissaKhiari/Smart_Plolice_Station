#ifndef LOGIN_H
#define LOGIN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <functional>
#include <QSqlRecord>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

class login
{
public:
    login();
    int hash(QString);
    bool sign_in(QString,QString);
     bool sign_up(QString,QString);
};

#endif // LOGIN_H
