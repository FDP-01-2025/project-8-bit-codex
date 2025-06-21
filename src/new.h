#ifndef new_H
#define new_H

#include <iostream>
#include <conio.h>
#include "character.h"

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
using namespace std;

void new_game()
{
    int tecla;
    bool repite = true;
    int opcion = 1;
    do
    {
        system("cls");
        cout << "===============================" << endl;
        cout << "         Select you class      " << endl;
        cout << "===============================" << endl;
        cout << (opcion == 1 ? "==> " : "   ") << "  Assasin" << endl;
        cout << (opcion == 2 ? "==> " : "   ") << "  Mage" << endl;
        cout << (opcion == 3 ? "==> " : "   ") << "  Knight" << endl;
        cout << (opcion == 4 ? "==> " : "   ") << "  Berserk" << endl;

        tecla = getch();

        switch (tecla)
        {
        case TECLA_ARRIBA:
            opcion--;
            if (opcion < 1)
                opcion = 4;
            break;
        case TECLA_ABAJO:
            opcion++;
            if (opcion > 4)
                opcion = 1;
            break;
        case ENTER:
            switch (opcion)
            {
            case 1:
                cout << " Your character is assasin: " << endl;
                cout << "HP: " << assasin.hp << endl;
                cout << "Defense: " << assasin.def << endl;
                cout << "Strenght:" << assasin.strength << endl;
                cout << "dexterity: " << assasin.dex << endl;
                cout << "Inteligence: " << assasin.intel << endl;
                cout << "Luck: " << assasin.luck << endl;
                cout << "Inicial object: " << assasin.object << endl;
                system("pause");
                break;
            case 2:
                cout << "Your character is Mage: " << endl;
                cout << "HP: " << mage.hp << endl;
                cout << "Defense: " << mage.def << endl;
                cout << "Strenght:" << mage.strength << endl;
                cout << "dexterity: " << mage.dex << endl;
                cout << "Inteligence: " << mage.intel << endl;
                cout << "Luck: " << mage.luck << endl;
                cout << "Inicial object: " << mage.object << endl;
                system("pause");
                break;
            case 3:
                cout << "Your character if Knight: " << endl;
                cout << "HP: " << knight.hp << endl;
                cout << "Defense: " << knight.def << endl;
                cout << "Strenght:" << knight.strength << endl;
                cout << "dexterity: " << knight.dex << endl;
                cout << "Inteligence: " << knight.intel << endl;
                cout << "Luck: " << knight.luck << endl;
                cout << "Inicial object: " << knight.object << endl;
                system("pause");
                break;
            case 4:
                cout <<"Your character is Berserker: "<<endl;
                cout << "HP: " << berserk.hp << endl;
                cout << "Defense: " << berserk.def << endl;
                cout << "Strenght:" << berserk.strength << endl;
                cout << "dexterity: " << berserk.dex << endl;
                cout << "Inteligence: " << berserk.intel << endl;
                cout << "Luck: " << berserk.luck << endl;
                cout << "Inicial object: " << berserk.object << endl;
                system("pause");
                break;
            }
            break;
        }
    } while (repite);
}
#endif
