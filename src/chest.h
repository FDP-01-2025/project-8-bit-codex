#ifndef chest_H
#define chest_H
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

string chest()
{
    int N;
    srand(time(NULL));
    int num = (rand() % 5) + 1;

    if (num == 1)
    {
        cout << "\t\t\t\t===========================\n";
        cout << "\t\t\t\tHave found a potion of life\n";
        cout << "\t\t\t\t===========================\n";
        return "Potion of Life";
    }
    else if (num == 2)
    {
        cout << "\t\t\t\t===============================\n";
        cout << "\t\t\t\tHave found a potion of strength\n";
        cout << "\t\t\t\t===============================\n";
        return "Potion of Strength";
    }
    else if (num == 3)
    {
        cout << "\t\t\t\t========================\n";
        cout << "\t\t\t\tHave found a defense pot\n";
        cout << "\t\t\t\t========================\n";
        return "Defense Potion";
    }
    else if (num == 4)
    {
        cout << "\t\t\t\t=============\n";
        cout << "\t\t\t\tEmpty chest!!\n";
        cout << "\t\t\t\t=============\n";
        return "Empty Chest";
    }
    else if (num == 5)
    {
        cout << "\t\t\t\t===============\n";
        cout << "\t\t\t\tEnemy in sight!!\n";
        cout << "\t\t\t\t===============\n";
        return "Enemy Encountered";
    }
    return "";
    
}
#endif