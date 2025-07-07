#ifndef enemies_H
#define enemies_H
//Estructura de enemigos
struct enemies//Stadisticas de un enemigos base
{
    int hp;
    int strength;
};

//normal enemies
const enemies skeleton = {70, 10};
const enemies zombie = {70, 10};

//Boss
const enemies Dragon = {800, 100};
const enemies Mini_Dragon = {600, 80};
const enemies Dark_knight = {450, 60};
const enemies orc = {300, 50};
const enemies Spider = {250, 30};

#endif