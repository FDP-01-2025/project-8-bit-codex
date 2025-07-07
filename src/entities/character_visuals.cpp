#include "character_visuals.h"

// Aqui se declaran las estructuras originales de los personajes
extern const character knight;

extern const character assasin;

extern const character mage;

extern const character berserk;

// Se declararon las imagenes externas de los personajes
extern const char* image_knight;

extern const char* image_assasin;

extern const char* image_mage;

extern const char* image_berserk;


// Aqui se asocia personaje + imagen
const characterVisuals knight_with_image = {knight, image_knight};

const characterVisuals assasin_with_image = {assasin, image_assasin};

const characterVisuals mage_with_image = {mage, image_mage};

const characterVisuals berserk_with_image = {berserk, image_berserk};
