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
#include <QJsonObject>
#include <QMessageBox>
#include <string>
using std::string;
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
    vLayout = new QVBoxLayout(this);
    hLayoutNickname = new QHBoxLayout();
    hLayoutPassword = new QHBoxLayout();

    title = new QLabel("Five sec to pic !");

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

    QEventLoop eventLoop;
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req( QUrl( QString(Parametre::serverAdresse+"/api/user/get/"+nickname+"/"+password) ) );
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called


    if (reply->error() == QNetworkReply::NoError) {
        //success
        int id = reply->readAll().toInt();
        if(reply->readAll() != "0"){
            qDebug() << "id connected : " + QString::number(id);
            user = new User();
            user->setConnected(true);
            user->setId(id);
            remove(vLayout);
            client = new Client(this);
            client->userId = "123456";
        }else{
            QMessageBox msgBox;
            msgBox.setText("Sorry ! Invalid nickname/password ");
            msgBox.exec();
        }
        delete reply;
    }
    else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }
}

void Widget::remove(QLayout* layout)
{
    QLayoutItem* child;
    while(layout->count()!=0)
    {
        child = layout->takeAt(0);
        if(child->layout() != 0)
        {
            remove(child->layout());
        }
        else if(child->widget() != 0)
        {
            delete child->widget();
        }

        delete child;
    }
}
