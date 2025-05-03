#include "rotational_cipher.h"

namespace rotational_cipher {

// TODO: add your solution here
char code(char c, int k) {
    k = k % 26; // to be sure k is in range 0...25

    if(isupper(c)){
        c += k;
        if(c > 90 ) c -= 26;
    } else {
        // maximum char value is 127 and can be our of range after adding k to lovercase char
        int ascii = static_cast<int>(c) + k;
        if(ascii > 122 ) ascii -= 26;
        c = static_cast<char>(ascii);
    }
    return c;
}

std::string rotate(std::string text, int k){
    std::string result{""};
    for(char c : text){
        if(isalpha(c)) {
            result += code(c, k);
        } else {
            result += c;
        }
    }
    return result;
}

}  // namespace rotational_cipher
