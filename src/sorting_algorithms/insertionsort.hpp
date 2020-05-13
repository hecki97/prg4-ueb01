//
//  insertionsort.hpp
//  ueb01
//

#ifndef insertionsort_hpp
#define insertionsort_hpp

#include <stdio.h>

namespace isort {

    /**
      Implementation of the insertion sort algorithm
      @param array An (unsorted) int array
      @param size Size of array
      @returns Sorted int array
     */
    int* sort(int array[], size_t size);
}

#endif /* insertionsort_hpp */
