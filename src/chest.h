#ifndef chest_H
#define chest_H
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

string chest()
{
    srand(time(NULL));    
    int num = (rand() % 5) + 1;   //Genera un numero al azar del 1 al 5
     //Dependiendo de que valor tome num asi sera el objeto que salga
    if (num == 1) //Cofre: pocion de vida
    {
        cout << "\t\t\t\t===========================\n";
        cout << "\t\t\t\tHave found a potion of life\n";
        cout << "\t\t\t\t===========================\n";
        return "Potion of Life";
    }
    else if (num == 2)//Cofre: pocion de fuerza
    {
        cout << "\t\t\t\t===============================\n";
        cout << "\t\t\t\tHave found a potion of strength\n";
        cout << "\t\t\t\t===============================\n";
        return "Potion of Strength";
    }
    else if (num == 3)//Cofre: pocion de defensa
    {
        cout << "\t\t\t\t========================\n";
        cout << "\t\t\t\tHave found a defense pot\n";
        cout << "\t\t\t\t========================\n";
        return "Defense Potion";
    }
    else if (num == 4)// Cofre vacio
    {
        cout << "\t\t\t\t=============\n";
        cout << "\t\t\t\tEmpty chest!!\n";
        cout << "\t\t\t\t=============\n";
        return "Empty Chest";
    }
    else if (num == 5)//Cofre con enemigo
    {
        cout << "\t\t\t\t===============\n";
        cout << "\t\t\t\tEnemy in sight!!\n";
        cout << "\t\t\t\t===============\n";
        return "Enemy Encountered";
    }
    return "";
    
}
#endif