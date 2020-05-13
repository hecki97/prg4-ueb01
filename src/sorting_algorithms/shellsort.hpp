//
//  shellsort.hpp
//  ueb01
//

#ifndef shellsort_hpp
#define shellsort_hpp

#include <stdio.h>
#include <array>
#include <vector>
#include <algorithm>

namespace ssort {
    /**
    * Implementation of the shell sort algorithm
     @param array An (unsorted) int array
     @param size Size of array
     @returns Sorted int array
    */
    int* sort(int array[], size_t size);
}

#endif /* shellsort_hpp */
