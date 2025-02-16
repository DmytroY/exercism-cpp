#include <string>

namespace log_line {
    std::string message(std::string line) {
        // return the message
        int position = line.find(":");
        return line.substr(position + 2);
    }

    std::string log_level(std::string line) {
        // return the log level
        int position = line.find(":");
        return line.substr(1, position - 2);
    }

    std::string reformat(std::string line) {
        std::string msg = log_line::message(line) + " (" + log_line::log_level(line) + ")";
        return msg;
    }
}

// int main() {
//     std::cout << log_line::message("[ERROR]: file not found") << std::endl;
//     std::cout << log_line::log_level("[ERROR]: file not found") << std::endl;
//     std::cout << log_line::reformat("[ERROR]: file not found") << std::endl;
// }