#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QLabel>
#include <QFont>
#include <QFontDatabase>
#include <QGraphicsDropShadowEffect>

#include <string>

#include "page.h"

namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);
private slots:
  void handleYesButton();
  void handleNoButton();
  void handleRestartButton();
  void updateScreenQuestion();
  void updateScreenLastPage();
  void programInfo();
  void whatInfo();
  void printLicense();
private:
  QPushButton *y_button; // yes-button
  QPushButton *n_button; // no-button
  QPushButton *r_button; // restart button
  QPushButton *startButton;
  QLabel      *question;
  QLabel      *photo;
  QLabel      *description;
  QLabel      *wikiLink;
  QLabel      *last;
  QMenu       *helpMenu;
  
  
};
#endif // MAINWINDOW_H