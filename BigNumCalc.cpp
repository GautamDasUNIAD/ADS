#include "BigNumCalc.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
// default constructor and desctructor
BigNumCalc::BigNumCalc(){};
BigNumCalc::~BigNumCalc(){};

// create a list from a provided string
std::list<int> BigNumCalc::buildBigNum(std::string numString){
    // create a list object
    std::list<int> big_number;
    // loop through each character of the string
    for (int i = 0; i < numString.length(); i++){
        // get ith digit from the stirng as an integer
        // but subtracting the integer value of 'zero'
        int digit = numString[i] - '0';
        // add to the big_number
        big_number.push_back(digit);

    }
    
    return big_number;
}
    
// add two list numbers together
std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2){
    // create a list to store the result
    std::list<int> result;

    // initialize the carry variable
    int carry = 0;

    // loop through both lists in reverse order
    // initialize reverse iterator first first list
    auto iterator1 = num1.rbegin();
    auto iterator2 = num2.rbegin();

    // keep looping the end of both lists is reached
    while(iterator1 != num1.rend() || iterator2 !=num2.rend()){
        // get the element at the current position from both lists
        // add the two + carry -> total
        int total = *iterator1 + *iterator2 + carry;
        // mod it by 10 -> result_num
        int result_num = total % 10;
        // add the result_num to the result list
        result.push_front(result_num);
        // carry = (total - result / 10)
        carry = (total - result_num)/10;
        // move to next element
        if (iterator1 != num1.rend()){
            iterator1++;
            if (iterator1 == num1.rend()){
                *iterator1 = 0;
            }
        }
        if (iterator2 != num2.rend()){
            iterator2++;
            if (iterator2 == num2.rend()){
                *iterator2 = 0;
            }
        }
        
    }
    // add the carry to the result if it is not zero
    if (carry != 0){
        result.push_front(carry);
    }

    for (auto it = result.begin(); it != result.end(); it++){
        std::cout << *it;
    }
    std::cout<< '\n';

    return result;
}
// subtract two list numbers
std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2){
    // create a list to store the result
    std::list<int> result;
    // loop through both lists in reverse order
    // initialize reverse iterator first first list
    auto iterator1 = num1.rbegin();
    auto iterator2 = num2.rbegin();

    // initialize variables to hold digits
    int digit1;
    int digit2; 
    // initialize variable to hold the result for each digit
    int result_num;


    // keep looping the end of both lists is reached
    while(iterator1 != num1.rend() || iterator2 !=num2.rend()){
        // get the element at the current position from both lists
        digit1 = *iterator1;
        digit2 = *iterator2; 

        // if digit 1 is >= digit2, then just subtract the two numbers
        if (digit1 >= digit2){
            result_num = digit1 - digit2;
        }else{
            // try get the second number in the first list
            if (iterator1 != num1.rend()){
                // move to the next digit in the first list 
                iterator1++;

                // subtract 1 from that digit
                *iterator1 = *iterator1 - 1;

                // get the result now 
                result_num = digit1+10 - digit2;

                // return iterator to current position
                iterator1--;
            } else{
                // the second number is bigger than the first one
                // since we are trying to find the difference and all
                // results have to be positive,
                // redo the subtraction but with reversed numbers
                return sub(num2, num1);
            }

        }
        // add the result to the result list
        result.push_front(result_num);

        // move to next element for both lists 
        // (if that element exists):

        // if the iterator is not already past the last element
        if (iterator1 != num1.rend()){
            // move to the next element
            iterator1++;
            // if the iterator is now past the last element
            if (iterator1 == num1.rend()){
                // make the element at the iterator zero
                *iterator1 = 0;
            }
        }
        
        // if the iterator is not already past the last element
        if (iterator2 != num2.rend()){
            // move to the next element
            iterator2++;
            // if the iterator is now past the last element
            if (iterator2 == num2.rend()){
                // make the element at the iterator zero
                *iterator2 = 0;
            }
        }   
    }
    
    for (auto it = result.begin(); it != result.end(); it++){
        std::cout << *it;
    }
    std::cout<< '\n';

    return result;

}

// multiply two list numbers
std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2){
    // the final result list
    std::list<int> final_result;
    // setting it to zero
    final_result.push_back(0);

    // init carry variable
    int carry = 0;

    // variable to hold which digit the iterator is on
    // 0 is the left most digits
    int digit = 0; 

    // reverse loop through each element in the second list
    for (auto iterator2 = num2.rbegin(); iterator2 != num2.rend(); ++iterator2){
        // create new list to hold the multiple of current element of num2
        // and the all of l1
        std::list<int> temporary_result;

        // depeding on what digit the loop is on
        // add zeroes at the end of the list
        for (int i = 0; i < digit; i++){
            temporary_result.push_back(0);
        }

        // reverse loop trough the first list
        for (auto iterator1 = num1.rbegin(); iterator1 != num1.rend(); ++iterator1){
            // multiply element from second list and first list  and add the carry
            int total = (*iterator2)*(*iterator1) + carry;
            // mod total by 10 to get the result number
            int result_num = total % 10;
            // add the result number to the temporary result
            temporary_result.push_front(result_num);
            // calculate the carry <- (total / result_num)/10 
            carry = (total - result_num)/10;
        }
        // if the carry isn't zero, add it to the temporary result
        if (carry != 0){
            temporary_result.push_front(carry);
        }
        // add the temporary result to the final result
        final_result = add(final_result, temporary_result);
        // increment the digit
        digit++;
    }
    
    // return the final result
    return final_result;
}
