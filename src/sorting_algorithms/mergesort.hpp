//
//  mergesort.hpp
//  ueb01
//

#ifndef mergesort_hpp
#define mergesort_hpp

#include <stdio.h>

namespace msort {
    /**
     Implementation of the merge sort algorithm
     @param array An (unsorted) int array
     @param size Size of the array
     @returns The sorted int array of the specified size
     */
    int* sort(int array[], size_t size);

    /**
     @param left The left half of an array
     @param size_left Size of the left subarray
     @param right The right half of an array
     @param size_right Size of the right subarray
     @return The sorted array combining left and right
     */
    int* merge(int left[], size_t size_left, int right[], size_t size_right);
}

#endif /* mergesort_hpp */
