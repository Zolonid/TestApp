#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#ifdef _DEBUG
#include <QDebug>
#endif

#include <QObject>
#include "connectiondialog.h"
#include "QTcpSocket"

class ConnectionManager : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionManager(QObject *parent = nullptr);

private:
    QTcpSocket *_socket;

    void openConnection(QString address, int port);

signals:
    void serverResponse(QString response);
    void connectionStatus(bool isOpen);

public slots:
    void sendData(QString data);
    void showConnectionWindow();
    void onReadyRead();
    void onStateChange(QAbstractSocket::SocketState newState);

};

#endif // CONNECTIONMANAGER_H
