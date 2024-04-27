#include "func_dlya_servera.h"

QByteArray funcdlyaservera::parse(QString data)
{
    QStringList dataList = data.split(QLatin1Char('&')); // рвем строки по символу '&'
    QString nameOfFunc = dataList.front(); // название функции
    dataList.pop_front(); // удаляем название функции
    if (nameOfFunc == "auth") // авторизация
    {
        return auth(dataList.at(0), dataList.at(1));
    }
    else if (nameOfFunc == "reg") // регистрация
    {
        return reg(dataList.at(0), dataList.at(1), dataList.at(2));
    }
    else if (nameOfFunc == "graf") // граф
    {
        return graf(dataList.at(0), dataList.at(1), dataList.at(2));
    }
    else // Если другое
    {
        return QString("Error").toUtf8(); // ошибка
    }
}

QByteArray funcdlyaservera::auth(QString log, QString pass)
{
    return QString("Succesfully auth").toUtf8();
}

QByteArray funcdlyaservera::reg(QString log, QString pass, QString mail)
{
    return QString("Succesfully auth").toUtf8();
}

QByteArray funcdlyaservera::graf(QString learningRate, QString maxIterations, QString precision)
{
    return QString("Result: 123").toUtf8();
}
