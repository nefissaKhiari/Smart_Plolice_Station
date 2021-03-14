#ifndef AFFAIRESJURIDIQUES_H
#define AFFAIRESJURIDIQUES_H

#include "intervenant.h"
#include "affaire.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AffairesJuridiques; }
QT_END_NAMESPACE

class AffairesJuridiques : public QMainWindow
{
    Q_OBJECT

public:
    AffairesJuridiques(QWidget *parent = nullptr);
    ~AffairesJuridiques();

private slots:
    void on_B_GestionIntervenant_clicked();

    void on_B_GestioAffaire_clicked();

    void on_B_BackToGestions_clicked();

    void on_B_BackToGestions_2_clicked();

    void on_B_AjouterAffaire_clicked();

    void on_B_ModifierIntervenant_clicked();

    void on_B_AAnnulerIntervenant_clicked();

    void on_B_MAnuulerIntervenant_clicked();

    void on_B_ModifierAffaire_clicked();

    void on_B_AAnnulerAffaire_clicked();

    void on_B_MAnnulerAffaire_clicked();

    void on_B_AjouterIntervenant_clicked();

    void on_B_AConfirmerIntervenant_clicked();

    void on_B_SupprimerIntervenant_clicked();

    void on_B_MConfirmerIntervenant_clicked();

    void on_B_AConfirmerAffaire_clicked();

    void on_B_SupprimerAffaire_clicked();

    void on_B_MConfirmerAffaire_clicked();

private:
    Ui::AffairesJuridiques *ui;
    Intervenant intervenant;
    Affaire affaire;
};
#endif // AFFAIRESJURIDIQUES_H
