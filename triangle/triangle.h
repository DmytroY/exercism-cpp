#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include <stdexcept>

namespace triangle {
// TODO: add your solution here
enum flavor {
    equilateral,
    isosceles,
    scalene
};

inline bool is_exist(double a, double b, double c) {
    if( a > b + c || b > a + c || c > a + b || a * b * c == 0){
        return false;
    }
    return true;
}

inline flavor kind(double a, double b, double c) {
    if(is_exist(a, b, c)) {
        if(a == b && a == c) { return equilateral;}
        if(a == b || a == c || b ==c) { return isosceles;}
        return scalene;
    } else {
        throw std::domain_error("Invalid triangle");
    }
}


}  // namespace triangle

#endif  // TRIANGLE_H