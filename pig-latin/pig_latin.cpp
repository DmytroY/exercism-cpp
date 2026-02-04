#include "pig_latin.h"

namespace pig_latin {

// TODO: add your solution here
std::string incode(const std::string& word){
    std::set<char> vowels{'a', 'e', 'i', 'o', 'u'}; 
    // 1. strt with vowels or xr or yt
    if(vowels.find(word[0]) != vowels.end() ||
        word.substr(0,2) == "xr" ||
        word.substr(0,2) == "yt" )
    {
       return word + "ay"; 
    } 

    // 2. "thrush" -> "ushthr" -> "ushthray"
    if(vowels.find(word[0]) == vowels.end()){
        std::string chunk{};
        size_t i{0}; //chunk size

        // while consonants
        while(vowels.find(word[i]) == vowels.end() || i >= word.size()){
            // 4. Branch if any consonants + "y" in the word:"rhythm" -> "ythmrh" -> "ythmrhay"
            if(i > 0 && word[i] == 'y'){
                return word.substr(i , word.size() - i) +  chunk + "ay";
            }

            chunk += word[i];
            i++;
        }
        //3. Branch if any consonants + "qu" in the word: "square" -> "aresqu" -> "aresquay"
        if(chunk[i - 1] == 'q' && word[i] == 'u'){
            return word.substr(i +1 , word.size() - i + 1) +  chunk + "uay";

        }
        return word.substr(i, word.size() - i) + chunk + "ay";
    }   
    return word + "!";
}

std::string translate(const std::string& text){
    std::string result{}, word{};
    // traversing by words
    std::istringstream stream(text);
    while(stream) {
        stream >> word;
        if(stream){
            result.append(incode(word) + " ");
        }
    }
    result.pop_back(); //trim last space
    return result;
}

}  // namespace pig_latin
