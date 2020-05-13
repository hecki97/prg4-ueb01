//
//  shellsort.cpp
//  ueb01
//
// Implementation inspired by:
// https://en.wikipedia.org/wiki/Shellsort#Pseudocode
//

#include "shellsort.hpp"

int* ssort::sort(int array[], size_t size) {
    std::vector<size_t> gaps;

    size_t h = 0;
    while (h < size) {
        h = 3 * h + 1;
        gaps.push_back(h);
    }

    // Reverse gaps to start with the largest gap and work down to a gap of 1
    std::reverse(gaps.begin(), gaps.end());
    for (size_t gap : gaps) {

        for (size_t i = gap; i < size; i++) {

            // Perform inner insertion sort
            int temp = array[i];
            size_t j = i;
            while (j >= gap && array[j-gap] > temp) {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }
    }

    return array;
}
