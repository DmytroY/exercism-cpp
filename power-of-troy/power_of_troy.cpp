#include "power_of_troy.h"

namespace troy {

    // define a new artifact object and set the possession pointer of the human accordingly
    void give_new_artifact(human& ref2human, std::string artifact_name) {
        ref2human.possession = std::make_unique<artifact>(artifact_name);
    }

    void exchange_artifacts(std::unique_ptr<artifact>& possession1, std::unique_ptr<artifact>& possession2) {
        auto temp_var = std::move(possession1);
        possession1 = std::move(possession2);
        possession2 = std::move(temp_var);
    }

    // manifest_power(eleven, "psychokinesis");
    // eleven.own_power->effect;
    // "psychokinesis"
    void manifest_power(human human, std::string power_name) {
        human.own_power = std::make_unique<power>(power_name);
    }

}  // namespace troy
