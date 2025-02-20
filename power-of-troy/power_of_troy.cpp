#include "power_of_troy.h"

namespace troy {

    // define a new artifact object and set the possession pointer of the human accordingly.
    void give_new_artifact(human& humanObj, const std::string& artifactName) {
        artifact newArtifact(artifactName);
        humanObj.possession = std::make_unique<artifact>(std::move(newArtifact));
    }

    
}  // namespace troy
