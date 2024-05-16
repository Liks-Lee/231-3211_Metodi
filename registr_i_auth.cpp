#include "registr_i_auth.h"
#include "ui_registr_i_auth.h"

registr_i_auth::registr_i_auth(QWidget *parent) : QWidget(parent), ui(new Ui::registr_i_auth)
{
    ui->setupUi(this);
    ui->mail->setVisible(false);
    ui->regis->setVisible(false);
    ui->regknopka->setVisible(false);
    ui->voyti->setVisible(false);
}

registr_i_auth::~registr_i_auth()
{
    delete ui;
}


void registr_i_auth::on_authknopka_clicked()
{
    // Обработка авторизации
    emit auth(ui->login->text(), ui->password->text());
}


void registr_i_auth::on_regknopka_clicked()
{
    emit reg(ui->login->text(), ui->password->text(),ui->mail->text());
}


void registr_i_auth::on_cozdat_clicked()
{
    ui->mail->setVisible(true);
    ui->regis->setVisible(true);
    ui->regknopka->setVisible(true);
    ui->voyti->setVisible(true);

    ui->authoriz->setVisible(false);
    ui->authknopka->setVisible(false);
    ui->cozdat->setVisible(false);
}


void registr_i_auth::on_voyti_clicked()
{
    ui->authoriz->setVisible(true);
    ui->authknopka->setVisible(true);
    ui->cozdat->setVisible(true);

    ui->mail->setVisible(false);
    ui->regis->setVisible(false);
    ui->regknopka->setVisible(false);
    ui->voyti->setVisible(false);
}

