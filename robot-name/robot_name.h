#pragma once
#include <string>
#include <set>

namespace robot_name {

// TODO: add your solution here

    char rA();
    char rD();
    std::string generate_name();

    class robot {
        private:
            std::string _name;

        public:
            static std::set<std::string> _names;
            robot();
            std::string name() const;
            void reset();
    };
}  // namespace robot_name
