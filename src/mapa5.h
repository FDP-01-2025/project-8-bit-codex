#ifndef mapa5_H
#define mapa5_H

#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <string>
#include "utils/inputs.h"
#include "entities/enemies.h"
#include "chest.h"
#include "combat.h"
#include "new.h"
#include "entities/character.h"
#include "Inventory.h"
using namespace std;

#define FIL 28
#define COL 80
#define ANCHO_TERMINAL 80

#define wall 1
#define characters 2
#define zombies 3
#define eskeletons 4
#define chests 5
#define boss 6

int mapa5[FIL][COL];
extern character player;
void imprimir_mapa5();
void copia_nivel5();
void inicializar_mapa5();
void mover_personaje_wasd5();

void inicializar_mapa5()
{
    for (int i = 0; i < FIL; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            if (i == 0 || i == FIL - 1 || j == 0 || j == COL - 1)
            {
                mapa5[i][j] = 1;
            }
            else
            {
                mapa5[i][j] = 0;
            }
        }
    }
}

void imprimir_mapa5()
{
    int espacios = (ANCHO_TERMINAL - COL) / 2;
    for (int i = 0; i < FIL; ++i)
    {
        for (int s = 0; s < espacios; ++s)
            cout << " ";
        for (int j = 0; j < COL; ++j)
        {
            switch (mapa5[i][j])
            {
            case wall:
                cout << "#";
                break;
            case characters:
                cout << "*";
                break;
            case zombies:
                cout << "Z";
                break;
            case eskeletons:
                cout << "E";
                break;
            case chests:
                cout << "$";
                break;
            case boss:
                cout << "B";
                break;
            default:
                cout << " ";
                break;
            }
        }
        cout << endl;
    }
}

void copia_nivel5()
{
    int nivel5[FIL][COL] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 4, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1, 1, 5, 3, 0, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 3, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 3, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 6, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 4, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 3, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 4, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1, 1, 5, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 4, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},

    };
    for (int i = 0; i < FIL; ++i)
        for (int j = 0; j < COL; ++j)
            mapa5[i][j] = nivel5[i][j];
}

void mover_personaje_wasd5(character &player)
{
    int px = -1, py = -1;
    for (int i = 0; i < FIL; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            if (mapa5[i][j] == 2)
            {
                px = i;
                py = j;
                break;
            }
        }
        if (px != -1)
            break;
    }
    imprimir_mapa5();
    while (true)
    {
        char tecla = _getch();
        int nx = px, ny = py;
        switch (tecla)
        {
        case 'w':
        case 'W':
        case TECLA_ARRIBA:
            nx--;
            break;
        case 's':
        case 'S':
        case TECLA_ABAJO:
            nx++;
            break;
        case 'a':
        case 'A':
        case TECLA_IZQUIERDA:
            ny--;
            break;
        case 'd':
        case 'D':
        case TECLA_DERECHA:
            ny++;
            break;
        case 'q':
        case 'Q':
        case ESC:
            break;
        }
        if (nx >= 0 && nx < FIL && ny >= 0 && ny < COL)
        {
            int celda = mapa5[nx][ny];

            if (celda == 0)
            {
                // Movimiento libre
                mapa5[px][py] = 0;
                px = nx;
                py = ny;
                mapa5[px][py] = characters;
            }
            else if (celda == zombies)
            {
                cout << "\n¡Te encontraste con un ZOMBI! \n";
                sleep(1);
                combatSystem(player, zombie, className);
                mapa5[nx][ny] = 0; // Elimina el zombi
                mapa5[px][py] = 0;
                px = nx;
                py = ny;
                mapa5[px][py] = characters;
            }
            else if (celda == eskeletons)
            {
                cout << "\n¡Un ESQUELETO bloquea tu camino! \n";
                sleep(1);
                combatSystem(player, skeleton, className);
                mapa5[nx][ny] = 0; // Elimina el esqueleto
                mapa5[px][py] = 0;
                px = nx;
                py = ny;
                mapa5[px][py] = characters;
            }
            else if (celda == chests)
            {
                cout << "\n¡Has encontrado un COFRE! \n";
                string objeto = chest();
                if (objeto != "Enemy Encountered" && objeto != "Empty Chest" && !objeto.empty())
                {
                    addToInventory(objeto);
                }
                sleep(2);
                mapa5[nx][ny] = 0; // Quita el cofre
                mapa5[px][py] = 0;
                px = nx;
                py = ny;
                mapa5[px][py] = characters;
            }
            else if (celda == boss)
            {
                cout << "\n¡Te enfrentas al JEFE FINAL! \n";
                combatSystem(player, Dragon, className);
                sleep(2);
                mapa5[nx][ny] = 0; // Quita el cofre
                mapa5[px][py] = 0;
                px = nx;
                py = ny;
                mapa5[px][py] = characters;
            }
        }

        Sleep(0);
        system("cls");
        imprimir_mapa5();
    }
}

#endif
