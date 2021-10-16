#ifndef CONSOLEWIDGET_H
#define CONSOLEWIDGET_H

#ifdef _DEBUG
#include <QDebug>
#endif

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class ConsoleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ConsoleWidget(QWidget *parent = nullptr);

private:
    QTextEdit *consoleHistory;
    QLineEdit *consoleInputLine;
    QPushButton *buttonEnter;

    void buildUI();

signals:
    void consoleInput(QString);

public slots:
    void appendConsole(QString message);
    void setInputability(bool newState);
    void onConsoleInput();
};

#endif // CONSOLEWIDGET_H
