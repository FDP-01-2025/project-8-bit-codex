
#include <iostream>
#include <windows.h>
#include "menu.h"
#include "Inventory.h"
#include "mapa.h"
#include "mapa2.h"
#include "mapa3.h"
#include "mapa4.h"
#include "mapa5.h"
#include "new.h"
#include "utils/Screen.h"
#include "utils/inputs.h"
int itemCount = 0;
string inventory[MAX_ITEMS];
int main() {
    character player;
    gotoxy(0,0);
    hideCursor();
    copia_nivel1();         
    mover_personaje_wasd(player); 
    return 0;
}
