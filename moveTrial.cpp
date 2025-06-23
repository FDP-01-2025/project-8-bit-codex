#include <iostream>
#include <conio.h>  // para _getch()
#include <cstdlib>  // para system("cls")

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;

int x = WIDTH / 2;
int y = HEIGHT / 2;

void dibujar() {
    system("cls"); // Limpia la pantalla (en Windows)

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == y && j == x)
                cout << '@'; // Nuestro personaje
            else
                cout << ' ';
        }
        cout << endl;
    }
}

void entrada() {
    char tecla = _getch(); // Lee una tecla sin necesidad de presionar Enter

    switch (tecla) {
        case 'w': if (y > 0) y--; break;
        case 's': if (y < HEIGHT - 1) y++; break;
        case 'a': if (x > 0) x--; break;
        case 'd': if (x < WIDTH - 1) x++; break;
        case 'q': exit(0); // Para salir
    }
}

int main() {
    while (true) {
        dibujar();
        entrada();
    }
    return 0;
}
