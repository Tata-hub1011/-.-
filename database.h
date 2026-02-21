

#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>

struct User {
    QString login;
    QString name;
    bool isBanned = false;
};

struct Message {
    QString from;
    QString to;
    QString text;
};

class Database {
public:
    static QVector<User> loadUsers();
    static QVector<Message> loadMessages();
    static void updateUsers(const QVector<User>& users);
};

#endif

