#ifndef SERVER_TCP_H
#define SERVER_TCP_H

#include <QCoreApplication> // для базовых функций QT
#include <QObject> // для работы сигналов и слотов
#include <QString> // для работы со строками
#include <QTcpServer> // для реализации сервера по протоколу TCP
#include <QTcpSocket> // для работы с сокетами (ip + порт)
#include <QtNetwork> // для работы с сетью
#include <QByteArray> // для работы с пригодными к передаче данными
#include <QDebug> // для вывода сообщений в консоль

class TcpServer : public QObject
{
    Q_OBJECT // чтобы когда поступал сигнал, слот ответственный за эту работу работал
public:
    explicit TcpServer(QObject* parent = nullptr); // создание сервера
    ~TcpServer(); // закрытие сервера
public slots:
    void slotNewConnection(); // слот нового подключения клиента
    void slotClientDisconnected(); // слот отключения клиента
    void slotServerRead(); // слот чтения сервера
private:
    QTcpServer* mTcpServer; // сервер
    QTcpSocket* mTcpSocket; // текущее соединение

};

#endif // SERVER_TCP_H
