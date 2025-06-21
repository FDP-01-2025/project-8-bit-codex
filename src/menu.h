#ifndef menu_H
#define menu_H

#include "new.h"
#include "load.h"
#include "character.h"
#include <iostream>
#include <conio.h>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
using namespace std;
void menu_new()
{
    new_game();
}
void menu_load()
{
    character assasin;
    load_game(assasin);
}
void menu_principal()
{
    int tecla;
    bool repite = true;
    int opcion = 1;
    do
    {
        system("cls");
        cout << "===============================" << endl;
        cout << "         Tower of souls        " << endl;
        cout << "===============================" << endl;
        cout << (opcion == 1 ? "==> " : "   ") << "  New Game" << endl;
        cout << (opcion == 2 ? "==> " : "   ") << "  Load Game" << endl;
        cout << (opcion == 3 ? "==> " : "   ") << "  Exit" << endl;

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
                break;
            case 2:
                menu_load();
                break;
            case 3:
                repite = false;
                break;
            }
            break;
        }
    }while (repite);
}
#endif