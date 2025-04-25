#include "prime_factors.h"
#include <iostream>

namespace prime_factors {

  long long next(long long d) {
    if(d == 2) return 3;
    return d + 2;
  }
  
  std::vector<long long> of(long long n){
    std::vector<long  long> result{};
    long long divisor{2};
  
    while(n > 1){
      if(n % divisor == 0) {
        result.push_back(divisor);
        n /= divisor;
      } else {
        divisor = next(divisor);
      }
    }
  
    return result;
  }
}  // namespace prime_factors
