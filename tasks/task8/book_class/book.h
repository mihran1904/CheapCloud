#ifndef BOOK_H
#define BOOK_H
#include <QString>
class Book {
public:
    Book(const QString& title,const QString& author,const QString& ISBN);
    Book(const Book& book);
    Book operator=(const Book& book);
    Book();
    QString getTitle() const;
    QString getAuthor() const;
    QString getISBN() const;
    void setTitle(const QString&);
    void setAuthor(const QString&);
    void setISBN(const QString&);
private:
    QString _title;
    QString _author;
    QString _ISBN;
};

#endif // BOOK_H
