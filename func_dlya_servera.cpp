#include "func_dlya_servera.h"
#include "bazadannix.h"

QByteArray funcdlyaservera::parse(QString data)
{
    QStringList dataList = data.split(QLatin1Char('&')); // рвем строки по символу '&'
    QString nameOfFunc = dataList.front(); // название функции
    dataList.pop_front(); // удаляем название функции
    dataList.replaceInStrings(QRegularExpression("\\r\\n$"), QString()); // \r\n убираем
    if (nameOfFunc == "auth") // авторизация
    {
        return auth(dataList.at(0), dataList.at(1));
    }
    else if (nameOfFunc == "reg") // регистрация
    {
        return reg(dataList.at(0), dataList.at(1), dataList.at(2));
    }
    else if (nameOfFunc == "rsa") // шифрование
    {
        return rsa();
    }
    else if (nameOfFunc == "sha_512") // хэширование
    {
        return sha_512();
    }
    else if (nameOfFunc == "mtd_dln_ppl") // метод деления пополам
    {
        return mtd_dln_ppl();
    }
    else if (nameOfFunc == "graf") // граф
    {
        return graf();
    }
    else if (nameOfFunc == "\xFF\xFB\x1F\xFF\xFB \xFF\xFB\x18\xFF\xFB'\xFF\xFD\x01\xFF\xFB\x03\xFF\xFD\x03")
    {
        return QString("").toUtf8(); // чтобы без ошибок
    }
    else // Если другое
    {
        return QString("Error\r\n").toUtf8(); // ошибка
    }
}

QByteArray funcdlyaservera::auth(QString log, QString pass)
{
    QSqlQuery* query = new QSqlQuery;
    query->prepare("SELECT * FROM User WHERE Login = :Login AND Password = :Password"); // проверка на пидораса
    query->bindValue(":Login", log);
    query->bindValue(":Password", pass);

    if (!Database::getInstance().queryToDatabase(query))
    {
        return query->lastError().text().toUtf8();
    }

    if (query->first())
    {
        return QString("Successfully auth\r\n").toUtf8();
    }

    return QString("Takogo net").toUtf8();
}

QByteArray funcdlyaservera::reg(QString log, QString pass, QString mail)
{
    QSqlQuery* query = new QSqlQuery;
    query->prepare("INSERT INTO User (Login, Password, Email, Privileges) "
                   "VALUES (:Login, :Password, :Email, :Privileges)");
    query->bindValue(":Login", log);
    query->bindValue(":Password", pass);
    query->bindValue(":Email", mail);
    query->bindValue(":Privileges", QString("default"));

    if (!Database::getInstance().queryToDatabase(query))
    {
        return query->lastError().text().toUtf8(); // Ну ладно, на самом деле Анжелина хорошая и умная
    }
    else
    {
        return QString("Successfully reg\r\n").toUtf8();
    }
}

QByteArray funcdlyaservera::rsa()
{
    return QString("Shifrovanie").toUtf8();
}

QByteArray funcdlyaservera::sha_512()
{
    return QString("Xeshirovanie").toUtf8();
}

QByteArray funcdlyaservera::mtd_dln_ppl()
{
    return QString("Delenie popolam").toUtf8();
}

QByteArray funcdlyaservera::graf()
{
    return QString("Dracula").toUtf8();
}
