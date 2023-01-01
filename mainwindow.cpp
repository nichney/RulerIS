#include "mainwindow.h"
#include "page.h"
#include "pages.cpp"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  this->setGeometry(400, 200, 1060, 670); // resize and move window

  // create buttons
  // setgeometry(x, y, width, height)
  this->y_button = new QPushButton("Да", this); // Yes-button
  this->y_button->setGeometry(5, 375, 360, 251);
  this->y_button->setObjectName("yes");
  this->n_button = new QPushButton("Нет", this); // No-Button
  this->n_button->setGeometry(401, 375, 360,  251);
  this->n_button->setObjectName("no");
  this->r_button = new QPushButton("Сначала", this); // Restart button
  this->r_button->setGeometry(828, 5, 216, 54);
  this->r_button->setObjectName("res");

  this->question = new QLabel(Q1.question.c_str(), this);
  this->question->setGeometry(5, 5, 828, 360);
  this->author = new QLabel("Неправильно угадал? Есть ошибка?\nНапишите:\nTelegram - @kir_osm\nПочта - kirillosm09@gmail.com", this);
  this->author->setGeometry(820, 300, 240, 360); 
  this->author->setObjectName("author");

 
  this->photo = new QLabel("фото", this); 
  this->photo->hide(); // show when last page
  this->wikiLink = new QLabel("wiki", this); 
  this->wikiLink->hide(); // show when last page
  this->description = new QLabel("description", this); 
  this->description->hide(); // show when last page

  this->wikiLink->setWordWrap(true); // auto wrap
  this->question->setWordWrap(true);
  this->description->setWordWrap(true);
  this->author->setWordWrap(true);

  this->question->setAlignment(Qt::AlignLeft);
  this->wikiLink->setAlignment(Qt::AlignTop);
  this->description->setAlignment(Qt::AlignTop);

  // connect button actions and functions
  connect(y_button, &QPushButton::released, this, &MainWindow::handleYesButton);
  connect(n_button, &QPushButton::released, this, &MainWindow::handleNoButton);
  connect(r_button, &QPushButton::released, this, &MainWindow::handleRestartButton);
}
 
void MainWindow::handleYesButton()
{
  if(CURRENT.PageYes->isLast){
    // draw last page
    CURRENT = *(CURRENT.PageYes);
    updateScreenN();
  }
  else{
    // ask next question
    CURRENT = *(CURRENT.PageYes);
    updateScreenY();
  }
}

void MainWindow::handleNoButton()
{
  if(CURRENT.PageNo->isLast){
    // draw last page
    CURRENT = *(CURRENT.PageNo);
    updateScreenN();
  }
  else{
    // ask next question
    CURRENT = *(CURRENT.PageNo);
    updateScreenY();
  }
}

void MainWindow::handleRestartButton()
{
  CURRENT = Q1; // Show first question
  this->photo->hide(); // hide photo
  this->wikiLink->hide(); // hide link
  this->description->hide();
  updateScreenY();
}

void MainWindow::updateScreenY(){
  // Draw screen when not last question
  this->y_button->show();
  this->n_button->show();
  this->question->setText(CURRENT.question.c_str());
  this->question->setGeometry(5, 5, 828, 360);
  this->question->setAlignment(Qt::AlignLeft);
}

void MainWindow::updateScreenN(){
  this->y_button->hide();
  this->n_button->hide();
  this->question->setText(CURRENT.question.c_str());
  //this->question->setGeometry(265, 5, 454, 180);
  this->question->move(265, 5);
  this->question->setFixedWidth(454);
   this->question->setAlignment(Qt::AlignTop);

  this->photo->setStyleSheet(std::string("background-image: url(" + CURRENT.photoPath + "); background-repeat: no-repeat;").c_str());
  this->photo->setGeometry(5, 5, 255, 370);
  this->photo->setText("");

  this->wikiLink->setText(std::string("<a href=\""+ CURRENT.wikiLink +"\">Ссылка на Википедию (можно нажать)</a>").c_str());
  this->wikiLink->setGeometry(265, 187, 525, 175);
  this->wikiLink->setTextFormat(Qt::RichText);
  this->wikiLink->setTextInteractionFlags(Qt::TextBrowserInteraction);
  this->wikiLink->setOpenExternalLinks(true);

  this->description->setText(CURRENT.description.c_str());
  this->description->setGeometry(265, 362, 525, 300);


  this->photo->show();
  this->wikiLink->show();
  this->description->show();
}
