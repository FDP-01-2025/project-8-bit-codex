#ifndef save_H
#define save_H
#include <iostream>
#include <fstream>
using namespace std;
#include "entities/character.h"
#include "new.h"

void save(const character &player, const string &className)
{
    ofstream archivo("save_tower.txt");
    if (archivo.is_open())
    {
        archivo << className <<endl;
        archivo << player.hp << endl;
        archivo << player.def << endl;
        archivo << player.strength << endl;
        archivo << player.dex << endl;
        archivo << player.intel << endl;
        archivo << player.luck << endl;
        archivo << player.object << endl;
        archivo << player.level << endl;
        archivo.close();
        cout << "successfully saved game" << endl;
    }
    else
    {
        cout << "the game could not be saved" << endl;
    }
}
#endif