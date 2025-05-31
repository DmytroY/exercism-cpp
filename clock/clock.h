#pragma once
#include <string>

namespace date_independent {

// TODO: add your solution here
class clock{
    public:
        clock(int, int);
        static clock at(int, int);
        clock plus(int);
        operator std::string() const;
        bool operator==(const clock&) const;
        bool operator!=(const clock&) const;
    
    private:
        int _hour;
        int _minute;
};

}  // namespace date_independent
