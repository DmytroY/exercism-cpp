#include "largest_series_product.h"
#include <stdexcept>

namespace largest_series_product {

unsigned largest_product(std::string input, unsigned span){
    if(span > input.size()) throw std::domain_error("span can't be greater than input length");
    //sliding window
    unsigned result{0}, product{1};
    for(unsigned i = 0; i <= input.size() - span; i++){
        product = 1;
        for(unsigned j = i; j < i + span; j++){
            char c = input[j];
            if (!isdigit(c)) throw std::domain_error("only digits allowed in input string");
            product *= (c - '0');
        }
        if(product > result) result = product;
    }
    return result;
}

}  // namespace largest_series_product
