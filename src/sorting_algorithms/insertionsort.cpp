//
//  insertionsort.cpp
//  ueb01
//
// Implementation inspired by:
// https://www.toptal.com/developers/sorting-algorithms/insertion-sort
//

#include "insertionsort.hpp"

int* isort::sort(int array[], size_t size) {

    // Begin at the leftmost index and iterate over every array element from left to right
    for (size_t i = 1; i < size; i++) {

        // Begin at current index i and move from right to left until we're either at the beginning of the array or array[j-1] < array[j]
        for (size_t j = i; j > 0 && array[j-1] > array[j]; j--) {

            // Swap the value at index k - 1 with the value at index k
            int temp = array[j-1];
            array[j-1] = array[j];
            array[j] = temp;

        }
    }

    return array;
}
