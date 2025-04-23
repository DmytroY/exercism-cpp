#include "bob.h"
#include <regex>
#include <algorithm>

namespace bob {

// TODO: add your solution here
std::string hey(std::string text){
    bool isquestion{false};
    bool isallupper{false};

    // remove all space-like characters
    text.erase(std::remove_if(text.begin(), text.end(), ::isspace), text.end());
    
    if(text.size() == 0) return "Fine. Be that way!";
    if(text.back() == '?') isquestion = true;

    for(char c : text){
        if(isupper(c)) isallupper = true;
        if(islower(c)){
            isallupper = false;
            break;
        }
    }

    if(isquestion){
        if(isallupper) return "Calm down, I know what I'm doing!";
        return "Sure.";
    }
    if(isallupper) return "Whoa, chill out!";    
    return "Whatever.";
}
}  // namespace bob
