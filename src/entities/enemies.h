#ifndef enemies_H
#define enemies_H
//Estructura de enemigos
struct enemies//Stadisticas de un enemigos base
{
    int hp;
    int strength;
};

//normal enemies
const enemies skeleton = {70, 5};
const enemies zombie = {70, 4};

//Boss
const enemies Dragon = {800, 20};
const enemies Mini_Dragon = {600, 17};
const enemies Dark_knight = {450, 16};
const enemies orc = {300, 15};
const enemies Spider = {250, 10};

#endif