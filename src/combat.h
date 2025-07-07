#ifndef COMBAT_H
#define COMBAT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstdlib> 
#include "entities/character.h"
#include "entities/enemies.h"
#include "utils/screen.h"
#include "inventory.h"
#include "critical.h"
#include "gameOver.h"

using namespace std;

// Estructura para estados especiales del jugador mientras este en combate.
struct PlayerState {
    bool isBlocking = false;
    int blockUses = 3;
    int defenseBoost = 0;
    int evasionBoost = 0;
};

// Función para calcular el daño que realiza el jugador mientras esta en combate.
int calculatePlayerDamage(const character &player) {
    int baseDamage = 0;
    if (player.dex + player.strength > 0) {
        baseDamage = (rand() % (player.dex + player.strength)) + 1;
    }
    // Estructura solo para el personaje "mage".
    if (player.intel > 0 && player.dex <= 5 && player.strength <= 5) {
        baseDamage += (rand() % player.intel);
    }
    return baseDamage;
}

// Función para calcular la probabilidad de evasión del jugador en combate.
bool tryEvade(int luck) { 
    int chance = rand() % 100;
    return chance < luck; //1 punto en luck es 1% de prob de evadir, ejemplo: 10% de evadir si luck = 10.
}

// Función para calcular evasión del enemigo
bool enemyTryEvade() {
    int chance = rand() % 100;
    return chance < 15; // 15% de probabilidad fija para evadir, no mas de dos veces seguidas para que no sea injusto.
}

// Turno del jugador
void playerTurn(character &player, enemies &enemy, PlayerState &state) {
    system("cls");
    hideCursor();
    int tecla;
    int option = 1;
    bool repite = true;

    while (repite) {
        gotoxy(0, 0);
        cout << "\t\t\t\t===================== Your Turn ==========================\n";
        cout << (option == 1 ? "\t\t\t\t==> Attack\n" : "\t\t\t\t    Attack\n"        );
        cout << (option == 2 ? "\t\t\t\t==> Use Object\n" : "\t\t\t\t    Use Object\n");
        cout << (option == 3 ? "\t\t\t\t==> Block\n" : "\t\t\t\t    Block\n"          );
        cout << "\t\t\t\t========================================================\n"   ;

        tecla = getch();//para ingresar datos en la consola sin presionar enter

        switch (tecla) {
            case TECLA_ARRIBA:
            case 'w':
            case 'W':
                option--;
                if (option < 1) option = 3;
                break;
            case TECLA_ABAJO:
            case 's':
            case 'S':
                option++;
                if (option > 3) option = 1;
                break;
            case ENTER:
                switch (option) {
                    case 1: { // Atacar
                        system("cls");
                        int baseDamage = calculatePlayerDamage(player);
                        
                        // Calcular si hay crítico y el daño final
                        CriticalInfo critInfo = calculateCriticalDamage(player, baseDamage);
                        
                        // Mostrar mensaje de crítico si aplica
                        if (critInfo.isCritical) {
                            displayCriticalMessage(player);
                            Sleep(800);
                        }
                        
                        if (enemy.hp - critInfo.damage <= 0) {
                            enemy.hp = 0;
                            cout << "\t\t\t\tEnemy defeated!\n";
                            Sleep(1000);
                        } else {
                            enemy.hp -= critInfo.damage;
                            if (critInfo.isCritical) {
                                cout << "\t\t\t\tCritical hit! You dealt " << critInfo.damage 
                                     << " damage (x" << critInfo.multiplier << ")!\n";
                            } else {
                                cout << "\t\t\t\tYou hit the enemy for " << critInfo.damage << " damage.\n";
                            }
                            Sleep(1000);
                        }
                        repite = false;
                        break;
                    }
                    case 2: // Usar objeto
                        Inventory(); // Abre el menú de inventario
                        system ("cls");
                        break;
                    case 3: // Accion de combate bloquear
                        if (state.blockUses > 0) {
                            state.isBlocking = true;
                            state.blockUses--;

                            if (state.blockUses == 2) {  //Primer uso
                                state.defenseBoost = 50; // Bloqueo total de daño
                                state.evasionBoost = 50;
                            } else if (state.blockUses == 1) { //Segundo uso
                                state.defenseBoost = 30;       //Bloqueo pierde efectividad
                                state.evasionBoost = 30;
                            } else if (state.blockUses == 0) {//Tercer uso
                                state.defenseBoost = 10;      //Bloqueo casi agotado
                                state.evasionBoost = 10;
                            }

                            cout << "\t\t\t\tYou take a defensive stance!\n";
                            Sleep(1000);
                            repite = false;
                        } else {
                            cout << "\t\t\t\tNo more blocks left.\n";
                            Sleep(1000);
                        }
                        break;
                }
                break;
            case ESC:
                repite = false;
                break;
        }
    }
}

// Turno del enemigo
void enemyTurn(character &player, enemies &enemy, PlayerState &state) {
    system("cls");
    static bool lastEnemyEvaded = false;

    cout << "\t\t\t\tEnemy's Turn...\n";

// Si no evadió en el último turno, y hay suerte, puede evadir ahora
if (!lastEnemyEvaded && (rand() % 100) < 20 && enemyTryEvade()) {
    cout << "\t\t\t\tThe enemy evades your previous attack!\n";
    lastEnemyEvaded = true;
    Sleep(1000);
    return;
} else {
    lastEnemyEvaded = false; // Permitir evadir en próximo turno
}

    // Si está bloqueando, aplicar efectos
    if (state.isBlocking) {
        int finalDefense = player.def + state.defenseBoost;
        int evadeChance = player.luck + state.evasionBoost;

        if (tryEvade(evadeChance)) {
            cout << "\t\t\t\tYou evaded the attack!\n";
            Sleep(1000);
            state.isBlocking = false;
            return;
        } else {
            int damage = max(0, enemy.strength - (finalDefense / 2));
            player.hp -= damage;
            cout << "\t\t\t\tBlocked attack! You took " << damage << " damage.\n";
            Sleep(1000);
            state.isBlocking = false;
            return;
        }
    }

    // Ataque normal
    int damage = max(20, enemy.strength - (player.def / 2));
    player.hp -= damage;
    cout << "\t\t\t\tYou were hit for " << damage << " damage.\n";
    Sleep(1000);
}

// Sistema principal de combate.
void combatSystem(character &player, enemies enemy, string &className) {//cambie el enemies &enemy a enmies enemy para probar
    srand(time(0));
    PlayerState state;
    int turnCounter = 0;

    while (player.hp > 0 && enemy.hp > 0) {
        turnCounter++;

        playerTurn(player, enemy, state);
        if (enemy.hp <= 0) break;

        enemyTurn(player, enemy, state);
        if (player.hp <= 0) break;
    }

    system("cls");

    if (player.hp <= 0) {
    //Mensaje por si el jugador pierde por manco.

cout << "    ____    _    __  __ _____    _____     _______ ____     " <<endl;
cout << "   / ___|  / \  |  \/  | ____|  / _ \ \   / / ____|  _ \    " <<endl;
cout << "  | |  _  / _ \ | |\/| |  _|   | | | \ \ / /|  _| | |_) |   " <<endl;
cout << "  | |_| |/ ___ \| |  | | |___  | |_| |\ V / | |___|  _ <    " <<endl;
cout << "   \____/_/   \_\_|  |_|_____|  \___/  \_/  |_____|_| \_\   " <<endl;
    cout << " " << endl;
        cout << "\t\t\t\tPress any key to return to main menu...\n";
        /*Falta agregar funcion para volver al menu principal o volver a cargar desde 
        la ultima vez que se guardo*/
        getch();
    } else {
    
cout << " ____  ____  _______   __  ____  _        _   _   _  ____ _   _ _____ _____ ____  _____ ____    " << endl;  
cout << "|  _ \|  _ \| ____\ \ / / / ___|| |      / \ | | | |/ ___| | | |_   _| ____|  _ \| ____|  _ \   " << endl; 
cout << "| |_) | |_) |  _|  \ V /  \___ \| |     / _ \| | | | |  _| |_| | | | |  _| | |_) |  _| | | | |  " << endl;
cout << "|  __/|  _ <| |___  | |    ___) | |___ / ___ \ |_| | |_| |  _  | | | | |___|  _ <| |___| |_| |  " << endl;
cout << "|_|   |_| \_\_____| |_|   |____/|_____/_/   \_\___/ \____|_| |_| |_| |_____|_| \_\_____|____/   " << endl;
        cout << " " << endl;
        cout << "\t\t\t\tYou gained 1 level!\n"; //Informa al jugador que gano un nivel
        
        player.level++; //Nivel del jugador aumenta
        Sleep(2000);
    }
}

#endif