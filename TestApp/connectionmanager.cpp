#include "connectionmanager.h"

ConnectionManager::ConnectionManager(QObject *parent) : QObject(parent)
{
    _socket = new QTcpSocket(this);
    connect(_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(_socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onStateChange(QAbstractSocket::SocketState)));
}

void ConnectionManager::sendData(QString data)
{
    #ifdef _DEBUG
    qDebug() << "sendData() is called with: " << data;
    #endif

    //IT TOOK 4 HOURS OF MY LIFE TO FIGURE OUT THAT THERE IS TWO BACKSLASHES INSTEAD OF ONE
    _socket->write(data.replace("\\\\", "\\", Qt::CaseSensitivity::CaseInsensitive).toLatin1() + "\n");
}

void ConnectionManager::showConnectionWindow()
{
    #ifdef _DEBUG
    qDebug() << "showConnectionWindow() is called";
    #endif

    //Calling dialog to get address and port for connection
    //Validation is in dialog itself
    ConnectionDialog conDialog;
    if (conDialog.exec()) {
        QString conAddress = conDialog.address->text();
        QString conPort = conDialog.port->text();

        #ifdef _DEBUG
        qDebug() << "Parsed: " << conAddress << " and " << conPort;
        #endif

        openConnection(conAddress, conPort.toInt());
    }
}

void ConnectionManager::openConnection(QString address, int port)
{
    #ifdef _DEBUG
    qDebug() << "openConnection() is called with: " << address << " " << port;
    #endif

    if(_socket->state() != QTcpSocket::UnconnectedState){
        _socket->abort();
    }

    _socket->connectToHost(address, port);
}

void ConnectionManager::onReadyRead()
{
    QString data = _socket->readAll();

    #ifdef _DEBUG
    qDebug() << "onReadyRead() is called";
    qDebug() << data;
    #endif

    emit serverResponse(data);
}

void ConnectionManager::onStateChange(QAbstractSocket::SocketState newState)
{
    #ifdef _DEBUG
    qDebug() << "Connection state -> " << newState;
    #endif

    if(newState == QAbstractSocket::SocketState::ConnectedState)
    {
        emit connectionStatus(true);
    }
    else
    {
        emit connectionStatus(false);
    }
}
