#include "armstrong_numbers.h"
#include <cmath>

namespace armstrong_numbers {

// TODO: add your solution here
bool is_armstrong_number(int n){
    // calculate count of digits
    int m = n;
    int digits{0};
    do {
        m /= 10;
        digits++;
    } while (m);

    // calculate the sum
    m = n;
    int sum{0};
    while(m){
        sum += std::pow(m % 10, digits);
        m /= 10;
    }
    return n == sum;
}
}  // namespace armstrong_numbers
