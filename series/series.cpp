#include "series.h"

namespace series {

// TODO: add your solution here
    std::vector<std::string> slice(std::string text, int n){
        //("9142", 2) -> {"91", "14", "42"}
        int l = text.length();
        if(l < n || n < 1) throw std::domain_error("wrond arguments");
        std::vector<std::string> result{};
        for(int i = 0; i <= l - n; i++) {
            result.push_back(text.substr(i, n));
        }
        return result;
    }
}  // namespace series
