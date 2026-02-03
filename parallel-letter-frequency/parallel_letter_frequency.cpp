#include "parallel_letter_frequency.h"

namespace parallel_letter_frequency {
    std::map<char, unsigned> frequency(std::vector<std::string_view> texts){
        std::array<std::atomic<unsigned>,256> fr{};

        std::for_each(std::execution::par_unseq, texts.begin(), texts.end(),
            [&](std::string_view text){
                for(unsigned char c : text){
                    if(isalpha(c)){
                        fr[(char)tolower(c)].fetch_add(1, std::memory_order_relaxed);
                    }
                }
            }
        );

        std::map<char, unsigned> result;
        for (size_t i = 0; i < 256; ++i) {
            if(fr[i]){
                result[i] = fr[i].load();
            }
        }
        return result;
    }
}
