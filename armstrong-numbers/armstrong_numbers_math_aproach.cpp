#include "armstrong_numbers.h"
#include <cmath>

namespace armstrong_numbers {

// TODO: add your solution here

// 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
bool is_armstrong_number(int n){
    // calculate count of digits
    int m = n;
    int digits{0};
    do {
        m /= 10;
        digits++;

    
    } while (m);

    m = n;
    int result{0};
    while(m){
        result += std::pow(m % 10, digits);
        m /= 10;
    }

    
    return n == result;
}
}  // namespace armstrong_numbers
