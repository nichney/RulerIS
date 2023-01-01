#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
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
  void updateScreenY();
  void updateScreenN();
private:
  QPushButton *y_button; // yes-button
  QPushButton *n_button; // no-button
  QPushButton *r_button; // restart button
  QLabel      *question;
  QLabel      *photo;
  QLabel      *description;
  QLabel      *author;
  QLabel      *wikiLink;
  
  
};
#endif // MAINWINDOW_H