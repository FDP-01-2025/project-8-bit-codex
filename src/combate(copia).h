/*aqui se copio el archivo de combate original
para no saturarlo de texto inecesario y poder trabajarlo
sin la posibilidad de malobrarlo*/

#ifndef COMBAT_H
#define COMBAT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "entities/character_visuals.h"
#include "entities/enemies_visuals.h" // Aquí está definido enemyVisuals
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
    if (player.intel > 0 && player.dex <= 5 && player.strength <= 5) {
        baseDamage += (rand() % player.intel);
    }
    return baseDamage;
}

// Función para calcular la probabilidad de evasión del jugador en combate.
bool tryEvade(int luck) { 
    int chance = rand() % 100;
    return chance < luck; // 1 punto en luck es 1% de prob de evadir
}

// Función para calcular evasión del enemigo
bool enemyTryEvade() {
    int chance = rand() % 100;
    return chance < 15; // 15% de probabilidad fija para evadir
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
        cout << (option == 1 ? "\t\t\t\t==> Attack\n" : "\t\t\t\t    Attack\n" );
        cout << (option == 2 ? "\t\t\t\t==> Use Object\n" : "\t\t\t\t    Use Object\n");
        cout << (option == 3 ? "\t\t\t\t==> Block\n" : "\t\t\t\t    Block\n" );
        cout << "\t\t\t\t========================================================\n";

        tecla = getch();

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
                        CriticalInfo critInfo = calculateCriticalDamage(player, baseDamage);

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
                                cout << "\t\t\t\tCritical hit! You dealt " << critInfo.damage << " damage (x" << critInfo.multiplier << ")!\n";
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
                        system("cls");
                        break;
                    case 3: // Bloquear
                        if (state.blockUses > 0) {
                            state.isBlocking = true;
                            state.blockUses--;

                            if (state.blockUses == 2) {
                                state.defenseBoost = 50;
                                state.evasionBoost = 50;
                            } else if (state.blockUses == 1) {
                                state.defenseBoost = 30;
                                state.evasionBoost = 30;
                            } else if (state.blockUses == 0) {
                                state.defenseBoost = 10;
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
void enemyTurn(character &player, const enemies &enemy, PlayerState &state) {
    system("cls");
    static bool lastEnemyEvaded = false;

    cout << "\t\t\t\tEnemy's Turn...\n";

    if (!lastEnemyEvaded && (rand() % 100) < 20 && enemyTryEvade()) {
        cout << "\t\t\t\tThe enemy evades your previous attack!\n";
        lastEnemyEvaded = true;
        Sleep(1000);
        return;
    } else {
        lastEnemyEvaded = false;
    }

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

    int damage = max(20, enemy.strength - (player.def / 2));
    player.hp -= damage;
    cout << "\t\t\t\tYou were hit for " << damage << " damage.\n";
    Sleep(1000);
}

// Sistema principal de combate
void combatSystem(character &player, enemyVisuals &enemy, string &className) {
    srand(time(0));
    PlayerState state;
    int turnCounter = 0;

    system("cls");
    cout << enemy.image; // Muestra la imagen ASCII del enemigo
    cout << "\nGet ready for battle!\n";
    Sleep(1500);
    system("cls");

    while (player.hp > 0 && enemy.data.hp > 0) {
        turnCounter++;

        playerTurn(player, enemy.data, state);
        if (enemy.data.hp <= 0) break;

        enemyTurn(player, enemy.data, state);
        if (player.hp <= 0) break;
    }

    system("cls");

    if (player.hp <= 0) {
        cout << "\t\t\t\tGAME OVER\n";
        cout << " " << endl;
        cout << "\t\t\t\tPress any key to return to main menu...\n";
        getch();
    } else {
        cout << "\t\t\t\tPREY SLAUGHTERED\n";
        cout << " " << endl;
        cout << "\t\t\t\tYou gained 1 level!\n";
        player.level++;
        Sleep(2000);
    }
}

#endif