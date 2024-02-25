#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    readbtn = new QPushButton("Read File");
    writebtn = new QPushButton("Write File");

    connect(readbtn, &QPushButton::clicked, this, &MainWindow::read_file);
    connect(writebtn, &QPushButton::clicked, this, &MainWindow::write_file);

    write_display = new QTextEdit();
    read_display = new QTextEdit();
    read_display->setReadOnly(true);
    QVBoxLayout * vLayout = new QVBoxLayout();
    vLayout->addWidget(write_display);
    write_display->setAlignment(Qt::AlignLeft);
    write_display->setMinimumSize(100,100);
    vLayout->addWidget(read_display);
    QGridLayout * gLayout = new QGridLayout();
    gLayout->addWidget(writebtn,0,0);
    gLayout->addWidget(readbtn,0,1);
    setMaximumSize(500,600);
    //
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(vLayout);

    setCentralWidget(centralWidget);
    centralWidget->show();

    // Add grid layout to vLayout
    vLayout->addLayout(gLayout);


}
void MainWindow::write_file() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QDir::homePath());
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << write_display->toPlainText();
            file.close();
        }
    }
}

void MainWindow::read_file() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath());
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            read_display->setPlainText(in.readAll());
            file.close();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

