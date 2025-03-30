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

    char wybierzOpcjeZMenuEdycja();
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(const Adresat &adresat);
    void wyswietlIloscWyszukanychAdresatow(const int &iloscAdresatow);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
        plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void dodajAdresata();
    void usunAdresata();
    void edytujAdresata();
    void wyszukajAdresataPoImieniu();
    void wyszukajAdresataPoNazwisku();
    void wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
};
#endif
