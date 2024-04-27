#include "server_tcp.h" // включаем h-файл
#include "func_dlya_servera.h" // включаем функции для сервера

TcpServer::~TcpServer()
{
    mTcpServer->close();// закрываем сервер
}

TcpServer::TcpServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this); // создаем сервер

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &TcpServer::slotNewConnection); // чтобы функция начинала работать при новом подключении

    if (!mTcpServer->listen(QHostAddress::Any, 33333)) // чтобы сервер видел все адреса и порт 33333
    {
        qDebug() << "Server is not started"; // если не работает
    }
    else
    {
        qDebug() << "Server is started"; // если работает
    }
}

void TcpServer::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection(); // сохраняем текущее подключение (айпи+порт)

    connect(mTcpSocket, &QTcpSocket::readyRead,this,&TcpServer::slotServerRead); // заставляем его читать по сигналу готовности
    connect(mTcpSocket,&QTcpSocket::disconnected,this,&TcpServer::slotClientDisconnected); // обработка отключения

    mTcpSocket->write("Server connected!"); // отправка клиенту сообщения
}

void TcpServer::slotServerRead()
{
    QString res = "";

    while (mTcpSocket->bytesAvailable() > 0) // условие про байты
    {
        QByteArray arr = mTcpSocket->readAll(); // засовываем все в массив
        qDebug() << arr << "\n"; // выводим все
        if (arr == "\x01") // если конец строки
        {
            mTcpSocket->write(res.toUtf8()); // отправка ответа клиента
            res = ""; // очищаем строку
        }
        else // если не конец
            res.append(arr); // добавляем к результату
    }
    mTcpSocket->write(funcdlyaservera::parse(res)); // подключаем функцию анализа
}

void TcpServer::slotClientDisconnected()
{
    mTcpSocket->close(); // закрытие клиента
}
