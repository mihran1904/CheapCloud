#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QVBoxLayout"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,secWindow(nullptr)
{
    ui->setupUi(this);
    vlayout = new QVBoxLayout(ui->centralwidget);
    display = new QLineEdit();
    display->setReadOnly(true);
    display->setMinimumHeight(30);
    QPushButton *addBook = new QPushButton("NEW BOOK");
    vlayout->addWidget(addBook);
    vlayout->addWidget(display);
    connect(addBook,&QPushButton::clicked,this,&MainWindow::onPushBtn);
    QPushButton *getBookFields =new QPushButton("Get Book Fields");
    connect(getBookFields,&QPushButton::clicked,this,&MainWindow::onGetBtn);
    vlayout->addWidget(getBookFields);
}
/*
Book MainWindow::getBook() {
    return mybook;
}
*/
void MainWindow::onPushBtn(){
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (btn->text() == "NEW BOOK") {
        if (!secWindow) {
            secWindow = new newWindow(this);
            connect(secWindow, &newWindow::destroyed, [this](){
                secWindow = nullptr;  // Set to nullptr when the new window is closed
            });
        }

        // Show the new window
        secWindow->show();
    }
}

void MainWindow::onGetBtn() {
    QGridLayout *glayout = new QGridLayout();
    vlayout->addLayout(glayout);
    mybook = secWindow->getBook();
    QLineEdit *title_tag = new QLineEdit();
    title_tag->setReadOnly(true);
    title_tag->setMinimumHeight(40);
    title_tag->setText("Book Title");
    QLineEdit *author_tag = new QLineEdit();
    author_tag->setReadOnly(true);
    author_tag->setMinimumHeight(40);
    author_tag->setText("Book Author");
    QLineEdit *isbn_tag = new QLineEdit();
    isbn_tag->setReadOnly(true);
    isbn_tag->setMinimumHeight(40);
    isbn_tag->setText("Book ISBN");
    QLineEdit *title_set = new QLineEdit();
    QLineEdit *author_set = new QLineEdit();
    QLineEdit *isbn_set = new QLineEdit();
    title_set->setMinimumHeight(40);
    title_set->setReadOnly(true);
    author_set->setMinimumHeight(40);
    author_set->setReadOnly(true);
    isbn_set->setMinimumHeight(40);
    isbn_set->setReadOnly(true);
    title_set->setText(mybook->getTitle());
    author_set->setText(mybook->getAuthor());
    isbn_set->setText(mybook->getISBN());
    glayout->addWidget(title_tag,0,0);
    glayout->addWidget(author_tag,1,0);
    glayout->addWidget(isbn_tag,2,0);
    glayout->addWidget(title_set,0,1);
    glayout->addWidget(author_set,1,1);
    glayout->addWidget(isbn_set,2,1);
}

MainWindow::~MainWindow()
{
    delete ui;

}

