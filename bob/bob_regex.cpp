#include "bob.h"
#include <regex>
#include <algorithm>

namespace bob {

// TODO: add your solution here
std::string hey(std::string text){

    // remove all space-like characters
    text.erase(std::remove_if(text.begin(), text.end(), ::isspace), text.end());

    // only uppercase lettes and '?' at the end
    if(std::regex_match(text, std::regex("(?=.*[A-Z])^[^a-z]*\\?$"))) return "Calm down, I know what I'm doing!";

    // only uppercase lettes
    if(std::regex_match(text, std::regex("(?=.*[A-Z])^[^a-z]*$"))) return "Whoa, chill out!";

    if(text.size() == 0) return "Fine. Be that way!";

    if(text.back() == '?') return "Sure.";
    
    return "Whatever.";
}
}  // namespace bob
