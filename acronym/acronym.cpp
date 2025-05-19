#include "acronym.h"

namespace acronym {

// TODO: add your solution here

std::string acronym(std::string text) {
    std::string acr{};
    bool first{true};
    for(char c : text){
        if(c == static_cast<char>(39)) continue;
        if(isalpha(c) && first) {
            acr += toupper(c);
            first = false;
        }
        if(!isalpha(c)) {
            first = true;
        }
    }
    return acr;
}

}  // namespace acronym
