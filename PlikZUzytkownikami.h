#ifndef PlikZUzytkownikami_H
#define PlikZUzytkownikami_H

#include <iostream>
#include <vector>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami {
    const string nazwaPlikuZUzytkownikami;

    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(const Uzytkownik &uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(const string &daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami(string NAZWA_PLIKU_Z_UZYTKOWNIKAMI) : nazwaPlikuZUzytkownikami(NAZWA_PLIKU_Z_UZYTKOWNIKAMI) {};
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void dopiszUzytkownikaDoPliku(const Uzytkownik &uzytkownik);
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
};
#endif
