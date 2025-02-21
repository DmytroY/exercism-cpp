#pragma once

#include <string>
#include <memory>

namespace troy {

struct artifact {
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

struct human {
    std::unique_ptr<artifact> possession;
    std::unique_ptr<power> own_power;
    std::shared_ptr<power> influenced_by;   
    human(): possession(nullptr), own_power(nullptr), influenced_by(nullptr) {}
};

void give_new_artifact(human& ref2human, std::string artifact_name);

// exchange_artifacts(uchiha.possession, uzumaki.possession);
void exchange_artifacts(std::unique_ptr<artifact>& possession1, std::unique_ptr<artifact>& possession2);
void manifest_power(human human, std::string power);

}  // namespace troy
