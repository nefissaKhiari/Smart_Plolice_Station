#ifndef SERVICEADMINISTRATIF_H
#define SERVICEADMINISTRATIF_H

#include <QMainWindow>
#include "citoyen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ServiceAdministratif; }
QT_END_NAMESPACE

class ServiceAdministratif : public QMainWindow
{
    Q_OBJECT

public:
    ServiceAdministratif(QWidget *parent = nullptr);
    ~ServiceAdministratif();

private slots:
    void on_B_GestionCitoyen_clicked();

    void on_B_BackToGestions_clicked();

    void on_B_AccederProfil_clicked();

    void on_B_AjouterCitoyen_clicked();

    //void on_B_AConfirmerCitoyen_clicked();

    void on_B_AAnnulerCitoyen_clicked();

    void on_B_MConfirmerCitoyen_clicked();

    void on_B_MAnnulerCitoyen_clicked();

    void on_B_returnCitoyen_clicked();

    void on_B_MConfirmerCitoyen_2_clicked();

    void on_B_SupprimerCitoyen_clicked();

    void on_B_AConfirmerCitoyen_clicked();

private:
    Ui::ServiceAdministratif *ui;
    Citoyen C;
};
#endif // SERVICEADMINISTRATIF_H
