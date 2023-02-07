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
private:
  QPushButton *y_button; // yes-button
  QPushButton *n_button; // no-button
  QPushButton *r_button; // restart button
  QLabel      *question;
  QLabel      *photo;
  QLabel      *description;
  QLabel      *author;
  QLabel      *wikiLink;
  QMenu       *helpMenu;
  
  
};
#endif // MAINWINDOW_H