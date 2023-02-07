#include <QApplication>
#include <QFile>
#include <QIcon>

#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QFile qssStyle("data/style.qss"); // load qss from 'data/style.qss'
    qssStyle.open(QFile::ReadOnly);
    app.setStyleSheet(qssStyle.readAll()); // set style from file
    qssStyle.close(); // close file
    app.setWindowIcon(QIcon("data/logo.png")); // set icon

    MainWindow mainWindow; // create and show main app window
    mainWindow.show(); 

    return app.exec();
}