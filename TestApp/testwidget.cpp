#include "testwidget.h"

TestWidget::TestWidget(QWidget *parent) : QTabWidget(parent)
{
    buildUI();
    setInputability(false);

    connect(okMarkButton, SIGNAL(clicked()), this, SLOT(onMarkButtonPush()));
    connect(okRangeButton, SIGNAL(clicked()), this, SLOT(onRangeButtonPush()));
    connect(getMathButton, SIGNAL(clicked()), this, SLOT(onGetMathButtonPush()));
}

void TestWidget::buildUI()
{
    //Upper left side
    rangeStartLabel = new QLabel(tr("Range start:"), this);
    rangeStopLabel = new QLabel(tr("Range stop:"), this);
    rangeStartInp = new QLineEdit(this);
    rangeStopInp = new QLineEdit(this);
    okRangeButton = new QPushButton(tr("Set range") , this);

    //Upper right side
    mark1Label = new QLabel(tr("Marker 1:"), this);
    mark2Label = new QLabel(tr("Marker 2:"), this);
    mark1Inp = new QLineEdit(this);
    mark2Inp = new QLineEdit(this);
    okMarkButton = new QPushButton(tr("Set markers") , this);

    rangeStartInp->setText("1000");
    rangeStopInp->setText("8000");
    mark1Inp->setText("2000");
    mark2Inp->setText("6000");

    //Center center
    mathOutput = new QTextEdit(this);
    mathOutput->setReadOnly(true);

    //Bottom center
    getMathButton = new QPushButton(tr("Get Math"), this);

    //Validators
    QValidator *freqValidator = (new QDoubleValidator(0.1, 9000, 5, this));
    //Dot is objectively better than comma
    freqValidator->setLocale(QLocale::English);
    rangeStartInp->setValidator(freqValidator);
    rangeStopInp->setValidator(freqValidator);
    mark1Inp->setValidator(freqValidator);
    mark2Inp->setValidator(freqValidator);

    //Setting max width
    rangeStartLabel->setMaximumWidth(80);
    rangeStopLabel->setMaximumWidth(80);
    mark1Label->setMaximumWidth(80);
    mark2Label->setMaximumWidth(80);
    rangeStartInp->setMaximumWidth(40);
    rangeStopInp->setMaximumWidth(40);
    mark1Inp->setMaximumWidth(40);
    mark2Inp->setMaximumWidth(40);

    QGridLayout *lLayout = new QGridLayout();
    lLayout->addWidget(rangeStartLabel, 0, 0, Qt::AlignHCenter);
    lLayout->addWidget(rangeStopLabel, 1, 0, Qt::AlignHCenter);

    lLayout->addWidget(rangeStartInp, 0, 1, Qt::AlignHCenter);
    lLayout->addWidget(rangeStopInp, 1, 1, Qt::AlignHCenter);

    lLayout->addWidget(okRangeButton, 2, 0, 1, 2);

    QGridLayout *rLayout = new QGridLayout();
    rLayout->addWidget(mark1Label, 0, 0, Qt::AlignHCenter);
    rLayout->addWidget(mark2Label, 1, 0, Qt::AlignHCenter);

    rLayout->addWidget(mark1Inp, 0, 1, Qt::AlignHCenter);
    rLayout->addWidget(mark2Inp, 1, 1, Qt::AlignHCenter);

    rLayout->addWidget(okMarkButton, 2, 0, 1, 2);

    QHBoxLayout *ULayout = new QHBoxLayout();
    ULayout->addLayout(lLayout);
    ULayout->addLayout(rLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(ULayout);
    mainLayout->addWidget(mathOutput);
    mainLayout->addWidget(getMathButton);
}

void TestWidget::getResponse(QString response)
{
    QList<QString> temp = response.split(',');

    //Converting response to human readable response
    QString readableResponse = tr("Mean: %1\n").arg(temp[0]);
    readableResponse.append(tr("St. D.: %1\n").arg(temp[1]));
    readableResponse.append(tr("P-p.: %1\n").arg(temp[2]));

    //Only 1 response should be visible on output
    mathOutput->setText(readableResponse);
}

void TestWidget::onRangeButtonPush()
{
    if (rangeStartInp->hasAcceptableInput() && rangeStopInp->hasAcceptableInput())
    {
        QString rStart = freqConverter(rangeStartInp->text());
        QString rStop = freqConverter(rangeStopInp->text());

        emit sendCommand(QString("SENS:FREQ:STAR %1\nSENS:FREQ:STOP %2\n").arg(rStart, rStop));
    }
    else
    {
        Util::ShowErrorBox("Incorrect input.");
    }
}

void TestWidget::onMarkButtonPush()
{
    if (mark1Inp->hasAcceptableInput() && mark2Inp->hasAcceptableInput())
    {
        QString mark1 = freqConverter(mark1Inp->text());
        QString mark2 = freqConverter(mark2Inp->text());

        emit sendCommand(QString("CALC1:MARK1:STAT ON\nCALC1:MARK1:X %1\nCALC1:MARK2:STAT ON\nCALC1:MARK2:X %2\n").arg(mark1, mark2));
    }
    else
    {
        Util::ShowErrorBox("Incorrect input.");
    }
}

void TestWidget::onGetMathButtonPush()
{
    emit sendCommand(QString("CALC1:TRAC1:MST:DATA?"));
}

QString TestWidget::freqConverter(QString freq)
{
    //Function to convert input freq from MHz to Hz for server
    float temp = freq.toDouble() * 1000000;

    return QString::number(temp, 'e', 7);
}

void TestWidget::setInputability(bool newState)
{
    #ifdef _DEBUG
    qDebug() << "setInputability() is called with: " << newState;
    #endif

    this->setEnabled(newState);
}
