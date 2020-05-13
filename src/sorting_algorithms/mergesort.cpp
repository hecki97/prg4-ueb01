//
//  mergesort.cpp
//  ueb01
//
// Implementation inspired by:
// https://en.wikipedia.org/wiki/Merge_sort#Top-down_implementation_using_lists
//

#include "mergesort.hpp"

int* msort::sort(int array[], size_t size) {
    // Base case. A list containing zero or one elements is sorted by definition
    if (size <= 1) {
        return array;
    }
    
    // Recursively sort left subarray
    size_t size_left = size / 2;
    int* left = msort::sort(array, size_left);
    
    // Recursively sort right subarray
    size_t size_right = size - size_left;
    int* right = msort::sort(&array[size_left], size_right);
    
    // Merge now-sorted subarrays
    return msort::merge(left, size_left, right, size_right);
}

int* msort::merge(int left[], size_t size_left, int right[], size_t size_right) {
    // Allocate memory to temporarily store sorted values
    size_t merged_size = size_left + size_right;
    int* temp = new int[merged_size];

    size_t i {0};
    size_t j {0};
    size_t current {0};

    while (i < size_left && j < size_right) {
        if (left[i] <= right[j]) {
            temp[current] = left[i];
            i++;
        } else {
            temp[current] = right[j];
            j++;
        }
        current++;
    }

    // Either left or right may have elements left; consume them.
    // (Only one of the following loops will actually be entered)
    while (i < size_left) {
        temp[current] = left[i];
        current++;
        i++;
    }

    while (j < size_right) {
        temp[current] = right[j];
        current++;
        j++;
    }

    // Update values in the original array with the values stored in temp[]
    for (size_t i = 0; i < merged_size; i++) {
        left[i] = temp[i];
    }

    delete [] temp;

    return left;
}
