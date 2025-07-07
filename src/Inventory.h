#ifndef Inventory_H
#define Inventory_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "entities/character.h"
#include "entities/enemies.h"
#include "utils/Screen.h"
#include "chest.h"
#include "utils/inputs.h"
using namespace std;
const int MAX_ITEMS = 10;
extern string inventory[MAX_ITEMS];
extern int itemCount;
void Inventory()
{
    system("cls");
    hideCursor();
    int tecla;
    bool repite = true;
    int opcion = 1;
    do
    {
        gotoxy(0, 0);//Evita parpadeo
        cout << "\t\t\t\t=====================Inventory==========================\n";
        for (int i = 0; i < MAX_ITEMS; ++i) //Un invetario funcional con WASD y las flechas
        {
            if (i < itemCount)
            {
                cout << (opcion == i + 1 ? "\t\t\t\t==> " : "  \t\t\t\t    ");
                cout << inventory[i] << endl;
            }
            else
            {
                cout << (opcion == i + 1 ? "\t\t\t\t==> " : "  \t\t\t\t    ");
                cout << "    " << endl;
            }
        }
        cout << "\t\t\t\t==========================================================\n";
        tecla = getch();

        switch (tecla) //Switch para un menu funcional con WASD y las flechas
        {
        case TECLA_ARRIBA:
        case 'w':
        case 'W':
            opcion--;
            if (opcion < 1)
                opcion = MAX_ITEMS;
            break;
        case TECLA_ABAJO:
        case 's':
        case 'S':
            opcion++;
            if (opcion > MAX_ITEMS)
                opcion = 1;
            break;
        case ENTER:
            if (opcion <= itemCount && itemCount > 0)
            {
                system("cls");
                cout << "\n\t\t\t\tYou have selected: " << inventory[opcion - 1] << endl;
                for (int i = opcion - 1; i < itemCount - 1; ++i)
                {
                    inventory[i] = inventory[i + 1];
                }
                inventory[itemCount - 1].clear();//Al usar un objeto se quita del inventario
                itemCount--;
                Sleep(2000);
                system("cls");
            }
            break;
        case ESC:
            repite = false;
            break;
        }
    } while (repite);
}
void addToInventory(const string &item)//El objeto se agrega al inventario
{
    if (item.empty())
        return;
    if (itemCount < MAX_ITEMS)
    {
        inventory[itemCount++] = item;
        cout << "\t\t\t\tAdded object to the inventory:" << item << endl;
    }
    else
    {
        cout << "Full inventory!" << endl;
    }
}
void showInventory()//Se muestra el inventario
{
    cout << "\n--- Inventory ---\n";
    for (int i = 0; i < itemCount; ++i)
    {
        cout << i + 1 << ". " << inventory[i] << endl;
    }
    cout << "------------------\n";
}
void chest_final()
    {
        for (int i = 0; i < 5; ++i)
        {
            string objeto = chest();
            if (objeto != "Enemy Encountered" && objeto != "Empty Chest" && !objeto.empty())
            {
                addToInventory(objeto);
            }
            Sleep(1000);
        }
        Inventory();
    }
#endif