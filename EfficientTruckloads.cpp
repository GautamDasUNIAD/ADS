#include "EfficientTruckloads.h"
#include <map>
#include <iostream>

EfficientTruckloads::EfficientTruckloads(){}

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
    //momoization
    // std::cout<< tester;
    tester = 1;
    // std::cout << "STARTING WITH " << numCrates << " "<< loadSize << std::endl;

    // std::cout << "memo is currently: ";
    // for (int i = 0; i < 20; i++){
    //     for (int j=0; j < 5; j++){
            // std::cout << "[" << i << "]" << "[" << j << "]" << " = " << this->memo[i][j] << std::endl;
    //     }
    // }

    if (this->memo[numCrates][loadSize] != 0){

        // std::cout << "Returning from this->memo check";
        // std::cout << this->memo[numCrates][loadSize] << std::endl;
        return this->memo[numCrates][loadSize];
    }
    if (numCrates <= loadSize){
        this->memo[numCrates][loadSize] = 1;
        // std::cout<< "added" << 1 << "to the memo for" << numCrates<< " " << loadSize<< "\n";
        // std::cout << this->memo[numCrates][loadSize] << std::endl;
        return 1;
    }
    else {
        if (numCrates % 2 == 0){
            int trucksum = numTrucks(numCrates/2, loadSize) * 2 ;

            this->memo[numCrates][loadSize] = trucksum;
            // std::cout<< "added" << trucksum << "to the memo for" << numCrates<< " " << loadSize<< "\n";
            // std::cout << this->memo[numCrates][loadSize] << std::endl;

            return trucksum;
        }
        else{
            int trucksum = numTrucks((numCrates+1)/2, loadSize)+ numTrucks((numCrates-1)/2, loadSize) ;
            this->memo[numCrates][loadSize] = trucksum;
            // std::cout<< "added" << trucksum << "to the memo for" << numCrates<< " " << loadSize<< "\n";
            return trucksum;
        }        
    }
}
