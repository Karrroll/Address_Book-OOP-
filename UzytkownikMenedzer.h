#ifndef UzytkownikMenedzer_H
#define UzytkownikMenedzer_H

#include <iostream>
#include <vector>

#include "PlikZUzytkownikami.h"
#include "MetodyWczytujace.h"

using namespace std;

class UzytkownikMenedzer {
    PlikZUzytkownikami plikZUzytkownikami;
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;


    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {};
    int pobierzIdZalogowanegoUzytkownika();
    void rejestracjaUzytkownika();
    void wczytajUzytkownikowZPliku();
    void wypiszWszytskichUzytkownikow();
    int logowanieUzytkownika();
    void wylogujUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();

};

#endif
