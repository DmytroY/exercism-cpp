#if !defined(GRAINS_H)
#define GRAINS_H
#include <cmath>

namespace grains {

// TODO: add your solution here
inline unsigned long long int square(int n) {
    return pow(2, n-1);
}

// recursive aproach
// inline unsigned long long int square(int n) {
//     if(n == 1) {
//         return 1;
//     } else {
//         return 2 * square(n -1);
//     }

// }

inline unsigned long long int total() {
    unsigned long long int sum = 0;
    for(int n = 1 ; n <= 64 ; n++) {
        sum = sum + square(n);
    }
    return sum;
}

}  // namespace grains

#endif  // GRAINS_H