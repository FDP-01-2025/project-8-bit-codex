#include "mapa5.h"
#include "utils/Screen.h"
int main() {
    gotoxy(-1,-1);
    hideCursor();
    copia_nivel5();
    mover_personaje_wasd();
    return 0;
}
