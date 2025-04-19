#include "nth_prime.h"
#include <algorithm>

namespace nth_prime {

// TODO: add your solution here
unsigned nth(unsigned n) {
    if(n == 0) throw std::domain_error("argument should be > 0");

    std::vector<int> primes = {2,};
    unsigned candidate = 1;
    // int is_prime = 0;

    while(primes.size() < n){
        candidate += 2;
        if(std::find_if(primes.begin(), primes.end(), [candidate](int element){return candidate % element == 0;}) == primes.end()){
            primes.push_back(candidate);
        }
    }

    // while(primes.size() < n){
    //     is_prime = 1;
    //     candidate += 2;
    //     for(auto item : primes) {
    //         if(candidate % item == 0) {
    //             is_prime = 0;
    //             break;
    //         }
    //     }
    //     if(is_prime) primes.push_back(candidate);
    // }
    return primes.back();
}

}  // namespace nth_prime
