#ifndef AFFINE_CIPHER_H
#define AFFINE_CIPHER_H
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cmath>

namespace affine_cipher {



// TODO: add your solution here
const unsigned m{26}; //the length of the alphabet
void valid(const unsigned& a);
unsigned mmi(const unsigned& a, const unsigned& m);

std::string encode(const std::string& text, const unsigned& a, const unsigned& b);
std::string decode(const std::string& code , const unsigned& a, unsigned b);

}  // namespace affine_cipher

#endif  // AFFINE_CIPHER_H
