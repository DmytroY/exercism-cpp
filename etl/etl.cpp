#include "etl.h"

namespace etl {

// TODO: add your solution 
std::map<char, int> transform(std::map<int, std::vector<char>> old) {
    std::map<char, int> result{};

    for(auto it = old.begin(); it != old.end(); it++) {
        for(char c : it->second){
            result.insert({c + 32, it->first});
        }
    }
    return result;
}

}  // namespace etl
