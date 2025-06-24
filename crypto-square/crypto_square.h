#pragma once
#include <string>
#include <cmath>
#include <vector>

namespace crypto_square {

// TODO: add your solution here

class cipher{
    private:
        std::vector<std::vector<char>> _v;
        int _n_x, _n_y;
    public:
        cipher(std::string text);
        std::string normalized_cipher_text();
};

}  // namespace crypto_square
