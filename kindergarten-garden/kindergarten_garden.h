#pragma once
#include <array>
#include <string>

namespace kindergarten_garden {

// TODO: add your solution here
enum class Plants{
    clover,
    grass,
    violets,
    radishes,
    error
};
kindergarten_garden::Plants to_enum(char c);
std::array<kindergarten_garden::Plants, 4> plants(std::string garden, std::string name);

}  // namespace kindergarten_garden
