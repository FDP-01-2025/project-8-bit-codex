#ifndef menu_H
#define menu_H

#include "new.h"
#include "load.h"
#include "character.h"
#include "loading.h"
#include "imagen.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
using namespace std;
void menu_new()
{
    character player;
    string className;
    new_game(player, className);
}
void menu_load(int cla)
{
    character player;
    string className;
    load_game(player, className);
}
void menu_principal()
{
    int cas;
    int tecla;
    bool repite = true;
    int opcion = 1;
    do
    {
        system("cls");
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

        tecla = getch();

        switch (tecla)
        {
        case TECLA_ARRIBA:
            opcion--;
            if (opcion < 1)
                opcion = 3;
            break;
        case TECLA_ABAJO:
            opcion++;
            if (opcion > 3)
                opcion = 1;
            break;
        case ENTER:
            switch (opcion)
            {
            case 1:
                menu_new();
                cas = 1;
                repite = false;
                break;
            case 2:
                menu_load;
                cas = 2;
                repite = false;
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
}
#endif