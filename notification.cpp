#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>



notification::notification()
{

}

void notification::notifications_modifiervehicule(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des véhicules ","Un véhicule est modifié",QSystemTrayIcon::Information,15000);

}

void notification::notifications_modifiermission(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des missions ","Une mission est modifiée",QSystemTrayIcon::Information,15000);

}

void notification::notifications_supprimermaintenance(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   //notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des equipements en maintenance ","Etat d'equipement modifier",QSystemTrayIcon::Information,15000);
}

void notification::notifications_ajoutercitoyen()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Gestion des citoyens ","Nouveau citoyen ajouté ",QSystemTrayIcon::Information,15000);
}
void notification::notifications_ajouterservice()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Gestion des services ","Nouveau service ajouté ",QSystemTrayIcon::Information,15000);
}
void notification::notifications_supprimercitoyen(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Gestion des citoyens ","Citoyen Supprimé",QSystemTrayIcon::Information,15000);
}
void notification::notifications_supprimerservice(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Gestion des services ","Service supprimé",QSystemTrayIcon::Information,15000);

}
void notification::notifications_modifiercitoyen(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Gestion des citoyens ","Citoyen modifié",QSystemTrayIcon::Information,15000);

}
void notification::notifications_modifierservice(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Gestion des services ","Service modifié",QSystemTrayIcon::Information,15000);

}
void notification::notifications_envoyermail()
{

   QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


    notifyIcon->show();
    notifyIcon->showMessage("Email ","Mail Envoyé ",QSystemTrayIcon::Information,15000);
}
void notification::notifications_pdfservice()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("PDF enregistré .Prêt à être imprimer ","Nouveau citoyen ajouté ",QSystemTrayIcon::Information,15000);
}
