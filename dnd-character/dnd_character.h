#pragma once

namespace dnd_character {

int modifier(int);
int ability();

// variant 1, with struct
// struct Character {
//     int strength = ability();
//     int dexterity = ability();
//     int constitution = ability();
//     int intelligence = ability();
//     int wisdom = ability();
//     int charisma = ability();
//     int hitpoints = 10 + modifier(constitution);
// } ;

// variant 2, with Class
class Character {
    public:
        int strength;
        int dexterity;
        int constitution;
        int intelligence;
        int wisdom;
        int charisma;
        int hitpoints;

        Character(){
            strength = ability();
            dexterity = ability();
            constitution = ability();
            intelligence = ability();
            wisdom = ability();
            charisma = ability();
            hitpoints = 10 + modifier(constitution);
        }
};

}  // namespace dnd_character
