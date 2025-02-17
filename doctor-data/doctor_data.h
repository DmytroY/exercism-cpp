#include <string>
using namespace std;

namespace star_map {
    enum System {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani,
    };
}

namespace heaven {
    class Vessel {
        public:
            string name;
            int generation;
            star_map::System current_system;
            int busters;

            Vessel(string name, int generation)
                : name(name), generation(generation), current_system(star_map::System::Sol), busters(0) {}

            Vessel(string name, int generation, star_map::System system)
                : name(name), generation(generation), current_system(system), busters(0){}
            
            Vessel replicate(string name);
            void make_buster();
            bool shoot_buster();
    };

    std::string get_older_bob(Vessel, Vessel);
    bool in_the_same_system(Vessel, Vessel);
} // namespace heaven

