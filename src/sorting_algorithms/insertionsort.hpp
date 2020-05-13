//
//  insertionsort.hpp
//  ueb01
//

#ifndef insertionsort_hpp
#define insertionsort_hpp

#include <stdio.h>

namespace isort {

    /**
     * Implementation of the insertion sort algorithm
     * @param array A (unsorted) int vector
     * @returns A sorted int vector
     */
    int* sort(int array[], size_t size);
}

#endif /* insertionsort_hpp */
