#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H


#include <QSystemTrayIcon>
#include<QString>
class Notifications
{
public:
    Notifications();
    void notifications_ajoutercitoyen();
    void notifications_ajouterservice();
    void notifications_supprimercitoyen();
    void notifications_supprimerservice();
    void notifications_modifiercitoyen();
    void notifications_modifierservice();
    void notifications_envoyermail();

};



#endif // NOTIFICATIONS_H
