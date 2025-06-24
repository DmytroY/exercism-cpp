#pragma once
#include <string>
#include <set>
#include <map>
#include <algorithm>

namespace anagram {

// TODO: add your solution here
std::map<char, int> mapit(const std::string& text);
std::string lowerit(std::string s);

class anagram{
    private:
        std::string _word;
        std::map<char, int> _map;

    public:
        anagram(std::string);
        std::set<std::string> matches(std::set<std::string>);        
};
}  // namespace anagram
