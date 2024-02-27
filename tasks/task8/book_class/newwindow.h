#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include "book.h"
#include "ui_newwindow.h"
namespace Ui {
class newWindow;
}

class newWindow : public QWidget
{
    Q_OBJECT

public:
    explicit newWindow(QWidget *parent = nullptr);
    ~newWindow();

private slots:
    void saveAndClose();
    void cancelAndClose();
public:
    Book* getBook();


private:
    Ui::newWindow *ui;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    Book *book;
    QVBoxLayout *vlayout;
    QGridLayout *glayout;
    QLineEdit *title_tag;
    QLineEdit *author_tag;
    QLineEdit *isbn_tag;
    QLineEdit *title_set;
    QLineEdit *author_set;
    QLineEdit *isbn_set;

};

#endif // NEWWINDOW_H
