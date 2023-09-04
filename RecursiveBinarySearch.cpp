#include "RecursiveBinarySearch.h"

// Constructor Function
RecursiveBinarySearch::RecursiveBinarySearch(){};

// Helper function/function accessible to user
bool RecursiveBinarySearch::search(std::vector<int> list, int target){
    // Set the starting index as 0
    int start = 0;
    // Set the ending index as the last element
    int end = list.size()-1;

    // call the Recursive Search Function with the paramters and return the value
    return RecursiveSearch(list, target, start, end);
}

bool RecursiveBinarySearch::RecursiveSearch(std::vector<int> list, int target, int start, int end){ 
    // Find middle value of the list
    // by adding the start and end indexes, and then diving by 2
    
    // using integer division so that
    // for even totals you get the middle term,
    // for odd totals you get the xth term, instead of the x.5 th  term
    int middle = (start + end) / 2;

    // if the element at the middle index is correct, return True
    if (list.at(middle) == target){
        return true;
    }
    
    // else proceed to split the search area based on the value of the middle element

    // but first check the base case
    // if the area we are checking consists of only one element
    if (start == end){
        // returning false, because if this element was the correct one
        // it would have been found above 
        return false;
    }
    // boolean containing the result -> is the target in this search area
    bool result;


    // if the target was smaller than the middle value of the search area,
    // then the target would be in the first half of the search area (if it is in there at all)
    // therefore, the recursive call will the tell function to look in the first half of the current search area
    if (target < list.at(middle)){
        // recursive call to look from same start to middle - 1
        result = RecursiveSearch(list, target, start, middle-1);
    }
    // if the target is bigger than the middle value
    // then it is the second half of the search area (if in the list at all)
    // therefore, the recursive call will tell the function to look in the second half of the current search area
    else{
        // recursive call to look from middle +1 to the same end
        result = RecursiveSearch(list, target, middle+1, end);
    }
    
    // return the result bool
    return result;    
}
