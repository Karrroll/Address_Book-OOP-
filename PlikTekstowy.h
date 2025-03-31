#ifndef PlikTekstowy_H
#define PlikTekstowy_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {
    string nazwaPliku;

public:
    PlikTekstowy(const string &nazwaPliku) {
        this->nazwaPliku = nazwaPliku;
    }
    string pobierzNazwePliku() const { return nazwaPliku; };
    bool czyPlikJestPusty(fstream &plikTekstowy);

};

#endif
