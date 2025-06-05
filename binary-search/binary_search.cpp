#include "binary_search.h"

namespace binary_search {

// TODO: add your solution here
std::size_t find(std::vector<int> data, int value){
    std::size_t shift{0};
    while(data.size()){
        std::size_t i = data.size() / 2;
        if(data[i] == value) return i + shift;
        if(data[i] < value ) {
            // delete left
            data.erase(data.begin(), data.begin() + i + 1);
            shift += (i + 1);
        } else {
            // delete rigth
            data.erase(data.begin() + i, data.end());
        }
    }
    
    throw std::domain_error("Value not found");
}
}  // namespace binary_search
