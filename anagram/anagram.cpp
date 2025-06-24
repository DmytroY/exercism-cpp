#include "anagram.h"

namespace anagram {

// TODO: add your solution here

std::map<char, int> mapit(const std::string& text){
    std::map<char, int> map;
    for(char c : lowerit(text)){ map[c] = map[c] + 1; }
    return map;
}

std::string lowerit(std::string s){
    std::transform(s.begin(), s.end(), s.begin(), ::tolower );
    return s;
}

anagram::anagram(std::string word) : _word(word), _map(mapit(word)) { }

std::set<std::string> anagram::matches(std::set<std::string> candidates){
    std::set<std::string> result;
    for(auto word : candidates){
        auto temp_map = mapit(word);
        if(temp_map == _map && lowerit(word) != lowerit(_word)) result.insert(word);
    }
    return result;
} 

}  // namespace anagram
