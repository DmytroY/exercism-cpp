
#include "affine_cipher.h"

namespace affine_cipher {

// TODO: add your solution here

void valid(const unsigned& a){
    
    if(std::__gcd(a, m) > 1) throw std::invalid_argument("invalid argument");
}

unsigned mmi(const unsigned& a, const unsigned& m){
    // finding modular multiplicative inverse of a under modulo m
    for(unsigned x = 1; x < m; x++){
        if((a * x) % m == 1) return x;
    }
    return 0;
}

std::string encode(const std::string& text, const unsigned& a, const unsigned& b){
    
    valid(a);// initial arguments validation

    // preprocessing
    std::string text_n{};
    for(char c : text){
        if(isalnum(c)){
            text_n.push_back(tolower(c));
        }
    }

    // encoding
    std::string result{};
    int i; // letter index in alphabet
    int j; // encripted letter index;
    int n{-1}; // counter
    for(char c : text_n){
        n++;
        if (n && n % 5 == 0){
            result.push_back(' ');  
        }         

        if(isdigit(c)){
            result.push_back(c);
            continue;
        }
        i = c - 'a';
        j = (a * i + b) % m;
        result.push_back('a' + j);
    }
    return result;
}

std::string decode(const std::string& code , const unsigned& a, unsigned b){
    
    valid(a); // initial arguments validation

    // preprocessing
    std::string text{};
    for(char c : code){
        if(isalnum(c)){
            text.push_back(tolower(c));
        }
    }

    // D(y) = (a^-1)(y - b) mod m
    // (a^-1) is the modular multiplicative inverse (MMI) of a mod m
    // y is numeric value of an encrypted letter
    b %= m;
    for(size_t i = 0; i < text.size(); i++){
        if(isdigit(text[i])) continue;
        text[i] = (mmi(a, m)*(text[i] - 'a' - b + m)) % m + 'a';
    }
    return text;

}

}  // namespace affine_cipher
