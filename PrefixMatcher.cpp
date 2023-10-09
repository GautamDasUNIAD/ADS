#include "PrefixMatcher.h"
#include "Trie.h"
#include <iostream>
// constructor
PrefixMatcher::PrefixMatcher(){};

// return the router with the longest matching prefix
int PrefixMatcher::selectRouter(std::string networkAddress){
    // change 1s to bs and 0s to a's
    std::string modified_networkAddress;
    for (auto address_char : networkAddress){
        if (address_char == '1'){
            modified_networkAddress += 'b';
        } else {
            modified_networkAddress += 'a';
        }
    }

    // get address of the node that represents the last character that matches
    // from the given address using the return_address_from_key method of the trie class
    Trienode* address = ip_addresses.return_address_from_key(modified_networkAddress);

    // using address get the router
    return ip_nums[address];
}
// add a router address
void PrefixMatcher::insert(std::string address, int routerNumber){
    // change 1s to bs and 0s to a's
    std::string modified_address;
    for (auto address_char : address){
        if (address_char == '1'){
            modified_address += 'b';
        } else {
            modified_address += 'a';
        }
    }
    
    // add the modified address to trie using return_address_from_inserted_key method
    Trienode* node_address =  ip_addresses.return_address_from_inserted_key(modified_address);

    // add the address and router number to the map
    ip_nums[node_address] = routerNumber;
}
