#include "sortingapplication.h"
#include "ui_sortingapplication.h"

SortingApplication::SortingApplication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SortingApplication)
    ,m_strategy(nullptr)
    ,m_displayAfterSort(nullptr)
    ,m_displayBeforeSort(nullptr)
    ,m_bubbleSortBtn(nullptr)
    ,m_selectionSortBtn(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Sorting Application by choosen strategy");
    m_vLayout = new QVBoxLayout(ui->centralwidget);
    setLayout(m_vLayout);
    m_displayBeforeSort = new QTextEdit();
    m_displayBeforeSort->setReadOnly(true);
    QLineEdit *display_info = new QLineEdit();
    display_info->setReadOnly(true);
    display_info->setText("in first place you see unordered numbers choose what strategy do you want for sort");
    m_vLayout->addWidget(display_info);
    m_displayAfterSort = new QTextEdit();
    m_displayAfterSort->setReadOnly(true);
    m_vLayout->addWidget(m_displayBeforeSort);
    QGridLayout *gLayout = new QGridLayout();
    m_bubbleSortBtn = new QPushButton("Bubble Sort");
    m_selectionSortBtn = new QPushButton("Selection Sort");
    gLayout->addWidget(m_bubbleSortBtn,0,0);
    gLayout->addWidget(m_selectionSortBtn,0,1);
    m_vLayout->addLayout(gLayout);
    connect(m_bubbleSortBtn,&QPushButton::clicked,this,&SortingApplication::onPushBtn);
    connect(m_selectionSortBtn,&QPushButton::clicked,this,&SortingApplication::onPushBtn);
    m_vLayout->addWidget(m_displayAfterSort);
    m_data = new FileHandler(QString("nums_data.txt"));

    m_nums = m_data->readArrayFromFile();


    QString tmp;
    for (const int& i  : m_nums) {
        tmp += (QString::number(i));
        tmp += QString(";");
    }
    m_displayBeforeSort->setText(tmp);
}

void SortingApplication::onPushBtn() {
    QPushButton *btn = qobject_cast<QPushButton*>(sender());

    if (btn->text() == "Bubble Sort") {
        if (m_strategy == nullptr) {
            m_strategy = new BubbleSort;
            m_strategy->sort(m_nums);
        }
    }
    else if (btn->text() == "Selection Sort") {
        if (m_strategy == nullptr) {
        m_strategy = new SelectionSort;
        m_strategy->sort(m_nums);
        }
    }
    QString tmp;
    for (const int& i  : m_nums) {
        tmp += (QString::number(i));
        tmp += QString(";");
    }
    m_displayAfterSort->setText(tmp);
}

SortingApplication::~SortingApplication()
{
    delete ui;
    delete m_data;
}
