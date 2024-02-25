#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include <QTextEdit>

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
    void read_file();
    void write_file();
private:
    Ui::MainWindow *ui;
    QPushButton *readbtn;
    QPushButton *writebtn;
    QTextEdit *write_display;
    QTextEdit *read_display;
};
#endif // MAINWINDOW_H
