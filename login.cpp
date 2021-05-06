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
    qry.prepare("SELECT * FROM policier WHERE mail_policier=:mail_policier AND (mdp_policier=:mdp_policier OR code=:mdp_policier )");
    qry.bindValue(":mail_policier",uname);
    qry.bindValue(":mdp_policier",this->hash(pwd));

    //current_user=uname;

    return qry.exec() && qry.next();

}

QString login::code_generator()
{
    static const char alphanum[] =
    "0123456789"
    "!@#$%^&*"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

    int stringLength = sizeof(alphanum) - 1;

    srand(time(0));
        QString Str;
        for(unsigned int i = 0; i < 7; ++i)
        {
        Str += alphanum[rand() % stringLength];

        }
        return Str;
}
bool login::update_mpd_reset(QString uname,QString code)
{
    QSqlQuery qry;
    qry.prepare("UPDATE policier SET code=:code WHERE (mail_policier=:mail_policier)");
    qry.bindValue(":mail_policier",uname);
    qry.bindValue(":code",this->hash(code));

    return qry.exec();
}

bool login::email_exist(QString uname)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM policier WHERE mail_policier=:mail_policier ");
    qry.bindValue(":mail_policier",uname);


    return qry.exec() && qry.next();

}
