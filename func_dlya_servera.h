#ifndef FUNC_DLYA_SERVERA_H
#define FUNC_DLYA_SERVERA_H

#include <QString>
#include <QStringList>
#include <QByteArray>

class funcdlyaservera
{
public:
    static QByteArray parse(QString data); // запросы

private:
    static QByteArray auth(QString log, QString pass); // авторизация
    static QByteArray reg(QString log, QString pass, QString mail); // регистрация

    static QByteArray graf(QString param1, QString param2, QString param3); // граф
};


#endif // FUNC_DLYA_SERVERA_H
