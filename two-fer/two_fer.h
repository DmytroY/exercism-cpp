#if !defined(TWO_FER_H)

#include <string>
#define TWO_FER_H

namespace two_fer {

inline std::string two_fer(std::string text="you") {
    text = "One for " + text +", one for me.";
    return text;   
}

}  // namespace two_fer

#endif  // TWO_FER_H
