#include "BubbleSort.h"
#include <iostream>

//Constructor function
BubbleSort::BubbleSort(){};

// Sorting function
std::vector<int> BubbleSort::sort(std::vector<int> list){
    // initialize a variable swapped to be used in the loop
    int swapped;

    // Create a loop for the variable i, that starts as the last value in the list
    // and then is decreased after every iteration
    for (int i= list.size()-1; i>0; i--){ 

        // set the value of swapped to 0
        // if by the end of this iteration swapped is still 0
        // that would mean there were no changed and list is sorted
        swapped = 0;

        

        // loop from the first to the ith element
        for(int j = 0; j < i; j++) {
            // check if the current element is greater than the element
            if(list.at(j) > list.at(j+1)) {
                // create a temporary variable to hold the current element
                int temp = list.at(j);
                
                // write the j+1 element in place of j
                list.at(j) = list.at(j+1);

                // write the temp (the previous j element) varible in place of j+1
                list.at(j+1) = temp;

                //change value of swapped to indicate a swap occured
                swapped = 1;
            }
        }

        // check if swapped changed
        if (swapped == 0){
            // there was no swap, break the loop
            break;
        }
        else{
            // there was a swap, continue
        }  
    }
    
    return list;
}


