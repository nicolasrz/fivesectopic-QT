#include "user.h"
#include <QNetworkReply>
#include <QEventLoop>
#include "parametre.h"
User::User()
{

}
User::~User()
{

}


QString User::getId(){
    return this->id;
}

void User::setId(QString id){
    this->id =id;
}

QString User::getNickname(){
    return this->nickname;
}

void User::setNickame(QString name){
    this->nickname = name;
}

QString User::getPassword(){
    return this->password;
}

void User::setPassword(QString password){
    this->password = password;
}

bool User::getConnected(){
    return this->connected;
}

void User::setConnected(bool connected){
    this->connected = connected;
}

QStringList User::getFriends(){
    QEventLoop eventLoop;
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));


    // the HTTP request
    QNetworkRequest req( QUrl( QString(Parametre::serverAdresse+"/api/friendgroup/users/user/"+this->id) ) );
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called
    std::string  replyString = reply->readAll().toStdString();
    QString replyQstring = QString::fromStdString(replyString);
    QStringList listFriend = replyQstring.split("#");
    if (reply->error() == QNetworkReply::NoError) {
        //success

        for(int i =0; i< listFriend.size(); ++i){
            qDebug() << listFriend[i];
        }
        delete reply;
    }
    else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }

    return listFriend;
}
