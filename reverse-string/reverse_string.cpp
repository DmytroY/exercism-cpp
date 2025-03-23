#include "reverse_string.h"

namespace reverse_string {

//var 1. traverse back to front
// std::string reverse_string(std::string text) {
//     std::string result = "";
//     for(int i = text.length() - 1; i >= 0 ; i--) {
//         result += text[i];
//     }
//     return result;
// }

//var 2. traverse front to back
// std::string reverse_string(std::string text) {
//     std::string result = "";
//     for(unsigned i = 0; i < text.length(); i++) {
//         result = text[i] + result;
//     }
//     return result;
// }

//var 3. "reverse" function from  <algorithm>
// std::string reverse_string(std::string text) {
//     reverse(text.begin(), text.end());
//     return text;
// }

//var 4. swap in place
// std::string reverse_string(std::string text) {
//     for (unsigned i = 0; i < text.length()/2; i++){
//         std::swap(text[i], text[text.length() - 1 - i]);
//     }
//     return text;
// }

//var 5. using stack
// std::string reverse_string(std::string text) {
//     std::stack<char> myStack;
//     for(char c : text){
//         myStack.push(c);
//     }
//     std::string result = "";
//     while(!myStack.empty()) {
//         result += myStack.top();
//         myStack.pop();
//     }
//     return result;
// }

//var6 transform with reverse output + lambda
std::string reverse_string(std::string text) {
    std::string result(text.size(), '\0');
    std::transform(text.begin(), text.end(), result.rbegin(), [] (auto c) {return c;});
    return result;
}

}  // namespace reverse_string
