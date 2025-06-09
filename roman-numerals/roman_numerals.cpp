#include "roman_numerals.h"

namespace roman_numerals {
    std::map<int, std::string, std::greater<int> > roman{
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9,"IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

    std::string convert(int n){
        std::string result{""};
            for(auto item : roman){
                while(item.first <= n){
                    result += item.second;
                    n -= item.first;
                }
            }
        return result;
    }
}  // namespace roman_numerals
