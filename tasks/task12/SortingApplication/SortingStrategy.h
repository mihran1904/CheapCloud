#ifndef SORTINGSTRATEGY_H
#define SORTINGSTRATEGY_H
#include <QVector>
class SortingStrategy {
public:
    virtual void sort(QVector<int> &vec) = 0;
    virtual ~SortingStrategy(){};
};

#endif // SORTINGSTRATEGY_H
