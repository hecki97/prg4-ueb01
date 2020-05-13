//
//  bubblesort.cpp
//  ueb01
//
//  Implementation inspired by:
//  https://en.wikipedia.org/wiki/Bubble_sort#Pseudocode_implementation
//

#include "bubblesort.hpp"

int* bsort::sort(int array[], size_t size) {

    size_t n = size;
    bool swapped;

    // Run at least once, and as long as at least one swap has occured
    do {
        swapped = false;

        for (size_t i = 1; i < n; i++) {
            
            // If the left element is smaller than the right one, swap them
            if (array[i-1] > array[i]) {

                // Swap the content of array[i] with array[i-1]
                int temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;

                // Remember swap
                swapped = true;

            }
        }

        // Assumption: After every loop, the largest element of the current scope has "bubbled up" to the rightmost position. Thus we don't need to look at that anymore.
        n--;
    } while(swapped);

    return array;
}
