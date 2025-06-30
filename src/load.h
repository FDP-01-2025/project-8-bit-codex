#ifndef load_H
#define load_H
#include <iostream>
#include <fstream>
#include <windows.h>
#include "entities/character.h"
using namespace std;

bool load_game(character &player, string &className)
{
    ifstream archivo("save_tower.txt");
    if (archivo.is_open())
    {
        archivo >> player.level;
        archivo >> className;
        archivo >> player.hp;
        archivo >> player.def;
        archivo >> player.strength;
        archivo >> player.dex;
        archivo >> player.intel;
        archivo >> player.luck;
        archivo >> player.object;
        archivo >> player.tower_level;
        archivo.close();
        cout << "\t\t\t\t========================\n";
        cout << "\t\t\t\tsuccessfully loaded game\n";
        cout << "\t\t\t\t========================\n";
        Sleep(1000);
        return true;
    }
    else
    {
        cout << "\t\t\t\t============================\n";
        cout << "\t\t\t\tthe game could not be loaded\n";
        cout << "\t\t\t\t============================\n";
        Sleep(1000);
        return false;
    }
}
#endif