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
void gameOverMenu(character &player, const string &className) {
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
        cout << "\t\t\t\t                What would you like to do?              \n";
        cout << "\t\t\t\t========================================================\n";
        cout << (opcion == 1 ? "\t\t\t\t==> " : "\t\t\t\t    ") << "Load from last save\n";
        cout << (opcion == 2 ? "\t\t\t\t==> " : "\t\t\t\t    ") << "Return to Main Menu\n";
        cout << (opcion == 3 ? "\t\t\t\t==> " : "\t\t\t\t    ") << "Exit Game\n";
        cout << "\t\t\t\t========================================================\n";

        tecla = getch();

        switch (tecla) {
            case TECLA_ARRIBA:
            case 'w':
            case 'W':
                opcion--;
                if (opcion < 1) opcion = 3;
                break;
            case TECLA_ABAJO:
            case 's':
            case 'S':
                opcion++;
                if (opcion > 3) opcion = 1;
                break;
            case ENTER:
                switch (opcion) {
                    case 1: // Cargar desde la ultima vez que se guardo
                        system("cls");
                        cout << "\t\t\t\tLoading from last save...\n";
                        Sleep(1000);
                        if (load_game(player, const_cast<string&>(className))) {
                            cout << "\t\t\t\tGame loaded successfully!\n";
                            Sleep(1000);
                            repite = false;
                        } else {
                            cout << "\t\t\t\tNo save file found. Press any key to continue...\n";
                            getch();
                        }
                        break;
                    case 2: // Volver al menu principal
                        system("cls");
                        returnToMainMenu();
                        repite = false;
                        break;
                    case 3: // Salir del juego
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