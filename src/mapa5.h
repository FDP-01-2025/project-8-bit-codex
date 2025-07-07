#ifndef mapa5_H
#define mapa5_H

#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <string>
#include "loading.h"
#include "image.h"
#include "utils/inputs.h"
#include "entities/enemies.h"
#include "chest.h"
#include "combat.h"
#include "new.h"
#include "entities/character.h"
#include "Inventory.h"
using namespace std;

//se define la altura y el ancho del mapa
#define FIL 28
#define COL 80
#define ANCHO_TERMINAL 80

//se define los tipos de celda del mapa
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

// Imprime el mapa en la consola
void imprimir_mapa5()
{
    gotoxy(0, 0);
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

// Mueve al personaje en el mapa usando las teclas WASD o flechas
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
                cout << "\t\t\t\t================================================\n";
                cout << (opcion == 1 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Inventory\n";
                cout << (opcion == 2 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Save game\n";
                cout << (opcion == 3 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Exit\n";
                cout << "\t\t\t\t================================================\n";

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
                        Inventory(player);
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
                system("cls");
                cout << "\t\t\t\t=================================\n";
                cout << "\t\t\t\t         You met a zombie        \n";
                cout << "\t\t\t\t=================================\n";
                image_zombie();
                sleep(2);
                combatSystem(player, zombie, className);
                mapa5[nx][ny] = 0; // Elimina el zombi
                mapa5[px][py] = 0;
                px = nx;
                py = ny;
                mapa5[px][py] = characters;
            }
            else if (celda == eskeletons)
            {
                system("cls");
                cout << "\t\t\t\t=================================\n";
                cout << "\t\t\t\t   A skeleton blocks your path   \n";
                cout << "\t\t\t\t=================================\n";
                image_eskeleton();
                sleep(2);
                combatSystem(player, skeleton, className);
                mapa5[nx][ny] = 0; // Elimina el esqueleto
                mapa5[px][py] = 0;
                px = nx;
                py = ny;
                mapa5[px][py] = characters;
            }
            else if (celda == chests)
            {
                cout << "\n  You have found a chest  \n";
                string objeto = chest();
                if (objeto != "Enemy Encountered" && objeto != "Empty Chest" && !objeto.empty())
                {
                    addToInventory(objeto);
                }
                else if (objeto == "Enemy Encountered")
                {
                    combatSystem(player, zombie, className);
                }
                sleep(2);
                system("cls");
                mapa5[nx][ny] = 0; // Quita el cofre
                mapa5[px][py] = 0;
                px = nx;
                py = ny;
                mapa5[px][py] = characters;
            }
            else if (celda == boss)
            {
                // Encuentra al jefe final
                system ("cls");
                cout << "\t\t\t\t=================================\n";
                cout << "\t\t\t\t      You face the final boss    \n";
                cout << "\t\t\t\t=================================\n";
                image_dragon();
                Sleep(3000);
                combatSystem(player, Dragon, className);
                    cout << "\t\t\t\t=======================\n";
                    cout << "\t\t\t\tThank you for playing! \n";
                    cout << "\t\t\t\t=======================\n";
                mapa5[nx][ny] = 0; // Quita el jefe
                mapa5[px][py] = 0;
                px = nx;
                py = ny;
                mapa5[px][py] = characters;
            }
        }

        Sleep(0);
        imprimir_mapa5();
    }
}

#endif
