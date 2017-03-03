#include "client.h"
#include "camera.h"

Client::Client(QObject *parent, QWidget *widget) : QObject(parent)
{
    socket = new QTcpSocket(this);
    this->widget = widget;
    connect(socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    socket->abort(); // On désactive les connexions précédentes s'il y en a
    socket->connectToHost("127.0.0.1", 50885);
}


void Client::on_boutonEnvoyer_clicked(){
    //envoyer la photo ici
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    QPointer<QPushButton> button = qobject_cast<QPushButton*>(sender());

    // On prépare le paquet à envoyer
    QString messageAEnvoyer = button->objectName();
    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet

}

void Client::donneesRecues(){

    QDataStream in(socket);

    if (tailleMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
             return;

        in >> tailleMessage;
    }

    if (socket->bytesAvailable() < tailleMessage)
        return;


    // Si on arrive jusqu'à cette ligne, on peut récupérer le message entier
    QString messageRecu;
    in >> messageRecu;

    // if je suis bien le mec qui doit recevoir
    if(messageRecu == this->userId){
        //je lance l'appareil photo de mon pote et une notification
        Camera *camera = new Camera(this->widget);
        camera->init(300,300);
    }

    // On remet la taille du message à 0 pour pouvoir recevoir de futurs messages
    tailleMessage = 0;
    //je me lance une notif et si je clique dessus je lance l'appareil
}

void Client::connecte(){
    qDebug() << "connection réussie !";
}
