#include "matching_brackets.h"

namespace matching_brackets {

// TODO: add your solution here
    bool check(std::string text){
        // brackets [], braces {}, parentheses ()
        const std::vector<char> opening{ '[', '{', '(' };
        const std::vector<char> closing{ ']', '}', ')' };
        std::stack<char> my_stack{};

        for(char c : text){
            // c is in the opening
            if(find(opening.begin(), opening.end(), c) != opening.end()) {
                my_stack.push(c);
            } 

            // c is in the closing
            auto it = find(closing.begin(), closing.end(), c);
            if(it != closing.end()) {
                //check if closing brackets correspond opening brackets in the stack
                int index = std::distance(closing.begin(), it);
                if(my_stack.empty() || opening[index] != my_stack.top()) {
                    return false;
                } else {
                    my_stack.pop();
                }
            }

        }
        return my_stack.empty();
    }
    
}  // namespace matching_brackets
