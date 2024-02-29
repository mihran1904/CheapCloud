#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myexception.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,shape(nullptr)
{
    ui->setupUi(this);
    QVBoxLayout *vlayout = new QVBoxLayout(ui->centralwidget);
    info_display = new QLineEdit();
    info_display->setReadOnly(true);
    setFixedSize(350,350);
    info_display->setText("Enter values for Circle & Rectangel");
    info_display->setAlignment(Qt::AlignCenter);
    QLineEdit *circle_tag = new QLineEdit();
    circle_tag->setReadOnly(true);
    circle_tag->setText("Circle Radius");
    QLineEdit *rect_tag_h = new QLineEdit();
    rect_tag_h->setReadOnly(true);
    rect_tag_h->setText("Rectangel height");
    QLineEdit *rect_tag_l = new QLineEdit();
    rect_tag_l->setReadOnly(true);
    rect_tag_l->setText("Rectangel length");
    circle_input = new QLineEdit();
    rect_inp_l = new QLineEdit();
    rect_inp_h = new QLineEdit();
    setWindowTitle("Calculate Shape Area With Exception hndl");
    btn1 = new QPushButton("Circle Area");
    btn2 = new QPushButton("Rectangel Area");
    connect(btn1,&QPushButton::clicked,this,&MainWindow::onPushBtn);
    connect(btn2,&QPushButton::clicked,this,&MainWindow::onPushBtn);
    vlayout->addWidget(info_display);
    QGridLayout *glayout = new QGridLayout();
    glayout->addWidget(circle_tag,0,0);
    glayout->addWidget(circle_input,0,1);
    glayout->addWidget(rect_tag_h,1,0);
    glayout->addWidget(rect_inp_h,1,1);
    glayout->addWidget(rect_tag_l,2,0);
    glayout->addWidget(rect_inp_l,2,1);
    glayout->addWidget(btn1,3,0);
    glayout->addWidget(btn2,3,1);
    vlayout->addLayout(glayout);
}
void MainWindow::onPushBtn() {
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (btn->text() == "Circle Area") {
        if (shape != nullptr) {
            delete shape;
        }
        try {
            shape = new Circle(circle_input->text().toDouble());
            QMessageBox output;
            output.setWindowTitle("CALCULATING SHAPE AREA OUTPUT");
            output.setText(QString::number(shape->calculate_area()));
            output.exec();
        }
        catch (const MyException& msg) {
            QMessageBox output;
            output.setWindowTitle("Error");
            output.setText(msg.getMsg());
            output.exec();
        }
    }
    if (btn->text() == "Rectangel Area") {
        if (shape != nullptr) {
            delete shape;
        }
        try {
            double height = rect_inp_h->text().toDouble();
            double length = rect_inp_l->text().toDouble();
            shape = new Rectangel(height,length);
            QMessageBox output;
            output.setWindowTitle("CALCULATING SHAPE AREA OUTPUT");
            output.setText(QString::number(shape->calculate_area()));
            output.exec();
        }
        catch (const MyException& msg) {
            QMessageBox output;
            output.setWindowTitle("Error");
            output.setText(msg.getMsg());
            output.exec();
        }

    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
