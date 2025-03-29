#ifndef MetodyWczytujace_H
#define MetodyWczytujace_H

#include <iostream>
#include <sstream>

using namespace std;

class MetodyWczytujace {

public:
    static int wczytajLiczbe();
    static string wczytajTekst();
    static string wczytajLinie();
    static string pobierzLiczbe(const string &tekst, int &pozycjaZnaku);
    static int wczytajLiczbeCalkowita();
    static int podajIdWybranegoAdresata();
    static char wczytajZnak();
};

#endif
