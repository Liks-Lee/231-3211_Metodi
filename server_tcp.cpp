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
    while (mTcpServer->hasPendingConnections())
    {
        QTcpSocket *socket = mTcpServer->nextPendingConnection(); // Запись в переменную ожидающего сокета
        int descriptor = socket->socketDescriptor();
        sockets[descriptor] = socket;

        connect(socket, &QTcpSocket::readyRead, this, &TcpServer::slotServerRead); // Соединение сигнала готовности к чтению со слотом чтения сообщений
        connect(socket, &QTcpSocket::disconnected, this, &TcpServer::slotClientDisconnected); // Соединение сигнала и слота отключения клиента

        socket->write("Server connected!\r\n"); // Игорь душнила
    }
}

void TcpServer::slotServerRead()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender()); // Узнаем клиента, отправившего сообщение
    if (!socket)
    {
        return; // Если сокета не существует
    }

    int descriptor = socket->socketDescriptor();
    auto iter = sockets.find(descriptor);

    if (iter == sockets.end())
    {
        qDebug() << "Error";
        return; // Если сокет за пределами словаря
    }

    socket = iter.value();

    QString res = ""; // Строка результат
    while (socket->bytesAvailable() > 0) // Пока можно считывать байты
    {
        QByteArray arr = socket->readAll(); // Создание массива и запись в него всего, что считывается
        qDebug() << arr << "\n"; // Вывод считанных данных в консоль

        if (arr == "\x01") // Если конец строки
        {
            socket->write(res.toUtf8()); // Отправка проанализированного результата
            res = ""; // Обнуление строки
        }
        else // Если не конец строки
            res.append(arr); // Добавление к строке считанных данных
    }

    if (!res.isEmpty())
    {
        socket->write(funcdlyaservera::parse(res)); // Отправка проанализированного результата
    }
}

void TcpServer::slotClientDisconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    int descriptor = socket->socketDescriptor();
    sockets.remove(descriptor);
    socket->deleteLater(); // закрытие клиента
}
