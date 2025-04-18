#include "collatz_conjecture.h"

namespace collatz_conjecture {

// TODO: add your solution here
unsigned steps(int n){
    if(n < 1) throw std::domain_error(" argument should be > 0");
    unsigned counter = 0;
    while(n != 1) {
        if(n%2) {
            n = n * 3 + 1;
        } else {
            n = n / 2;
        }
        counter++;
    }
    return counter;
}

}  // namespace collatz_conjecture
