#ifndef FUNC_DLYA_CLIENTA_H
#define FUNC_DLYA_CLIENTA_H

#include <QObject>
#include "mainwindow.h"
#include "registr_i_auth.h"
#include "client.h"

class func_dlya_clienta : public QObject
{
    Q_OBJECT

private:
    MainWindow* ui_main;
    registr_i_auth* ui_auth;
    Client* client;

public:
    func_dlya_clienta();

public slots:
    void sendAuth(QString log, QString pass);
    void sendReg(QString log, QString pass, QString email);
    void msgHandler(QString msg);

    void rechenieRSA(QString text);
    void rechenieHash(QString text);
    void rechenieDelenie(QString  massiv, QString chislo);
    void rechenieGraf(QString kolvovershin, QString vershinu, QString start_end);

signals:
    void rechenie(QString text);
};
#endif // FUNC_DLYA_CLIENTA_H
