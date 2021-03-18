#include "gestiondetenu.h"
#include "ui_gestiondetenu.h"

gestiondetenu::gestiondetenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gestiondetenu)
{
    ui->setupUi(this);
}

gestiondetenu::~gestiondetenu()
{
    delete ui;
}


void gestiondetenu::on_B_GestionIntervenant_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void gestiondetenu::on_B_GestioAffaire_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void gestiondetenu::on_B_BackToGestions_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void gestiondetenu::on_B_BackToGestions_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void gestiondetenu::on_B_AjouterAffaire_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void gestiondetenu::on_B_ModifierIntervenant_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void gestiondetenu::on_B_AAnnulerIntervenant_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void gestiondetenu::on_B_MAnuulerIntervenant_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void gestiondetenu::on_B_ModifierAffaire_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void gestiondetenu::on_B_AAnnulerAffaire_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void gestiondetenu::on_B_MAnnulerAffaire_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void gestiondetenu::on_B_AjouterIntervenant_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
