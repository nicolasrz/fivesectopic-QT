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
    QString getPassword();
    void setPassword(QString password);

    bool getConnected();
    void setConnected(bool connected);

    QString getId();
    void setId(QString id);

    QStringList getFriends();





private:
    QString id;
    QString nickname;
    QString password;
    bool connected;
};

#endif // USER_H
