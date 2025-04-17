#include "nucleotide_count.h"

namespace nucleotide_count {

// TODO: add your solution here
    std::map<char, int> count(std::string seq) {
        std::map<char, int> result = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
        for(char c : seq) {
            auto it = result.find(c);
            if(it == result.end()){
                throw std::invalid_argument("invalid_nucleotide");
            }
            result[c]++;               
            } 
        return result;
    }
}  // namespace nucleotide_count
