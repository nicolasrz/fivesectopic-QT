#include "widget.h"
#include <QPointer>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include "parametre.h"

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

    QPointer<QLineEdit> editNickname = new QLineEdit();
    QPointer<QLineEdit> editPassword = new QLineEdit();
    editPassword->setEchoMode(QLineEdit::Password);

    hLayoutNickname->addWidget(labelNickname);
    hLayoutNickname->addWidget(editNickname);


    hLayoutPassword->addWidget(labelPassword);
    hLayoutPassword->addWidget(editPassword);

    vLayout->addWidget(title);
    vLayout->addLayout(hLayoutNickname);
    vLayout->addLayout(hLayoutPassword);

}
