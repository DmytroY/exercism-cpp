#include "power_of_troy.h"

namespace troy {

    // define a new artifact object and set the possession pointer of the human accordingly
    void give_new_artifact(human& ref2human, std::string artifact_name) {
        // auto art1 = std::make_unique<artifact>(artifact_name); // unique smart pointer to newly created artifact
        // ref2human.possession = std::move(art1); // move ownership to human
        ref2human.possession = std::make_unique<artifact>(artifact_name); //same in one string
    }

    void exchange_artifacts(std::unique_ptr<artifact>& possession1, std::unique_ptr<artifact>& possession2) {
        auto temp_var = std::move(possession1);
        possession1 = std::move(possession2);
        possession2 = std::move(temp_var);
    }

    // manifest_power(eleven, "psychokinesis");
    // eleven.own_power->effect;
    // "psychokinesis"
    void manifest_power(human& human, std::string power_name) {
        // auto power1 = std::make_unique<power>(power_name);
        // human.own_power =std::move(power1);
        human.own_power = std::make_unique<power>(power_name);
    }

    //manifest_power(pamela_isley, "control pheromones");
    // use_power(pamela_isley, count_vertigo);
    // count_vertigo.influenced_by->effect;
    // "control pheromones"
    void use_power(human& caster, human& target) {
        target.influenced_by = caster.own_power;
    }

    int power_intensity(human& human) {
        return human.own_power.use_count();

    }

}  // namespace troy
