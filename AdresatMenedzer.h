#ifndef AdresatMenedzer_H
#define AdresatMenedzer_H

#include "UzytkownikMenedzer.h"
#include "PlikZAdresatami.h"
#include "Adresat.h"
#include "MetodyWczytujace.h"

#include <iostream>
#include <vector>

using namespace std;

class AdresatMenedzer {
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;

public:
    void ustawIdZalogowanegoUzytkownika(int idAktualnieZalogowanegoUzytkownika);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
    void wyswietlDaneAdresata(Adresat adresat);
    void dodajAdresata();
    Adresat podajDaneNowegoAdresata();
};

#endif
