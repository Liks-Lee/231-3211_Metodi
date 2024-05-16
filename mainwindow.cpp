#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentTask = rsa;
    ui->Zagolovok->setText("RSA");
    ui->arg1->setPlaceholderText("Text");
    ui->arg2->setVisible(false);
    ui->arg3->setVisible(false);
    ui->Otvet->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::rechenie(QString text)
{
    ui->Otvet->setText(text);
}
void MainWindow::on_Reshit_clicked()
{
    if (currentTask == rsa)
    {
        emit RSA(ui->arg1->text());
    }
    else if (currentTask == sha512)
    {
        emit hash(ui->arg1->text());
    }
    else if (currentTask == delenie)
    {
        emit Delenie(ui->arg1->text(), ui->arg2->text());
    }
    else if (currentTask == graf)
    {
        emit Graf(ui->arg1->text(), ui->arg2->text(), ui->arg3->text());
    }
}


void MainWindow::on_another_clicked()
{
    if (currentTask == rsa)
    {
        currentTask = sha512;
        ui->Zagolovok->setText("Sha-512");
        ui->arg1->setPlaceholderText("String");
        ui->Otvet->setText("");
    }
    else if (currentTask == sha512)
    {
        currentTask = delenie;
        ui->Zagolovok->setText("Metod Deleniya Popolam");
        ui->arg1->setPlaceholderText("Massiv (Format: -4,0,1,2)");
        ui->arg2->setPlaceholderText("Chislo");
        ui->arg2->setVisible(true);
        ui->Otvet->setText("");
    }
    else if (currentTask == delenie)
    {
        currentTask = graf;
        ui->Zagolovok->setText("Graf");
        ui->arg1->setPlaceholderText("Kolvovershin ");
        ui->arg2->setPlaceholderText("Vershinu (Format : 1,2,3%4,5,6%");
        ui->arg3->setPlaceholderText("Start_End (Format : 1,2");
        ui->arg3->setVisible(true);
        ui->Otvet->setText("");
    }
    else if (currentTask == graf)
    {
        currentTask = rsa;
        ui->Zagolovok->setText("RSA");
        ui->arg1->setPlaceholderText("Text");
        ui->arg2->setVisible(false);
        ui->arg3->setVisible(false);
        ui->Otvet->setText("");
    }
}

