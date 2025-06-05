#include <iostream>
using namespace std;

int main()
{
    int hp, def, strenght, dex, intel, luck, option;
    cout << "select your clase" << endl;
    cout << "1- assassin" << endl;
    cout << "2- mage" << endl;
    cout << "3- knight" << endl;
    cout << "4- berserk" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
        hp = 10;
        def = 5;
        strenght = 5;
        dex = 15;
        intel = 5;
        luck = 10;

        cout << "you have selected the asassin class, which its caracterized by his high chances of a critic hit" << endl;
        break;
    case 2:
        hp = 8;
        def = 8;
        strenght = 3;
        dex = 5;
        intel = 20;
        luck = 6;

        cout << "you have slected the mage class, which its caracterized by his high intelligence" << endl;
        break;
    case 3:
        hp = 15;
        def = 15;
        strenght = 10;
        dex = 3;
        intel = 3;
        luck = 4;

        cout << "you have selected the class knight, which its caracterized by his defense" << endl;
        break;
        hp = 20;
        def = 10;
        strenght = 12;
        dex = 3;
        intel = 0;
        luck = 5;

        cout << "you have selected berserk class, which its caracterized by his high hp" << endl;
    default:
        cout << "select a valid option";
    }

    return 0;
}