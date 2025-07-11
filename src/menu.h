#ifndef menu_H
#define menu_H
#include "new.h"
#include "load.h"
#include "entities/character.h"
#include "loading.h"
#include "image.h"
#include "utils/Screen.h"
#include "utils/inputs.h"
#include <iostream>
#include <conio.h>
using namespace std;
character player;
string className;
int cas;
void menu_new(character &player, string &className)
{
    new_game(player, className);
}
bool menu_load()
{
    return load_game(player, className);
}
int menu_principal()
{
    hideCursor();//Esconde el cursor al ejecutar
    int tecla;
    bool repite = true;
    int opcion = 1;
    do
    {
        gotoxy(0, 0);
        cout << "\t\t\t\t========================================================\n";
        cout << "\t\t\t\t            _____ _____       _______ ____              \n";
        cout << "\t\t\t\t           |_   _/ _ \\ \\      / / ____|  _ \\         \n";
        cout << "\t\t\t\t             | || | | \\ \\ /\\ / /|  _| | |_) |        \n";
        cout << "\t\t\t\t             | || |_| |\\ V  V / | |___|  _ <           \n";
        cout << "\t\t\t\t             |_| \\___/  \\_/\\_/  |_____|_| \\_\\      \n";
        cout << "\t\t\t\t                         ___  _____                     \n";
        cout << "\t\t\t\t                        / _ \\|  ___|                   \n";
        cout << "\t\t\t\t                       | | | | |_                       \n";
        cout << "\t\t\t\t                       | |_| |  _|                      \n";
        cout << "\t\t\t\t                        \\___/|_|                       \n";
        cout << "\t\t\t\t                ____   ___  _   _ _     ____            \n";
        cout << "\t\t\t\t               / ___| / _ \\| | | | |   / ___|          \n";
        cout << "\t\t\t\t               \\___ \\| | | | | | | |   \\___ \\       \n";
        cout << "\t\t\t\t                ___) | |_| | |_| | |___ ___) |          \n";
        cout << "\t\t\t\t               |____/ \\___/ \\___/|_____|____/         \n";
        cout << "\t\t\t\t========================================================\n";
        cout << (opcion == 1 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  New Game\n";
        cout << (opcion == 2 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Load Game\n";
        cout << (opcion == 3 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Exit\n";

        tecla = getch(); //Windows detecta las teclas

        switch (tecla) //Switch para un menu funcional con WASD y las flechas
        {
        case TECLA_ARRIBA:
        case 'w':
        case 'W':
            opcion--;
            if (opcion < 1)
                opcion = 3;
            break;
        case TECLA_ABAJO:
        case 's':
        case 'S':
            opcion++;
            if (opcion > 3)
                opcion = 1;
            break;
        case ENTER:
            switch (opcion)
            {
            case 1:
                system("cls");
                menu_new(player, className);
                cas = 1;
                repite = false;
                break;
            case 2:
                system("cls");
                if (menu_load())
                {
                    cas = 2;
                    repite = false;
                }
                else
                {
                    repite = true;
                }
                break;
            case 3:
                cas = 3;
                repite = false;
                break;
            }
            break;
        }
    } while (repite);
    system("cls");
    if (cas == 1)
    {
        cout << "\t\t\t\t======================================================" << endl;
        cout << "\t\t\t\tOver time, death appeared, and only darkness remained." << endl;
        cout << "\t\t\t\tNow, humanity is on the verge of extinction." << endl;
        cout << "\t\t\t\tOnly you will be able to free them while" << endl;
        cout << "\t\t\t\tThis is your fate..." << endl;
        cout << "\t\t\t\t======================================================" << endl;
        image_dragon();
        loading();
        system("cls");
    }
    else if (cas == 2)
    {
        cout << "\t\t\t\t======================================================" << endl;
        cout << "\t\t\t\tContinue your journey to a world to" << endl;
        cout << "\t\t\t\tsave from the curse of the undead." << endl;
        cout << "\t\t\t\t======================================================" << endl;
        loading();
        system("cls");
    }
    else if (cas == 3)
    {
    }
    return cas;
}
#endif