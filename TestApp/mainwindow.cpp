#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    conMan = new class ConnectionManager;
    conWidget = new class ConsoleWidget;
    testWidget = new class TestWidget;
    tabWid = new class QTabWidget;

    buildMenuStrip();

    this->setCentralWidget(tabWid);
    tabWid->addTab(testWidget, tr("My App"));
    tabWid->addTab(conWidget, tr("Console"));

    //To server
    connect(conWidget, SIGNAL(consoleInput(QString)), conMan, SLOT(sendData(QString)));
    connect(testWidget, SIGNAL(sendCommand(QString)), conMan, SLOT(sendData(QString)));

    //To console log
    connect(conMan, SIGNAL(serverResponse(QString)), conWidget, SLOT(appendConsole(QString)));
    connect(testWidget, SIGNAL(sendCommand(QString)), conWidget, SLOT(appendConsole(QString)));

    //To mathOutput
    connect(conMan, SIGNAL(serverResponse(QString)), testWidget, SLOT(getResponse(QString)));

    //Enabling/disabling widgets depending on connection status
    connect(conMan, SIGNAL(connectionStatus(bool)), conWidget, SLOT(setInputability(bool)));
    connect(conMan, SIGNAL(connectionStatus(bool)), testWidget, SLOT(setInputability(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;

    delete this;
}

void MainWindow::buildMenuStrip()
{
    actionMenu = menuBar()->addMenu(tr("&Actions"));

    connectAct = new QAction(tr("&Connect to..."), this);
    actionMenu->addAction(connectAct);
    connect(connectAct, SIGNAL(triggered()), conMan, SLOT(showConnectionWindow()));

    exitAct = new QAction(tr("E&xit"), this);
    actionMenu->addAction(exitAct);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}

