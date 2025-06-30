#ifndef CRITICAL_H
#define CRITICAL_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "entities/character.h"

using namespace std;

// Estructura de los criticos
struct CriticalInfo {
    bool isCritical = false;
    int damage = 0;
    float multiplier = 1.0f;
};

// Función para calcular la probabilidad de crítico basada en luck
bool tryCritical(int luck) {
    int chance = rand() % 100;
    // Cada punto de luck da 2% de probabilidad de crítico máximo 40% con 20 luck
    int critChance = min(40, luck * 2);
    return chance < critChance;
}

// Función para calcular el multiplicador de crítico según la clase del personaje
float getCriticalMultiplier(const character &player) {
    // Assassin: critico.
    if (player.dex >= 15 && player.luck >= 10) {
        return 2.5f; // 250% daño
    }
    // Mage: crítico mágico
    else if (player.intel >= 20) {
        return 2.2f; // 220% daño
    }
    // Knight: crítico 
    else if (player.def >= 15 && player.strength >= 10) {
        return 2.0f; // 200% daño
    }
    // Berserk: crítico 
    else if (player.hp >= 20 && player.strength >= 12) {
        return 2.3f; // 230% daño
    }
    // Crítico genérico
    else {
        return 1.8f; // 180% daño
    }
}

// Función principal para calcular daño con posibilidad de crítico
CriticalInfo calculateCriticalDamage(const character &player, int baseDamage) {
    CriticalInfo critInfo;
    critInfo.damage = baseDamage;
    
    if (tryCritical(player.luck)) {
        critInfo.isCritical = true;
        critInfo.multiplier = getCriticalMultiplier(player);
        critInfo.damage = (int)(baseDamage * critInfo.multiplier);
    }
    
    return critInfo;
}

// Función para mostrar mensaje de crítico apropiado según la clase
void displayCriticalMessage(const character &player) {
    // Mensaje específico según estadísticas del personaje
    if (player.dex >= 15 && player.luck >= 10) {
        cout << "\t\t\t\t*** ASSASSIN'S PRECISION STRIKE! ***\n";
    }
    else if (player.intel >= 20) {
        cout << "\t\t\t\t*** MAGICAL CRITICAL BURST! ***\n";
    }
    else if (player.def >= 15 && player.strength >= 10) {
        cout << "\t\t\t\t*** KNIGHT'S DEVASTATING BLOW! ***\n";
    }
    else if (player.hp >= 20 && player.strength >= 12) {
        cout << "\t\t\t\t*** BERSERKER'S FURY! ***\n";
    }
    else {
        cout << "\t\t\t\t*** CRITICAL HIT! ***\n";
    }
}

#endif
