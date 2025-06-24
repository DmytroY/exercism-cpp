#pragma once
#include <string>
#include <set>
#include <map>
#include <algorithm>

namespace anagram {

// TODO: add your solution here
std::string lowerit(std::string s);
unsigned hashit(std::string s);

class anagram{
    private:
        unsigned _hash;
        std::string _word;

    public:
        anagram(std::string);
        std::set<std::string> matches(std::set<std::string>);        
};
}  // namespace anagram
