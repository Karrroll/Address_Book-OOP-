#ifndef KsiazkaAdresowa_H
#define KsiazkaAdresowa_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        adresatMenedzer = NULL;
    };
    ~KsiazkaAdresowa() {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    };

    int wybierzOpcjeZMenu(const string &kryterium);
    void wyswietlMenuGlowne();
    void wyswietlMenuUzytkownika();

    bool czyUzytkownikJestZalogowany();
    void rejestracjaUzytkownika();
    void wypiszWszytskichUzytkownikow();
    void logowanieUzytkownika();
    void wylogujUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();

    void wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
    void dodajAdresata();
    void usunAdresata();
    void edytujAdresata();
    void wyszukajAdresataPoImieniu();
    void wyszukajAdresataPoNazwisku();
};

#endif
