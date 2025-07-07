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

using namespace std;
int itemCount = 0;
string inventory[MAX_ITEMS];


int main()
{

    system("cls");
    int opcion = menu_principal(); //Un filtro para las opciones del menu
    if (opcion == 1 )
    {
        // loop del juego
        int itemCount = 0;
        string inventory[MAX_ITEMS];

        gotoxy(0, 0);
        hideCursor();
        copia_nivel1();
        mover_personaje_wasd(player);
        return 0;
    }
    else if(opcion == 2){
        // loop del juego
        int itemCount = 0;
        string inventory[MAX_ITEMS];
        
        if (player.tower_level == 0) {
        
            gotoxy(0, 0);
            hideCursor();
            copia_nivel1();
            mover_personaje_wasd(player);
            return 0;
        }else if (player.tower_level == 1) 
        {
            gotoxy(0, 0);
            hideCursor();
            copia_nivel2();
            mover_personaje_wasd2(player);
        }else if (player.tower_level == 2){
            gotoxy(0, 0);
            hideCursor();
            copia_nivel3();
            mover_personaje_wasd3(player);
        }else if (player.tower_level == 3){
            gotoxy(0, 0); 
            hideCursor();
            copia_nivel4();
            mover_personaje_wasd4(player);
        }else if (player.tower_level == 4){
            gotoxy(0, 0);
            hideCursor();  
            copia_nivel5();
            mover_personaje_wasd5(player);
        }
        
        

    }
    cout << "\t\t\t\t=======================\n";
    cout << "\t\t\t\tThank you for playing! \n";
    cout << "\t\t\t\t=======================\n";
    Sleep(1000);
}