#ifndef ENEMY_VISUALS_H
#define ENEMY_VISUALS_H

#include "enemies.h" // Aquí están definidos los enemigos y sus estadisticas correspondientes
#include "image.h"     // Aquí están definidas las imágenes ASCII de cada enemigo

// Estructura que combinara datos del enemigo + su imagen ASCII
struct enemyVisuals {
    enemies data;
        // Datos del enemigo (hp, strength)
    const char* image;      // Puntero a la imagen ASCII, por asi decirlo una forma de concatenar
};

// Aqui se asocia cada enemigo con su respectiva imagen ASCII para ser usado en un cpp

//enemigos normales
extern const enemyVisuals skeleton_with_image;
extern const enemyVisuals zombie_with_image;

//jefazos
extern const enemyVisuals Dragon_with_image;
extern const enemyVisuals Mini_Dragon_with_image;
extern const enemyVisuals Dark_knight_with_image;
extern const enemyVisuals Dark_knight_with_image;
extern const enemyVisuals Spider_with_image;

#endif