#include "SelectionSort.h"

void SelectionSort::sort(QVector<int> &vec) {
    int min_index = 0;
    for (int i = 0; i < vec.size(); ++i) {
        min_index = i;
        for (int j = i; j < vec.size(); ++j) {
            if ( vec[j] < vec[min_index]) {
                min_index = j;
            }
        }
        if ( min_index != i) {
            std::swap(vec[i],vec[min_index]);
        }
    }
}
