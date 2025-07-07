#ifndef TOWER_LEVEL_H
#define TOWER_LEVEL_H

#include <iostream>
#include <windows.h>
#include <fstream>
#include "mapa.h"
#include "mapa2.h"
#include "mapa3.h"
#include "mapa4.h"
#include "mapa5.h"
#include "new.h"
#include "utils/Screen.h"
#include "utils/inputs.h"
#include "entities/character.h"
#include "combat.h"

void load(){
// loop del juego
        int itemCount = 0;
        string inventory[MAX_ITEMS];
        
        if (player.tower_level == 0) {
            gotoxy(0, 0);
            hideCursor();
            copia_nivel1();
            mover_personaje_wasd(player);
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

#endif