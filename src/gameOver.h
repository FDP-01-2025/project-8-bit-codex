#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include "entities/character.h"
#include "save.h"
#include "load.h"
#include "utils/Screen.h"
#include "utils/inputs.h"
#include "menu.h"

using namespace std;

// Función para volver al menú principal
void returnToMainMenu() {
    system("cls");
    cout << "\t\t\t\tReturning to Main Menu...\n";
    Sleep(1000);
    
    // Llamar al menú principal
    int opcion = menu_principal();
    if (opcion == 1 || opcion == 2) {
        // El juego continúa desde el menú
        cout << "\t\t\t\tStarting game...\n";
        Sleep(1000);
    }
}

// Función para mostrar opciones de Game Over
void gameOverMenu(character &player, string &className) {
    system("cls");
    hideCursor();
    int tecla;
    int opcion = 1;
    bool repite = true;

    while (repite) {
        gotoxy(0, 0);
        cout << "\t\t\t\t========================================================\n";
        cout << "\t\t\t\t                    *** GAME OVER ***                   \n";
        cout << "\t\t\t\t                Your journey ends here...               \n";
        cout << "\t\t\t\t========================================================\n";
        cout << (opcion == 1 ? "\t\t\t\t==> " : "\t\t\t\t    ") << "Exit Game\n";
        cout << "\t\t\t\t========================================================\n";

        tecla = getch();

        switch (tecla) {
            case TECLA_ARRIBA:
            case 'w':
            case 'W':
                opcion--;
                if (opcion < 1) opcion = 1;
                break;
            case TECLA_ABAJO:
            case 's':
            case 'S':
                opcion++;
                if (opcion > 1) opcion = 1;
                break;
            case ENTER:
                switch (opcion) {
                    case 1: // Salir del juego
                        system("cls");
                        cout << "\t\t\t\t=======================\n";
                        cout << "\t\t\t\tThank you for playing! \n";
                        cout << "\t\t\t\t=======================\n";
                        Sleep(1000);
                        exit(0); // Salir del programa
                        break;
                }
                break;
            case ESC:
                repite = false;
                break;
        }
    }
}

#endif