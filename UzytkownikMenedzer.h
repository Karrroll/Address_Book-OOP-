#ifndef UzytkownikMenedzer_H
#define UzytkownikMenedzer_H

#include <iostream>

#include "PlikZUzytkownikami.h"
#include "AdresatMenedzer.h"
#include "MetodyWczytujace.h"

using namespace std;

class UzytkownikMenedzer {
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(const string &login);

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    void ustawIdZalogowanegoUzytkownika(const int id) { idZalogowanegoUzytkownika = id; };
    int pobierzIdZalogowanegoUzytkownika() const { return idZalogowanegoUzytkownika; };

    bool czyUzytkownikJestZalogowany();
    void rejestracjaUzytkownika();
    void wypiszWszytskichUzytkownikow();
    void logowanieUzytkownika();
    void wylogujUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
};

#endif
