#include "fomenu.hpp"
#include <iostream>
#include <fstream>
#include "bejegyzes.hpp"
#include <limits>

using std::ifstream;
using std::cout;
using std::endl;

int fomenu(lista& telefonkonyv){
    cout << endl << "x-x-x-x-> NYOMJ EGY GOMBOT A FOLYTATASHOZ <-x-x-x-x" << endl;

   getc(stdin);

            cout << endl <<"O-o-O-o-O-O-o-O-o-O O-o-O-o-O-O-o-O-o-O O-o-O-o-O " << endl
                        << "O-o                                           o-O   "
                << endl <<"O-o-O-o-O  TELEFONKONYV ULTIMATE VER. O-o-O-o-O-o" << endl
                        << "O-o                                           o-O   "
                << endl <<"O-o-O-o-O-O-o-O-o-O O-o-O-o-O-O-o-O-o-O-o-O-o-O-O" << endl << endl;



    cout << "    VALASSZ AZ ALABBIAK KOZUL:" << endl << endl
         << "  o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o" << endl
         << "  |                                           | " << endl
         << "  o   Teljes adatbazis megjelenitese: 1       o" << endl
         << "  |                                           | " << endl
         << "  o   Nevjegyfelvetel : 2                     o" << endl
         << "  |                                           | " << endl
         << "  o   Kereses/Torles: 3                       o" << endl
         << "  |                                           | " << endl
         << "  o   Kilepes : 4                             o" << endl
         << "  |                                           | " << endl
         << "  o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o" << endl << endl;


    int VALAMI;
    std::cin >> VALAMI;
    cout << endl << "Valasztott:" << VALAMI << endl << endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch(VALAMI)
    {
        case 1:
            telefonkonyv.adatbazis_kiiras();
            return 0;

        case 2:
            telefonkonyv.nevjegyfelvetel();
            return 0;

        case 3:

           telefonkonyv.kereses();

            cout << endl << "Mit szeretnel most?" << endl << endl << "Adat torlese:1 " << endl << "Semmit <3 : minden mas gomb" << endl;

            int szam;
            std::cin >> szam;
            cout << endl << endl<< "Valasztott: " << szam << endl << endl;

            switch(szam){

                case 1:
                    telefonkonyv.elemtorol();
                    telefonkonyv.fajlbair();
                    break;

                default:
                    return 0;
        }
            return 0;

        case 4:
            cout << endl <<"Szia!:)" << endl << endl;
            return -1;

        default:
            cout << endl <<"Ilyen lehetoseg nincs! Kerlek kovesd az utasitasokat! :(" << endl;
            return -1;
    }
}
