#include "raindrops.h"

namespace raindrops {

    std::string convert(int n) {
        std::string result ="";
        if (n % 3 == 0) result = "Pling";
        if (n % 5 == 0) result = result + "Plang";
        if (n % 7 == 0) result = result + "Plong";
        if (result == "") return std::to_string(n);
        return result;
    }
}  // namespace raindrops
