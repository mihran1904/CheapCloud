#ifndef SORTINGAPPLICATION_H
#define SORTINGAPPLICATION_H

#include <QMainWindow>
#include "Filehandler.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class SortingApplication;
}
QT_END_NAMESPACE

class SortingApplication : public QMainWindow
{
    Q_OBJECT

public:
    SortingApplication(QWidget *parent = nullptr);
    ~SortingApplication();
private slots:
    void onPushBtn();
    //void afterPushBtn();
private:
    Ui::SortingApplication *ui;
    FileHandler *m_data;
    QVector<int> m_nums;
    SortingStrategy *m_strategy;
    QVBoxLayout *m_vLayout;
    QTextEdit *m_displayBeforeSort;
    QTextEdit *m_displayAfterSort;
    QPushButton *m_bubbleSortBtn;
    QPushButton *m_selectionSortBtn;
};
#endif // SORTINGAPPLICATION_H
