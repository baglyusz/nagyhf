#include "bejegyzes.hpp"
#include "fomenu.hpp"
#include "gtest_lite.h"
//#include "memtrace.h"
#include <iostream>
#include <locale>
#include <fstream>
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#include <Windows.h>
#endif

    using std::cout;
    using std::endl;

int main(){
    setlocale(LC_ALL, "");
    #if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    #endif

    lista telefonkonyv;

    telefonkonyv.adatbazis_beolvasas();

    while(fomenu(telefonkonyv)!=-1){
         ;
    }

    return 0;
}
