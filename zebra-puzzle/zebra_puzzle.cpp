#include "zebra_puzzle.h"

namespace zebra_puzzle {

Solution solve(){
    Solution solution;

    enum Color {YELLOW, BLUE, RED, IVORY, GREEN};
    enum Nation {NORWEGIAN, ENGLISHMAN, JAPANESE, SPANIARD, UKRAINIAN};
    enum Pet { DOG, FOX, HORSE, SNAIL, ZEBRA};
    enum Beverage {WATER, COFFEE, JUICE, MILK, TEA};
    enum Hobby    {PAINTER, CHESS, DANCING, FOOTBALL, READING};

    // Vectors for fast permutations
    std::array<int, 5> nation   = {0, 1, 2, 3, 4};
    std::array<int, 5> color    = {0, 1, 2, 3, 4};
    std::array<int, 5> pet      = {0, 1, 2, 3, 4};
    std::array<int, 5> beverage = {0, 1, 2, 3, 4};
    std::array<int, 5> hobby    = {0, 1, 2, 3, 4};
    
    // Names for easy converting enum int values to readable ouput
    //const char* ColorNames[]    = { "Yellow", "Blue", "Red", "Ivory", "Green" };
    const char* NationNames[]   = { "Norwegian", "Englishman", "Japanese", "Spaniard", "Ukrainian" };
    //const char* PetNames[]      = { "Dog", "Fox", "Horse", "Snail", "Zebra" };
    //const char* BeverageNames[] = { "Water", "Coffee", "Juice", "Milk", "Tea" };
    //const char* HobbyNames[]    = { "Painter", "Chess", "Dancing", "Football", "Reading" };

    int i; // arrays index
    std::array<int, 5>::iterator it;

    do {
        // COLOR
        // 6.The green house is immediately to the right of the ivory house.
        it = std::find(color.begin(), color.end(), Color::IVORY);
        i = it - color.begin();
        if(i == 4 || color[i + 1] != Color::GREEN) continue;

        do {
            // COLOR + NATION
            // 10.The Norwegian lives in the first house.
            if(nation[0] != Nation::NORWEGIAN) continue;

            // 15.The Norwegian lives next to the blue house.
            if(color[1] != Color::BLUE) continue;

            // 2.The Englishman lives in the red house.
            it = std::find(nation.begin(), nation.end(), Nation::ENGLISHMAN);
            i = it - nation.begin();
            if(color[i] != Color::RED) continue;

            do {
                // COLOR + NATION + BEVERAGE
                // 9.The person in the middle house drinks milk.
                if(beverage[2] != Beverage::MILK) continue;

                // 4.The person in the green house drinks coffee.
                it = std::find(color.begin(), color.end(), Color::GREEN);
                i = it - color.begin();
                if(beverage[i] != Beverage::COFFEE) continue;

                // 5.The Ukrainian drinks tea.
                it = std::find(nation.begin(),nation.end(), Nation::UKRAINIAN);
                i = it - nation.begin();
                if(beverage[i] != Beverage::TEA) continue;

                do {
                    // COLOR + NATION + BEVERAGE + HOBBY
                    // 8.The person in the yellow house is a painter.
                    it = std::find(color.begin(), color.end(), Color::YELLOW);
                    i = it - color.begin();
                    if(hobby[i] != Hobby::PAINTER) continue;

                    // 13.The person who plays football drinks orange juice.
                    it = std::find(hobby.begin(), hobby.end(), Hobby::FOOTBALL);
                    i = it - hobby.begin();
                    if(beverage[i] != Beverage::JUICE) continue;

                    // 14.The Japanese person plays chess.
                    it = std::find(nation.begin(),nation.end(), Nation::JAPANESE);
                    i = it - nation.begin();
                    if(hobby[i] != Hobby::CHESS) continue;

                    do {
                        // COLOR + NATION + BEVERAGE + HOBBY + PET
                        // 3.The Spaniard owns the dog.
                        it = std::find(nation.begin(),nation.end(), Nation::SPANIARD);
                        i = it - nation.begin();
                        if(pet[i] != Pet::DOG) continue;

                        // 7.The snail owner likes to go dancing.
                        it = std::find(pet.begin(), pet.end(), Pet::SNAIL);
                        i = it - pet.begin();
                        if(hobby[i] != Hobby::DANCING) continue;

                        // 11.The person who enjoys reading lives in the house next to the person with the fox.
                        it = std::find(hobby.begin(), hobby.end(), Hobby::READING);
                        int i1 = it - hobby.begin();
                        it = std::find(pet.begin(), pet.end(), Pet::FOX);
                        int i2 = it- pet.begin();
                        if(abs(i1-i2) != 1) continue;

                        // 12.The painter's house is next to the house with the horse.
                        it = std::find(hobby.begin(), hobby.end(), Hobby::PAINTER);
                        i1 = it - hobby.begin();
                        it = std::find(pet.begin(), pet.end(), Pet::HORSE);
                        i2 = it- pet.begin();
                        if(abs(i1-i2) != 1) continue;

                        // all conditions are satisfied

                        it = std::find(beverage.begin(), beverage.end(), Beverage::WATER);
                        i = it - beverage.begin();
                        solution.drinksWater = NationNames[nation[i]];

                        it = std::find(pet.begin(), pet.end(), Pet::ZEBRA);
                        i = it - pet.begin();
                        solution.ownsZebra = NationNames[nation[i]];

                    } while(std::next_permutation(pet.begin(), pet.end()));
                } while(std::next_permutation(hobby.begin(), hobby.end()));
            } while(std::next_permutation(beverage.begin(), beverage.end()));
        } while(std::next_permutation(nation.begin(), nation.end()));
    } while(std::next_permutation(color.begin(), color.end()));

    return solution;
}

}  // namespace zebra_puzzle
