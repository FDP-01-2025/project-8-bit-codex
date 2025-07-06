#include <iostream>
#include <windows.h>
#include "src/menu.h"
#include "src/Inventory.h"

using namespace std;
int itemCount = 0;
string inventory[MAX_ITEMS];


int main()
{
    
    system("cls");
    int opcion = menu_principal();
    if (opcion == 1 || opcion == 2) {
        //loop del juego
    }
    cout << "\t\t\t\t=======================\n";
    cout << "\t\t\t\tThank you for playing! \n";
    cout << "\t\t\t\t=======================\n";
    Sleep(1000);
    
}