#include "isbn_verifier.h"

namespace isbn_verifier {

// TODO: add your solution here

bool is_valid(std::string s){
    int i{10};
    int sum{0};
    for(char c : s){
        if(c == '-') continue;
        if(c == 'X' && i != 1) return false;
        if(c == 'X') {
            sum = sum + 10;
        } else {
            sum = sum + (c - '0') * i;
        }
        i--;
    }
    if( sum % 11 == 0 && i == 0) return true;
    return false;
}

}  // namespace isbn_verifier
