#ifndef FUNC_DLYA_SERVERA_H
#define FUNC_DLYA_SERVERA_H

#include <QString>
#include <QStringList>
#include <QByteArray>
#include <QtSql>

class funcdlyaservera
{
public:
    static QByteArray parse(QString data); //игорь сэр да сэр

private:
    static QByteArray auth(QString log, QString pass); // авторизация
    static QByteArray reg(QString log, QString pass, QString mail); // регистрация

    static QByteArray rsa(); // шифрование
    static QByteArray sha_512(); // хэширование
    static QByteArray mtd_dln_ppl(); // метод деленяи пополам
    static QByteArray graf(); // граф граф граф граф граф
};


#endif // FUNC_DLYA_SERVERA_H
