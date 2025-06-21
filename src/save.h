#ifndef save_H
#define save_H
#include <iostream>
#include <fstream>
using namespace std;
#include "character.h"

void save(character &assasin)
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
#endif