#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");

    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wyswietlWszystkichAdresatowZalogowanegoUzytkownika();

//    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
//    ksiazkaAdresowa.wylogujUzytkownika();
//    ksiazkaAdresowa.wypiszWszytskichUzytkownikow();



    return 0;
}
