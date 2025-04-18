#include "nth_prime.h"

namespace nth_prime {

// TODO: add your solution here
unsigned nth(unsigned n) {
    if(n == 0) throw std::domain_error("argument should be > 0");
    if(n == 1) return 2;
    std::vector<int> primes = {2, 3, };
    unsigned candidate = 3;
    int is_prime = 0;
    while(primes.size() < n){
        is_prime = 1;
        candidate += 2;
        for(auto item : primes) {
            if(candidate % item == 0) {
                is_prime = 0;
                break;
            }
        }
        if(is_prime) primes.push_back(candidate);
    }
    return primes.back();
}

}  // namespace nth_prime
