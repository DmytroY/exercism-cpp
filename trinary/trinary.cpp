#include "trinary.h"

namespace trinary {

// TODO: add your solution here
int to_decimal(std::string text) {
    int result{0};
    std::set allowed{'0', '1', '2'};
    int weight{1};

    while(text.size() > 0) {
        // check that character is in allowed range
        if(!allowed.count(text.back())) return 0;
        result += weight * (text.back() - '0');
        text.pop_back();
        weight *= 3;
    }
    return result;
}
}  // namespace trinary
