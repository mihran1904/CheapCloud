#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "SortingStrategy.h"

class BubbleSort : public SortingStrategy
{
public:

    void sort(QVector<int> &vec) override;
};

#endif // BUBBLESORT_H
