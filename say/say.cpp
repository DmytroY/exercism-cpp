#include "say.h"
#include <iostream>

namespace say {

// TODO: add your solution here
std::string helper(long long int n){
    std::vector<std::string> ones{"zero","one","two","three","four","five","six","seven","eight","nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
    std::vector<std::string> tens{"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    std::string result;

    // hundreds
    if(n > 99) {
        if(n % 100 == 0) return ones[n/100] + " hundred";
        result = ones[n/100] + " hundred ";
    }
    
    // tens. i.e. 123 -> 23
    n = n - (n/100)*100;
    if(n > 0 && n < 20) return result + ones[n];
    if(n % 10 == 0) return result + tens[n/10];
    result = result + tens[n/10] + "-";

    // ones. 233-> 3
    n = n - (n/10)*10;
    if(n) result = result + ones[n];
    return result;
}

std::string in_english(long long int n) {
    // out of range
    if(n < 0 || n >= 1e12) throw std::domain_error("out of range");
    
    // zero
    if(!n) return "zero";
    
    std::string result{""};
    // bil
    if(n >=1e9) {
        if(n - static_cast<long long int>(n / 1e9) * 1e9 == 0) return helper(n / 1e9) + " billion";
        result = helper(n/1e9) + " billion ";
        n = n - static_cast<long long int>(n / 1e9) * 1e9; // 1 234 342 345 -> 234 342 345 
    }

    // mil
    if(n >= 1e6) {
        if(n - static_cast<int>(n / 1e6) * 1e6 == 0) return result + helper(n / 1e6) + " million";
        result = result  + helper(n/1e6) + " million ";
        n = n - static_cast<int>(n / 1e6) * 1e6; // 234 342 345  -> 342 345 
    }

    // thousand
    if(n >= 1e3) {
        if(n-static_cast<int>(n/1e3)*1e3 == 0) return result + helper(n/1e3) + " thousand";
        result = result + helper(n/1e3) + " thousand ";
        n = n - static_cast<int>(n / 1e3) * 1e3; // 342 345  -> 345
    }
    return result + helper(n);
}

}  // namespace say
