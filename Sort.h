#ifndef SORT
#define SORT

#include <vector>

//Create the class
class Sort{
    // Pure virtual function because every sub-class will have a seperate version
    // And this class will not have its own implementaion 
    virtual std::vector<int> sort(std::vector<int> list) = 0;
};

#endif