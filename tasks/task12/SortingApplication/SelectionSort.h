#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include "SortingStrategy.h"

class SelectionSort : public SortingStrategy
{
public:
    void sort(QVector<int> &vec) override;
};

#endif // SELECTIONSORT_H
