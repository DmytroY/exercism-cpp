#include "perfect_numbers.h"

namespace perfect_numbers {
    classification classify(int n){
        if(n < 1) throw std::domain_error("argument should be > 0");
        int aliquot_sum{0};
        for(int i = 1; i <= n/2; i++){
            if(n % i == 0) aliquot_sum += i;
        }
        if(n < aliquot_sum) return classification::abundant;
        if(n > aliquot_sum) return classification::deficient;
        return classification::perfect;
    }
}  // namespace perfect_numbers
