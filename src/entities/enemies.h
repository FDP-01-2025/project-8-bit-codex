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
const enemies Dragon = {350, 7};
const enemies Mini_Dragon = {300, 6};
const enemies Dark_knight = {250, 5};
const enemies orc = {200, 4};
const enemies Spider = {150, 3};

#endif