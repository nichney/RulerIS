#include "mainwindow.h"
#include "page.h"
#include "pages.cpp"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  // setGeometry(x, y, width, height)
  // resize and move window
  this->move(400, 200); // (x, y)
  this->setFixedSize(1080, 720); // forbid to change window size and set window size
  this->setStyleSheet("QMainWindow {background-image: url(\"data/startScreen.png\")}");

  // Menu
  QMenuBar* mainMenu = new QMenuBar;
  this->helpMenu = new QMenu("Помощь");
  this->helpMenu->addAction("Справка", this, SLOT(whatInfo()));
  this->helpMenu->addAction("О программе", this, SLOT(programInfo()));
  this->helpMenu->addAction("About Qt", QApplication::instance(), SLOT(aboutQt()));
  mainMenu->addMenu(helpMenu);
  this->setMenuBar(mainMenu);

  // Font (method from stackowerflow)
  int id = QFontDatabase::addApplicationFont("font/AubreyPro.otf");
  QString family = QFontDatabase::applicationFontFamilies(id).at(0);
  QFont AubreyPro(family);


  // Question Label
  this->question = new QLabel("Загадайте любого правителя России от Рюрика до В.В.Путина", this);
  this->question->setGeometry(120, 112, 700, 370);
  this->question->setFont(AubreyPro);

  // Wiki Label
  this->wikiLink = new QLabel("wiki", this); 
  this->wikiLink->setGeometry(100, 590, 400, 60);
  this->wikiLink->hide();

  // Description label
  this->description = new QLabel("description", this);
  this->description->setGeometry(100, 440, 400, 150);
  this->description->setFont(AubreyPro); 
  this->description->hide();

  // Last label
  this->last = new QLabel("Last", this);
  this->last->setGeometry(100, 115, 600, 325);
  this->last->setFont(AubreyPro); 
  this->last->hide();

  // Photo
  this->photo = new QLabel("photo", this); 
  this->photo->hide();

  // Start button
  this->startButton = new QPushButton("Начать", this); // Yes-button
  this->startButton->setGeometry(150, 498, 150, 45);
  QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect;
  shadow->setOffset(10, 10);
  shadow->setBlurRadius(5);
  this->startButton->setGraphicsEffect(shadow);
  this->startButton->setFont(AubreyPro);

  // Yes Button
  this->y_button = new QPushButton("Да", this); // Yes-button
  this->y_button->setGeometry(255, 540, 208, 61);
  QGraphicsDropShadowEffect *shadow1 = new QGraphicsDropShadowEffect;
  shadow1->setOffset(10, 10);
  shadow1->setBlurRadius(5);
  this->y_button->setGraphicsEffect(shadow1);
  this->y_button->setFont(AubreyPro);
  this->y_button->hide();

 // No Button
  this->n_button = new QPushButton("Нет", this); // Yes-button
  this->n_button->setGeometry(629, 540, 208, 61);
  QGraphicsDropShadowEffect *shadow2 = new QGraphicsDropShadowEffect;
  shadow2->setOffset(10, 10);
  shadow2->setBlurRadius(5);
  this->n_button->setGraphicsEffect(shadow2);
  this->n_button->setFont(AubreyPro);
  this->n_button->hide();

  // Return Button
  this->r_button = new QPushButton("Сначала", this); // Yes-button
  this->r_button->setGeometry(918, 33, 121, 36);
  QGraphicsDropShadowEffect *shadow3 = new QGraphicsDropShadowEffect;
  shadow3->setOffset(10, 10);
  shadow3->setBlurRadius(5);
  this->r_button->setGraphicsEffect(shadow3);
  this->r_button->setFont(AubreyPro);
  this->r_button->hide();

  // obj names
  this->y_button->setObjectName("yes");
  this->n_button->setObjectName("no");
  this->r_button->setObjectName("res");
  this->startButton->setObjectName("start");
  this->question->setObjectName("question");
  this->wikiLink->setObjectName("wiki");
  this->description->setObjectName("description");
  this->last->setObjectName("last");


  // auto wrap
  this->question->setWordWrap(true);
  this->wikiLink->setWordWrap(true); 
  this->description->setWordWrap(true);
  this->last->setWordWrap(true);


  // set alignment
  this->question->setAlignment(Qt::AlignLeft);
  this->wikiLink->setAlignment(Qt::AlignTop);
  this->description->setAlignment(Qt::AlignTop);


  // connect button actions and functions
  connect(y_button, &QPushButton::released, this, &MainWindow::handleYesButton);
  connect(startButton, &QPushButton::released, this, &MainWindow::updateScreenQuestion);
  connect(n_button, &QPushButton::released, this, &MainWindow::handleNoButton);
  connect(r_button, &QPushButton::released, this, &MainWindow::handleRestartButton);
}
 
void MainWindow::whatInfo()
{
  QMessageBox::about(this,"Справка" , "RulerIS - программа, которая угадывает правителя России, начиная от Рюрика и заканчивая Путиным. Процесс отгадывания правителя происходит с помощью ответов пользователем на вопросы с возможными вариантами ответа \"Да\" и \"Нет\". В правом верхнем углу доступна кнопка \"Сначала\", которая включает на экране первый вопрос системы.\n2022 - 2023");
}

void MainWindow::programInfo()
{
  QMessageBox::about(this,"О программе" , "Version: 4.77b\n\nDate: 18.02.2023\n\nCode: Kirill Osmolovsky (kirillosm09@gmail.com)\n\nDesign: Eva Varaksina (vev_9@mail.ru)\n\nPictures: ru.wikipedia.org\n\nFont: https://fonts-online.ru/fonts/aubrey-pro \n\nScientific adviser: Larisa Vsevolodvna Kolyagina");
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
  this->last->hide();
  this->question->show();
  updateScreenQuestion();
}

void MainWindow::updateScreenQuestion(){
  // Draw screen when next question
  this->setStyleSheet("QMainWindow {background-image: url(\"data/question.png\")}");
  this->startButton->hide();
  this->y_button->show();
  this->n_button->show();
  this->r_button->show();
  this->question->setText(CURRENT.question.c_str());

  this->question->setGeometry(143, 130, 793, 360);
  this->question->setFixedWidth(793); // idk why setGeometry() dont change Width. Perhaps reason is setFixedWidth call in updateScreenN()
}

void MainWindow::updateScreenLastPage(){
  // draw screen when last page
  this->setStyleSheet("QMainWindow {background-image: url(\"data/result.png\")}");
  this->y_button->hide();
  this->n_button->hide();
  this->question->hide();
  this->last->setText(CURRENT.question.c_str());
  this->last->setAlignment(Qt::AlignTop);

  this->photo->setStyleSheet(std::string("background-image: url(" + CURRENT.photoPath + "); background-repeat: no-repeat;").c_str());
  this->photo->setGeometry(810, 100, 400, 500);
  this->photo->setText("");

  this->wikiLink->setText(std::string("<a href=\""+ CURRENT.wikiLink +"\">Ссылка на Википедию (можно нажать)</a>").c_str());
  this->wikiLink->setTextFormat(Qt::RichText);
  this->wikiLink->setTextInteractionFlags(Qt::TextBrowserInteraction);
  this->wikiLink->setOpenExternalLinks(true); // clickable link

  this->description->setText(CURRENT.description.c_str());

  this->photo->show();
  this->wikiLink->show();
  this->description->show();
  this->last->show();
}
