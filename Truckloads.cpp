#include "Truckloads.h"

Truckloads::Truckloads(){}
int Truckloads::numTrucks(int numCrates, int loadSize) {
    if (numCrates <= loadSize){
        return 1;
    }
    else {
        if (numCrates % 2 == 0){
            int trucksum = numTrucks(numCrates/2, loadSize) * 2 ;
            return trucksum;
        }
        else{
            int trucksum = numTrucks((numCrates+1)/2, loadSize)+ numTrucks((numCrates-1)/2, loadSize) ;
            return trucksum;
        }
        
    }
}