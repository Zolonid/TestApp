#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include <QValidator>
#include "util.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QLineEdit;
QT_END_NAMESPACE

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    ConnectionDialog(QWidget *parent = 0, Qt::WindowType flags = Qt::WindowType::Popup);
    QLineEdit *address;
    QLineEdit *port;

private:
    QLabel *addressLabel;
    QLabel *portLabel;
    QPushButton *connectButton;
    QPushButton *cancelButton;

private slots:
    void onAcceptButton();
};

#endif // CONNECTIONDIALOG_H
