#pragma once
#include <string>

namespace date_independent {

// TODO: add your solution here
class clock{
    public:
        static clock at(int, int);
        clock plus(int) const;
        explicit operator std::string() const;
        bool operator==(const clock&) const;
        bool operator!=(const clock&) const;
    
    private:
        clock(int, int);
        int _hour;
        int _minute;
};

}  // namespace date_independent
