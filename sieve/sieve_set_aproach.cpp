#include "sieve.h"
#include <set>
#include <algorithm>

namespace sieve {

// TODO: add your solution here
    std::vector<int> primes(int max) {
        // set of all numbers
        std::set<int> all;
        for(int i = 2; i <= max; i++) {all.insert(i);}
        
        // set of composite numbers
        std::set<int> composite{};
        for(int i = 4; i <= max; i++){
            for(int k = 2; k <= i / 2; k++){
                if(i % k == 0) {composite.insert(i);}
            }
        }

        // substract set all - set composite -> vector primes
        std::vector<int> primes;
        std::set_difference(all.begin(), all.end(),
                            composite.begin(), composite.end(),
                        std::back_inserter(primes));
        return primes;
    }
}  // namespace sieve
