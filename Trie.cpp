#include "Trie.h"
#include <vector>
// constructor variable
Trie::Trie(){
    root = new Trienode;
}

// function to search for key in trie
bool Trie::search_key(std::string key){
    // set current node
    Trienode* current_node = root;

    // loop through each character of the key
    for (int i = 0; i<key.length(); i++){
        // get corressponding index of the character
        int character_index = key[i] - 97;
        // see if the current node has a child at that index (that isn't a nullptr)
        Trienode* child = current_node->getchildren()[character_index];
        if(child != nullptr){
            // set the child node to be the current node
            current_node = child;
        }else{
            // key doesn't exist
            // return False
            return false;
        }
    }

    // since function hasn't returned true, all the characters exist in trie, in the required order
    // if the current node (the one representing the last character of the key) is an end of a word
    // key exists
    if (current_node->IsEndOfWord() == true){
        return true;
    }else{
        // key doesn't exist
        return false;
    }
}
// function to add key to trie
void Trie::add_key(std::string key){
    // set current node
    Trienode* current_node = root;

    // loop through all characters in the key
    for (int i = 0; i  < key.length(); i++){
        // for each character in the key, get its relative index
        // for example a has the index 0, and b has 1
        int character_index = key[i] - 97; //take 97 because 
        
        // get the child of the current node at the character_index
        Trienode* child_at_index = current_node->getchildren()[character_index];

        // check to see if the current node has a child at the character_index
        if (child_at_index != nullptr){
            // it does have child
            // set current node to be child node
            current_node = child_at_index;
        }else{
            // it doen't have a child at the given index
            // create a new child node
            Trienode* new_child = new Trienode;
            // add new child node to the given index for the current node
            current_node->setchild(new_child, character_index);
            // set current node to the new child node
            current_node = new_child;
        }
    }
    // change the last node to be the end of the word
    current_node->setEndofWord(true);
}

// recursive delete function
Trienode* recursive_delete(Trienode* node, std::string key,int depth){

    // if current node is a nullptr, key is not in tree, return nullptr
    if (node == nullptr){
        return nullptr;
    }


    // base case, end of key
    if (depth == key.length()){
        // change the endofword value to be false
        node->setEndofWord(false);
        // see if the node has any non-nullptr children
        Trienode** node_children = node->getchildren();
        // boolean that stores whether or not node has any non-nullptr children
        bool node_has_children = false;

        for (int i = 0; i < 26; i++){
            if (node_children[i] != nullptr){
                node_has_children = true;
                break;
            }
        }
        
        // if the node doesn't have any children, return nullptr
        if (node_has_children == false){
            return nullptr;
        }else{
            // else return the node
            return node;
        } 
    }
    // if the key exists in this trie, the current node will have a non-nullptr child node at
    // the index that corresponds to the character for the child node
    // for example, if the key is 'abc' and we are currently on the node representing 'b',
    // then if the key exists, there must be a child node at the index that corresponds to 'c', 
    // here, get that index
    int character_index = key[depth]- 97;

    // get the child node at that index
    Trienode* child = node->getchildren()[character_index];

    // recursive call the delete function on the node's child at the corresponding index, 
    // replace current child with the output of the function
    node->setchild(recursive_delete(child, key, depth+1),character_index);
    
    // after recusive call, see if the node has any non-nullptr children
    Trienode** node_children = node->getchildren();
    // boolean that stores whether or not node has any non-nullptr children
    bool node_has_children = false;

    for (int i = 0; i < 26; i++){
        if (node_children[i] != nullptr){
            node_has_children = true;
            break;
        }
    }
    
    // if the node doesn't have any children, return nullptr and is not the end of a word itself
    if (node_has_children == false && node->IsEndOfWord() == false){
        return nullptr;
    }
    // if it does have children, return the node's adress
    else {
        return node;
    }


}


// function to delete key from trie
void Trie::delete_key(std::string key){
    // using recursive function calls
    recursive_delete(root, key, 0);
}

// recursive function to return all keys in trie as vector
std::vector<std::string> Trie::return_all_keys(Trienode* root){
    // if root is nullptr, then root wasn't provided, use the original trie's root
    if (root == nullptr){
        root = this->root;
        
    }
    
    // initialize vector to hold all the keys
    std::vector<std::string> results;

    // base case, if current root is null ptr
    if (root == nullptr){
        return results;
    }

    // loop through all children of the root
    Trienode** children = root->getchildren(); 
    for (int i = 0; i < 26; i++){
        // set child
        Trienode* child = children[i];
        if (child != nullptr){
            char child_char = i + 97;

            // call recursive function on child
            
            std::vector<std::string> child_keys = return_all_keys(child);
            // for each string in the child_keys, add the character represented by the child's index
            // at the front and add the results vector
            for(std::string key : child_keys){
                results.push_back(child_char + key);
            }
            // if the child is the end of a word, add the character of the child to the results
            if(child->IsEndOfWord() == true){
                // converting to string
                std::string s;
                s = s + child_char;
                results.push_back(s); 
            }
        }
    }
    return results;
}

// function to return all keys with given prefix
std::vector<std::string> Trie::return_from_prefix(std::string prefix){
    // initialize vector to hold the keys that have the provided prefix
    std::vector<std::string> results;

    // set current node
    Trienode* current_node = root;

    // loop through each character of the prefix
    for (int i = 0; i<prefix.length(); i++){
        // get corressponding index of the character
        int character_index = prefix[i] - 97;
        // see if the current node has a child at that index (that isn't a nullptr)
        Trienode* child = current_node->getchildren()[character_index];
        if(child != nullptr){
            // set the child node to be the current node
            current_node = child;
        }else{
            // prefix doesn't exist
            // return the empty vector
            return results;
        }
    }
    // current_node is the node representing the last character of the prefix
    // if the current_node is the end of a word, add the prefix to the results
    if (current_node->IsEndOfWord() == true){
        results.push_back(prefix);
    }
    // use the return_all_keys function to get vector with all keys from current_node
    std::vector<std::string> all_keys_results = return_all_keys(current_node);

    // for each key in the returned results, add the given prefix and add to results vector
    for(auto key : all_keys_results){
        results.push_back(prefix + key);
    }

    return results;
}

// function to return the address of the node that represents the last
// char of a key that matches in the trie 
// eg. if "abcd" is in trie, with input "abcde" it returns address of node
// corresponding to d
Trienode* Trie::return_address_from_key(std::string key){
    // set current node
    Trienode* current_node = root;

    // loop through each character of the key
    for (int i = 0; i<key.length(); i++){
        // get corressponding index of the character
        int character_index = key[i] - 97;
        // see if the current node has a child at that index (that isn't a nullptr)
        Trienode* child = current_node->getchildren()[character_index];
        if(child != nullptr){
            // set the child node to be the current node
            current_node = child;
        }else{
            // last char to match the key was the char represented by current node
            // therefore return address of current node
            return current_node;
        }
    }

    // entire key is in the trie
    // and current node represents the last character of the key
    // return current node
    return current_node;
}

// function to return the address of the node that represents the last
// char of a key that is added to the trie
Trienode* Trie::return_address_from_inserted_key(std::string key){
    // set current node
    Trienode* current_node = root;

    // loop through all characters in the key
    for (int i = 0; i  < key.length(); i++){
        // for each character in the key, get its relative index
        // for example a has the index 0, and b has 1
        int character_index = key[i] - 97; //take 97 because 
        
        // get the child of the current node at the character_index
        Trienode* child_at_index = current_node->getchildren()[character_index];

        // check to see if the current node has a child at the character_index
        if (child_at_index != nullptr){
            // it does have child
            // set current node to be child node
            current_node = child_at_index;
        }else{
            // it doen't have a child at the given index
            // create a new child node
            Trienode* new_child = new Trienode;
            // add new child node to the given index for the current node
            current_node->setchild(new_child, character_index);
            // set current node to the new child node
            current_node = new_child;
        }
    }
    // change the last node to be the end of the word
    current_node->setEndofWord(true);

    // return the address of the last node
    return current_node;
}