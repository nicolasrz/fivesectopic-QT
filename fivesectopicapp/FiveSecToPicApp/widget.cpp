#include "widget.h"
#include <QPointer>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include "parametre.h"
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QDebug>
#include <QUrl>
#include <QNetworkReply>
#include <QEventLoop>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumHeight(Parametre::sizeH);
    this->setMinimumWidth(Parametre::sizeW);
    init();
}

Widget::~Widget()
{

}

void Widget::init(){
    QPointer<QVBoxLayout> vLayout = new QVBoxLayout(this);
    QPointer<QHBoxLayout> hLayoutNickname = new QHBoxLayout();
    QPointer<QHBoxLayout> hLayoutPassword = new QHBoxLayout();

    QPointer<QLabel> title = new QLabel("Five sec to pic !");

    QPointer<QLabel> labelNickname = new QLabel("Nickname");
    QPointer<QLabel> labelPassword = new QLabel("Password");

    editNickname = new QLineEdit();
    editPassword = new QLineEdit();
    editPassword->setEchoMode(QLineEdit::Password);

    QPointer<QPushButton> buttonConnect = new QPushButton("Connection");

    hLayoutNickname->addWidget(labelNickname);
    hLayoutNickname->addWidget(editNickname);


    hLayoutPassword->addWidget(labelPassword);
    hLayoutPassword->addWidget(editPassword);

    vLayout->addWidget(title);
    vLayout->addLayout(hLayoutNickname);
    vLayout->addLayout(hLayoutPassword);
    vLayout->addWidget(buttonConnect);

    connect(buttonConnect,&QPushButton::clicked,this, &Widget::connectApp);

}

void Widget::connectApp(){
    QString nickname = editNickname->text();
    QString password = editPassword->text();


    //QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    //connect(manager, SIGNAL(finished(QNetworkReply*)),manager, SLOT(replyFinished(QNetworkReply*)));
//    connect(manager, SIGNAL(finished(QNetworkReply*)),manager, SLOT(replyFinished(QNetworkReply*)));

//    QUrl url(Parametre::serverAdresse+"/api/user/get/"+nickname+"/"+password);
//    manager->get(QNetworkRequest(url));

    QNetworkAccessManager networkManager;
    qDebug() << nickname;
    qDebug() << password;
    QUrl url(Parametre::serverAdresse+"/api/user/get/"+nickname+"/"+password);
    QNetworkRequest request;
    request.setUrl(url);

    QNetworkReply* currentReply = networkManager.get(request);
    QString data = (QString) currentReply->readAll();
    qDebug() << data;

    QEventLoop eventLoop;
    QNetworkAccessManager mgr;
        QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

        // the HTTP request
        QNetworkRequest req( QUrl( QString(Parametre::serverAdresse+"/api/user/get/"+nickname+"/"+password) ) );
        QNetworkReply *reply = mgr.get(req);
        eventLoop.exec(); // blocks stack until "finished()" has been called

        if (reply->error() == QNetworkReply::NoError) {
            //success
            qDebug() << "Success" <<reply->readAll();
            delete reply;
        }
        else {
            //failure
            qDebug() << "Failure" <<reply->errorString();
            delete reply;
        }


}
