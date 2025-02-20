#pragma once

#include <string>
#include <memory>

namespace troy {

struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

// Implement a human struct (or class) that has a smart-pointer to an artifact as possession member variable.
struct human {
    
    std::string name;
    std::unique_ptr<artifact> possession;
    std::unique_ptr<power> own_power;
    std::shared_ptr<power> influenced_by;

    human() {
        possession = nullptr;
        own_power = nullptr;
        influenced_by = nullptr;
    }
};

void give_new_artifact(human& humanObj, const std::string& artifactName);

}  // namespace troy
