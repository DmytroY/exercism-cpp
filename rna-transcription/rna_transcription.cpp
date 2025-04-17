#include "rna_transcription.h"

namespace rna_transcription {

    // TODO: add your solution here
    /*  G -> C
        C -> G
        T -> A
        A -> U     */

    char to_rna(char c) {
        std::map<char, char> dict = {{'G','C'},{'C','G'},{'T','A'},{'A','U'}};
        return dict[c];
    }

    std::string to_rna(std::string s) {
        std::map<char, char> dict = {{'G','C'},{'C','G'},{'T','A'},{'A','U'}};
        std::string result = "";
        for(char c : s) {
            result += dict[c];
        }
        return result;
    }

}  // namespace rna_transcription
