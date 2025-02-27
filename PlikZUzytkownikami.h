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

    bool czyPlikJestPusty();
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami();
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
};

#endif
