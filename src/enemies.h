#ifndef enemies_H
#define enemies_H

struct enemies
{
    int hp;
    int strength;
};

//normal enemies
const enemies skeleton = {10, 5};
const enemies zombie = {8, 8};

//Boss
const enemies Dragon = {15, 15};
const enemies Mini_Dragon = {15, 15};
const enemies Dark_knight = {20, 10};
const enemies orc = {20, 30};
const enemies Spider = {19, 20};

#endif