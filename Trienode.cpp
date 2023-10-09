#include "Trienode.h"
#include <iostream>

Trienode::Trienode(){};

bool Trienode::IsEndOfWord(){
    return EndOfWord;
}

void Trienode::setEndofWord(bool end){
    EndOfWord = end;
}

Trienode** Trienode::getchildren(){
    return children;
}

void Trienode::setchild(Trienode* new_child, int index){
    // set child at index to new child
    children[index] = new_child;
}


// int main(void){
//     Trienode Node1;
//     Trienode Node2;
//     std::cout << &Node1 << "\t" << &Node2 << std::endl;

//     Trienode** children = Node1.getchildren();
//     for (int i = 0; i < 26; i++){
//         std::cout << i << "\t" <<children[i] << std::endl;
//     }
    
//     Node1.setchild(&Node2, 0);
//     children = Node1.getchildren();
//     for (int i = 0; i < 26; i++){
//         std::cout << i << "\t" <<children[i] << std::endl;
//     }
//     return 0;
// }