#include "crypto_square.h"

namespace crypto_square {

// TODO: add your solution here

cipher::cipher(std::string arg){
    
    // normalize
    std::string text;
    for(char c : arg) {
        if( !isalnum(c) ) continue;
        text += tolower(c);   
    }

    // resize 2D vector to store result
    int size = text.size();
    _n_x = ceil(sqrt(size));
    _n_y = _n_x;
    if(_n_x && (_n_x * (_n_x - 1) >= size)) _n_y--;
    _v.resize(_n_y, std::vector<char>(_n_x));

    // store to 2D vector
    int i{0};
    for(int y = 0; y < _n_y ; y++){
        for(int x = 0; x < _n_x; x++){
            if(i < size){
               _v[y][x] = text[i]; 
            } else {
                _v[y][x] =' ';
            }
            i++;
        }
    }
}

std::string cipher::normalized_cipher_text() {
    std::string result;
    for(int x = 0; x < _n_x; x++){
        for(int y = 0; y < _n_y ; y++){
            result += _v[y][x];
        }
        if(x < _n_x - 1) result += ' ';
    }
    return result;
}

}  // namespace crypto_square
