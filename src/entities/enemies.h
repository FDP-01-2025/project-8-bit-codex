#ifndef enemies_H
#define enemies_H

struct enemies
{
    int hp;
    int strength;
};

//normal enemies
const enemies skeleton = {100000, 1};
const enemies zombie = {100000, 1};

//Boss
const enemies Dragon = {1400000, 7};
const enemies Mini_Dragon = {1300000, 6};
const enemies Dark_knight = {1200000, 5};
const enemies orc = {1100000, 4};
const enemies Spider = {1000000, 3};

#endif