#include "Autocomplete.h"

Autocomplete::Autocomplete(){}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord){
    // return the results from the return_from_prefix method of trie
    return all_words.return_from_prefix(partialWord);
    
}

void Autocomplete::insert(std::string word){
    // add the word using add_key method of trie.
    all_words.add_key(word);
}