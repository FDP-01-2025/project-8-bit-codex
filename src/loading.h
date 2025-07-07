#ifndef loading_H
#define loading_H
#include <iostream>
#include <windows.h>
using namespace std;

void loading(){  //Pantalla de carga 
    char x =219;
    cout <<"========================"<<endl;
    cout <<"Loading Please Wait     "<<endl;
    for (int i = 1; i <=20; i++){
        cout <<x;
        Sleep(200);
    }
}
#endif