#ifndef load_H
#define load_H
#include <iostream>
#include <fstream>
using namespace std;
#include "character.h"

bool load_game(character &player, string &class_name)
{
    ifstream archivo("save_tower.txt");
    if (archivo.is_open())
    {
        archivo >> player.hp;
        archivo >> player.def;
        archivo >> player.strength;
        archivo >> player.dex;
        archivo >> player.intel;
        archivo >> player.luck;
        archivo >> player.object;
        archivo >> player.level;
        archivo.close();
        cout << "successfully loaded game" << endl;
        system("pause");
        return true;
    }
    else
    {
        cout << "the game could not be loaded" << endl;
        system("pause");
    }
    return false;
}
#endif