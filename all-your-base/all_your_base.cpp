#include "all_your_base.h"

namespace all_your_base {

// TODO: add your solution here
std::vector<unsigned int> convert(unsigned int in_base, std::vector<unsigned int> in_digits, unsigned int out_base){
    // invalid arguments
    if( in_base < 2 || out_base < 2) { throw std::invalid_argument("invalid_argument");}

    for(auto item: in_digits){
        if(item >= in_base) { throw std::invalid_argument("invalid_argument");}
    }

    // convertion is no needed
    if(in_base == out_base) {return {in_digits};}

    // convertion
    std::vector<unsigned int> out_digits;
    unsigned int base10{0};
    // step 1, convert to base10
    for(unsigned int i = 0; i < in_digits.size(); i++) {
        base10 += in_digits[in_digits.size() - 1 - i] * std::pow(in_base, i);
    };
    // step 2, convert to out_base
    while (base10 > 0){
        out_digits.insert(out_digits.begin(), base10 % out_base);
        base10 /= out_base;
    }
    return out_digits;
}
    
}  // namespace all_your_base
