#include <QApplication>
#include <QFile>
#include <QIcon>

#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QFile qssStyle("data/style.qss");
    qssStyle.open(QFile::ReadOnly);
    app.setStyleSheet(qssStyle.readAll());
    qssStyle.close();
    app.setWindowIcon(QIcon("data/logo.png"));

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}