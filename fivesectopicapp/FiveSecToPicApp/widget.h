#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPointer>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <user.h>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void init();
    QPointer<QVBoxLayout> vLayout ;
    QPointer<QHBoxLayout> hLayoutNickname ;
    QPointer<QHBoxLayout> hLayoutPassword;

    QPointer<QLineEdit> editNickname;
    QPointer<QLineEdit> editPassword;
    QPointer<QLabel> title ;
    User *user;

public slots:
    void connectApp();
};

#endif // WIDGET_H
