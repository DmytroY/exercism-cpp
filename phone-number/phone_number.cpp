#include "phone_number.h"

namespace phone_number {

// TODO: add your solution here
    phone_number::phone_number(std::string text){
        for(char c : text){
            if((__number.length() == 0 || __number.length() == 3) && (c == '1' || c == '0')) continue;
            if(isdigit(c)) {
                __number += c;
            }
        }
        if(__number.length() != 10) throw std::domain_error("wrong phone number format");
    }

    std::string phone_number::number() const {
        return __number;
    }

}  // namespace phone_number
