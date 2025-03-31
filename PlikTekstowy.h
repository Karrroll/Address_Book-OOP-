#ifndef PlikTekstowy_H
#define PlikTekstowy_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {
    const string NAZWA_PLIKU;

public:
    PlikTekstowy(string &nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {}

    string pobierzNazwePliku() const { return NAZWA_PLIKU; };

    bool czyPlikJestPusty(fstream &plikTekstowy);

};

#endif
