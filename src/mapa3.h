#ifndef mapa3_H
#define mapa3_H

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
#include "mapa4.h"
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
#define exit 7

int mapa3[FIL][COL];
extern character player;
void imprimir_mapa3();
void copia_nivel3();
void inicializar_mapa3();
void mover_personaje_wasd3();

void inicializar_mapa3()
{
    for (int i = 0; i < FIL; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            if (i == 0 || i == FIL - 1 || j == 0 || j == COL - 1)
            {
                mapa3[i][j] = 1;
            }
            else
            {
                mapa3[i][j] = 0;
            }
        }
    }
}

void imprimir_mapa3()
{
    int espacios = (ANCHO_TERMINAL - COL) / 2;
    for (int i = 0; i < FIL; ++i)
    {
        for (int s = 0; s < espacios; ++s)
            cout << " ";
        for (int j = 0; j < COL; ++j)
        {
            switch (mapa3[i][j])
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
            case exit:
                cout << "X";
                break;
            default:
                cout << " ";
                break;
            }
        }
        cout << endl;
    }
}

void copia_nivel3()
{
    int nivel3[FIL][COL] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 3, 0, 0, 5, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 4, 0, 0, 5, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 4, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3, 0, 0, 0, 5, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 5, 0, 5, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 7, 0, 6, 0, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 5, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1, 1, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 5, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 5, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    for (int i = 0; i < FIL; ++i)
        for (int j = 0; j < COL; ++j)
            mapa3[i][j] = nivel3[i][j];
}

void mover_personaje_wasd3(character &player)
{
    int px = -1, py = -1;
    for (int i = 0; i < FIL; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            if (mapa3[i][j] == 2)
            {
                px = i;
                py = j;
                break;
            }
        }
        if (px != -1)
            break;
    }
    imprimir_mapa3();
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
        case 'i':
        case 'I':
        case ESC:
            int tecla;
            bool repite = true;
            int opcion = 1;
            do
            {
                system("cls");
                gotoxy(0, 0);
                cout << (opcion == 1 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Inventory\n";
                cout << (opcion == 2 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Save game\n";
                cout << (opcion == 3 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Exit\n";

                tecla = getch();

                switch (tecla)
                {
                case TECLA_ARRIBA:
                case 'w':
                case 'W':
                    opcion--;
                    if (opcion < 1)
                        opcion = 3;
                    break;
                case TECLA_ABAJO:
                case 's':
                case 'S':
                    opcion++;
                    if (opcion > 3)
                        opcion = 1;
                    break;
                case ENTER:
                    switch (opcion)
                    {
                    case 1:
                        Inventory();
                        break;
                    case 2:
                        save(player, className);
                        break;
                    case 3:
                        repite = false;
                        break;
                    }
                    break;
                }
            } while (repite);
            break;
        }
        if (nx >= 0 && nx < FIL && ny >= 0 && ny < COL)
        {
            int celda = mapa3[nx][ny];

            if (celda == 0)
            {
                // Movimiento libre
                mapa3[px][py] = 0;
                px = nx;
                py = ny;
                mapa3[px][py] = characters;
            }
            else if (celda == zombies)
            {
                cout << "\n¡Te encontraste con un ZOMBI! \n";
                sleep(1);
                combatSystem(player, zombie, className);
                mapa3[nx][ny] = 0; // Elimina el zombi
                mapa3[px][py] = 0;
                px = nx;
                py = ny;
                mapa3[px][py] = characters;
            }
            else if (celda == eskeletons)
            {
                cout << "\n¡Un ESQUELETO bloquea tu camino! \n";
                sleep(1);
                combatSystem(player, skeleton, className);
                mapa3[nx][ny] = 0; // Elimina el esqueleto
                mapa3[px][py] = 0;
                px = nx;
                py = ny;
                mapa3[px][py] = characters;
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
                mapa3[nx][ny] = 0; // Quita el cofre
                mapa3[px][py] = 0;
                px = nx;
                py = ny;
                mapa3[px][py] = characters;
            }
            else if (celda == boss)
            {
                cout << "\n¡Te enfrentas al JEFE FINAL! \n";
                combatSystem(player, Dark_knight, className);
                sleep(2);
                mapa3[nx][ny] = 0; // Quita el jefe
                mapa3[px][py] = 0;
                px = nx;
                py = ny;
                mapa3[px][py] = characters;
            }
            else if (celda == exit)
            {
                cout << "\n¡Has encontrado la SALIDA! \n";
                system("cls");
                sleep(1);
                inicializar_mapa4();
                copia_nivel4();
                imprimir_mapa4();
                mover_personaje_wasd4(player);
                return;
            }
        }

        Sleep(0);
        system("cls");
        imprimir_mapa3();
    }
}

#endif
