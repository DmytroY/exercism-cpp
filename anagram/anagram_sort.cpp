#include "anagram.h"

namespace anagram {

// TODO: add your solution here

std::string lowerit(std::string s){
    std::transform(s.begin(), s.end(), s.begin(), ::tolower );
    return s;
}

std::string lsortit(std::string s){
    s = lowerit(s);
    std::sort(s.begin(), s.end());
    return s;
}

anagram::anagram(std::string word) : _sorted(lsortit(word)), _word(lowerit(word)) { }

std::set<std::string> anagram::matches(std::set<std::string> candidates){
    std::set<std::string> result;
    for(auto word : candidates){
        if(lsortit(word) == _sorted && lowerit(word) != _word){
            result.insert(word);
        }
    }
    return result;
}  

}  // namespace anagram
