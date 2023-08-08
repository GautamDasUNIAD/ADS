#include "Reverser.h"
#include <cmath>
Reverser::Reverser(){}

int Reverser::reverseDigit(int value){
    if (value < 0 ) {
        return -1;
    }    

    if (value < 10) {
        return value;
    }

    //find number of zeros
    int ndigits = 0;
    for (int i = value; i > 0; i=i/10){
        ndigits++;
    }
    // std::cout << ndigits << std::endl;

    int nzeroes = ndigits - 1;
    //find last digit
    int last_digit = value % 10;

    return (last_digit * pow(10, nzeroes) + reverseDigit((value - last_digit) / 10));
}

std::string Reverser::reverseString(std::string string){
    if (string.length() == 1) {
        return string;
    }

    
    char last_char = string[string.length()-1];

    std::string remaining = "";
    for (int i = 0; i < string.length()-1; i++){
        remaining = remaining + string[i];
    } 


    return (last_char + reverseString(remaining));
}