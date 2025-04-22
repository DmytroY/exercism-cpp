#include "atbash_cipher.h"

namespace atbash_cipher {

// TODO: add your solution here
    std::string encode(std::string text){
        text = decode(text);
        for(unsigned i = 5; i < text.size(); i +=6){
            text.insert(i, " ");
        }
        return text;
    }

    std::string decode(std::string text) {
        std::string result;
        for(char c : text){
            if(isalnum(c)){
                if(isalpha(c)) {
                    int asciiCodedValue = 219 - (int)tolower(c); // code a->z, z->a
                    c = (char)asciiCodedValue;
                }
                result.push_back(c);
            }
        }
        return result;
    }
}  // namespace atbash_cipher
