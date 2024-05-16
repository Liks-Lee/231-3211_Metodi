#include "func_dlya_clienta.h"

func_dlya_clienta::func_dlya_clienta()
{
    client = Client::getInstance();

    ui_auth = new registr_i_auth;
    ui_auth->show();
    connect(ui_auth, &registr_i_auth::auth, this, &func_dlya_clienta::sendAuth);
    connect(ui_auth, &registr_i_auth::reg, this, &func_dlya_clienta::sendReg);
    connect(client, &Client::msgFromServer, this, &func_dlya_clienta::msgHandler);;
}

void func_dlya_clienta::sendAuth(QString log, QString pass)
{
    client->sendMsgToServer("auth&" + log + "&" + pass);
}

void func_dlya_clienta::sendReg(QString log, QString pass, QString email)
{
    client->sendMsgToServer("reg&" + log + "&" + pass + "&" + email);
}

void func_dlya_clienta::msgHandler(QString msg)
{
    if (msg == "Successfully auth\r\n" || msg == "Successfully reg\r\n")
    {
        delete ui_auth;
        ui_main = new MainWindow;
        ui_main->show();

        connect(ui_main, &MainWindow::RSA, this, &func_dlya_clienta::rechenieRSA);
        connect(ui_main, &MainWindow::hash, this, &func_dlya_clienta::rechenieHash);
        connect(ui_main, &MainWindow::Delenie, this, &func_dlya_clienta::rechenieDelenie);
        connect(ui_main, &MainWindow::Graf, this, &func_dlya_clienta::rechenieGraf);

        connect(this, &func_dlya_clienta::rechenie, ui_main, &MainWindow::rechenie);
    }
    else
    {
        emit rechenie(msg);
    }
}

void func_dlya_clienta::rechenieRSA(QString text)
{
    client->sendMsgToServer("rsa&" + text );
}

void func_dlya_clienta::rechenieHash(QString text)
{
    client->sendMsgToServer("sha_512&" + text);
}

void func_dlya_clienta::rechenieDelenie(QString  massiv, QString chislo)
{
    client->sendMsgToServer("mtd_dln_ppl&" + massiv + "&" + chislo);
}

void func_dlya_clienta::rechenieGraf(QString kolvovershin, QString vershinu, QString start_end)
{
    client->sendMsgToServer("graf&" + kolvovershin + "&" + vershinu + "&" + start_end);
}
