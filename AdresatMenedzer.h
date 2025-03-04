#ifndef AdresatMenedzer_H
#define AdresatMenedzer_H

#include "UzytkownikMenedzer.h"
#include "PlikZAdresatami.h"
#include "Adresat.h"

#include <iostream>

using namespace std;

class AdresatMenedzer {
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);

public:
    void ustawIdZalogowanegoUzytkownika(int id);

    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
    void dodajAdresata();
};

#endif
