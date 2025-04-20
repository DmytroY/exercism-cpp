#include "protein_translation.h"

namespace protein_translation {

std::string codon_to_amino(std::string codon) {
    std::map<std::string, std::string> dict {
        {"AUG", "Methionine"},
        {"UUU", "Phenylalanine"},
        {"UUC",	"Phenylalanine"},
        {"UUA",	"Leucine"},
        {"UUG",	"Leucine"},
        {"UCU", "Serine"},
        {"UCC", "Serine"},
        {"UCA", "Serine"},
        {"UCG",	"Serine"},
        {"UAU", "Tyrosine"},
        {"UAC",	"Tyrosine"},
        {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"},
        {"UAA",	"STOP"},
        {"UAG",	"STOP"},
        {"UGA",	"STOP"},
    };
    return {dict[codon]};
}

// TODO: add your solution here
std::vector<std::string> proteins(std::string rna) {
    std::vector<std::string> result;
    for(unsigned i = 0; i < rna.length(); i +=3){
        std::string codon = rna.substr(i, 3);
        if(codon_to_amino(codon) == "STOP") break;
        result.push_back(codon_to_amino(codon));
    }
    return result;
}

}  // namespace protein_translation
