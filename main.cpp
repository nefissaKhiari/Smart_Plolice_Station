#include "gestionequipement.h"

#include <QApplication>
#include"connection.h"
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection C;
    bool connection=C.createConnection();
   GestionEquipement w;
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
