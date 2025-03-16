#include "leap.h"

namespace leap {

// TODO: add your solution here
    bool is_leap_year(int year){
        if(!(year % 400)) { return true;}
        if(!(year % 100)) { return false;}
        if(!(year % 4)) { return true; }
        return false;
    }

}  // namespace leap
