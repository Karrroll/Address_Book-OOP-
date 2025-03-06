#ifndef MetodyWczytujace_H
#define MetodyWczytujace_H

#include <iostream>

using namespace std;

class MetodyWczytujace {

public:
    static string wczytajLinie();
    static string pobierzLiczbe(const string &tekst, int &pozycjaZnaku);
};

#endif
