#ifndef TRIENODE
#define TRIENODE

class Trienode{
    private:
        // value to check if this is the end of the word
        bool EndOfWord = false;
        // list of children, made an array, because letters are accessed by index according to lecture
        // for example a will be at index 1
        // length is predifined as 26 because I have assumed only the letters a-z are being used, for other cases this would be changed
        // no dynamic array, because the letters are accessed by index (according to lectures), so a child node at index 0 represents a 
        // and child node at index 25 represents z
        Trienode* children[26] = {nullptr};
    public:
        // constructor function
        Trienode();
        // check if this is the end of the word
        bool IsEndOfWord();
        // set/unset node as "end of word"
        void setEndofWord(bool end);
        // return array of children
        Trienode** getchildren();
        // change the child at provided index to the new child
        void setchild(Trienode* new_child, int index);
};

#endif