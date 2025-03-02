#ifndef AdresatMenedzer_H
#define AdresatMenedzer_H

#include "UzytkownikMenedzer.h"
#include "PlikZAdresatami.h"

#include "Adresat.h"

#include <iostream>
#include <vector>

using namespace std;

class AdresatMenedzer {
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;

public:
    int pobierzIdOstatniegoAdresata();
    void ustawIdZalogowanegoUzytkownika(int idAktualnieZalogowanegoUzytkownika);
    void ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);
    void pobierzAdresatowZalogowanegoUzytkownikaZPliku();
    void wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
    void wyswietlDaneAdresata(Adresat adresat);

};

#endif

