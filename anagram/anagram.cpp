#include "anagram.h"

namespace anagram {

// TODO: add your solution here

std::string lowerit(std::string s){
    std::transform(s.begin(), s.end(), s.begin(), ::tolower );
    return s;
}

unsigned hashit(std::string s){
    s = lowerit(s);
    unsigned hash;
    for(char c : s) {
        hash += c * 1.5;
    }
    return hash;
}

anagram::anagram(std::string word) : _hash(hashit(word)), _word(lowerit(word)) { }

std::set<std::string> anagram::matches(std::set<std::string> candidates){
    std::set<std::string> result;
    for(auto word : candidates){
        if(hashit(word) == _hash && lowerit(word) != _word){
            result.insert(word);
        }
    }
    return result;
}  

}  // namespace anagram
