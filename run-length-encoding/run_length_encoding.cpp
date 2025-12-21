#include "run_length_encoding.h"

namespace run_length_encoding {

std::string encode(std::string in){
        in = in + "#";
        std::string result;
        unsigned count{0};
        for(unsigned i = 0; i < in.size(); i++){
            if(i == 0 || in[i] == in[i - 1]){
                count++;
            } else {
                std::string multiplier = (count < 2) ? "" : std::to_string(count);
                result.append(multiplier + in[i-1]);
                count = 1;
            }
        }
        return result;
}

}  // namespace run_length_encoding
