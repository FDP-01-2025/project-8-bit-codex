#include <iostream>
#include <windows.h>
#include <fstream>
#include "src/menu.h"
#include "src/Inventory.h"
#include "src/mapa.h"
#include "src/mapa2.h"
#include "src/mapa3.h"
#include "src/mapa4.h"
#include "src/mapa5.h"
#include "src/new.h"
#include "src/utils/Screen.h"
#include "src/utils/inputs.h"
#include "src/entities/character.h"
#include "src/combat.h"
#include "src/tower_level.h"

using namespace std;
int itemCount = 0;
string inventory[MAX_ITEMS];

int main()
{

    system("cls");
    int opcion = menu_principal(); // Un filtro para las opciones del menu
    if (opcion == 1)
    {
        // loop del juego
        gotoxy(0, 0);
        hideCursor();
        copia_nivel1();
        mover_personaje_wasd(player);
        return 0;
    }
    else if (opcion == 2)
    {
        load();
    }
    cout << "\t\t\t\t=======================\n";
    cout << "\t\t\t\tThank you for playing! \n";
    cout << "\t\t\t\t=======================\n";
    Sleep(1000);
}