#ifndef QUICKSORT
#define QUICKSORT

#include "Sort.h"
#include <vector>

class QuickSort : Sort{
    public:
        // constructor function
        QuickSort();

        // sorting function, to sort a list using quick sort
        std::vector<int> sort(std::vector<int> list);
};

#endif