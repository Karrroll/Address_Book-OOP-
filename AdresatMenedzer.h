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
    PlikZAdresatami plikZAdresatami;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(const Adresat &adresat);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
        plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
    void dodajAdresata();
};

#endif
