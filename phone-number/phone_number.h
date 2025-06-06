#pragma once
#include <string>
#include <stdexcept>

namespace phone_number {

// TODO: add your solution here
    class phone_number{
        private:
            std::string __number;
        public:
            phone_number(std::string text);
            std::string number() const;
    };

}  // namespace phone_number
