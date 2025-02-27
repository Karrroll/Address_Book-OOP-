#ifndef PlikZUzytkownikami_H
#define PlikZUzytkownikami_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "Uzytkownik.h"         // mozna usunac bo jest guard
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami {
    string nazwaPlikuZUzytkownikami;
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    fstream plikTekstowy;

    bool czyPlikJestPusty();
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami();
    void wczytajUzytkownikowZPliku(vector <Uzytkownik> &uzytkownicy);
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
};

#endif
