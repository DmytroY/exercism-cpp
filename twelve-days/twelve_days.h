#pragma once
#include <string>
#include <vector>

namespace twelve_days {

// TODO: add your solution here
const std::vector<std::vector<std::string>> numerals {
    {"none", "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"},
    {
        {"none"},
        {"a Partridge in a Pear Tree."},
        {"two Turtle Doves, and "},
        {"three French Hens, "},
        {"four Calling Birds, "},
        {"five Gold Rings, "},
        {"six Geese-a-Laying, "},
        {"seven Swans-a-Swimming, "},
        {"eight Maids-a-Milking, "},
        {"nine Ladies Dancing, "},
        {"ten Lords-a-Leaping, "},
        {"eleven Pipers Piping, "},
        {"twelve Drummers Drumming, "},
    }
};

std::string chunk(const int& n);
std::string recite(const int& first, const int& last);

}  // namespace twelve_days
