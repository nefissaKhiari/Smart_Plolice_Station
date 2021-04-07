#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
Notifications::Notifications()
{

}

void Notifications::notifications_ajoutercitoyen()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Gestion des citoyens ","Nouveau citoyen ajouté ",QSystemTrayIcon::Information,15000);
}
void Notifications::notifications_ajouterservice()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Gestion des services ","Nouveau service ajouté ",QSystemTrayIcon::Information,15000);
}
void Notifications::notifications_supprimercitoyen(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Gestion des citoyens ","Citoyen Supprimé",QSystemTrayIcon::Information,15000);
}
void Notifications::notifications_supprimerservice(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Gestion des services ","Service supprimé",QSystemTrayIcon::Information,15000);

}
void Notifications::notifications_modifiercitoyen(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Gestion des citoyens ","Citoyen modifié",QSystemTrayIcon::Information,15000);

}
void Notifications::notifications_modifierservice(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Gestion des services ","Service modifié",QSystemTrayIcon::Information,15000);

}
void Notifications::notifications_envoyermail()
{

   QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Email ","Mail Envoyé ",QSystemTrayIcon::Information,15000);
}
void Notifications::notifications_pdfservice()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("PDF enregistré .Prêt à être imprimer ","Nouveau citoyen ajouté ",QSystemTrayIcon::Information,15000);
}
