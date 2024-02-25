#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "sort_algo.h"
#include <QMap>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onPushButton();
private:
    Ui::MainWindow *ui;
    QLineEdit *display_arr;
    QLineEdit *display;
    const int arr_size;
    int arr[5];
    void(*bubble_sort_ptr)(int*,const int) = &bubble_sort;
    void(*selection_sort_ptr)(int*,const int) = &selection_sort;
    QMap<QString,void(*)(int*,const int)> fnc_choose;
    QString sorted_arr;
    QLineEdit *display_sorted;
};
#endif // MAINWINDOW_H
