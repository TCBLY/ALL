#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.setGeometry(100, 100, 800, 500);
    mainWindow.show();
    return a.exec();
}
