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

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des equipements en maintenance ","Etat d'equipement modifier",QSystemTrayIcon::Information,15000);
}
