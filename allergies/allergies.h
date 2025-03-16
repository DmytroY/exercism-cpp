#if !defined(ALLERGIES_H)

#include <string>
#include <map>
#include <unordered_set>

#define ALLERGIES_H

namespace allergies {

// TODO: add your solution here
    extern std::map<int, std::string,  std::greater<int>> allergenes_map;

    class allergy_test{
        std::unordered_set<std::string> allergenes_set;
        public:
            allergy_test(int n);
            bool is_allergic_to(std::string food);
            std::unordered_set<std::string> get_allergies();
    };

}  // namespace allergies

#endif  // ALLERGIES_H