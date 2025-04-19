#include "sieve.h"

namespace sieve {

// TODO: add your solution here
    std::vector<int> primes(int max) {
        // create vector of prime flags
        std::vector<bool> flags(max + 1, true);
        //not primes by default
        flags[0] = false; 
        flags[1] = false;

        for(int i = 2; i <= max; i++) {mp[i] = true;}

        //sieve of Eratosthenes implementation
        std::vector<int> primes;  
        for(int i = 2; i <= max; i++) {
            // skip if marked as not prime
            if(!mp[i]) continue;
            // reset all future divisible members
            for(int k = i * i; k <= max; k = k + i) {mp[k] = false;}
            // save that prime
            primes.push_back(i);
        }
        return primes;
    }
}  // namespace sieve
