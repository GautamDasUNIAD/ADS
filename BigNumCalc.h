#ifndef BIGNUMCALC
#define BIGNUMCALC

#include <list>
#include <string>

class BigNumCalc{
    // public methods 
    public:
        // default constructor
        BigNumCalc();
        // default destructor
        ~BigNumCalc();

        // create a list from a provided string
        std::list<int> buildBigNum(std::string numString);
        // add two list numbers together
        std::list<int> add(std::list<int> num1, std::list<int> num2);
        // subtract two list numbers
        std::list<int> sub(std::list<int> num1, std::list<int> num2);
        // multiply two list numbers
        std::list<int> mul(std::list<int> num1, std::list<int> num2);
};


#endif