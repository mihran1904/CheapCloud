#include "mainwindow.h"
#include "circle.h"
#include "rectangle.h"
#include <QApplication>
#include <QTextEdit>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Shape *shape = new Circle(2.2);
    QTextEdit textEdit(&w);
    QTextEdit textEdit2(&w);
    textEdit.setText(QString("circle area : ") + QString::number(shape->calculate_area()));
    QVBoxLayout *vlayout = new QVBoxLayout(w.centralWidget());

    vlayout->addWidget(&textEdit);
    textEdit.setReadOnly(true);
    textEdit.setMinimumSize(100,50);
    vlayout->addWidget(&textEdit2);
    textEdit2.setReadOnly(true);
    textEdit2.setMinimumSize(100,50);
    w.setFixedSize(300,300);
    w.setLayout(vlayout);
    Shape *shape2 = new Rectangle(3,4);
    textEdit2.setText(QString("rectangel area: ") + QString::number(shape2->calculate_area()));



    w.show();
    return a.exec();
}
