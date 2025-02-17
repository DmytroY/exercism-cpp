// ERROR: FILE CORRUPTED. Please supply valid C++ Code.
#include <string>
#include "doctor_data.h"

using namespace std;
namespace heaven {

    string get_older_bob(Vessel v1, Vessel v2) {
        return (v1.generation < v2.generation) ? v1.name : v2.name;
    }

    bool in_the_same_system(Vessel v1, Vessel v2) {
        return (v1.current_system == v2.current_system) ? true : false;
    }

    Vessel Vessel::replicate(std::string name) {
        heaven::Vessel new_vessel = *this;
        new_vessel.name = name;
        new_vessel.generation++;
        return new_vessel;
    }

    void Vessel::make_buster() {busters++;}

    bool Vessel::shoot_buster() {
        if (busters > 0) {
            busters--;
            return true;
        }
        return false;
    }
} // namespace heaven