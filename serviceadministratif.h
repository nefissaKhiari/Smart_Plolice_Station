#ifndef SERVICEADMINISTRATIF_H
#define SERVICEADMINISTRATIF_H

#include <QMainWindow>
#include "citoyen.h"
#include "service.h"

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

    void on_B_BackToGestions_2_clicked();

    void on_B_GestioService_clicked();

    void on_B_AjouterService_clicked();

    void on_B_ModifierService_clicked();

    void on_B_AConfirmerService_clicked();

    void on_B_AAnnulerService_clicked();

    void on_B_MAnnulerService_clicked();

    void on_B_MConfirmerService_clicked();

    void on_B_SupprimerService_clicked();

    void on_TE_ADescService_copyAvailable(bool b);

    void on_B_Recherche_clicked();

    //void on_LE_recherche_cursorPositionChanged(int arg1, int arg2);

    void on_LE_recherche_textChanged(const QString &arg1);

private:
    Ui::ServiceAdministratif *ui;
    Citoyen C;
     Service S;
};
#endif // SERVICEADMINISTRATIF_H
