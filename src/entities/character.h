#ifndef character_H
#define character_H

// structura para personajes
struct character
{
    int level;
    int hp;
    int def;
    int strength;
    int dex;
    int intel;
    int luck;
    int object;
    int tower_level;
};

const character assasin = {1, 10, 5, 5, 15, 5, 10, 1, 0};
const character mage = {1, 8, 8, 3, 5, 20, 6, 3, 0};
const character knight = {1, 15, 15, 10, 3, 3, 4, 2, 0};
const character berserk = {1, 20, 10, 12, 3, 0, 5, 2, 0};

#endif