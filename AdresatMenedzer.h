#ifndef AdresatMenedzer_H
#define AdresatMenedzer_H

#include "UzytkownikMenedzer.h"
#include "PlikZAdresatami.h"
#include <iostream>

using namespace std;

class AdresatMenedzer {
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;

public:
    int pobierzIdOstatniegoAdresata();
    void ustawIdZalogowanegoUzytkownika(int idAktualnieZalogowanegoUzytkownika);
    void ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);
    void pobierzAdresatowZalogowanegoUzytkownikaZPliku();

};

#endif

