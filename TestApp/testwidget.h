#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QTabWidget>
#include <QValidator>
#include "util.h"

class TestWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit TestWidget(QWidget *parent = nullptr);

private:
    void buildUI();
    QString freqConverter(QString freq);

    //Upper left side
    QLabel *rangeStartLabel = nullptr;
    QLabel *rangeStopLabel = nullptr;
    QLineEdit *rangeStartInp = nullptr;
    QLineEdit *rangeStopInp = nullptr;
    QPushButton *okRangeButton = nullptr;

    //Upper right side
    QLabel *mark1Label = nullptr;
    QLabel *mark2Label = nullptr;
    QLineEdit *mark1Inp = nullptr;
    QLineEdit *mark2Inp = nullptr;
    QPushButton *okMarkButton = nullptr;

    //Bottom center
    QTextEdit *mathOutput = nullptr;
    QPushButton *getMathButton = nullptr;

signals:
    void sendCommand(QString command);

public slots:
    void getResponse(QString response);

private slots:
    void onRangeButtonPush();
    void onMarkButtonPush();
    void onGetMathButtonPush();
    void setInputability(bool newState);

};

#endif // TESTWIDGET_H
