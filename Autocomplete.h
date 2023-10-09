#ifndef AUTOCOMPLETE
#define AUTOCOMPLETE

#include "Trie.h"
#include <vector>
#include <string>

class Autocomplete{
    private:
        Trie all_words;
    public:
        std::vector<std::string> getSuggestions(std::string partialWord);  // return the known words that start with partialWord

        void insert(std::string word); // add a word to the known words

        // constructor
        Autocomplete();
};


#endif
