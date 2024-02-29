#include "mainwindow.h"
#include "ui_mainwindow.h"

void print_shape_area(Shape* shape) {
    QMessageBox output;
    output.setWindowTitle("CALCULATING SHAPE AREA OUTPUT");
    output.setText(QString::number(shape->calculate_area()));
    output.exec();
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,shape(nullptr)
{
    ui->setupUi(this);
    QVBoxLayout *vlayout = new QVBoxLayout(ui->centralwidget);
    info_display = new QLineEdit();
    info_display->setReadOnly(true);
    setFixedSize(300,300);
    info_display->setText("You have Circle(R:3) and Rectagel(H:3,L:5)");
    setWindowTitle("Calculate Shape Area");
    btn1 = new QPushButton("Circle Area");
    btn2 = new QPushButton("Rectangel Area");
    connect(btn1,&QPushButton::clicked,this,&MainWindow::onPushBtn);
    connect(btn2,&QPushButton::clicked,this,&MainWindow::onPushBtn);
    vlayout->addWidget(info_display);
    QGridLayout *glayout = new QGridLayout();
    glayout->addWidget(btn1,0,0);
    glayout->addWidget(btn2,0,1);
    vlayout->addLayout(glayout);

}

void MainWindow::onPushBtn() {
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (btn->text() == "Circle Area") {
        if (shape != nullptr) {
            delete shape;
        }
        shape = new Circle(3);
        print_shape_area(shape);
    }
    if (btn->text() == "Rectangel Area") {
        if (shape != nullptr) {
            delete shape;
        }
        shape = new Rectangel(3,5);
        print_shape_area(shape);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
