#ifndef save_H
#define save_H
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
#include "entities/character.h"
#include "new.h"

void save(const character &player, const string &className)
{
    ofstream archivo("save_tower.txt"); //Abre el archivo para guardar los datos del personaje
    if (archivo.is_open())
    {
        archivo << player.level << endl;
        archivo << className <<endl;
        archivo << player.hp << endl;
        archivo << player.def << endl;
        archivo << player.strength << endl;
        archivo << player.dex << endl;
        archivo << player.intel << endl;
        archivo << player.luck << endl;
        archivo << player.object << endl;
        archivo << player.tower_level <<endl;
        archivo.close();
        cout << "\t\t\t\t=======================\n";
        cout << "\t\t\t\tsuccessfully saved game\n";
        cout << "\t\t\t\t=======================\n";
        Sleep(1000);
    }
    else
    {
        cout << "\t\t\t\t===========================\n";
        cout << "\t\t\t\tthe game could not be saved\n";
        cout << "\t\t\t\t===========================\n";
        Sleep(1000);
    }
}
#endif