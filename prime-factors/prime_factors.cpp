#include "prime_factors.h"
#include <iostream>
#include <cmath>

namespace prime_factors {

  bool isprime(long long candidate) {
    if(candidate < 2) return false;
    if(candidate == 2) return true;
    bool isprime{true};
    for(long long d = 3; d <= std::sqrt(candidate); d += 2){
      if(candidate % d == 0) isprime = false;
    }
    return isprime;
  
  }
  long long next(long long prime) {
    if(prime == 2) return 3;
    do {
      prime += 2;
    } while(!isprime(prime));
    
    return prime;
  }
  
  std::vector<long long> of(long long n){
  
    std::vector<long  long> result{};
    long long prime{2};
  
    while(n > 1){
      if(n % prime == 0) {
        result.push_back(prime);
        n /= prime;
      } else {
        prime = next(prime);
      }
    }
  
    return result;
  }
}  // namespace prime_factors
