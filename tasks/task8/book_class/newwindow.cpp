#include "newwindow.h"
#include "ui_newwindow.h"
#include <QMessageBox>
newWindow::newWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newWindow)
{
    ui->setupUi(this);
    saveButton = new QPushButton("Save");
    cancelButton = new QPushButton("Cancel");
    book = new Book{};
    connect(saveButton,&QPushButton::clicked,this,&newWindow::saveAndClose);
    connect(cancelButton,&QPushButton::clicked,this,&newWindow::cancelAndClose);
    vlayout = new QVBoxLayout(this->window());
    glayout = new QGridLayout();
    vlayout->addLayout(glayout);

    title_tag = new QLineEdit();
    title_tag->setReadOnly(true);
    title_tag->setMinimumHeight(40);
    title_tag->setText("Book Title");
    author_tag = new QLineEdit();
    author_tag->setReadOnly(true);
    author_tag->setMinimumHeight(40);
    author_tag->setText("Book Author");
    isbn_tag = new QLineEdit();
    isbn_tag->setReadOnly(true);
    isbn_tag->setMinimumHeight(40);
    isbn_tag->setText("Book ISBN");
    title_set = new QLineEdit();
    author_set = new QLineEdit();
    isbn_set = new QLineEdit();
    title_set->setMinimumHeight(40);
    author_set->setMinimumHeight(40);
    isbn_set->setMinimumHeight(40);
    glayout->addWidget(title_tag,0,0);
    glayout->addWidget(author_tag,1,0);
    glayout->addWidget(isbn_tag,2,0);
    glayout->addWidget(title_set,0,1);
    glayout->addWidget(author_set,1,1);
    glayout->addWidget(isbn_set,2,1);


    glayout->addWidget(saveButton,3,0);
    glayout->addWidget(cancelButton,3,1);
    setLayout(vlayout);
    setFixedSize(300,300);
    setWindowTitle("Set new book fields");

    show();
}

Book* newWindow::getBook() {
    return book;
}
void newWindow::saveAndClose() {
    book->setTitle(title_set->text());
    book->setAuthor(author_set->text());
    book->setISBN(isbn_set->text());
    QMessageBox::information(this,"Status","book fields succesfully added!" + book->getTitle(),QMessageBox::Ok);
    close();
}

void newWindow::cancelAndClose() {
    close();
}

newWindow::~newWindow()
{
    delete ui;
}
