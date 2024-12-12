#include "client.h"
#include "ui_clien.h"
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTcpSocket>

Client::Client(QWidget *parent)
: QDialog(parent)
, hostCombo(new QComboBox)
, portLineEdit(new QLineEdit)
, getFortuneButton(new QPushButton(tr("Get Fortune")))
, tcpSocket(new QTcpSocket(this))
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    connect(tcpSocket, &QIODevice::readyRead, this, &Client::readFortune);
    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of
    (&QAbstractSocket::error), this, &Client::displayError);

}
void Client::requestNewFortune()
{
    getFortuneButton->setEnabled(false);
    tcpSocket->abort();
    tcpSocket->connectToHost(hostCombo->currentText(),
    portLineEdit->text().toInt());
}
void Client::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
    QMessageBox::information(this, tr("Fortune Client"),
        tr("The host was not found. Please check the "
        "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
    QMessageBox::information(this, tr("Fortune Client"),
        tr("The connection was refused by the peer. "
        "Make sure the fortune server is running, "
        "and check that the host name and port "
        "settings are correct."));
        break;
default:
    QMessageBox::information(this, tr("Fortune Client"),
    tr("The following error occurred: %1.")
    .arg(tcpSocket->errorString()));
}
    getFortuneButton->setEnabled(true);
}
void Client::readFortune()
{
    in.startTransaction();
    QString nextFortune;
    in >> nextFortune;
    if (!in.commitTransaction())
    return;
if (nextFortune == currentFortune) {
    QTimer::singleShot(0, this, &Client::requestNewFortune);
    return;
}
    currentFortune = nextFortune;
    statusLabel->setText(currentFortune);
    getFortuneButton->setEnabled(true);
}
