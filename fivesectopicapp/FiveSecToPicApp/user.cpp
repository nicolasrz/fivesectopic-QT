#include "user.h"

User::User()
{

}
User::~User()
{

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
