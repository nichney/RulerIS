#include <QApplication>
#include <QFile>

#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QFile qssStyle("data/style.qss");
    qssStyle.open(QFile::ReadOnly);
    app.setStyleSheet(qssStyle.readAll());
    qssStyle.close();

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}