#ifndef ENEMY_VISUALS_H
#define ENEMY_VISUALS_H

#include "enemies.h" // Aquí están definidos los enemigos y sus estadisticas correspondientes
#include "image.h"     // Aquí están definidas las imágenes ASCII de cada enemigo

// Estructura que combina datos del enemigo + su imagen ASCII
struct enemyVisuals {
    enemies data;         // Datos del enemigo (hp, strength)
    const char* image;      // Puntero a la imagen ASCII
};

// Aqui se asocia cada enemigo con su respectiva imagen ASCII para ser usado en un cpp
extern const enemyVisuals image_eskeleton;
extern const enemyVisuals image_zombie;

extern const enemyVisuals image_dragon;
extern const enemyVisuals image_young_dragon;
extern const enemyVisuals image_Dark_Knight;
extern const enemyVisuals orc_with_art;
extern const enemyVisuals image_spider;

#endif