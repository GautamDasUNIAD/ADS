#include "QuickSort.h"
#include <iostream>

// constructor function
QuickSort::QuickSort(){};

// Recursive Sorting function
std::vector<int> QuickSort::sort(std::vector<int> list){
    // base case
    // if there are less than two elements
    // there is nothing to do
    if (list.size() < 2){
        return list;
    }

    // pick a pivot
    // According to the prac details, if length is >= 3, we make the third element the pivot
    // Since it is not defined for length < 3: if length is < 3, the pivot will be the last element
    int pivot_index;
    if (list.size() >=3 ){
        pivot_index = 2;
    } 
    else{
        // the last element is at 1, because if the size is less then 2,
        // then the list would have been returned already
        pivot_index = 1;
    }

    // create a variable to store the swapping index
    // when a swap needs to occur, you swap the current element with the eement at swapping index
    // set the swapping index to zero
    int swapping_index = 0;

    // loop through the vector
    for (int i= 0; i< list.size(); i++){
        // if the ith element is less than the pivot
        if (list.at(i) < list.at(pivot_index)){
            // swap the ith element with the elemet at the swapping index
            
            // create a temp variable to store the ith element
            int temp = list.at(i);

            // replace the element at i with the element at the swapping index
            list.at(i) = list.at(swapping_index);

            // replace the element at the swapping index with temp(the element previouosly at i)
            list.at(swapping_index) = temp;

            // if the swapping index is the same as th pivot_index
            // this would mean the pivot gets swapped
            // hence, the pivot index needs to be updated
            if (swapping_index == pivot_index){
                // update pivot_index
                pivot_index = i;
            }
            
            // increase swapping index by 1
            swapping_index++;

        }
        else{
            // don't increase the swapping index
        }
    }

    // swap the pivot and the element at the swapping index

    // temp variable to store the pivot
    int temp = list.at(pivot_index);

    // replace element at pivot index with element at swapping index
    list.at(pivot_index) = list.at(swapping_index);

    // place the temp( the pivot ) at the swapping index
    list.at(swapping_index) = temp;

    // create sub-arrays
    // smaller than pivot
    std::vector<int> small;
    
    // the pivot
    std::vector<int> pivot;
    
    // smaller than pivot
    std::vector<int> big;

    // add to sub-arrays
    for (int x : list){
        // check and add the corresponding vector
        if (x < list.at(pivot_index)){
            small.push_back(x);
        }
        // if x is the same as pivot, add the pivot vector
        // note that this means, that all values equal to the pivot are added
        // to the vector, this has been done so that in the recursive calls,
        // the lists provided will have fewer elements and hence will be a bit faster
        else if (x == list.at(pivot_index)){
            pivot.push_back(x);
        }
        else{
            big.push_back(x);
        }

    }

    // recursive call for big and small vector
    std::vector<int> big_sorted = sort(big);
    std::vector<int> small_sorted = sort(small);

    // add values from pivot vector to small_sorted
    for (int x : pivot){
        small_sorted.push_back(x);
    }
    // add values from big_sorted vector to small_sorted
    for (int x : big_sorted){
        small_sorted.push_back(x);
    }
    
    // return the small_sorted
    return small_sorted;
    
    

}