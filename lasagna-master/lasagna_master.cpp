#include <string>
#include <vector>
#include <algorithm>
#include "lasagna_master.h"

using namespace std;
namespace lasagna_master {

    int preparationTime(vector<string> layers, int time4layer) {
        return layers.size() * time4layer;
    }
    
    // quantities({"sauce", "noodles", "sauce", "meat", "mozzarella", "noodles"})};
    // needed.noodles => 100
    // needed.sauce => 0.4
    amount quantities(std::vector<std::string> layers) {
        const int perNudle = 50;
        const double perSauce = 0.2;
        int nudles_count = count(layers.begin(), layers.end(), "noodles");
        int sauce_count = count(layers.begin(), layers.end(), "sauce");
        return {nudles_count * perNudle, sauce_count * perSauce};
    }

    // std::vector<std::string> friendsList{"noodles", "sauce", "mozzarella", "kampot pepper"};
    // std::vector<std::string> myList{"noodles", "meat", "sauce", "mozzarella", "?"};
    // addSecretIngredient(myList, friendsList);
    // myList => {"noodles", "meat", "sauce", "mozzarella", "kampot pepper"}
    void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendsList){
        if( !friendsList.empty() && !myList.empty() ){
            myList.back() = friendsList.back();
        }
    }

    // std::vector<double> quantities{1.2, 3.6, 10.5};
    // scaleRecipe(quantities, 4);
    // => { 2.4, 7.2, 21 }
    std::vector<double> scaleRecipe(std::vector<double> quantities, int portions) {
        std::vector<double> result(quantities.size());
        transform(quantities.begin(), quantities.end(), result.begin(), [portions] (double x) { return x * portions / 2; });
        return result;
    }

    // std::vector<std::string> myList{"noodles", "meat", "sauce", "mozzarella", "?"};
    // std::string secretIngredient{"spice melange"};
    // addSecretIngredient(myList, secretIngredient);
    // myList => {"noodles", "meat", "sauce", "mozzarella", "spice melange"}
    void addSecretIngredient(std::vector<std::string>& myList, std::string secretIngredient) {
        if( !myList.empty() ){
            myList.back() = secretIngredient;
        }
    }

}  // namespace lasagna_master
