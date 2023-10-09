#ifndef TRIE
#define TRIE

#include "Trienode.h"
#include <string>
#include <vector>

class Trie{
    protected:
        // pointer to the root node in the trie
        Trienode* root;
    public: 
        // constructor 
        Trie();
        // function to search, returns true or false
        bool search_key(std::string key);
        // function to add key to trie
        void add_key(std::string key);
        // function to delete key from trie
        void delete_key(std::string key);

        // function to return all keys in trie as vector
        std::vector<std::string> return_all_keys(Trienode* root = nullptr);

        // function to return all keys with given prefix
        std::vector<std::string> return_from_prefix(std::string prefix);

        // function to return the address of the node that represents the last
        // char of a key that matches in the trie 
        // eg. if "abcd" is in trie, with input "abcde" it returns address of node
        // corresponding to d
        Trienode* return_address_from_key(std::string key);

        // function to return the address of the node that represents the last
        // char of a key that is added to the trie
        Trienode* return_address_from_inserted_key(std::string key);
};



#endif