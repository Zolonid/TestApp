#ifndef UTIL_H
#define UTIL_H

#include <QString>
#include <QErrorMessage>
#include <QMessageBox>
#include <QHostAddress>

class Util
{
public:
    static void ShowErrorBox(QString message, QWidget *parent = 0);
    static bool isIPv4(QString address);
    static bool isIPv6(QString address);
};

#endif // UTIL_H
