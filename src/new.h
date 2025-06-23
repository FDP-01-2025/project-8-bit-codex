#ifndef new_H
#define new_H

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "character.h"

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
using namespace std;
int cha;
void new_game()
{
    int tecla;
    bool repite = true;
    int opcion = 1;
    do
    {
        system("cls");
        cout << "\t\t\t\t======================================================" << endl;
        cout << "\t\t\t\t                   Select you class                  " << endl;
        cout << "\t\t\t\t======================================================" << endl;
        cout << (opcion == 1 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Assasin" << endl;
        cout << (opcion == 2 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Mage" << endl;
        cout << (opcion == 3 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Knight" << endl;
        cout << (opcion == 4 ? "\t\t\t\t==> " : "  \t\t\t\t    ") << "  Berserk" << endl;

        tecla = getch();

        switch (tecla)
        {
        case TECLA_ARRIBA:
            opcion--;
            if (opcion < 1)
                opcion = 4;
            break;
        case TECLA_ABAJO:
            opcion++;
            if (opcion > 4)
                opcion = 1;
            break;
        case ENTER:
            switch (opcion)
            {
            case 1:
                system("cls");
                cout << "\t\t\t\t======================================================" << endl;
                cout << "\t\t\t\tYour character is assasin: " << endl;
                cout << "\t\t\t\tHP: " << assasin.hp << endl;
                cout << "\t\t\t\tDefense: " << assasin.def << endl;
                cout << "\t\t\t\tStrenght:" << assasin.strength << endl;
                cout << "\t\t\t\tdexterity: " << assasin.dex << endl;
                cout << "\t\t\t\tInteligence: " << assasin.intel << endl;
                cout << "\t\t\t\tLuck: " << assasin.luck << endl;
                cout << "\t\t\t\tInicial object: " << assasin.object << endl;
                cout << "\t\t\t\t======================================================" << endl;
                cout << "\t\t\t\t                 .:=-:.:=+:.                 " << endl;
                cout << "\t\t\t\t      .*.       .=:    -@@@+.       .*.      " << endl;
                cout << "\t\t\t\t     :=.=:.    .--...::#@@@@=.    .:=.=:     " << endl;
                cout << "\t\t\t\t      .=:=:    :*::%@@@@@%*@%:    :=-+.      " << endl;
                cout << "\t\t\t\t       .-+-=   =-:@@@@@@@@@##=   ==+-.       " << endl;
                cout << "\t\t\t\t         :+-=..+-*@%%@@@%%@%@%..+++:         " << endl;
                cout << "\t\t\t\t          .=*+#-=%%=%+=*@#@%*@#+*=.          " << endl;
                cout << "\t\t\t\t           .:*==#@@ .:%@@*%@%%@#:.           " << endl;
                cout << "\t\t\t\t          .==-+*%@@-.+%@@%@@%*@%#=.          " << endl;
                cout << "\t\t\t\t       .+=:+=#==*@@@+-#@@@@@*++#**%*+.       " << endl;
                cout << "\t\t\t\t     .==:- .:*--+#@@@@+@@@@%+*+#=#*%-++.     " << endl;
                cout << "\t\t\t\t     .+:.....:%#**+@#*@#%@@%%#@+==+*=*+.     " << endl;
                cout << "\t\t\t\t      --. ..:=%%@%:=#@@@@@@@@%@#+:%=---      " << endl;
                cout << "\t\t\t\t       -+=..-::*#+##*@@@@@%#%#=+%#+**-       " << endl;
                cout << "\t\t\t\t        -+++.:+-=-:--+@*#@+-*@@@##+=-.       " << endl;
                cout << "\t\t\t\t         :+##=*-*=*.===@%=@@@@#=*#+:         " << endl;
                cout << "\t\t\t\t           ..===+*-..-*+%@@@+--=..           " << endl;
                cout << "\t\t\t\t             ..+#++#--%@@@*+#+..             " << endl;
                cout << "\t\t\t\t                 :+#+-@@%%+:                 " << endl;
                cha = 1;
                repite = false;
                Sleep(3000);
                break;
            case 2:
                system("cls");
                cout << "\t\t\t\t======================================================" << endl;
                cout << "\t\t\t\tYour character is Mage: " << endl;
                cout << "\t\t\t\tHP: " << mage.hp << endl;
                cout << "\t\t\t\tDefense: " << mage.def << endl;
                cout << "\t\t\t\tStrenght:" << mage.strength << endl;
                cout << "\t\t\t\tdexterity: " << mage.dex << endl;
                cout << "\t\t\t\tInteligence: " << mage.intel << endl;
                cout << "\t\t\t\tLuck: " << mage.luck << endl;
                cout << "\t\t\t\tInicial object: " << mage.object << endl;
                cout << "\t\t\t\t======================================================" << endl;
                cout << "\t\t\t\t                     @@#++%*+*@@             " << endl;
                cout << "\t\t\t\t                     @%=++#@@@@              " << endl;
                cout << "\t\t\t\t                    @@+==++@@                " << endl;
                cout << "\t\t\t\t                    @@*====++@@              " << endl;
                cout << "\t\t\t\t                    @@=====++#@              " << endl;
                cout << "\t\t\t\t         @@        @@=======++@@             " << endl;
                cout << "\t\t\t\t         @@        @%######-:#%@@            " << endl;
                cout << "\t\t\t\t   @@@   @@@  @@@ @@===========*@            " << endl;
                cout << "\t\t\t\t      @@#==*@@ @@@*+++++++++++++*@@@         " << endl;
                cout << "\t\t\t\t     @#..=#@+#@@###################%@@@      " << endl;
                cout << "\t\t\t\t     @=....=%+@@@%+@=::::=@=:::%**@@@@       " << endl;
                cout << "\t\t\t\t     @@:::::-%@ @@@@#-*%%%@%#=*@@@@          " << endl;
                cout << "\t\t\t\t      @@@%%@@@   @@=@#=--=---*@##@           " << endl;
                cout << "\t\t\t\t      @@%###@@   @==#@**+-=+*%%*=@@          " << endl;
                cout << "\t\t\t\t        @*+@     @*::%%%@%@%#%--+@@          " << endl;
                cout << "\t\t\t\t        =-+@   @@@@#::--:::-=--+@@@@         " << endl;
                cout << "\t\t\t\t        @*+@@@@#***%%:+@-::##-#@***#@@@      " << endl;
                cout << "\t\t\t\t        @*+@@+======#@=%#:=@--======++%@     " << endl;
                cout << "\t\t\t\t        @*+@#========*@*@=%%@#======++*@@    " << endl;
                cout << "\t\t\t\t        @*+@+=========+@@%@@*========++%@    " << endl;
                cout << "\t\t\t\t        @*+@====%%======%@@+=====*%=+++#@    " << endl;
                cout << "\t\t\t\t        @*+@===+@#======+*+======+@*+++*@@   " << endl;
                cout << "\t\t\t\t        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   " << endl;
                cha = 2;
                repite = false;
                Sleep(3000);
                break;
            case 3:
                system("cls");
                cout << "\t\t\t\t======================================================" << endl;
                cout << "\t\t\t\tYour character is Knight: " << endl;
                cout << "\t\t\t\tHP: " << knight.hp << endl;
                cout << "\t\t\t\tDefense: " << knight.def << endl;
                cout << "\t\t\t\tStrenght:" << knight.strength << endl;
                cout << "\t\t\t\tdexterity: " << knight.dex << endl;
                cout << "\t\t\t\tInteligence: " << knight.intel << endl;
                cout << "\t\t\t\tLuck: " << knight.luck << endl;
                cout << "\t\t\t\tInicial object: " << knight.object << endl;
                cout << "\t\t\t\t======================================================" << endl;
                cout << "\t\t\t\t@@@@@@@@@@@@@@@@@@@@-..::..@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@@@@@@@@@@@@@:.#@@*=#@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@@@@@@@@+:%+..*@@=:@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@@@@@@@@@@++*@@@@@@+:#@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@@@@@@@@@@@@@@@*.-@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@#@@@@%:...-#@@@@=..@%.*@@@@@=......+@#+@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@+.....##+....:@@@@@...@@@............@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@::@@-.@#......%.....+@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@#=.=@@*******@#.....@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@*-*@@@=.......@@@@...@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@@@#=.:+@@#-...=%%--:.=@@@@=...+@@@*:=@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@%.....@#+@@@@@@--@@*-:.@%.:@@@.*@@@@@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@=..:@@@#:......=%@@@@#.=@+....*@@@@@@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@:..@@@-............:@#.%%.......@@@@@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@%...@@@=.....+@:.....@#*@*......=@@@@@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@.--.....@@@#.....@@+-----@*-*@=.....@#*@@@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@:....+@@@@-...:@%-%@@@*+@#--=@%...@%::..+@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@@@@@-...-%@*-+@@@@@@@@@@@@@..%@@@+.*@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@@@@@..%@@#--@@@@@@@@@@@@@@@..@+..=@@@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@@@@:.#@@@@@=:*@@@@@@@@@@@@@..@#@@@@@@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@@@@..@@@@@@@@..%@@@@@@@@@@@..@@@@@@@@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@@@#.+@@@@@@@@@*.-@@@@@@@@@@..@@@@@@@@@@@@@@@@@@" << endl;
                cout << "\t\t\t\t@@@@@@@@@*++++++++++++++++++++++++++++++++@@@@@@@@@@@@" << endl;
                cha = 3;
                repite = false;
                Sleep(3000);
                break;
            case 4:
                system("cls");
                cout << "\t\t\t\t======================================================" << endl;
                cout << "\t\t\t\tYour character is Berserker: " << endl;
                cout << "\t\t\t\tHP: " << berserk.hp << endl;
                cout << "\t\t\t\tDefense: " << berserk.def << endl;
                cout << "\t\t\t\tStrenght:" << berserk.strength << endl;
                cout << "\t\t\t\tdexterity: " << berserk.dex << endl;
                cout << "\t\t\t\tInteligence: " << berserk.intel << endl;
                cout << "\t\t\t\tLuck: " << berserk.luck << endl;
                cout << "\t\t\t\tInicial object: " << berserk.object << endl;
                cout << "\t\t\t\t======================================================" << endl;
                cout << "\t\t\t\t                  ..+@+..                   " << endl;
                cout << "\t\t\t\t                .+%@@@@@@*.                 " << endl;
                cout << "\t\t\t\t              .-@@@@@@@@@@@=.               " << endl;
                cout << "\t\t\t\t              .#@@@@@@@@@@@#.               " << endl;
                cout << "\t\t\t\t              .#@@@@@@@@@@@%:               " << endl;
                cout << "\t\t\t\t              .#-.+#@@@%+.-#:               " << endl;
                cout << "\t\t\t\t              .#%+:.+@*.:+%%:               " << endl;
                cout << "\t\t\t\t              .#@@@++@+=@@@%:               " << endl;
                cout << "\t\t\t\t     .:..     .#@@@++@*=@@@#:     ..:..     " << endl;
                cout << "\t\t\t\t    :%@@=     .=@@@+...=@@@=.    .=@@%:     " << endl;
                cout << "\t\t\t\t    .=#%%=...*:.=@@+. .=@@=.:#...=%%#=.     " << endl;
                cout << "\t\t\t\t       ..*@@@:  ..--. .-=.. .:@@@*..        " << endl;
                cout << "\t\t\t\t        .:@@@%.   ... ...  ..%@@@:.         " << endl;
                cout << "\t\t\t\t       .-=...+%#-.      ..:#@*...==.        " << endl;
                cout << "\t\t\t\t              .:*@#-...-#@*:.               " << endl;
                cout << "\t\t\t\t          ........=@@@@@=........           " << endl;
                cout << "\t\t\t\t        ..@@@@@@@@@@#+#@@@@@@@@@@..         " << endl;
                cout << "\t\t\t\t       .-%@@@@@@@#:.....:*@@@@@@@@-.        " << endl;
                cout << "\t\t\t\t     ..+@@@@@%=..         ..=%@@@@@+.       " << endl;
                cout << "\t\t\t\t   ..+%#*=:..                ...:=*#@+..    " << endl;
                cout << "\t\t\t\t   ....                            .....    " << endl;
                cha = 4;
                repite = false;
                Sleep(3000);
                break;
            }
            break;
        }
    } while (repite);
}
#endif
