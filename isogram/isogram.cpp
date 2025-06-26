#include "isogram.h"

namespace isogram {

// TODO: add your solution here
bool is_isogram(std::string text){
    std::map<char,int> map;
    for(char c : text){
        c = tolower(c);
        if(!isalnum(c)) continue;
        if(map[c]) return false;
        map[c] = 1;
    }
return true;
}
}  // namespace isogram
