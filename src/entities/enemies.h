#ifndef enemies_H
#define enemies_H
//Estructura de enemigos
struct enemies//Stadisticas de un enemigos base
{
    int hp;
    int strength;
};

//normal enemies
const enemies skeleton = {70, 1};
const enemies zombie = {70, 1};

//Boss
const enemies Dragon = {800, 10};
const enemies Mini_Dragon = {600, 8};
const enemies Dark_knight = {450, 6};
const enemies orc = {300, 5};
const enemies Spider = {250, 3};

#endif