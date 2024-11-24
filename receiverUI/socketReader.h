#pragma once
#include "sql.h"
#include "utils.h"

#include <QCoreApplication>
#include <QDebug>
#include <QTcpSocket>

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

class SocketReader : public QObject {
  Q_OBJECT

public:
  explicit SocketReader(QObject *parent = nullptr)
      : QObject(parent), clientSocket(nullptr) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
      qFatal("Failed to create socket");
    }

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd, reinterpret_cast<struct sockaddr *>(&address),
             sizeof(address)) < 0) {
      qFatal("Bind failed");
    }

    if (listen(server_fd, 3) < 0) {
      qFatal("Listen failed");
    }

    qDebug() << "Server listening on port 8080...";

    int client_fd = accept(server_fd, nullptr, nullptr);
    if (client_fd < 0) {
      qFatal("Accept failed");
    }

    qDebug() << "Client connected, creating QTcpSocket from client_fd";

    clientSocket = new QTcpSocket(this);
    if (!clientSocket->setSocketDescriptor(client_fd)) {
      qFatal("Failed to set socket descriptor");
    }

    connect(clientSocket, &QTcpSocket::readyRead, this,
            &SocketReader::onReadyRead);
  }

private slots:
  void onReadyRead();

private:
  QTcpSocket *clientSocket;
};
