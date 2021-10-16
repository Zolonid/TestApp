#include "util.h"

void Util::ShowErrorBox(QString message, QWidget *parent)
{
    QMessageBox errorBox(parent);
    errorBox.setText(message);
    errorBox.exec();
}

bool Util::isIPv4(QString address){
QHostAddress a(address);
return (QAbstractSocket::IPv4Protocol == a.protocol());
}

bool Util::isIPv6(QString address)
{
    QHostAddress a(address);
    return (QAbstractSocket::IPv6Protocol == a.protocol());
}
