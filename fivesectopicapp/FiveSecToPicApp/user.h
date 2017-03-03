#ifndef USER_H
#define USER_H
#include <QString>

class User
{
public:
    User();
    ~User();

    QString getNickname();
    void setNickame(QString name);
    QString getPassord();
    void setPassword(QString password);


private:
    QString nickname;
    QString password;
};

#endif // USER_H
