#pragma once
#include <vector>
#include <string>

namespace flower_field {

char get_or_space(std::vector<std::string>&, int&, int&);
std::vector<std::string> annotate(std::vector<std::string>);

}  // namespace flower_field
