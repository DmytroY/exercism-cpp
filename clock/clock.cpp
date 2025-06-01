#include "clock.h"

namespace date_independent {

// TODO: add your solution here
clock::clock(int h, int m) {
    clock::_hour = h;
    clock::_minute = m;
}

clock clock::at(int h, int m) {
    if(m < 0){
        h += m / 60 - 1;
        m = 60 + (m % 60); 
    } 
    if(h < 0) h = 24 + (h % 24);
    h += m / 60;
    h = h % 24;
    m = m % 60;

    clock c(h, m);
    return c;
}

 clock::operator std::string() const{
    std::string hour = "00" + std::to_string(_hour);
    std::string minute = "00" + std::to_string(_minute);
    return hour.substr(hour.length()-2) + ":" + minute.substr(minute.length()-2);
}

bool clock::operator==(const clock& other_c) const {
    return _minute == other_c._minute && _hour == other_c._hour;
}

bool clock::operator!=(const clock& other_c) const {
    return _minute != other_c._minute ||_hour != other_c._hour;
}

clock clock::plus(int i) const { return clock::at(_hour, _minute + i); }
}  // namespace date_independent
