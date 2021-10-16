#include "consolewidget.h"

ConsoleWidget::ConsoleWidget(QWidget *parent) : QWidget(parent)
{
    buildUI();
    setInputability(false);

    connect(buttonEnter, SIGNAL(clicked()), this, SLOT(onConsoleInput()));
    connect(this, SIGNAL(consoleInput(QString)), this, SLOT(appendConsole(QString)));
}

void ConsoleWidget::buildUI()
{
    #ifdef _DEBUG
    qDebug() << "buildUI() is called";
    #endif

    consoleHistory = new QTextEdit(this);
    consoleHistory->setReadOnly(true);

    consoleInputLine = new QLineEdit(this);
    buttonEnter = new QPushButton(tr("Enter"));

    QGridLayout *gLayout = new QGridLayout(this);
    gLayout->addWidget(consoleHistory, 0, 0);

    QHBoxLayout *inpLayout = new QHBoxLayout();
    inpLayout->addWidget(consoleInputLine, 0);
    inpLayout->addWidget(buttonEnter, 0);

    gLayout->addLayout(inpLayout, 1, 0);
}

void ConsoleWidget::appendConsole(QString message)
{
    #ifdef _DEBUG
    qDebug() << "appendConsole() is called with: " << message;
    #endif

    consoleHistory->append(message);
}

void ConsoleWidget::setInputability(bool newState)
{
    #ifdef _DEBUG
    qDebug() << "setInputability() is called with: " << newState;
    #endif

    this->setEnabled(newState);
}

void ConsoleWidget::onConsoleInput()
{
    #ifdef _DEBUG
    qDebug() << "onConsoleInput() is called";
    #endif

    QString input = consoleInputLine->text();
    consoleInputLine->clear();

    #ifdef _DEBUG
    qDebug() << input.replace("\\n", "\n", Qt::CaseSensitivity::CaseInsensitive);
    #endif

    emit consoleInput(input);
}
