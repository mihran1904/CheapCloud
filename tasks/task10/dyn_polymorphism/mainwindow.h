#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "circle.h"
#include "rectangel.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onPushBtn();
private:
    Ui::MainWindow *ui;
    Shape *shape;
    QPushButton *btn1;
    QPushButton *btn2;
    QLineEdit *info_display;

};
#endif // MAINWINDOW_H
