#ifndef UzytkownikMenedzer_H
#define UzytkownikMenedzer_H

#include <iostream>
#include <vector>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyWczytujace.h"

using namespace std;

class UzytkownikMenedzer {
    PlikZUzytkownikami plikZUzytkownikami;
//    int idZalogowanegoUzytkownika;        utworzylem lokalnie. getter, setter?
    vector <Uzytkownik> uzytkownicy;


    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {};
    void rejestracjaUzytkownika();
    void wczytajUzytkownikowZPliku();
    void wypiszWszytskichUzytkownikow();
    int logowanieUzytkownika();
    int wylogujUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);

};

#endif
