#include "BubbleSort.h"

void BubbleSort::sort(QVector<int> &vec)  {
    bool swaped = false;
    for (int i = 0; i < vec.size(); ++i) {
        for(int j = 0; j < vec.size() - 1; ++j) {
            if (vec[j] < vec[j + 1]) {
                std::swap(vec[j],vec[j + 1]);
            }
        }
        if (!swaped) {
            break;
        }
    }
}
