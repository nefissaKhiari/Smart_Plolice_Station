#ifndef AMENDE_H
#define AMENDE_H

#include <QString>
#include <QSqlQueryModel>
#include "ui_gestionamende.h"


class Amende
{
private:
    int ID_amende;
    QString type_amende;
   int prix_amende;
    QString description_amende;
    QString lieu_amende;
   QString  date_amende;
   int CIN_policier;

public:
   Amende();
   Amende(int, QString, int, QString, QString, QString, int);

    void setId_amende(int);
    int getId_amende();

    void setType_amende(QString);
    QString getType_amende();

    void setPrix_amende(int);
    int getPrix_amende();

    void setDescription_amende(QString);
    QString getDescription_amende();

    void setLieu_amende(QString);
    QString getLieu_amende();

    void setDate_amende(  QString);
      QString getDate_amende();

      void setCIN_policier(  int);
        int getCIN_policier();


    bool ajouter_amende();
    bool modifier_amende();
    bool supprimer_amende(int);

    QSqlQueryModel* afficher_amende();
    QSqlQueryModel* listId_amende();

    QSqlQueryModel* Envoyer_sms_amende(QString);

    QSqlQueryModel* afficherHistorique(Ui::GestionAmende *ui);
    void addToHistory(QString action, QString type, QString id);



};


#endif // AMENDE_H
