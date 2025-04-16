#include "hamming.h"
#include <stdexcept>

namespace hamming {

// TODO: add your solution here
int compute(std::string a, std::string b) {
    if(a.length() != b.length()) throw std::domain_error("arguments should have same length");
    if(a == b) return 0;

    int counter = 0;
    for(unsigned i = 0; i < a.length(); i++) {
        if(a[i] != b[i]) counter++;
    }
    return counter;
}

}  // namespace hamming
