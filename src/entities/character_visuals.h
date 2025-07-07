#ifndef CHARACTER_VISUALS_H
#define CHARACTER_VISUALS_H

#include "character.h" // Aquí están definidos los enemigos y sus estadisticas correspondientes
#include "image.h"     // Aquí están definidas las imágenes ASCII de cada enemigo

// Estructura que combina datos del enemigo + su imagen ASCII
struct characterVisuals {
    character data;         // Datos del enemigo (hp, strength)
    const char* image;      // Puntero a la imagen ASCII
};

// Aqui se asocia cada enemigo con su respectiva imagen ASCII para ser usado en un cpp
extern const characterVisuals image_knight;

extern const characterVisuals image_assasin;

extern const characterVisuals image_mage;

extern const characterVisuals image_berserk;

#endif