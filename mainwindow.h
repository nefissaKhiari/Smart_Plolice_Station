#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "citoyen.h"
#include "service.h"
#include "notification.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_B_GestionCitoyen_clicked();

    void on_B_GestioService_clicked();

    void on_B_BackToGestions_clicked();

    void on_B_AccederProfil_clicked();

    void on_B_AjouterCitoyen_clicked();

    void on_B_AAnnulerCitoyen_clicked();

    void on_B_AConfirmerCitoyen_clicked();

    void on_B_MAnnulerCitoyen_clicked();

    void on_B_MConfirmerCitoyen_clicked();

    void on_B_SupprimerCitoyen_clicked();

    void on_B_MConfirmerCitoyen_2_clicked();

    void on_B_returnCitoyen_clicked();

    void on_B_AjouterService_clicked();

    void on_B_ModifierService_clicked();

    void on_B_AAnnulerService_clicked();

    void on_B_AConfirmerService_clicked();

    void on_B_MAnnulerService_clicked();

    void on_B_MConfirmerService_clicked();

    void on_B_BackToGestions_2_clicked();

    void on_B_SupprimerService_clicked();

    void on_LE_recherche_textChanged(const QString &arg1);

    void on_LE_rechercheS_textChanged(const QString &arg1);

    void on_B_Trier_clicked();

    void on_B_TrierS_clicked();

    void on_B_ResetTableIntervenant_2_clicked();

    void on_B_ResetTableIntervenant_clicked();

    void on_B_EnvoyeMail_clicked();

    void on_pushButton_2_clicked();

    void on_B_returnCitoyen_3_clicked();

private:
    Ui::MainWindow *ui;
    Citoyen C;
  Service S;
  Notifications N;
};

#endif // MAINWINDOW_H
