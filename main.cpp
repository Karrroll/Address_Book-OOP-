#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");

    ksiazkaAdresowa.wypiszWszytskichUzytkownikow();

    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wylogujUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wylogujUzytkownika();


//    ksiazkaAdresowa.rejestracjaUzytkownika();
//    ksiazkaAdresowa.rejestracjaUzytkownika();
//
//    ksiazkaAdresowa.wypiszWszytskichUzytkownikow();



    return 0;
}
