#include "user.h"

User::User()
{

}
User::~User()
{

}


int User::getId(){
    return this->id;
}

void User::setId(int id){
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
