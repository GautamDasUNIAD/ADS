#ifndef BUBBLESORT
#define BUBBLESORT

#include "Sort.h"

// Create child class from Sort class
class BubbleSort: Sort {
    public:
        // Constructor function
        BubbleSort();

        // Function to sort using bubble sort
        std::vector<int> sort(std::vector<int> list);
};

#endif