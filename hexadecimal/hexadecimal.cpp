#include "hexadecimal.h"

namespace hexadecimal {

// TODO: add your solution here
int convert(std::string str) {
	int result{0};
	for(int i = str.length() - 1; i >= 0; i--) {
		if(isalpha(str[i])){
			if(str[i] < 97 || str[i] > 102) return 0;
			result += (str[i] - 87) * pow(16, str.length() - 1 - i);
		} else {
			result += (str[i] - '0') * pow(16, str.length() - 1 - i);
		}
	}
	return result;
}
}  // namespace hexadecimal
