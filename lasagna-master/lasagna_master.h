#pragma once
#include <vector>
#include <string>

namespace lasagna_master {

    struct amount {
        int noodles;
        double sauce;
    };

    int preparationTime(std::vector<std::string> layers, int time4layer=2);
    amount quantities(std::vector<std::string> layers);
    void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendsList);
    std::vector<double> scaleRecipe(std::vector<double> quantities, int portions);
    void addSecretIngredient(std::vector<std::string>& myList, std::string secretIngredient);

}  // namespace lasagna_master
