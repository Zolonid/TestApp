#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifdef _DEBUG
#include <QDebug>
#endif

#include <QMainWindow>
#include <QTabWidget>
#include "consolewidget.h"
#include "connectionmanager.h"
#include "testwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void buildMenuStrip();

    Ui::MainWindow *ui;
    QTabWidget *tabWid = nullptr;
    ConsoleWidget *conWidget = nullptr;
    ConnectionManager *conMan = nullptr;
    TestWidget *testWidget = nullptr;
    QMenu *actionMenu = nullptr;
    QAction *connectAct = nullptr;
    QAction *isLogging = nullptr;
    QAction *exitAct = nullptr;
};
#endif // MAINWINDOW_H
