#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
#include <vector>
#include <iostream>

int main(void){
    // take input of the form int1 int2 int3 ..
    // store as a vector

    // initiallizing the vector
    std::vector<int> UnSorted;

    // initialize a variable as the input number
    int i;

    // using a while loop
    while (true){
        
        // get current number
        std::cin >> i;

        // add the the vector
        UnSorted.push_back(i);

        // check if the next value is an new line character
        if (std::cin.peek() == '\n'){
            // have reached the end of the input
            break;
        }
    }

    // use the quick sort class to sort the list

    // create a quick sort object
    QuickSort sorter;

    // sort the list
    std::vector<int> Sorted = sorter.sort(UnSorted);

    // Use binary search to test if 1 is in the list

    // create a binarysearch object
    RecursiveBinarySearch searcher;

    // serach for 1
    bool result = searcher.search(Sorted, 1);
    
    // output the result as true or false
    if (result == 1){
        std::cout << "True ";
    }
    else{
        std::cout << "False ";
    } 

    // output the sorted list
    for ( int x : Sorted){
        std::cout << x << " ";
    }





    



    
    return 0;
    


}