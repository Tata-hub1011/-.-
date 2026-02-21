

#include "database.h"

QVector<User> Database::loadUsers() {
    QVector<User> users;
    QFile file("chat_data.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith("U:")) {
                QStringList parts = line.mid(2).split(":");
                if (parts.size() >= 3) {
                    bool banned = (parts.size() > 3 && parts[3] == "1");
                    users.append({parts[0], parts[2], banned});
                }
            }
        }
    }
    return users;
}

QVector<Message> Database::loadMessages() {
    QVector<Message> messages;
    QFile file("chat_data.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith("M:")) {
                QStringList parts = line.mid(2).split(":");
                if (parts.size() >= 3) {
                    messages.append({parts[0], parts[1], parts[2]});
                }
            }
        }
    }
    return messages;
}

void Database::updateUsers(const QVector<User>& users) {
}

