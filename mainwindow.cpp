
#include "mainwindow.h"
#include <QHeaderView>
#include <QLabel>
#include <QTabWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Админ-панель чата (сервер)");
    resize(800, 500);

    auto *centralWidget = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(centralWidget);
    auto *tabs = new QTabWidget();

    userTable = new QTableWidget(0, 3);
    userTable->setHorizontalHeaderLabels({"Логин", "Имя", "Статус"});
    userTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    userTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    msgList = new QListWidget();

    tabs->addTab(userTable, "Пользователи");
    tabs->addTab(msgList, "Все сообщения (Лог)");

    refreshBtn = new QPushButton("Обновить данные");
    banBtn = new QPushButton("Забанить/Разбанить");
    banBtn->setStyleSheet("background-color: #e74c3c; color: white; font-weight: bold;");

    mainLayout->addWidget(tabs);
    mainLayout->addWidget(refreshBtn);
    mainLayout->addWidget(banBtn);

    setCentralWidget(centralWidget);

    connect(refreshBtn, &QPushButton::clicked, this, &MainWindow::refreshData);
    connect(banBtn, &QPushButton::clicked, this, &MainWindow::banUser);

    refreshData();
}

void MainWindow::refreshData() {
    auto users = Database::loadUsers();
    userTable->setRowCount(0);
    for (const auto& u : users) {
        int row = userTable->rowCount();
        userTable->insertRow(row);
        userTable->setItem(row, 0, new QTableWidgetItem(u.login));
        userTable->setItem(row, 1, new QTableWidgetItem(u.name));
        userTable->setItem(row, 2, new QTableWidgetItem(u.isBanned ? "Забанен" : "Активен"));
    }

    auto msgs = Database::loadMessages();
    msgList->clear();
    for (const auto& m : msgs) {
        QString display = QString("[%1 -> %2]: %3").arg(m.from, m.to, m.text);
        msgList->addItem(display);
    }
}

void MainWindow::banUser() {
    int row = userTable->currentRow();
    if (row >= 0) {
        QString login = userTable->item(row, 0)->text();
        refreshData();
    }
}


