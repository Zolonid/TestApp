#include "connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent, Qt::WindowType flags) :   QDialog(parent)
{
    this->setWindowFlag(flags);
    this->setFixedSize(200, 100);

    addressLabel = new QLabel(tr("Address"), this);
    portLabel = new QLabel(tr("Port"), this);
    connectButton = new QPushButton(tr("Connect"), this);
    cancelButton = new QPushButton(tr("&Cancel"), this);

    address = new QLineEdit(this);
    port = new QLineEdit(this);

    address->setText("127.0.0.1");
    port->setText("5025");

    QValidator *portValidator = new QIntValidator(1, 65535, this);
    port->setValidator(portValidator);

    QGridLayout *gLayout = new QGridLayout();
    gLayout->addWidget(addressLabel, 0, 0);
    gLayout->addWidget(address, 0, 1);

    gLayout->addWidget(portLabel, 1, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(port, 1, 1, Qt::AlignLeft);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(connectButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 2, 1, Qt::AlignRight);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(gLayout);

    connect(connectButton, SIGNAL(clicked()), this, SLOT(onAcceptButton()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    setWindowTitle(tr("Connect to..."));
}

void ConnectionDialog::onAcceptButton()
{
    if(Util::isIPv4(address->text()) && port->hasAcceptableInput())
    {
        this->accept();
    }
    else
    {
        Util::ShowErrorBox(tr("It is not valid IPv4 addres"), this);
    }
}
