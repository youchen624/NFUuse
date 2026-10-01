#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets>
#include <QtNetwork>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void start();
    void acceptConnection();
    void updateServerProgress();
    void displayError(QAbstractSocket::SocketError socketError);
private:
    QProgressBar        *serverProgressBar;
    QLabel              *serverStatusLabel;
    QPushButton         *startButton;
    QPushButton         *quitButton;
    QDialogButtonBox    *buttonBox;

    QTcpServer          tcpServer;
    QTcpSocket          *tcpServerConnection;
    qint64              totalBytes;
    qint64              byteReceived;
    qint64              fileNameSize;
    QString             fileName;
    QFile               *localFile;
    QByteArray          inBlock;
};
#endif // DIALOG_H
