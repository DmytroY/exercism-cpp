#include "twelve_days.h"

namespace twelve_days {

// TODO: add your solution here
std::string chunk(const int& n){
    std::string result = "On the " + numerals[0][n] + " day of Christmas my true love gave to me: ";
    for(int i = n; i > 0; i--){
        result = result.append(numerals[1][i]);
    }
    return result + "\n";
}

std::string recite(const int& first, const int& last){
    std::string result{};
    for(int n = first; n <= last; n++){
        result = result + chunk(n) + "\n";
    }
    result.pop_back();
    return result;
}

}  // namespace twelve_days
