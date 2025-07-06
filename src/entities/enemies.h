#ifndef enemies_H
#define enemies_H

struct enemies
{
    int hp;
    int strength;
};

//normal enemies
const enemies skeleton = {100000, 5};
const enemies zombie = {100000, 8};

//Boss
const enemies Dragon = {1900000, 30};
const enemies Mini_Dragon = {1700000, 15};
const enemies Dark_knight = {1500000, 10};
const enemies orc = {1100000, 30};
const enemies Spider = {1000000, 20};

#endif