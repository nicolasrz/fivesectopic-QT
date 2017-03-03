#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtWidgets>
#include <QtNetwork>


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    QString userId;

public slots:
    void on_boutonEnvoyer_clicked();

private:
    QTcpSocket *socket; // Représente le serveur
    quint16 tailleMessage;

signals:

private slots:
//        void on_message_returnPressed();
    void donneesRecues();
    void connecte();
};

#endif // CLIENT_H
