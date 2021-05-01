#include "policestation.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection C;
    bool connection=C.createConnection();
    QTranslator t;
    QStringList languages;
    languages << "Francais" << "English";
    QString lang = QInputDialog::getItem(NULL, "Selectionnez la langue", "Langue", languages);
    if(lang == "English"){
        t.load(":/tr/english.qm");
        a.installTranslator(&t);
    }
    /*if(lang != "Francais"){
        a.installTranslator(&t);
    }*/
    PoliceStation w;
    if(connection){
        w.show();
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("connexion avec la base de donnee"),
                    QObject::tr("Pas de connexion avec la base de donnee.\n"
                                "Cliquer Ok."), QMessageBox::Ok);
    }
    return a.exec();
}
