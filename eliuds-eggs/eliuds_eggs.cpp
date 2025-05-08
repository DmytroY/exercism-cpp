#include "eliuds_eggs.h"
#include <bitset>
#include <cmath>

namespace chicken_coop {

// TODO: add your solution here

// === variant 1. bitset
// int positions_to_quantity(int d){
//     std::bitset<4*8> d_bs(d);
//     return d_bs.count();
// }

// === variant 2. bitwise comparison
// int bits_needed(int n){
//     if(n < 0) return 0;
//     return log2(n) + 1;
// }
// int positions_to_quantity(int n){
//     int sum{0};
//     for(int i = 0; i < bits_needed(n); i++) {
//         if(n & (1<<i)) sum++;
//     }  
//     return sum;
// }

// === variant 3. 

// find maximum value of binary progression (1, 2, 4, 8, 16 ...) which is still <= n
int max_pow2k (int n){
    if(n < 1) return 0;
    return std::pow(2, static_cast<int>(log2(n)));
}
int positions_to_quantity(int n){

    int count{0};
    while (n > 0){
        n = n - max_pow2k(n);
        count++;
    }
    return count;
}




}  // namespace chicken_coop
