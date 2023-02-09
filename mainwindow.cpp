#include "mainwindow.h"
#include "page.h"
#include "pages.cpp"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  // resize and move window
  this->move(400, 200); // (x, y)
  this->setFixedSize(1080, 670); // forbid to change window size and set window size

  // Menu
  QMenuBar* mainMenu = new QMenuBar;
  this->helpMenu = new QMenu("Помощь");
  this->helpMenu->addAction("Справка", this, SLOT(whatInfo()));
  this->helpMenu->addAction("О программе", this, SLOT(programInfo()));
  this->helpMenu->addAction("About Qt", QApplication::instance(), SLOT(aboutQt()));
  mainMenu->addMenu(helpMenu);
  this->setMenuBar(mainMenu);

  // create buttons
  // setGeometry(x, y, width, height)
  this->y_button = new QPushButton("Да", this); // Yes-button
  this->y_button->setGeometry(5, 380, 360, 251);
  this->n_button = new QPushButton("Нет", this); // No-Button
  this->n_button->setGeometry(401, 380, 360,  251);
  this->r_button = new QPushButton("Сначала", this); // Restart button
  this->r_button->setGeometry(843, 35, 216, 54);
  

  // create labels
  this->question = new QLabel(Q1.question.c_str(), this);
  this->question->setGeometry(5, 35, 828, 360);
  this->author = new QLabel("Неправильно угадал? Есть ошибка?\nНапишите:\nTelegram - @kir_osm\nПочта - kirillosm09@gmail.com", this);
  this->author->setGeometry(835, 200, 240, 460); 
  

  // hidden elements (for last screen)
  this->photo = new QLabel("фото", this); 
  this->wikiLink = new QLabel("wiki", this); 
  this->description = new QLabel("description", this); 
  this->photo->hide(); 
  this->description->hide();
  this->wikiLink->hide();  

  // obj names
  this->y_button->setObjectName("yes");
  this->n_button->setObjectName("no");
  this->r_button->setObjectName("res");
  this->author->setObjectName("author");
  this->question->setObjectName("question");
  this->wikiLink->setObjectName("wiki");
  this->description->setObjectName("description");
  // auto wrap
  this->wikiLink->setWordWrap(true); 
  this->question->setWordWrap(true);
  this->description->setWordWrap(true);
  this->author->setWordWrap(true);

  // set alignment
  this->question->setAlignment(Qt::AlignLeft);
  this->wikiLink->setAlignment(Qt::AlignTop);
  this->description->setAlignment(Qt::AlignTop);

  // connect button actions and functions
  connect(y_button, &QPushButton::released, this, &MainWindow::handleYesButton);
  connect(n_button, &QPushButton::released, this, &MainWindow::handleNoButton);
  connect(r_button, &QPushButton::released, this, &MainWindow::handleRestartButton);
}
 
void MainWindow::whatInfo()
{
  QMessageBox::about(this,"Справка" , "RulerIS - информационная система, которая угадывает правителя России, начиная от Рюрика и заканчивая Путиным. Процесс отгадывания правителя происходит с помощью ответов пользователем на вопросы с возможными вариантами ответа \"Да\" и \"Нет\". В правом верхнем углу доступна кнопка \"Сначала\", которая включает на экране первый вопрос системы.\n2022 - 2023");
}

void MainWindow::programInfo()
{
  QMessageBox::about(this,"О программе" , "Version: 3.75b\n\nDate: 09.02.2023\n\nCode & Design: Kirill Osmolovsky (kirillosm09@gmail.com)\n\nPictures: ru.wikipedia.org\n\nScientific adviser: Larisa Vsevolodvna Kolyagina");
}

void MainWindow::handleYesButton()
{
  if(CURRENT.PageYes->isLast){
    // draw last page
    CURRENT = *(CURRENT.PageYes);
    updateScreenLastPage();
  }
  else{
    // ask next question
    CURRENT = *(CURRENT.PageYes);
    updateScreenQuestion();
  }
}

void MainWindow::handleNoButton()
{
  if(CURRENT.PageNo->isLast){
    // draw last page
    CURRENT = *(CURRENT.PageNo);
    updateScreenLastPage();
  }
  else{
    // ask next question
    CURRENT = *(CURRENT.PageNo);
    updateScreenQuestion();
  }
}

void MainWindow::handleRestartButton()
{
  CURRENT = Q1; // load first question to CURRENT
  this->photo->hide(); // hide photo
  this->wikiLink->hide(); // hide link
  this->description->hide();
  updateScreenQuestion();
}

void MainWindow::updateScreenQuestion(){
  // Draw screen when next question
  this->y_button->show();
  this->n_button->show();
  this->question->setText(CURRENT.question.c_str());
  this->question->setGeometry(5, 35, 828, 360);
  this->question->setFixedWidth(828); // idk why setGeometry() dont change Width. Perhaps reason is setFixedWidth call in updateScreenN()
}

void MainWindow::updateScreenLastPage(){
  // draw screen when last page
  this->y_button->hide();
  this->n_button->hide();
  this->question->setText(CURRENT.question.c_str());
  this->question->move(265, 35);
  this->question->setFixedWidth(554);
  this->question->setAlignment(Qt::AlignTop);

  this->photo->setStyleSheet(std::string("background-image: url(" + CURRENT.photoPath + "); background-repeat: no-repeat;").c_str());
  this->photo->setGeometry(5, 35, 255, 370);
  this->photo->setText("");

  this->wikiLink->setText(std::string("<a href=\""+ CURRENT.wikiLink +"\">Ссылка на Википедию (можно нажать)</a>").c_str());
  this->wikiLink->setGeometry(265, 252, 525, 175);
  this->wikiLink->setTextFormat(Qt::RichText);
  this->wikiLink->setTextInteractionFlags(Qt::TextBrowserInteraction);
  this->wikiLink->setOpenExternalLinks(true); // clickable link

  this->description->setText(CURRENT.description.c_str());
  this->description->setGeometry(265, 397, 525, 300);

  this->photo->show();
  this->wikiLink->show();
  this->description->show();
}
