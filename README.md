# Proyecto de C++ - Tower of souls

## Descripción del Proyecto

Tower of Souls es un juego de acción RPG por consola donde el jugador debe ascender la Torre de la almas, enfrentando enemigos y jefes en cada piso. El objetivo es llegar a la cima superando desafíos y recolectando objetos. Cada piso presenta enemigos únicos y un jefe final, y el jugador puede encontrar objetos que le ayudarán en su aventura. El juego está desarrollado completamente en C++ y se ejecuta en la terminal, sin dependencias externas.

## Mecánica Principal y Jugabilidad
1. **Objetivo principal:** Supera los 5 niveles de la Torre 

2. **Sistema de combate:** Combate por turno

3. **Controles:** 
- Mover personaje: WASD o  ↑ ↓ → ← 
- Inventario: ESC o I
- Aceptar: ENTER

4. **Mapa:**
- Z : Zombies
- E : Esqueletos
- B : Jefe de Piso 
- X : Salida
- $ : Cofres

## Structura

```
8-Bit Codex/
├── if, Else, Else-If (Verificar celdas de mapa)
├── For (Imprimir el mapa)
├── While, Dowhile (Bucle del juego)
├── Switch (Menu interactivo)
├── Functions (combatSystem)
├── Arrays (Mapas)
├── Structs (Struct character y enemies)
└── Archivos (Save y Load)
```

## Equipo

- **Nombre del equipo:** 8-Bit Codex

### Integrantes del equipo

1. **Nombre completo:** Leandro Javier Aquino Merino
   **Carnet:** 00036725

2. **Nombre completo:** Luis Alessandro Campos Menjivar 
   **Carnet:** 00122425

3. **Nombre completo:** Jefferson Alejandro Alvarado Argueta 
   **Carnet:** 00067525

4. **Nombre completo:** Rodrigo Alejandro hernandez Guerra
   **Carnet:** 00207525

## Requisitos Previos

- Compilador de C++ (recomendado: g++ 6.3.0 MinGW)
- Sistema operativo: Unicamente Windows

## Instrucciones de Ejecución

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone https://github.com/FDP-01-2025/project-8-bit-codex.git
2. Abre una terminal en la carpeta del proyecto.

3. Ejecuta el siguiente comando:
   ```bash
   g++ -o main.cpp
   ```
4. Ejecuta el programa generado:
   ```bash
   main.exe
   ```
