#ifndef save_H
#define save_H
#include <iostream>
#include <fstream>
using namespace std;
#include "character.h"
#include "new.h"

void save(const character &player, const string &class_name)
{
    ofstream archivo("save_tower.txt");
    if (archivo.is_open())
    {
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