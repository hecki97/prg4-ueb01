//
//  bubblesort.hpp
//  ueb01
//

#ifndef bubblesort_hpp
#define bubblesort_hpp

#include <stdio.h>

namespace bsort {
    /**
     Implementation of the bubble sort algorithm
     @param array An (unsorted) int array
     @param size Size of array
     @returns Sorted int array
    */
    int* sort(int array[], size_t size);
}

#endif /* bubblesort_hpp */
