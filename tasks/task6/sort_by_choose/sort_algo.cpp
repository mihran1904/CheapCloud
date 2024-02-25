#include "sort_algo.h"
#include "algorithm"
void bubble_sort(int* arr,const int size) {
    bool swaped = false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if ( arr[j] > arr[j + 1]){
                std::swap(arr[j],arr[j + 1]);
            }
        }
        if (!swaped) {
            break;
        }
    }
}

void selection_sort(int *arr, const int size) {
    bool swaped = false;
    int min_index = 0;
    for (int i = 0; i < size; ++i) {
        min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min_index]){
                min_index = j;
                swaped = true;
            }
        }
        if (min_index != i) {
            std::swap(arr[i],arr[min_index]);
        }
        if (!swaped) {
            break;
        }
    }
}
