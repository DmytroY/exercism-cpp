#include "run_length_encoding.h"
#include <cmath>
#include <algorithm>

namespace run_length_encoding {

std::string encode(const std::string& text){
    if(text.size() < 2) return text;
    std::string result;
    result.reserve(text.size());
    unsigned count{1};
    for(size_t i = text.size() - 1; i > 0; i--){
        if( text[i] == text[i - 1]){
            count++;
        } else {
            result.push_back(text[i]);
            if(count > 1){
                std::string count_str = std::to_string(count);
                reverse(count_str.begin(), count_str.end()); 
                result += count_str;
            }
            count = 1;
        }
    }
    result.push_back(text[0]);
    if(count > 1){
        std::string count_str = std::to_string(count);
        reverse(count_str.begin(), count_str.end()); 
        result += count_str;
    } 
    reverse(result.begin(), result.end());
    return result;
}

std::string decode(const std::string& text){
    std::string result;
    unsigned multiplier{1};
    unsigned position{0};
    char ll;
    for(int i = text.size() - 1; i >= 0; i--){
        if(isdigit(text[i])){
            multiplier += (text[i] - '0') * pow(10, position);
            position++;
            
        } else {
            if(multiplier > 1){
                for(unsigned k = 2; k < multiplier; k++){
                    result.push_back(ll);
                }
                multiplier = 1;
                position = 0;
            }
            ll = text[i];
            result.push_back(ll);
        }
    }
    if(multiplier > 1){
        for(unsigned k = 2; k < multiplier; k++){
            result.push_back(ll);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

}  // namespace run_length_encoding
