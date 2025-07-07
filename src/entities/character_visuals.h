#ifndef CHARACTER_VISUALS_H
#define CHARACTER_VISUALS_H

#include "character.h" // Aquí están definidos los personajes y sus estadisticas correspondientes
#include "image.h"     // Aquí están definidas las imágenes ASCII de cada personaje

// Estructura que combina datos del personaje + su imagen ASCII
struct characterVisuals {
    character data;         // Datos del personaje (hp, strength,etc)
    const char* image;      // Puntero a la imagen ASCII
};

// Aqui se asocia cada personaje con su respectiva imagen ASCII para ser usado en un cpp
extern const characterVisuals knight_with_image;

extern const characterVisuals assasin_with_image;

extern const characterVisuals mage_with_image;

extern const characterVisuals berserk_with_image;

#endif