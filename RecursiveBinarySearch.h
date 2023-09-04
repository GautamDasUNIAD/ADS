#ifndef RECURSIVEBINARYSEARCH
#define RECURSIVEBINARYSEARCH

#include <vector>

class RecursiveBinarySearch{
    private:
        // the recursive function to search for an item in the list
        bool RecursiveSearch(std::vector<int> list, int target, int start, int end);
    public:
        // constructor
        RecursiveBinarySearch();

        // helper function/functioin accessible to a user,
        // calls the Recursive Search function and returns the output
        bool search(std::vector<int> list, int target);
};

#endif