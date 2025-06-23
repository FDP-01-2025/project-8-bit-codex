#ifndef load_H
#define load_H
#include <iostream>
#include <fstream>
using namespace std;
#include "character.h"

bool load_game1(character &assasin)
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
bool load_game2(character &mage)
{
    ifstream archivo("save_tower.txt");
    if (archivo.is_open())
    {
        archivo >> mage.hp;
        archivo >> mage.def;
        archivo >> mage.strength;
        archivo >> mage.dex;
        archivo >> mage.intel;
        archivo >> mage.luck;
        archivo >> mage.object;
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
bool load_game3(character &knight)
{
    ifstream archivo("save_tower.txt");
    if (archivo.is_open())
    {
        archivo >> knight.hp;
        archivo >> knight.def;
        archivo >> knight.strength;
        archivo >> knight.dex;
        archivo >> knight.intel;
        archivo >> knight.luck;
        archivo >> knight.object;
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
bool load_game4(character &berserk)
{
    ifstream archivo("save_tower.txt");
    if (archivo.is_open())
    {
        archivo >> berserk.hp;
        archivo >> berserk.def;
        archivo >> berserk.strength;
        archivo >> berserk.dex;
        archivo >> berserk.intel;
        archivo >> berserk.luck;
        archivo >> berserk.object;
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