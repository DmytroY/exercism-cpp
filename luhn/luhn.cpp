#include "luhn.h"
#include <regex>
#include <iostream>

namespace luhn {

// TODO: add your solution here
bool valid(std::string card_num){
    // get rid of spaces
    card_num = std::regex_replace(card_num, std::regex(" "), "");

    // // length 1 or less are not valid
    // int len = card_num.length();
    // if(len < 2) return false;

    int sum{0};
	bool iseven{false};
    for(int i = (card_num.length() - 1); i >= 0; i--) {
        // non-numeric is not alowed
        if(!isdigit(card_num[i])) return false;

		if(iseven){
			int n2 = 2 * (card_num[i] - '0');
			if(n2 <= 9) {
				sum += n2;
			} else {
				sum += (n2 - 9);
			}
		} else {
			sum += (card_num[i] - '0');
		}
		iseven = !iseven;
	}

	return !(sum % 10) && card_num.length() > 1;
}
}  // namespace luhn