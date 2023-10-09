#ifndef PREFIXMATCHER
#define PREFIXMATCHER

#include "Trie.h"
#include <map>

class PrefixMatcher{
    private:
        // a trie containing ip_address such as "1001"
        // however, due to the design of the trie, they are stored as "baab"
        // all implements still work
        Trie ip_addresses;
        // a map to connect the address of node that represents the router's ip's final character
        // & the router's number
        std::map<Trienode*, int> ip_nums;
    public:
        // Constructor
        PrefixMatcher();
        // return the router with the longest matching prefix
        int selectRouter(std::string networkAddress);
        // add a router address
        void insert(std::string address, int routerNumber);
};

#endif