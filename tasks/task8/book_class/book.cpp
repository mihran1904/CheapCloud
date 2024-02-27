#include "book.h"

Book::Book() : _title{""},_author{""},_ISBN{""} {}

Book::Book(const QString &title, const QString &author, const QString &ISBN) :
    _title{title},_author{author},_ISBN{ISBN} {}
Book::Book(const Book &book) {
    _title = book._title;
    _author = book._author;
    _ISBN = book._ISBN;
}
Book Book::operator =(const Book& book) {
    this->_title = book._title;
    this->_author = book._author;
    this->_ISBN = book._ISBN;
    return *this;
}
void Book::setAuthor(const QString & author) {
    _author = author;
}

void Book::setTitle(const QString & title) {
    _title = title;
}

void Book::setISBN(const QString & ISBN) {
    _ISBN = ISBN;
}

QString Book::getAuthor() const {
    return _author;
}

QString Book::getTitle() const {
    return _title;
}

QString Book::getISBN() const {
    return _ISBN;
}

