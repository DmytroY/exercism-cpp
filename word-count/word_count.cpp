#include "word_count.h"

namespace word_count {

// TODO: add your solution here
// Then: don't\ncry. javascript!!&@$%^&, 1, 2
// Then don't cry javascript 1 2

std::map<std::string, int> words(std::string text){
    std::map<std::string, int> result;
    std::string temp_str;
    for(unsigned i = 0; i < text.size(); i++){
        char c = text.at(i);
        if(c == 39 && (i == 0 || i == text.size() -1 || !isalnum(text.at(i-1)) || !isalnum(text.at(i+1)))) continue;

        if((c >= 'a' && c <= 'z') ||
            (c >='A' && c <= 'Z') ||
            (c >= '0' && c <= '9') ||
            c == 39){
            temp_str += tolower(c);
        } else {
            
            if(temp_str.size()){
                result[temp_str] += 1;
                temp_str = "";
            } 
        }  
    }
    if(temp_str.size()) result[temp_str] += 1;
return result;
}
}  // namespace word_count
