#ifndef new_H
#define new_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "entities/character.h"
#include "imagen.h"
#include "menu.h"
#include "Inventory.h"
#include "utils/Screen.h"
#include "utils/inputs.h"
using namespace std;
void new_game(character &player, string &className)
{
    hideCursor();
    int tecla;
    bool repite = true;
    int opcion = 1;
    do
    {
        gotoxy(0, 0);
        cout << "\t\t\t\t======================================================" << endl;
        cout << "\t\t\t\t                   Select you class                  " << endl;
        cout << "\t\t\t\t======================================================" << endl;
        cout << (opcion == 1 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Assasin" << endl;
        cout << (opcion == 2 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Mage" << endl;
        cout << (opcion == 3 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Knight" << endl;
        cout << (opcion == 4 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Berserk" << endl;

        tecla = getch();

        switch (tecla)
        {
        case TECLA_ARRIBA:
        case 'w':
        case 'W':
            opcion--;
            if (opcion < 1)
                opcion = 4;
            break;
        case TECLA_ABAJO:
        case 's':
        case 'S':
            opcion++;
            if (opcion > 4)
                opcion = 1;
            break;
        case ENTER:
            switch (opcion)
            {
            case 1:
                system("cls");
                player = assasin;
                className = "Assasin";
                cout << "\t\t\t\t======================================================" << endl;
                cout << "\t\t\t\tYour character is " <<className  << endl;
                cout << "\t\t\t\tHP: " << player.hp << endl;
                cout << "\t\t\t\tDefense: " << player.def << endl;
                cout << "\t\t\t\tStrenght:" << player.strength << endl;
                cout << "\t\t\t\tdexterity: " << player.dex << endl;
                cout << "\t\t\t\tInteligence: " << player.intel << endl;
                cout << "\t\t\t\tLuck: " << player.luck << endl;
                if(player.object == 1){
                    addToInventory("Potion of Life");
                } else if(player.object == 2){
                    addToInventory("Potion of Strength");
                } else {
                    addToInventory("Potion of Defense");
                }
                cout << "\t\t\t\tLevel tower: " <<player.level << endl;
                cout << "\t\t\t\t======================================================" << endl;
                image_assasin();
                repite = false;
                Sleep(3000);
                break;
            case 2:
                system("cls");
                player = mage;
                className = "Mage";
                cout << "\t\t\t\t======================================================" << endl;
                cout << "\t\t\t\tYour character is " <<className  << endl;
                cout << "\t\t\t\tHP: " << player.hp << endl;
                cout << "\t\t\t\tDefense: " << player.def << endl;
                cout << "\t\t\t\tStrenght:" << player.strength << endl;
                cout << "\t\t\t\tdexterity: " << player.dex << endl;
                cout << "\t\t\t\tInteligence: " << player.intel << endl;
                cout << "\t\t\t\tLuck: " << player.luck << endl;
                if(player.object == 1){
                    addToInventory("Potion of Life");   
                } else if(player.object == 2){
                    addToInventory("Potion of Strength");
                } else {
                    addToInventory("Potion of Defense");
                }
                cout << "\t\t\t\tLevel tower: " <<player.level << endl;
                cout << "\t\t\t\t======================================================" << endl;
                image_mage();
                repite = false;
                Sleep(3000);
                break;
            case 3:
                system("cls");
                player = knight;
                className = "Knight";
                cout << "\t\t\t\t======================================================" << endl;
                cout << "\t\t\t\tYour character is " <<className  << endl;
                cout << "\t\t\t\tHP: " << player.hp << endl;
                cout << "\t\t\t\tDefense: " << player.def << endl;
                cout << "\t\t\t\tStrenght:" << player.strength << endl;
                cout << "\t\t\t\tdexterity: " << player.dex << endl;
                cout << "\t\t\t\tInteligence: " << player.intel << endl;
                cout << "\t\t\t\tLuck: " << player.luck << endl;
                if(player.object == 1){
                    addToInventory("Potion of Life");
                } else if(player.object == 2){
                    addToInventory("Potion of Strength");
                } else {
                    addToInventory("Potion of Defense");
                }
                cout << "\t\t\t\tLevel tower: " <<player.level << endl;
                cout << "\t\t\t\t======================================================" << endl;
                image_knight();
                repite = false;
                Sleep(3000);
                break;
            case 4:
                system("cls");
                player = berserk;
                className = "Berserk";
                cout << "\t\t\t\t======================================================" << endl;
                cout << "\t\t\t\tYour character is " <<className  << endl;
                cout << "\t\t\t\tHP: " << player.hp << endl;
                cout << "\t\t\t\tDefense: " << player.def << endl;
                cout << "\t\t\t\tStrenght:" << player.strength << endl;
                cout << "\t\t\t\tdexterity: " << player.dex << endl;
                cout << "\t\t\t\tInteligence: " << player.intel << endl;
                cout << "\t\t\t\tLuck: " << player.luck << endl;
                if(player.object == 1){
                    addToInventory("Potion of Life");
                } else if(player.object == 2){
                    addToInventory("Potion of Strength");
                } else {
                    addToInventory("Potion of Defense");
                }
                cout << "\t\t\t\tLevel tower: " <<player.level << endl;
                cout << "\t\t\t\t======================================================" << endl;
                image_berserk();
                repite = false;
                Sleep(3000);
                break;
            }
            break;
        }
    } while (repite);
}
#endif
