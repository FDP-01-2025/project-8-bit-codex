#include "enemies_visuals.h"

// Aqui se declaran las estructuras originales de los enemigos 
extern const enemies skeleton;
extern const enemies zombie;

extern const enemies Dragon;
extern const enemies Mini_Dragon;
extern const enemies Dark_knight;
extern const enemies orc;
extern const enemies Spider;

// Se declararon las imagenes externas
extern const char* image_eskeleton;
extern const char* image_zombie;

extern const char* image_dragon;
extern const char* image_young_dragon;
extern const char* image_Dark_Knight;
extern const char* image_orc;
extern const char* image_spider;

// Aqui se asocia enemigo + imagen
const enemyVisuals skeleton_with_image = {skeleton, image_eskeleton};
const enemyVisuals zombie_with_image = {zombie, image_zombie};

const enemyVisuals Dragon_with_image = {Dragon, image_dragon};
const enemyVisuals Mini_Dragon_with_image = {Mini_Dragon, image_young_dragon};
const enemyVisuals Dark_knight_with_image = {Dark_knight, image_Dark_Knight};
const enemyVisuals Dark_knight_with_image = {orc, image_orc};
const enemyVisuals Spider_with_image = {Spider, image_spider};