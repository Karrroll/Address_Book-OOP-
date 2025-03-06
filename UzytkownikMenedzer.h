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
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {};
    int pobierzIdZalogowanegoUzytkownika() const { return idZalogowanegoUzytkownika; };

    void rejestracjaUzytkownika();
    void wczytajUzytkownikowZPliku();
    void wypiszWszytskichUzytkownikow();
    void logowanieUzytkownika(AdresatMenedzer &adresatMenedzer);
    void wylogujUzytkownika(AdresatMenedzer &adresatMenedzer);
    void zmianaHaslaZalogowanegoUzytkownika();
};

#endif
