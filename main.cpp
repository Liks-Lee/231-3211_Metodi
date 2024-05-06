#include <QCoreApplication>
#include "server_tcp.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    TcpServer server;

    return app.exec();
}

