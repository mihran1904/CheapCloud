#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "book.h"
#include <QPushButton>
#include <QLineEdit>
#include <QTextStream>
#include "newwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Book getBook();
private slots:
    void onPushBtn();
    void onGetBtn();
private:
    Ui::MainWindow *ui;
    QLineEdit *display;
    newWindow *secWindow;
    QVBoxLayout *vlayout;
    Book *mybook;
};
#endif // MAINWINDOW_H
