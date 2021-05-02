#include "affairesjuridiques.h"
#include "connection.h"

#include <QApplication>
#include <QMessageBox>
#include <QDebug>

//Git Push0
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection C;
    bool connection=C.createConnection();
    AffairesJuridiques w;
    if(connection){
        qDebug() << "Connexion Complet";
        w.show();
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("connexion avec la base de donnee"),
                    QObject::tr("Pas de connexion avec la base de donnee.\n"
                                "Cliquer Ok."), QMessageBox::Ok);
    }
    return a.exec();
}
