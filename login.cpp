#include "login.h"

login::login()
{

}
int login::hash(QString pwd)
{
    std::hash<std::string> hash;
    return hash(pwd.toStdString());
}
bool login::sign_in(QString uname,QString pwd)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM policier WHERE mail_policier=:mail_policier AND mdp_policier=:mdp_policier");
    qry.bindValue(":mail_policier",uname);
    qry.bindValue(":mdp_policier",this->hash(pwd));

    //current_user=uname;

    return qry.exec() && qry.next();

}
bool login::sign_up(QString uname,QString pwd)
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO policier (mail_policier,mdp_policier)"
                "VALUES (:mail_policier,:mdp_policier)");
    qry.bindValue(":mail_policier",uname);
    qry.bindValue(":mdp_policier",this->hash(pwd));


    return qry.exec();
}
