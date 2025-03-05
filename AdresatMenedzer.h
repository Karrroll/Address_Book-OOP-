#ifndef AdresatMenedzer_H
#define AdresatMenedzer_H

#include "PlikZAdresatami.h"
#include "Adresat.h"
#include "MetodyWczytujace.h"
#include "MetodyPomocnicze.h"

#include <iostream>
#include <vector>

using namespace std;

class AdresatMenedzer {
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMenedzer() : plikZAdresatami("Adresaci.txt") {};
    void ustawIdZalogowanegoUzytkownika(int id);

    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
    void dodajAdresata();
};

#endif
