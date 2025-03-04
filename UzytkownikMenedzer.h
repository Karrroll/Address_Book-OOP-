#ifndef UzytkownikMenedzer_H
#define UzytkownikMenedzer_H

#include <iostream>

#include "PlikZUzytkownikami.h"
#include "MetodyWczytujace.h"

using namespace std;

class AdresatMenedzer;          //zapowiedz klasy i u¿ycie wskaznika w polu klasy. Przez zaleznosci cykliczne?
class UzytkownikMenedzer {
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;
    AdresatMenedzer *adresatMenedzer;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {};
    int pobierzIdZalogowanegoUzytkownika();

    void rejestracjaUzytkownika();
    void wczytajUzytkownikowZPliku();
    void wypiszWszytskichUzytkownikow();
    void logowanieUzytkownika();
    void wylogujUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
};

#endif
