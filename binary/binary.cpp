#include "binary.h"

namespace binary {

// TODO: add your solution here
// 10
// l = 2
// i = 0, text[2-0-1] = 0




    int convert(std::string text){
        int result{0};
        int l = text.length();
        for(int i = 0; i < l; i++){
            if(!isdigit(text[l - i - 1])) return 0;
            if(text[l - i - 1] == '1') result += pow(2, i);
        }
        return result;
    }
}  // namespace binary
