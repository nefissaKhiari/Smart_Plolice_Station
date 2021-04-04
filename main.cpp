#include <QCoreApplication>
#include "messengerserver.h"

using namespace DuarteCorporation;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MessengerServer Server;
    if(!Server.startServer(3333)) {
        qDebug() << "Erreur : " << Server.errorString();
        return 1;
    }
    qDebug() << "Server a commence...";
    return a.exec();
}
