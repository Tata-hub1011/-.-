

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "database.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void refreshData();
    void banUser();

private:
    QTableWidget *userTable;
    QListWidget *msgList;
    QPushButton *refreshBtn;
    QPushButton *banBtn;
};

#endif

