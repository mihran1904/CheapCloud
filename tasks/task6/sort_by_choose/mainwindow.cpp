#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , arr_size(5)
    , arr{1,0,-3,5,2}
{
    ui->setupUi(this);
    QVBoxLayout *vLayout = new QVBoxLayout(ui->centralwidget);

    display_arr = new QLineEdit();
    display_arr->setReadOnly(true);
    display_arr->setAlignment(Qt::AlignCenter);
    display_arr->setMinimumHeight(50);
    vLayout->addWidget(display_arr);
    display_arr->setText(" you have { 1 , 0 , -3 , 5 , 2} array ");

    display = new QLineEdit();
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignCenter);
    display->setMinimumHeight(50);
    vLayout->addWidget(display);
    display->setText(" What logic you want to sort bubble or selection ");

    QGridLayout *gridLayout = new QGridLayout();
    vLayout->addLayout(gridLayout);

    QPushButton *btn1 = new QPushButton("Bubble Sort");
    QPushButton *btn2 = new QPushButton("Selection Sort");
    QPushButton *reset = new QPushButton("Clear");

    gridLayout->addWidget(btn1,0,0);
    gridLayout->addWidget(btn2,0,1);
    gridLayout->addWidget(reset,0,2);
    connect(btn1,&QPushButton::clicked,this,&MainWindow::onPushButton);
    connect(btn2,&QPushButton::clicked,this,&MainWindow::onPushButton);
    connect(reset,&QPushButton::clicked,this,&MainWindow::onPushButton);
    setFixedSize(500,600);

    display_sorted = new QLineEdit();
    display_sorted->setReadOnly(true);
    display_sorted->setAlignment(Qt::AlignCenter);
    display_sorted->setMinimumHeight(50);
    vLayout->addWidget(display_sorted);
    fnc_choose["Bubble Sort"] = bubble_sort_ptr;
    fnc_choose["Selection Sort"] = selection_sort_ptr;
}
void MainWindow::onPushButton(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button->text() == "Clear") {
        display_sorted->setText("");
    }
    else {
    sorted_arr.clear();
    fnc_choose[button->text()](arr,arr_size);
    for (int i = 0; i < arr_size; ++i) {
        sorted_arr += QString::number(arr[i]) + ",";
    }
    display_sorted->setText(sorted_arr + " by " + button->text());
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

