#ifndef load_H
#define load_H
#include <iostream>
#include <fstream>
using namespace std;
#include "character.h"

bool load_game(character &assasin)
{
    ifstream archivo("save_tower.txt");
    if (archivo.is_open())
    {
        archivo >> assasin.hp;
        archivo >> assasin.def;
        archivo >> assasin.strength;
        archivo >> assasin.dex;
        archivo >> assasin.intel;
        archivo >> assasin.luck;
        archivo >> assasin.object;
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