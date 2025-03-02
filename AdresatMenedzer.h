#ifndef AdresatMenedzer_H
#define AdresatMenedzer_H

#include "PlikZAdresatami.h"
#include <iostream>

using namespace std;

class AdresatMenedzer {
    int idZalogowanegoUzytkownika;
    PlikZAdresatami plikZAdresatami;

public:
    void ustawIdZalogowanegoUzytkownika(int idAktualnieZalogowanegoUzytkownika);
    void pobierzAdresatowZalogowanegoUzytkownikaZPliku(int id);

};

#endif

