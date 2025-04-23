#include "armstrong_numbers.h"
#include <string>
#include <cmath>

namespace armstrong_numbers {

// TODO: add your solution here
bool is_armstrong_number(int n){
    // calculate count of digits
    std::string str = std::to_string(n);
    int digits = str.size();

    // calculate the sum
    int sum{0};
    for(char c : str) {
        sum += std::pow(c - '0', digits);
    }
    
    return n == sum;
}
}  // namespace armstrong_numbers
