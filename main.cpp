

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    
    a.setStyleSheet(
        "QMainWindow { background-color: #2c3e50; }"
        "QTableWidget, QListWidget { background-color: #34495e; color: white; border: none; gridline-color: #7f8c8d; }"
        "QPushButton { background-color: #3498db; color: white; padding: 8px; border-radius: 4px; }"
        "QPushButton:hover { background-color: #2980b9; }"
        "QHeaderView::section { background-color: #2c3e50; color: white; }"
    );

    MainWindow w;
    w.show();
    return a.exec();
}

