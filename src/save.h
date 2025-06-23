#ifndef save_H
#define save_H
#include <iostream>
#include <fstream>
using namespace std;
#include "character.h"
#include "new.h"

void save()
{
    ofstream archivo("save_tower.txt");
    if (archivo.is_open())
    {
        archivo << assasin.hp << endl;
        archivo << assasin.def << endl;
        archivo << assasin.strength << endl;
        archivo << assasin.dex << endl;
        archivo << assasin.intel << endl;
        archivo << assasin.luck << endl;
        archivo << assasin.object << endl;
        archivo.close();
        cout << "successfully saved game" << endl;
    }
    else
    {
        cout << "the game could not be saved" << endl;
    }
}
void save_2()
{
    ofstream archivo("save_tower.txt");
    if (archivo.is_open())
    {
        archivo << mage.hp << endl;
        archivo << mage.def << endl;
        archivo << mage.strength << endl;
        archivo << mage.dex << endl;
        archivo << mage.intel << endl;
        archivo << mage.luck << endl;
        archivo << mage.object << endl;
        archivo.close();
        cout << "successfully saved game" << endl;
    }
    else
    {
        cout << "the game could not be saved" << endl;
    }
}
void save_3()
{
    ofstream archivo("save_tower.txt");
    if (archivo.is_open())
    {
        archivo << knight.hp << endl;
        archivo << knight.def << endl;
        archivo << knight.strength << endl;
        archivo << knight.dex << endl;
        archivo << knight.intel << endl;
        archivo << knight.luck << endl;
        archivo << knight.object << endl;
        archivo.close();
        cout << "successfully saved game" << endl;
    }
    else
    {
        cout << "the game could not be saved" << endl;
    }
}
void save_4()
{
    ofstream archivo("save_tower.txt");
    if (archivo.is_open())
    {
        archivo << berserk.hp << endl;
        archivo << berserk.def << endl;
        archivo << berserk.strength << endl;
        archivo << berserk.dex << endl;
        archivo << berserk.intel << endl;
        archivo << berserk.luck << endl;
        archivo << berserk.object << endl;
        archivo.close();
        cout << "successfully saved game" << endl;
    }
    else
    {
        cout << "the game could not be saved" << endl;
    }
}
#endif