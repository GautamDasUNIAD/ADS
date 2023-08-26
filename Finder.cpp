#include "Finder.h"

using namespace std;
vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    int none_found = 0; //becomes 1 when no substring was found
    for(size_t i = 1; i <= s2.size(); i++) {
        
        size_t found;
        if (none_found == 1){
            result.push_back(-1);
        }


        if (i > 1){
            found = s1.find(s2.substr(0, i), result[i-2]);
        }
        else{
            found = s1.find(s2.substr(0, i));
        }

        if (found != string::npos) {
            result.push_back(found);
        } else {
            result.push_back(-1);
        }
    }
    
    return result;
}
